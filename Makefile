CXXFLAGS := $(shell root-config --cflags)

# ROOT AND EIGEN INCLUDES (Computational libraries)
ROOTLIB := $(shell root-config --libs)
EIGEN_INC := $(shell pkg-config --cflags eigen3)


SRC_CPP := $(wildcard src/*.cpp)
SRC_C := $(wildcard src/*.C)

OBJS := $(patsubst src/%.cpp, bin/%.o, $(SRC_CPP))
OBJS += $(patsubst src/%.C, bin/%.o, $(SRC_C))

.PRECIOUS: $(OBJS)

VPATH = main:src 

# Just compiling
bin/%.o: %.cpp
	g++ -c $(CXXFLAGS) $^ -o $@ -I src $(EIGEN_INC)

# Just linking
bin/%.exe : bin/%.o $(OBJS)
	@echo "Compiling"
	g++ $(CXXFLAGS) $^ -o $@ -I src $(ROOTLIB) $(EIGEN_INC)

# Compiling and linking
bin/%.exe : %.C
	@echo "Compiling"
	g++ $(CXXFLAGS) $^ -o $@ -I src $(ROOTLIB) $(EIGEN_INC)

# Cleaning
clean :
	rm -f bin/*.o bin/*.exe
	clear