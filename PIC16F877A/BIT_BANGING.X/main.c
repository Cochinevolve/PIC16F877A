/*
 * File:   main.c
 * Author: Naveen
 * Description : generate PWM using Bit-banging method to control LED's On and Off time
 * Created on 12 August, 2025, 11:43 AM
 */


#include <xc.h>
#include "main.h"
#define __XTAL__FREQ 20000000
#pragma config WDTE = OFF       // Watchdog Timer Enable bit (WDT disabled)

static void init_config(void)
{
    LED_ARRAY_DDR = 0x00;    //setting the data direction as output
    LED_ARRAY     = 0x00;    //setting all bits in PORTD as zero
}


void main(void) {
    unsigned long int period = 100000;    //consider it as 100
    unsigned long int duty_cycle = 50000; //consider it as 50%(we can change the duty cycle value as per your need)
    unsigned long int loop_counter = 0;
    init_config();
    
    while(1)
    {
        if(loop_counter < duty_cycle)      //Non blocking delay
        {
            LED1 = ON;
        }
        else
        {
            LED1 = OFF;
        }
        if(loop_counter++ == period)
            loop_counter = 0;
    }
    return;
}
