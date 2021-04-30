
#include "activity1.h"
#include "activity2.h"
#include "activity3.h"
#include "activity4.h"
#define ON 1

int main(void)
{
	uint16_t Temp, ADC=0;
	char TempType;
	USARTInit(); /* Initialize Peripherals for UART */
	while(1){
		uint8_t Status;
		/* Turns LED ON if and only if both switches ButtonSensor and Heater are closed */
		Status=StatusOfLedActuator();
		if(Status==ON){
			Temp=ReadADC(ADC); /*reads sensor data from ADCChannel*/
    	    TempType=GeneratePWM(Temp);/*Generates PWM according to data received from sensor*/
			USARTWriteString(TempType);/*Sends data to serial monitor*/
		}
	}
	return 0;
}
