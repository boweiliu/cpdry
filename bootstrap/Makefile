ifndef makefile_env_defined
  include ../Makefile.env
endif

bin/a.out: src/main.cpp
	$(CC) $(CFLAGS) src/main.cpp -o bin/a.out

.PHONY: clean

clean:
	rm bin/a.out
