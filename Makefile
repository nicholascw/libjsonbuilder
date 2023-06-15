CFLAGS = --std=gnu99 -O0 -fPIC -Wall -Wextra
CC = gcc

ifeq ($(DEBUG), 1)
	CFLAGS += -g -DDEBUG
endif

.PHONY: all clean

all : libjsonbuilder

libjsonbuilder.so: obj/jsonbuilder.o
	$(CC) $(CFLAGS) -shared obj/jsonbuilder.o -o $@

clean:
	$(RM) vgcore.* obj/*.o libjsonbuilder.so

obj/%.o: %.c
	mkdir -p $(@D)
	$(CC) $(CFLAGS) -c -o $@ $<

install: jsonbuilder.h libjsonbuilder.so PKGBUILD
	makepkg -scfi
