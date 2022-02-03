CFLAGS:=-Wall -fpic -shared
LIB := liblogger.so
OBJS := logger.o
PREFIX := /usr

.PHONY: clean all install uninstall

all: $(LIB)

$(LIB): $(OBJS)
	$(CC) $(CFLAGS) -o $(LIB) $^

install:
	install -d $(DESTDIR)/$(PREFIX)/lib $(DESTDIR)/$(PREFIX)/include
	install -m 644 logger.h $(DESTDIR)/$(PREFIX)/include
	install -m 644 $(LIB) $(DESTDIR)/$(PREFIX)/lib

uninstall:
	$(RM) $(DESTDIR)/$(PREFIX)/lib/$(LIB)
	$(RM) $(DESTDIR)/$(PREFIX)/include/logger.h

clean:
	$(RM) $(LIB) $(OBJS)
