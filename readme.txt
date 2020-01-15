
to run:
enter: "make" to compile, then

enter: "./simulator BENCH_NAME_HERE" to run the specified benches.

./simulator bench_add_sub
./simulator bench_compare
./simulator bench_load_imm1
./simulator bench_load_imm2


Each line corresponds to a binary string in the given file. Next to the line is the expected output.
bench_load_imm1:
print(R0, decimal) => 0
print(R1, decimal) => 0
print(R2, decimal) => 0
print(R3, decimal) => 0
R0 = 1
print(R0, decimal) => 1
R0 = 2
print(R0, decimal) => 2
R0 = 3
print(R0, decimal) => 3
R0 = 4
print(R0, decimal) => 4
R0 = 5
print(R0, decimal) => 5
R0 = 6
print(R0, decimal) => 6
R0 = 7
print(R0, decimal) => 7
R0 = -8
print(R0, decimal) => -8
R0 = -7
print(R0, decimal) => -7
R0 = -6
print(R0, decimal) => -6
R0 = -5
print(R0, decimal) => -5
R1 = -4
print(R1, decimal) => -4
R3 = -3
print(R3, decimal) => -3
R4 = -2
print(R3, decimal) => -2
R4 = -1
print(R3, decimal) => -1

bench_load_imm2:
R0 = 7
R0 = R0 + R0
R0 = R0 + R0
R0 = R0 + R0
print(R0, decimal) => 56
print(R0, hex) => 38
print(R0, ASCII) => 8
print(R0, decimal, hex, ASCII) => 56 => 38 => 8
R1 = -1
print(decimal, hex) => -1, => FF
print(R0, hex, ASCII) => 38 => 8

bench_add_sub:
R0 = 1
R1 = 2
R3 = R1 + R0
print(R3, decimal) => 3
R3 = R3 + R3
print(R3, decimal) => 6
R3 = R3 + R3
print(R3, decimal) => 12
R4 = -8
R3 = R4 + R3
print(R3, decimal) => 4
R3 = R3 - R0
print(R3, decimal) => 3
R3 = R3 - R4
print(R3, decimal) => 11
R4 = R4 – R1
print(R4, decimal) => -9
R4 = R1 - R0
print(R4, decimal) => 1

bench_compare:
R0 = 7
R1 = 2
R2 = 2
compare(R1, R2, skip 1) note: compares as equals print(R2, decimal) note: This should be skipped
compare(R1, R2, skip 2) note: compares as equals
print(R2, decimal) note: should skipped
print(R2, decimal) note: should skipped
compare(R0, R1, skip 1) note: compare as not equals
print(R2, decimal) => 2
compare(R1, R0, skip 2) note: compare as not equals
print(R0, decimal) => 7

