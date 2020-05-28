/*
 * PWM.c
 *
 * Created: 17/04/2020 4:05:20 PM
 *  Author: M
 */
/*
non inverting
fast phase
10 bit
oc1a
*/ 
#include "PWM.h"
void PWM_init_timer1_oc1a(){
	SETBIT(DDRD,5);
	TCCR1A |= (1<<COM1A1)|(1<<WGM10)|(1<<WGM11);
	TCCR1B=(1<<WGM12)|(1<<CS10)|(1<<CS12);
	
	
}
void set_duty_oc1a(uint16_t duty){
OCR1A=10.23*duty;
}
void PWM_init_timer1_oc1b(){
	SETBIT(DDRD,4);
	TCCR1A |= (1<<COM1B1)|(1<<WGM10)|(1<<WGM11);
	TCCR1B=(1<<WGM12)|(1<<CS10)|(1<<CS12);	
}
void set_duty_oc1b(uint16_t duty){
	OCR1B=10.23*duty;
}
