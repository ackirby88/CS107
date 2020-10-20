from __future__ import absolute_import
import sys
import ctypes

class DIRFILE_INFO_T(ctypes.Structure):
    _fields_ = [('nentry',ctypes.c_uint),
                ('path_len',ctypes.c_uint),
                ('entry_list',ctypes.c_char_p)]

class Dataset:
    def __init__(self,paths):
        self.paths = paths

    def __len__(self):
        return len(self.paths)

    def __getitem__(self,index):
        img_name = self.paths[index]
        return img_name

class AIO_Interface:
    def __init__(self):
        self.aio_lib = []
        self.paths   = None
        self.nranks  = 0
        self.rank    = 0
        self.mpi_on  = 0

    def init(self):
        """Initialize AIO by loading in shared library and initializing mpi."""
        # ==================================================================== #
        # load aio_interface library
        self.aio_lib = ctypes.CDLL("../../builds/aio_release/lib/libaio_interface.so",ctypes.RTLD_GLOBAL)
        # ==================================================================== #
        # library argument types
        LP_c_char = ctypes.POINTER(ctypes.c_char)
        LP_LP_c_char = ctypes.POINTER(LP_c_char)
        LP_c_df_info = ctypes.POINTER(DIRFILE_INFO_T)
        # ==================================================================== #
        # void init(int,char **)
        self.aio_lib.init.argtypes = (ctypes.c_int,
                                      LP_LP_c_char)

        # dirfile_info_t * directory_search(char *,char *,int,int)
        self.aio_lib.directory_search.argtypes = (ctypes.c_char_p,
                                                  ctypes.c_char_p,
                                                  ctypes.c_int,
                                                  ctypes.c_int)
        self.aio_lib.directory_search.restype = LP_c_df_info

        # dirfile_info_t * partition_list(dirfile_info_t *,uint,uint,uint,char)
        self.aio_lib.partition_list.argtpyes = (LP_c_df_info,
                                                ctypes.c_uint,
                                                ctypes.c_uint,
                                                ctypes.c_uint)
        self.aio_lib.partition_list.restype = LP_c_df_info

        # shutdown_dirfile(dirfile_info_t *)
        self.aio_lib.shutdown_dirfile.argtpyes = (LP_c_df_info)
        # ==================================================================== #
        # initialize argc and argv from system
        argc = len(sys.argv)
        argv = (LP_c_char * (argc + 1))()
        for i, arg in enumerate(sys.argv):
                enc_arg = arg.encode('utf-8')
                argv[i] = ctypes.create_string_buffer(enc_arg)
        # ==================================================================== #
        # initialize aio
        if self.mpi_on == 0:
            self.aio_lib.init(argc,argv)
        self.mpi_on = 1
        self.rank = self.aio_lib.rank()
        self.nranks = self.aio_lib.size()

    def shutdown(self):
        if self.mpi_on == 1:
            self.aio_lib.shutdown()
        else:
            print("MPI already shutdown")
        self.mpi_on = 0

    def search_and_partition_files(self, path, pattern, depth, \
                                   shuffle, seed, batch_size):
        """Search for files give a root path and string pattern.
        After finding the files, it partitions across MPI ranks to generate local
        file lists.

        Input args:

        Return args:
            Dataset paths:      mpi-rank local path list
        """
        # 1. search for files
        b_path = path.encode('utf-8')
        b_pattern = ctypes.POINTER(ctypes.c_char)()
        if(pattern != None): b_pattern = pattern.encode('utf-8')

        search_mode = 1 # search for files only
        ginfo = self.aio_lib.directory_search(b_path,b_pattern,search_mode,depth)

        # check ginfo null
        if ginfo:
            Pass
        else:
            return None

        # 2. partition files into batches across mpi ranks
        pinfo = self.aio_lib.partition_list(ginfo,shuffle,seed,batch_size)
        paths = pinfo.contents.entry_list.split()

        # 3. clean up allocated c structures and return list
        self.aio_lib.shutdown_dirfile(ginfo)
        self.aio_lib.shutdown_dirfile(pinfo)
        return Dataset(paths)

    def __del__(self):
        if self.mpi_on == 1:
            self.aio_lib.shutdown()
        self.mpi_on = 0

