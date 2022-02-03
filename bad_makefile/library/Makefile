CFLAGS:=-Wall -fpic -shared
LIB:=libmath_functions.so
OBJS := math_functions.o
PREFIX := /usr

.PHONY: clean all install uninstall

all: $(LIB)

$(LIB): $(OBJS)
	$(CC) $(CFLAGS) -o $(LIB) $^

install:
	install -d $(DESTDIR)/$(PREFIX)/lib $(DESTDIR)/$(PREFIX)/include
	install -m 644 math_functions.h $(DESTDIR)/$(PREFIX)/include
	install -m 644 $(LIB) $(DESTDIR)/$(PREFIX)/lib

uninstall:
	$(RM) $(DESTDIR)/$(PREFIX)/lib/$(LIB)
	$(RM) $(DESTDIR)/$(PREFIX)/include/math_functions.h

clean:
	$(RM) $(LIB) $(OBJS)
