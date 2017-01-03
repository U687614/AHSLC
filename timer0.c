#include "timer0.h"
void timer0Init()
{
    //==============Timer0 Mode ============== timer or counter.
    //Increment every instruction cycle
    //TMR0CS=0 Timer mode ;TMR0CS=1 Counter mode OPTION_REG.
    TMR0CS=0;
    
    //==============SOFTWARE PROGRAMMABLE PRESCALER==============
    //The prescaler is enabled by clearing the PSA bit of the OPTION_REG register.
    //The prescale values are selectable via the PS<2:0> bits of the OPTION_REG register.
    // 8 prescaler options ranging from 1:2 to 1:256.
    // 1:1 prescaler PSA=1;
    PSA=0;
    //PS2=1;PS1=0;PS0=0;  //prescaler 1:32  1 pulse=16uS*244=7808uS 256HZ
    PS2=1;PS1=0;PS0=0;  //prescaler 1:32  1 pulse=16uS*255=4080uS 256HZ
    //TMR0 = 11;           // Preload value
     TMR0 = 0;           // Preload value 
    //PSA=0;
    //PS2=1;PS1=1;PS0=1;  //prescaler 1:256  1 pulse=128uS*255=32640uS 30HZ
    //TMR0 = 0;           // Preload value  
 
    //==============TIMER0 INTERRUPT==============
    //The TMR0IF is set every time the TMR0 register overflows from FFh to 00h.
    TMR0IF=0;
    TMR0IE=1;
}
