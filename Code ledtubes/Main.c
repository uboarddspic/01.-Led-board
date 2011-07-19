///////////////////////////////////////////////////////////////////////////
//  Product/Project : Walking led                                        //
///////////////////////////////////////////////////////////////////////////
//
//  File Name    : Main.c
//  Version      : 1.0
//  Description  : Rainbow flashing 
//               : For use with the led board and ledtubes
//               : The ledtubes consist of shiftregisters and R,G,B leds
//  Author       : Jim Clermonts
//  Target       : dsPIC33FJ64GP802
//  Compiler     : MPLAB C Compiler for PIC24 and dsPIC v3.25 in LITE mode
//  IDE          : MPLAB X IDE Beta4.0
//  Programmer   : uBRD bootloader
//  Last Updated : 09-01-2011
//
//  Copyright (c) Staronic 2011.
//  All rights are reserved. Reproduction in whole or in part is
//  prohibited without the written consent of the copyright owner.
///////////////////////////////////////////////////////////////////////////
#include    "Delay.h"
#include    "Peripherals.h"
#include    "uBRD.h"

//Configuration-for-programmer--------------------------
_FBS(RBS_NO_RAM & BSS_NO_FLASH & BWRP_WRPROTECT_OFF);               // No boot ram, flash, write protection
_FSS(RSS_NO_RAM & SWRP_WRPROTECT_OFF);                              // No protected sections
_FGS(GSS_OFF
& GCP_OFF & GWRP_OFF);                                              // No code protection
_FOSCSEL(FNOSC_FRCPLL & IESO_OFF);                                  // FRC Oscillator with PLL, no two-speed oscillator
_FOSC(FCKSM_CSDCMD & IOL1WAY_OFF & OSCIOFNC_ON  & POSCMD_NONE);     // Clock Switching and Fail Safe Clock Monitor is disabled
                                                                    // Multiple I/O reconfigurations admitted                                                                  // OSC2 Pin is digital I/O														                      // Primaire Oscillator Mode: none
_FWDT(FWDTEN_OFF & WINDIS_OFF);                                     // Watchdog Timer off
_FPOR(ALTI2C_ON & FPWRT_PWR64);                                     // 64 ms power-up timer
_FICD(JTAGEN_OFF & ICS_PGD2);                                       // JTAG program port off
//------------------------------------------------------

int main(void)
{
    unsigned char   i=0;
    unsigned int    DELAY=100;

    Init_port();
    Init();
    Init_ADC_pot();
    Init_timers();

    while (1) {
        RGBfade(255, 0, 0); // red
        RGBfade(0, 255, 0); // green
        RGBfade(0, 0, 255); // blue
        RGBfade(255, 255, 0); // red + green
        RGBfade(255, 0, 255); // red + blue
        RGBfade(0, 255, 255); // green + blue
        RGBfade(255, 255, 255); // red + green + blue

        for (i = 0; i < 10; i++) {
            // Potmeter 1 (left) determines speed of rainbow flash
            DELAY = (ADC(AD_POT1)) & 0xFF;

            Shiftleds(0b001);
            Delayms(DELAY);
            Shiftleds(0b001);
            Delayms(DELAY);
            Shiftleds(0b001);
            Delayms(DELAY);

            DELAY = (ADC(AD_POT1)) & 0xFF;

            Shiftleds(0b011);
            Delayms(DELAY);
            Shiftleds(0b011);
            Delayms(DELAY);
            Shiftleds(0b011);
            Delayms(DELAY);

            DELAY = (ADC(AD_POT1)) & 0xFF;

            Shiftleds(0b010);
            Delayms(DELAY);
            Shiftleds(0b010);
            Delayms(DELAY);
            Shiftleds(0b010);
            Delayms(DELAY);

            DELAY = (ADC(AD_POT1)) & 0xFF;

            Shiftleds(0b110);
            Delayms(DELAY);
            Shiftleds(0b110);
            Delayms(DELAY);
            Shiftleds(0b110);
            Delayms(DELAY);

            DELAY = (ADC(AD_POT1)) & 0xFF;

            Shiftleds(0b100);
            Delayms(DELAY);
            Shiftleds(0b100);
            Delayms(DELAY);
            Shiftleds(0b100);
            Delayms(DELAY);

            DELAY = (ADC(AD_POT1)) & 0xFF;

            Shiftleds(0b101);
            Delayms(DELAY);
            Shiftleds(0b101);
            Delayms(DELAY);
            Shiftleds(0b101);
            Delayms(DELAY);
        }
    }
    return (0);
}
