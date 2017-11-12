build:
	avr-gcc -std=c99 -Wall -ggdb3 -gdwarf-2 -Os  -mmcu=attiny84 -DF_CPU=8000000 main.c  -Wl,--relax,--gc-sections -Wl,--undefined=_mmcu,--section-start=.mmcu=0x910000 -Isimavr/simavr/sim/avr -o main.axf 

sim:
	simavr/simavr/run_avr -m attiny84 main.axf 

gtk:
	gtkwave gtkwave_trace.vcd -a gtkwave.gtkw

