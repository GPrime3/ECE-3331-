#include <driverlib.h>
#include <msp430.h>

// --- Function Prototypes ---
void straight(void);
void turn(void);

// PWM configuration
#define F_SMCLK (8000000UL)    // SMCLK = 8 MHz
#define F_PWM   20000UL        // PWM frequency = 20 kHz
#define CCR0VAL ((F_SMCLK/F_PWM)-1)  // Timer period

int main(void) {
    WDTCTL  = WDTPW | WDTHOLD;   // Stop watchdog timer
    PM5CTL0 &= ~LOCKLPM5;        // Unlock GPIOs (FRAM devices)

    // --- PIN setup ---
    P1DIR |= BIT0 | BIT3;        // P1.0 LED, P1.3 IN1
    P2DIR |= BIT3 | BIT6 | BIT7; // P2.3 IN4, P2.6 ENA, P2.7 ENB
    P3DIR |= BIT0 | BIT1;        // P3.0 IN2, P3.1 IN3
    

    // --- PWM setup (P2.6 = TB0.5, P2.7 = TB0.6) ---
    P2SEL0 |= BIT6 | BIT7;   
    P2SEL1 &= ~(BIT6 | BIT7);

    TB0CCR0  = CCR0VAL;           // PWM period
    TB0CCTL6 = OUTMOD_7;         
    TB0CCTL5 = OUTMOD_7;

    TB0CCR6  = (CCR0VAL+1) * 0.75; 
    TB0CCR5  = (CCR0VAL+1) * 0.75;

    TB0CTL   = TBSSEL_2 | MC_1 | TBCLR;  // SMCLK, Up mode, clear timer
    Straight();
    __delay_cycles(F_SMCLK * 0.155);
    turnPerp();
    __delay_cycles(F_SMCLK * 0.20);
    Stop1();

    while(1); // loop forever
    
}
void Straight(void){
    P1OUT |= BIT3;   // IN1 
    P3OUT &= ~BIT0;  // IN2
    P3OUT |= BIT1; // in3
    P2OUT |= BIT3;  // IN4
}

void turnPerp(void){
    P1OUT &= ~BIT3;   // IN1 
    P3OUT |= BIT0;  // IN2
    P3OUT &= ~BIT1; // in3
    P2OUT |= BIT3;  // IN4

}
void Stop1(void){
    P1OUT &= ~BIT3;   // IN1 
    P3OUT &= ~BIT0;  // IN2
    P3OUT &= ~BIT1; // in3
    P2OUT &= ~BIT3;  // IN4

}
