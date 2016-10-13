GPP_FLAGS=-lsystemc

all: prog

prog: testbench.c spi.h
	g++ $(GPP_FLAGS) $< -o $@

clean:
	rm -f prog

.PHONY: all clean

