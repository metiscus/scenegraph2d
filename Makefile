CXXFLAGS= -gdwarf-4 -O0 -Wall -Wextra
LDFLAGS=

default: all

all: libSG2D.a

libSG2D_SRC= \
	src/Object.cpp\
	src/RefPtr.cpp\
	src/Referenced.cpp\
	src/Node.cpp\
	src/Group.cpp

libSG2D_OBJ= $(libSG2D_SRC:.cpp=.o)

libSG2D.a: $(libSG2D_OBJ)
	- ar -rcs libSG2D.a  $(libSG2D_OBJ)

clean:
	- rm -f $(libSG2D_OBJ) libSG2D.a
