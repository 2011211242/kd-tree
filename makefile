PROJECT := $(shell readlink $(dir $(lastword $(MAKEFILE_LIST))) -f)

CXX = g++
CXXFLAGS = -std=c++11 \
		   -O3 \
		   -Wall \
		   -fno-omit-frame-pointer \
		   -fPIC 

INC_FLAGS= -I ${PROJECT}/include
BIN_DIR = $(PROJECT)/bin
LIB_DIR = $(PROJECT)/lib
MKDIR = $(BIN_DIR) \
		$(LIB_DIR)

OBJS =  $(shell find $(PROJECT) -type f -name "*.o")
BASE_SRC = $(shell find $(PROJECT)/src -type f -name "*.cpp" -type f ! -name "main.cpp")
BASE_OBJ = $(BASE_SRC:%.cpp=%.o)

SERVER_SRC = $(shell find $(PROJECT)/src -type f -name "main.cpp")
SERVER_OBJ = $(SERVER_SRC:.cpp=.o)
KDTREE_SERVER=$(BIN_DIR)/kdtree_server
LIB_KDTREE=$(LIB_DIR)/libkdtree.a
LD_KDTREE=$(LIB_DIR)/libkdtree.so

all: path \
	kdtree_server \
	kdtree_ld \
	kdtree_lib 

path: $(MKDIR)

$(MKDIR):
	mkdir -p $@

kdtree_server: path $(KDTREE_SERVER)
kdtree_lib:	path $(LIB_KDTREE)
kdtree_ld: path $(LD_KDTREE)

$(LIB_KDTREE): $(BASE_OBJ)
	ar csrv $@ $^

$(LD_KDTREE): $(BASE_OBJ)
	${CXX} ${CXXFLAGS} -shared $^ -o $@

$(BASE_OBJ): %.o: %.cpp $(BASE_SRC)
	${CXX} ${CXXFLAGS} ${INC_FLAGS} -c $< -o $@

$(SERVER_OBJ): %.o: %.cpp $(SERVER_SRC)
	${CXX} ${CXXFLAGS} ${INC_FLAGS} -c $< -o $@

$(KDTREE_SERVER): $(BASE_OBJ) $(SERVER_OBJ)
	${CXX} ${CXXFLAGS}  $^ -o $@

make clean:
	rm -rf $(BIN_DIR) $(LIB_DIR) $(OBJS)

