#CXX=clang++

CXXFLAGS:= -gdwarf-4 -O0 -Wall -Wextra -Iglm `pkg-config --cflags glfw3` `pkg-config --cflags glew`
LDFLAGS:= `pkg-config --libs glfw3` `pkg-config --libs glew` -L.

default: all

all: libSG2D.a example1

libSG2D_SRC= \
	Group.cpp\
	Image.cpp\
	Logging.cpp\
	Matrix.cpp\
	Node.cpp\
	Object.cpp\
	Program.cpp\
	Rectangle.cpp\
	Referenced.cpp\
	Shader.cpp\
	Stage.cpp\
	Texture.cpp\
	Transform.cpp\
	Uniform.cpp\
	VBO.cpp\
	stb/stb_image.cpp\
	

libSG2D_OBJ= $(libSG2D_SRC:.cpp=.o)

libSG2D.a: $(libSG2D_OBJ)
	- ar -rcs libSG2D.a  $(libSG2D_OBJ)

example1 : libSG2D.a
	$(CXX) $(CXXFLAGS) -o example1 example1.cpp -L. -lSG2D

clean:
	- rm -f $(libSG2D_OBJ) libSG2D.a example1.o
