BIN := programa
LIB := libfile_reader.so
BIN_SRCS := main.o
LIB_SRCS := file_reader.o
CPPFLAGS := -I$(shell pwd)/
LDFLAGS := -L$(shell pwd)/ -lfile_reader

.PHONY: clean all

all: $(LIB) $(BIN)

$(BIN): $(BIN_SRCS)
	$(CC) $(CPPFLAGS) -o $@ $^ $(LDFLAGS)

$(LIB): $(LIB_SRCS)
	$(CC) -fpic -shared -o $@ $^

clean:
	$(RM) $(BIN) $(LIB) $(LIB_SRCS) $(BIN_SRCS)
