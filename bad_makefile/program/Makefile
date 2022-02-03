OBJS := main.o math_functions.o
PREFIX := /usr
BIN := calculator
CFLAGS := -Wall
CPPFLAGS := -I$(shell pwd)

.PHONY: clean all install uninstall

all: $(BIN)

$(BIN): $(OBJS)
	$(CC) $(CPPFLAGS) $(CFLAGS) -o $@ $^
	
install:
	install -d $(DESTDIR)/$(PREFIX)/bin
	install -m 555 $(BIN) $(DESTDIR)/$(PREFIX)/bin

uninstall:
	$(RM) $(DESTDIR)/$(PREFIX)/bin/$(BIN)

clean:
	$(RM) $(BIN) $(OBJS)
