GPP_FLAGS=-lsystemc

all: prog

prog: testbench.cpp test_spi.h spi.h clk.h
	g++ $(GPP_FLAGS) $< -o $@

clean:
	rm -f prog

.PHONY: all clean

