CC = c99
CFLAGS = -Wall -O3
PREFIX = ~/.local

build/coin-count: src/main.c
	mkdir -p build
	$(CC) $(CFLAGS) $< -o $@

.PHONY: clean
clean:
	rm -vrf build

.PHONY: install
install: build/coin-count
	cp $^ $(PREFIX)/bin/
