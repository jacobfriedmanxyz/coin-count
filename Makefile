CC = tcc
PREFIX = ~/.local

build/coin-count: src/main.c
	$(CC) $< -o $@

.PHONY: clean
clean:
	rm build/*

.PHONY: install
install: build/coin-count
	cp $^ $(PREFIX)/bin/
