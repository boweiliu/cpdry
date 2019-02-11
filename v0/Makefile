ifndef makefile_env_defined
  include ../Makefile.env
endif

.PHONY: all clean

all: bin/a.out

out/main.cpp: src/main.cpd
	../bootstrap/bin/a.out src/main.cpd -o out/main.cpp

bin/a.out: out/main.cpp
	$(CC) $(CFLAGS) -x c++ out/main.cpp -o bin/a.out

clean:
	rm out/main.cpp bin/a.out
