#include "RobotSensors.h"

int leftTestValue = 0x230;
int rightTestValue = 0x230;

unsigned int leftSensorValue, rightSensorValue;

/*
 * main.c
 */
int main(void) {
    WDTCTL = WDTPW | WDTHOLD;	// Stop watchdog timer
	initializeADC10();
	P1DIR |= BIT0;
	P1DIR |= BIT6;
	
	for(;;){
		leftSensorValue = getLeftSensorValue();

		if(leftSensorValue < leftTestValue){
			P1OUT &= ~BIT0;
		}
		else{
			P1OUT |= BIT0;
		}

		rightSensorValue = getRightSensorValue();

		if(rightSensorValue < rightTestValue){
			P1OUT &= ~BIT6;
		}
		else{
			P1OUT |= BIT6;
		}
	}



	return 0;
}

#pragma vector = ADC10_VECTOR
__interrupt void ADC10_ISR(void){
	__bic_SR_register_on_exit(CPUOFF);
}
