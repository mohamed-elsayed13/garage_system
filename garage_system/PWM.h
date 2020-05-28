/*
 * PWM.h
 *
 * Created: 17/04/2020 4:05:53 PM
 *  Author: M
 */ 


#ifndef PWM_H_
#define PWM_H_

#include "header.h"
void PWM_init_timer1_oc1a();
void set_duty_oc1a(uint16_t duty);
void PWM_init_timer1_oc1b();
void set_duty_oc1b(uint16_t duty);

#endif /* PWM_H_ */