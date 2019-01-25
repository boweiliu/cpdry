
all: bootstrap.out bootstrap.cpp

bootstrap.out: bootstrap.cpd
	g++ -std=c++11 -x c++ bootstrap.cpd -o bootstrap.out

bootstrap.cpp: bootstrap.cpd
	./bootstrap.out bootstrap.cpd
