GPP_FLAGS=-lsystemc

all: prog

../drv/%.o:
	$(MAKE) -C ../drv $*.o

prog: testbench.cpp test_spi.h spi.h clk.h
	g++ $(GPP_FLAGS) $< -o $@

amba: amba_3_lite_tb.cpp amba_3_lite.h amba_3_lite_tb.h
	g++ $(GPP_FLAGS) $< -o $@

clean:
	rm -f prog

.PHONY: all clean

