/*
 * garage_system.c
 *
 * Created: 27/05/2020 5:56:15 AM
 *  Author: M
 */ 

#include "LCD.h"
#include "PWM.h"
uint8_t car_counter;
int main(void)
{
   	CLRBIT(DDRD,2);
   	CLRBIT(DDRD,3);
	SETBIT(MCUCR,ISC00);
	SETBIT(MCUCR,ISC01);
	SETBIT(GICR,INT0);
	SETBIT(MCUCR,ISC10);
	SETBIT(MCUCR,ISC11);
	SETBIT(GICR,INT1);
	sei();
	LCD_init();
	PWM_init_timer1_oc1b();
	PWM_init_timer1_oc1a();
	set_duty_oc1a(2.34375);		// 1.5ms pulse of PWM to make servo motor on angle 0
	set_duty_oc1b(2.34375);		// 1.5ms pulse of PWM to make servo motor on angle 0
	LCD_write_command(0x1);
	LCD_write_string("There are ");
	LCD_write_num(car_counter);
	LCD_write_string(" cars");
	LCD_write_command(0xc0);
	LCD_write_num(3-car_counter);
	LCD_write_string(" places");
	LCD_write_string(" Available");
	while(1)
    {
        //TODO:: Please write your application code 
    }
}
ISR(INT0_vect){			// Enter PIR
	
	if (car_counter<3)
	{
		car_counter++;
		LCD_write_command(0x1);
		LCD_write_string("There are ");
		LCD_write_num(car_counter);
		LCD_write_string(" cars");
		LCD_write_command(0xc0);
		LCD_write_num(3-car_counter);
		LCD_write_string(" places");
		LCD_write_string(" Available");
		set_duty_oc1a(3.125);   // 2ms pulse of PWM to make servo motor on angle 0
		_delay_ms(1000);
		set_duty_oc1a(2.34375);	// 1.5ms pulse of PWM to make servo motor on angle 90
	}
	else {
		LCD_write_command(0x1);
		LCD_write_string("full garage");
	}
}
ISR(INT1_vect){			// Exit PIR
	
	if (car_counter>0)
	{
		car_counter--;
		LCD_write_command(0x1);
		LCD_write_string("There are ");
		LCD_write_num(car_counter);
		LCD_write_string(" cars");
		LCD_write_command(0xc0);
		LCD_write_num(3-car_counter);
		LCD_write_string(" places");
		LCD_write_string(" Available");
		set_duty_oc1b(3.125);	// 2ms pulse of PWM to make servo motor on angle 90
		_delay_ms(1000);
		set_duty_oc1b(2.34375);	// 1.5ms pulse of PWM to make servo motor on angle 0

	}		
}