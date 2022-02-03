BIN := calculator
OBJS := main.o maths.o usage.o
CPPFLAGS := -I$(shell pwd)/

.PHONY: clean all install uninstall

all: $(BIN)

$(BIN): $(OBJS)
	$(CC) $(CPPFLAGS) -o $@ $^ $(LDFLAGS)

install:
	install -d $(DESTDIR)/$(PREFIX)/bin
	install -m 555 $(BIN) $(DESTDIR)/$(PREFIX)/bin

uninstall:
	$(RM) $(DESTDIR)/$(PREFIX)/bin/$(BIN)
	
clean:
	$(RM) $(BIN) $(OBJS)
