BIN := program
PREFIX := /usr
LIB := libfile_reader.so
BIN_OBJS := main.o
LIB_OBJS := file_reader.o
CPPFLAGS := -I$(shell pwd)/
LDFLAGS := -L$(shell pwd)/ -lfile_reader

.PHONY: clean all install unistall

all: $(LIB) $(BIN)

$(BIN): $(BIN_OBJS)
	$(CC) $(CPPFLAGS) -o $@ $^ $(LDFLAGS)

$(LIB): $(LIB_OBJS)
	$(CC) -fpic -shared -o $@ $^
	
install:
	install -d $(DESTDIR)/$(PREFIX)/lib $(DESTDIR)/$(PREFIX)/include
	install -d $(DESTDIR)/$(PREFIX)/bin
	install -m 644 file_reader.h $(DESTDIR)/$(PREFIX)/include
	install -m 644 $(LIB) $(DESTDIR)/$(PREFIX)/lib
	install -m 555 $(BIN) $(DESTDIR)/$(PREFIX)/bin

uninstall:
	$(RM) $(DESTDIR)/$(PREFIX)/lib/$(LIB)
	$(RM) $(DESTDIR)/$(PREFIX)/include/file_reader.h
	$(RM) $(DESTDIR)/$(PREFIX)/bin/$(BIN)

clean:
	$(RM) $(BIN) $(LIB) $(LIB_OBJS) $(BIN_OBJS)
