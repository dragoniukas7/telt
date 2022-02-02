BIN := calculator
BIN_SRCS := main.o maths.o usage.o
CPPFLAGS := -I$(shell pwd)/

.PHONY: clean all

all: $(BIN)

$(BIN): $(BIN_SRCS)
	$(CC) $(CPPFLAGS) -o $@ $^ $(LDFLAGS)

clean:
	$(RM) $(BIN) $(BIN_SRCS)
