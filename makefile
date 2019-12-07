GCC := gcc

main: build/main build/test
	$(GCC) -o build/master $<

build/main: src/main.c
	$(GCC) -c -o $@ $<

build/test: src/test.c
	$(GCC) -o build/test $<
