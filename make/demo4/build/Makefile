
# HELP: displays information message
# ---------------------------------------------------
help    :
	@echo ""
	@echo " Usage:"
	@echo "	make [TARGET] {DEBUG=1}"
	@echo ""
	@echo " TARGET:"
	@echo "	intel ... builds binaries using Intel Compilers"
	@echo "	gnu ... builds binaries using GNU Compilers"
	@echo""
	@echo "	help  ... displays this message      "
	@echo "	clean ... removes object files       "
	@echo "	backup ... creates tarball file       "

# Compiler Targets
# ----------------------------------------------
% :
	@echo "                                      "
	@echo " *** Compiling : $@ version           "
	@echo "                                      "
	$(MAKE) -f Makefile.dg ARCH=$@

# Maintanace Targets
# ----------------------------------------------
clean   :
	@echo "                                      "
	@echo " *** Clean : removing object files    "
	@echo "                                      "
	@( $(RM) *.o *.mod *~ Sample*)
	@( $(RM) ../src/*~ )
