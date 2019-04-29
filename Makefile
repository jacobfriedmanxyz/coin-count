CC = gcc

bin/coin_count: build/main.o build/config.o build/run.o
	$(CC) $^ -o $@

build/%.o: src/%.c
	$(CC) -c $^ -o $@

.PHONY: clean
clean:
	rm build/*
