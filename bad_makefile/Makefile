
.PHONY: lib src clean all

all: lib src

lib:
	$(MAKE) -C ./library

src:
	$(MAKE) -C ./program

install:
	$(MAKE) -C ./library install
	$(MAKE) -C ./program install

uninstall:
	$(MAKE) -C ./library uninstall
	$(MAKE) -C ./program uninstall

clean:
	$(MAKE) -C ./library clean
	$(MAKE) -C ./program clean
