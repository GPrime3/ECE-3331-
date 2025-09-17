void straight (void); //function to initiate motion
void turnPerp (void); //function to initiate turn
void stop (void); //function to come to a halt

#include <msp430.h>
#define F_SMCLK (8000000UL)
#define F_PWM 20000UL
#define CCR0VAL ((F_SMCLK/F_PWM)-1)

#define SEC (F_SMCLK/10)

int main(void){
    WDTCTL = WDTPW | WDTHOLD;

    //Pinsetup
    P2DIR |= BIT0 |BIT3; // sets pin 2.0 and 2.3 as output
    P3DIR = BIT3 | BIT6 |BIT7;// sets pin 3.3,3.6,3.7

    //PWM OUTPUT into PIN 2.7
    P2DIR |=BIT7;
    P2SEL0 |= BIT7;
    PSEL1 &= ~BIT7;
    //PWM OUTPUT into PIN 2.6
    P2DIR |=BIT6;
    P2SEL0 |= BIT6;
    PSEL1 &= ~BIT6;
    
    //Timer
    TB0CCR0 = CCR0VAL; //Period

    TB0CCTL6 = OUTMOD_7;
    TB0CCR6 = 25; // Duty Cycle

    TB0CTL = TBSSEL_2 | MC_1 | TBCLR;

}

void straight(void){
    //P1OUT = 0x00;
    //P1OUT |= 
}

void turnPerp(void){
    //P2OUT = 0x00;
    //P2OUT |=     
}
void stop(void){
    //P2OUT = 0x00;
    //P2OUT |= 0x00;
}