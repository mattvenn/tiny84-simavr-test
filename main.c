#include <avr/sleep.h>
#include <avr/delay.h>
#include "avr_mcu_section.h"
AVR_MCU(F_CPU, "attiny84");

#define HIGH(sfr, bit) (_SFR_BYTE(sfr) |= _BV(bit))
#define LOW(sfr, bit) (_SFR_BYTE(sfr) &= ~_BV(bit))

#define SET_OUTPUT(sfr, bit) (_SFR_BYTE(sfr) |= _BV(bit))
#define SET_INPUT(sfr, bit) (_SFR_BYTE(sfr) &= ~_BV(bit))



const struct avr_mmcu_vcd_trace_t _mytrace[]  _MMCU_ = {
    { AVR_MCU_VCD_SYMBOL("DDRB"), .what = (void*)&DDRB, },
    { AVR_MCU_VCD_SYMBOL("PORTB"), .what = (void*)&PORTB, },
};

void setup()
{
    SET_OUTPUT(DDRB,0);
}

void toggle(void){
    LOW(PORTB, 0);
    HIGH(PORTB, 0);
}

int main(void) {
    setup();
    for(int i = 0; i < 10; i ++) 
    {
        toggle();
    }
    sleep_cpu();
}
