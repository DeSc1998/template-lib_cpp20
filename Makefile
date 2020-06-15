
# Name of the project folder
PROJECT_NAME = $(notdir $(CURDIR))

# packages and libraries
PACKAGES = 
LIBS = 

# compiler and flags
INCLUDE_PATH = --include-directory=src/lib/
CXX = clang++
CXX_FLAGS = -Weverything -Wpedantic -Wshadow -std=c++20 -fdiagnostics-format=msvc \
	-Wno-c++98-compat -Wno-c++98-compat-pedantic $(INCLUDE_PATH)
CXX_FLAGS_RELEASE = -O3 $(CXX_FLAGS)
CXX_FLAGS_DEBUG = -O0 -D DEBUG -fcxx-exceptions $(CXX_FLAGS)

# output binary names
OUTPUT_RELEASE = $(addsuffix .exe,$(PROJECT_NAME))
OUTPUT_DEBUG = $(addsuffix _debug.exe,$(PROJECT_NAME))

#  precompiled header (currently unused)
PCH =

# search paths for make
vpath %.cpp src
vpath %.o obj

# list of source and object files
DIR = $(subst /,\,$(CURDIR))
# get sourcefiles via shell (windows)
SRC = $(notdir $(filter %.cpp,$(subst $(DIR),,$(shell dir src /s /b))))
#SRC = $(wildcard *.cpp)
OBJDIR = obj
OBJ = $(addprefix $(OBJDIR)/,$(subst .cpp,.o,$(SRC)))

$(OUTPUT_RELEASE) : $(OBJ)
	$(CXX) -o $(OUTPUT_RELEASE) $(CXX_FLAGS_RELEASE) $^

$(OUTPUT_DEBUG) : $(SRC)
	$(CXX) -o $(OUTPUT_DEBUG) $(CXX_FLAGS_DEBUG) $^

obj/%.o : %.cpp
	$(CXX) -o $@ $(CXX_FLAGS) -c $^

$(OBJDIR) :
	mkdir $(OBJDIR)


.PHONY : clean debug get all analyze analyze_d objdir

clean :
	del $(OUTPUT_RELEASE)
	del $(OUTPUT_DEBUG)
	del /q obj

debug : $(OUTPUT_DEBUG)

all : $(OBJDIR) $(OUTPUT_RELEASE) $(OUTPUT_DEBUG)

objdir : $(OBJDIR)

analyze : $(SRC)
	$(CXX) --analyze $(CXX_FLAGS) $^

analyze_d : $(SRC)
	$(CXX) --analyze $(CXX_FLAGS_DEBUG) $^

# testing make operations
get :
	echo $(wildcard *.cpp)
