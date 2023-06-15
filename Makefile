CFLAGS = --std=gnu99 -O0 -fPIC -Wall -Wextra
CC = gcc

ifeq ($(DEBUG), 1)
	CFLAGS += -g -DDEBUG
endif

.PHONY: all clean

all : libjsonbuilder.so

libjsonbuilder.so: obj/jsonbuilder.o
	$(CC) $(CFLAGS) -shared obj/jsonbuilder.o -o $@

clean:
	$(RM) -r vgcore.* libjsonbuilder.so libjsonbuilder src/ pkg/ obj/ libjsonbuilder*.tar*

obj/%.o: %.c
	mkdir -p $(@D)
	$(CC) $(CFLAGS) -c -o $@ $<

install: jsonbuilder.h libjsonbuilder.so PKGBUILD
	makepkg -scfi
