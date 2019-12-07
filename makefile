BUILD := build/main build/test
GCC := gcc

main: build/main build/test build/interface
	$(GCC) -o build/master $(BUILD)

build/main: src/main.c
	$(GCC) -c -o $@ $<

build/test: src/test.c
	$(GCC) -o build/test $<

build/interface: src/interface.cpp
	g++ -o $@ $<
