BIN := book

BIN_SRCS := main.c

.PHONY: clean all

all: $(BIN)

$(BIN): $(BIN_SRCS)
	$(CC) -o $@ $^ $(LDFLAGS)

clean:
	$(RM) $(BIN)
