drv = \
      amba_3_lite \
      amba_3_lite_discrete_adapter \
      amba_3_lite_pmodoled_adapter \
      discrete \
      pmodoled \
      spi \
      amba_3_lite_spi_adapter \


drivers = $(addsuffix .o, $(drv))

CFLAGS = -Wall -Wextra -Wpedantic -Wno-unused-parameter -Wno-return-type

%.o: %.c *.h
	$(CC) $(CFLAGS) -c $< -o $@

main: main.c sample.o $(drivers)
	$(CC) $(CFLAGS) $^ -o $@

clean:
	rm -f main $(drivers)

