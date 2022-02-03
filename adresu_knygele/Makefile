BIN := book
OBJS := main.o linked_list.o usage.o
CPPFLAGS := -g -I$(shell pwd)/

.PHONY: clean all

all: $(BIN)

$(BIN): $(OBJS)
	$(CC) $(CPPFLAGS) -o $@ $^ $(LDFLAGS)

clean:
	$(RM) $(BIN) $(OBJS)
