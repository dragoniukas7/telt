compiler:=gcc
Flags:=-Wall -Ipwd
OBJS:=main.o math_functions.o
PREFIX := /usr
BIN:=calculator
CPPFLAGS := -I$(shell pwd)/../library
LDFLAGS := -L$(shell pwd)/../library -lmath_functions

.PHONY: clean all install uninstall

all: $(BIN)

$(BIN): main.c
	$(compiler) $(CPPFLAGS) $(Flags) -o $@ $^ $(LDFLAGS)
	
install:
	install -d $(DESTDIR)/$(PREFIX)/bin
	install -m 555 $(BIN) $(DESTDIR)/$(PREFIX)/bin

uninstall:
	$(RM) $(DESTDIR)/$(PREFIX)/bin/$(BIN)

clean:
	rm -f $(BIN) $(OBJS)
