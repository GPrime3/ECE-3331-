void straight (void); //function to initiate motion
void turnPerp (void); //function to initiate turn
void stop (void); //function to come to a halt
void main(void){ // main function
    P1DIR |= 0x03;//assigning P1.1 and P1.2 as output
    P1SEL |= BIT6;//defining P1.6 as timer
    // need to confirm these numbers
    int period = 0x0FFF;  //PWM period
    float DC = 0.52; //duty cycle
    TACCR0 = // Time Clock/ TACCR0 = PMW

    // Layman's terms
     //while (distance< 2 ft){
    //straight();
    //}
    //turnPerp();
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