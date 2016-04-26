.PHONY: clean pack

CFLAGS   = -std=c99 -pedantic -g -Wall -Wextra -O2
CXXFLAGS = -std=c++11 -pedantic -Wall -Wextra -O2
OBJS     = htab_init.o \
           htab_init2.o \
           htab_lookup_add.o \
           htab_remove.o \
           htab_clear.o \
           htab_free.o \
           htab_foreach.o \
           hash_function.o

all: tail tail2 wordcount wordcount-dynamic

libhtable.a: $(OBJS)
	ar crs libhtable.a $(OBJS)

libhtable.so: $(OBJS)
	gcc $(CFLAGS) -shared -fPIC -o libhtable.so $(OBJS)

io.o: io.c io.h
	gcc $(CFLAGS) -c io.c -o $@

wordcount.o: wordcount.c io.h htable.h
	gcc $(CFLAGS) -c wordcount.c -o $@

hash_function.o: hash_function.c htable.h
	gcc $(CFLAGS) -c -fPIC hash_function.c -o $@

htab_init2.o: htab_init2.c htable.h
	gcc $(CFLAGS) -c -fPIC htab_init2.c -o $@

htab_init.o: htab_init.c htable.h
	gcc $(CFLAGS) -c -fPIC htab_init.c -o $@

htab_lookup_add.o: htab_lookup_add.c htable.h
	gcc $(CFLAGS) -c -fPIC htab_lookup_add.c -o $@

htab_foreach.o: htab_foreach.c htable.h
	gcc $(CFLAGS) -c -fPIC htab_foreach.c -o $@

htab_clear.o: htab_clear.c htable.h
	gcc $(CFLAGS) -c -fPIC htab_clear.c -o $@

htab_free.o: htab_free.c htable.h
	gcc $(CFLAGS) -c -fPIC htab_free.c -o $@

htab_remove.o: htab_remove.c htable.h
	gcc $(CFLAGS) -c -fPIC htab_remove.c -o $@

tail:
	gcc $(CFLAGS) -o $@ tail.c

tail2:
	g++ $(CXXFLAGS) -o $@ tail2.cc

wordcount: wordcount.o io.o libhtable.a
	gcc $(CFLAGS) wordcount.o io.o libhtable.a -o $@

wordcount-dynamic: wordcount.o io.o libhtable.so
	gcc $(CFLAGS) -dynamic wordcount.o io.o libhtable.so -o $@

clean:
	rm -f *.zip
	rm -f *.o
	rm -f *.so
	rm -f *.a
	rm -f tail
	rm -f tail2
	rm -f wordcount
	rm -f wordcount-dynamic

pack: clean
	zip xklima22.zip *.c *.cc *.h Makefile
