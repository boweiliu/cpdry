ifndef makefile_env_defined
  include ../Makefile.env
endif

all: bin/a.out

out/main.cpp: src/main.cpd
	../bootstrap/bin/a.out src/main.cpd out/main.cpp

bin/a.out: out/main.cpp
	$(CC) -x c++ out/main.cpp -o bin/a.out
