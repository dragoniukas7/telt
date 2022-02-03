OBJS := log_viewer.o
PREFIX := /usr
BIN := log_viewer
CFLAGS := -Wall
CPPFLAGS := -I$(shell pwd)/../lib -L$(shell pwd)/../lib -llogger -lsqlite3

.PHONY: clean all install uninstall

all: $(BIN)

$(BIN): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^ $(CPPFLAGS)
	
install:
	install -d $(DESTDIR)/$(PREFIX)/bin
	install -m 555 $(BIN) $(DESTDIR)/$(PREFIX)/bin

uninstall:
	$(RM) $(DESTDIR)/$(PREFIX)/bin/$(BIN)

clean:
	$(RM) $(BIN) $(OBJS)
