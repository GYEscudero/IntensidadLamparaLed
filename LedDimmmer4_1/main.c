/*************************************
 * main.c                            *
 *                                   *
 * Created: 2/5/2024 12:09:02 PM     *
 * Author: Gerson Yaser              *
 * Atenuador de Luz LED              *
 *                                   *
 * Dispositivo: ATmega328P           *
 * Frecuencia: 8 MHz a 5V            *
 * Pruebas: Realizadas en Protoboard *
 *************************************/ 


/* Direcctivas */
#define F_CPU 8000000UL
#include <xc.h>
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include "initPwm.h"
#include "pushButton.h"
#include "pwmSelector.h"
#include "ledLevel.h"

/* Protocolos de la funci�n */
void init_pwm ();
int8_t push_button (int8_t *count);
double pwm_selector (int8_t count, double *d_c);
void led_level (int8_t count);


/* Variables */
double duty_cycle = 0;
int8_t counter = 0;

/* Inicio de la funci�n principal */
int main(void)
{
	init_pwm ();	/* Llamado a la funcion que inicializa la se�al PWM */
	sei();			/* Habilita interrupciones del microcontrolador */
    
	while(1)
	{
		push_button (&counter);					/* Llamado a la funci�n que detecta los push button */
        pwm_selector (counter, &duty_cycle);	/* Llamado a la funci�n que cambia el ciclo del trabajo de PWM */
		led_level (counter);					/* Llamado a la funci�n que muestra el nivel de iluminaci�n */ 
    }
}  /* Fin de la principal */

/* Funci�n que realiza interrupci�n */
ISR (TIMER0_OVF_vect)
{
	OCR0A = ((duty_cycle/100) * 1023); /* recalcula el nivel del comparador */
} /* Fin de la funci�n */