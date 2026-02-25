#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
    // PB0 PB1 PB2 as input (X Y Z)
    DDRB &= ~((1 << PB0) | (1 << PB1) | (1 << PB2));

    // Enable pull-down logic externally with resistors
    // PD2 PD3 PD4 PD5 as output to 7447
    DDRD |= (1 << PD2) | (1 << PD3) | (1 << PD4) | (1 << PD5);

    while (1)
    {
        uint8_t X = 1;
        uint8_t Y = 0;
        uint8_t Z = 0;

        // F = X'Y' + YZ
        uint8_t F = ((!X) && (!Y)) || (Y && Z);

        if (F == 0)
        {
            PORTD &= ~((1<<PD2)|(1<<PD3)|(1<<PD4)|(1<<PD5)); // 0000
        }
        else
        {
            PORTD = (PORTD & 0b11000011) | (1<<PD2); // 0001
        }

        _delay_ms(100);
    }
}
