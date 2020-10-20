from __future__ import absolute_import
import core.AIO_Interface as aio

# Class Instance #
this = aio.AIO_Interface()

# API Functions #
def init():
    this.init()

def shutdown():
    this.shutdown()

def rank():
    return this.rank

def size():
    return this.nranks

def FindData(file_path,file_pattern=None,search_depth=0,shuffle=1,seed=2,batch_size=64):
    """Search file_path for files and partitions into unique, shuffled, file lists.

    Input params:
        file_path:      search path.
        file_pattern:   file path sub-string to match while searching for files.
        search_depth:   search directory depth (0: search this directory,
                                                1: search one layer deep [parallel search]).
        shuffle:        shuffle file lists among ranks
        seed:           seed for random shuffle
        batch_size:     partition file lists into multiples of batch_size (or near for remaining files)

    Return params:
        list:           list of local file paths unique to this rank
    """
    return this.search_and_partition_files(file_path, file_pattern, search_depth, \
                                           shuffle, seed, batch_size)

def LoadData(file_paths,file_type=-1):
    """Load data given an array of path strings.

    Input params:
        file_paths:     list of file paths
        file_type:      flag indicator of file type (0: image file)
    """
    # determine file type if default
#    if file_type == -1:
#        path = file_paths[0].lower()
#
#        if path.endswith(('.png', '.jpg', '.jpeg')):
#            from PIL import Image
#            file_type = 0
#
#    if file_type == 0:
#        # read image files
#        for item in enumerate(file_paths):
#            image = Image.open(item)
#            image.show()