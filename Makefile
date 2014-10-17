CXX=clang++
CXXFLAGS= -gdwarf-4 -O0 -Wall -Wextra
LDFLAGS=

default: all

all: libSG2D.a

libSG2D_SRC= \
	Referenced.cpp\
	Object.cpp\
	Node.cpp\
	Group.cpp\
	Transform.cpp\
	Matrix.cpp\
	

libSG2D_OBJ= $(libSG2D_SRC:.cpp=.o)

libSG2D.a: $(libSG2D_OBJ)
	- ar -rcs libSG2D.a  $(libSG2D_OBJ)

clean:
	- rm -f $(libSG2D_OBJ) libSG2D.a
