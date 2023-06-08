SRCS = src/double_up.c

build: src/main.c clean
	$(CC) -o build/double_up src/main.c $(SRCS)

clean:
	rm -rf build/*
