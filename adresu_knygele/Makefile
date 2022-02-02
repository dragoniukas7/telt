BIN := book


BIN_SRCS := main.o user_input.o
CPPFLAGS := -I$(shell pwd)/

.PHONY: clean all

all: $(BIN)

$(BIN): $(BIN_SRCS)
	$(CC) $(CPPFLAGS) -o $@ $^ $(LDFLAGS)

clean:
	$(RM) $(BIN)
