#############################################################################
# Makefile for General timer
#############################################################################

#
# Name(overwrite from the top make)
#
MODEL                   = inter_module_sync

#
# Location(overwrite from the top make)
#
PROJ_HOME               = $(shell pwd)/../../../..
LIBPATH                 = lib-$(MODEL)


#
# Location(for local)
#
MODEL_HOME                      = $(PROJ_HOME)/models
COMMON_MODEL_PATH               = $(MODEL_HOME)/common/common
COMMON_BUS_MODEL_PATH           = $(MODEL_HOME)/common/common_bus
INTER_MODULE_SYNC_MODEL_PATH    = $(COMMON_MODEL_PATH)/$(MODEL)

#
# SystemC location and architecture(overwrite from the top make)
#
SYSTEMC_HOME    ?= /shsv/MobAP2/prj_MCS/01_common/01_SystemC/systemc-2.3.1a_MOD_gcc62_64bit
SYSTEMC_INCPATH = $(SYSTEMC_HOME)/include

ifeq "$(shell uname -s)" "SunOS"
    TARGET_ARCH     ?= gccsparcOS5
else
    TARGET_ARCH     ?= linux
endif

#
# Make command(overwrite from the top make)
#
MAKE        = gmake

#
# other command(for local)
#
RM          = rm
RM_OPT      = -rf
AR          = ar cqs

#
# Linux RedHat7.3 - gcc2.96(overwrite from the top make)
#
CXX             ?= /usr/bin/g++
OPTFLAG         = -g
DEFFLAG         =
DBGFLAG         = -Wno-deprecated
INCPATH         = -I$(SYSTEMC_INCPATH) -I. -I$(COMMON_MODEL_PATH) -I$(INTER_MODULE_SYNC_MODEL_PATH) -I$(COMMON_BUS_MODEL_PATH)

#
# Linux RedHat7.3 - gcc2.96(for local)
#
DEPFLAG         = -MM
DEFFLAG_MINE    = -DREGIF_SC_REPORT -DSC_INCLUDE_DYNAMIC_PROCESSES
DBGFLAG_MINE    =
INCPATH_MINE    = -I/mnt/d/RVC_SVN_REPO/RCAR_BUS/environment/s956a/models/common/common
LIBDIR          = -L. -L$(SYSTEMC_HOME)/lib-linux64
CXXFLAGS        = $(OPTFLAG) $(DEFFLAG) $(DEFFLAG_MINE) $(DBGFLAG) $(DBGFLAG_MINE) $(INCPATH) $(INCPATH_MINE) #-fprofile-arcs -ftest-coverage -fno-elide-constructors -fpermissive

#
# Files(for local)
#
SOURCES     = main.cpp \
              axiif.cpp \
              bufcam.cpp

OBJECTS     = $(patsubst %.cpp, $(LIBPATH)/%.o, $(notdir $(SOURCES)))
GCNOS       = $(patsubst %.cpp, $(LIBPATH)/%.gcno, $(notdir $(SOURCES)))
GCDAS       = $(patsubst %.cpp, $(LIBPATH)/%.gcda, $(notdir $(SOURCES)))

TARGET      = $(LIBPATH)/$(MODEL).a

#
# Implicit rules
#
%.d:%.cpp
	$(CXX) $(DEPFLAG) $(CXXFLAGS) $< | sed 's!$*.o:!$$(LIBPATH)/&!g' > $@
$(LIBPATH)/%.o:%.cpp
	$(CXX) -c $(CXXFLAGS) -o $@ $<

#
# Build rules
#


.PHONY : all compile clean
all: $(DEPS)
	if test ! -d $(LIBPATH); then mkdir $(LIBPATH); fi;
	$(MAKE) -f Makefile compile
	$(MAKE) -f Makefile app


compile: $(TARGET)

$(TARGET): $(OBJECTS)
	$(AR) $@ $(OBJECTS) 2>&1 | c++filt
	@echo "Done"

$(OBJECTS): $(SOURCES) $(SOURCES:.cpp=.d)

app:
	$(CXX) $(CXXFLAGS) $(LIBDIR) -o $(@) $(LIBPATH)/*.o -lsystemc -lm -Wl,-rpath,$(SYSTEMC_HOME)/lib-linux64/
	@echo "done make app"

clean:
	find . -name "*~" -print -exec rm -f {} \;
	$(RM) $(RM_OPT) $(SOURCES:.cpp=.d) $(OBJECTS) $(GCNOS) $(GCDAS) $(TARGET) core
	$(RM) $(RM_OPT) $(LIBPATH)
	rm app
#
# Dependencies
#
$(DEPS):
	-include $(SOURCES:.cpp=.d)
