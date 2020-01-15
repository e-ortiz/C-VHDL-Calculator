## Edwin Ortiz, Dylan Sillart
## CPEG324 Lab1: 8-Bit Calculator ISA 
## makefile

build:
	gcc -std=c99 -o simulator main.c

bench_load_imm1: build
	./simulator bench_load_imm1

bench_load_imm2: build
	./simulator bench_load_imm2

bench_add_sub: build
	./simulator bench_add_sub

bench_compare: build
	./simulator bench_compare

clean:
	rm -f simulator
