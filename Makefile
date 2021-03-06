ifndef makefile_env_defined
  include Makefile.env
endif

.PHONY: bootstrap v0 all clean

v2: v1
	cd v2 && $(MAKE)

v1: v0
	cd v1 && $(MAKE)

v0: bootstrap
	cd v0 && $(MAKE)

bootstrap:
	cd bootstrap && $(MAKE)



clean:
	cd bootstrap && $(MAKE) clean
	cd v0 && $(MAKE) clean
	

#bootstrap: bootstrap/bin/bootstrap.out

#bootstrap/bin/bootstrap.out: bootstrap/src/bootstrap.cpd
#	cd bootstrap && mkdir -p bin && g++ -std=c++11 -x c++ src/bootstrap.cpd -o bin/bootstrap.out

#all: bootstrap.out bootstrap.cpp
#
#bootstrap.out: bootstrap.cpd
#	g++ -std=c++11 -x c++ bootstrap.cpd -o bootstrap.out
#
#bootstrap.cpp: bootstrap.cpd
#	./bootstrap.out bootstrap.cpd
