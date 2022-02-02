CC:=gcc
CFLAGS:=-Wall
LIB:=libmath_functions.so
LIB_SRCS := math_functions.c
PREFIX := /usr

all: $(LIB)

$(LIB): $(LIB_SRCS)
	$(CC) -fpic -shared -o $(LIB) $^

install:
	install -d $(DESTDIR)/$(PREFIX)/lib $(DESTDIR)/$(PREFIX)/include
	install -m 644 math_functions.h $(DESTDIR)/$(PREFIX)/include
	install -m 644 $(LIB) $(DESTDIR)/$(PREFIX)/lib

uninstall:
	$(RM) $(DESTDIR)/$(PREFIX)/lib/$(LIB)
	$(RM) $(DESTDIR)/$(PREFIX)/include/math_functions.h

clean:
	rm -f $(LIB)
