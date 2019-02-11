ifndef makefile_env_defined
  include Makefile.env
endif

.PHONY: bootstrap v0

all: v0

bootstrap:
	cd bootstrap && $(MAKE)

v0: bootstrap
	cd v0 && $(MAKE)
	

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
