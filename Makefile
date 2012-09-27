CXX ?= clang++

CPPFLAGS ?= -I/include -I/usr/include -I/usr/local/include -I$(HOME)/include -I$(HOME)/src
LDFLAGS ?= -L/usr/lib -L/usr/local/lib -L$(HOME)/lib

FLAGS = $(CPPFLAGS) $(LDFLAGS)

OPENGL = -framework OpenGL -framework GLUT
LOGGING = -lglog -lgflags

main:
	$(CXX) -o build/main main.cc $(FLAGS) $(OPENGL) $(LOGGING)

clean:
	rm build/main

run: main
	build/main
