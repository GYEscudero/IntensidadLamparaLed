/*****************************************
 *                                       *  
 *  initPwm.h                            *
 *                                       *
 *  Inicialización de puertos, pines y   *
 *  recursos a utilizar                  *
 *  Se configura puertos y pines de      *
 *  (entrada y salida, asi como los      * 
 *  recursos a utilizar para generar la  *
 *  señal PWM                            *
 *                                       *
 *  Dispositivo: ATmega328P              *
 *  Frecuencia: 8 MHz a 5V               *
 *  Pruebas: Realizadas en Protoboard    *
 *                                       *
 *****************************************/

/*  Directivas */
#include <xc.h>
#include <avr/io.h>
#include <avr/interrupt.h>

/* Inicio de la función init_pwm */
void init_pwm ()
{
	/* Configuración de puertos */
	DDRD |= (1 << DDD6);/* PIN D6 Configurado como salida para señal PWM */
	DDRD &= (~(1 << DDD0) & ~(1 << DDD1)); /* Configuracion de pines como entrada para los push button */
	DDRC |= ((1 << DDC0) | (1 << DDC1) | (1 << DDC2) | (1 << DDC3) | (1 << DDC4) | (1 << DDC5)); /* Configuración de pines
																									para nivel de intensidad
																									de LEDs */
	/* Configuración TCCR0A */
	TCCR0A |=(
	(1 << WGM00) |		/* FAST PWM... */
	(1 << WGM01) &		/* TOP 011 */
	
	~(1 << COM0B0) &	/* Operacion normal OC0B... */
	~(1 << COM0B1) &	/* Desconectado */
	
	~(1 << COM0A0) |	/* Clear OC0A... */
	(1 << COM0A1));		/* on compare match */
	
	/* Configuración TCCR0B */
	TCCR0B |=(
	(1 << CS01) &		/* Prescaler... */
	~(1 << CS00) &		/* 010... */
	~(1 << CS02) &		/* Clock/8 */
	
	~(1 << WGM02) &		/* Wave form Generator */
	
	~(1 << FOC0B) &		/* Force Output Compare B (Desactivado) */
	
	~(1 << FOC0A));		/* Force Output Compare A (Desactivado) */
	
	/* Configuración TIMSK0 */
	TIMSK0 |= (
	(1 << TOIE0) &		/* Enable */
	
	~(1 << OCIE0A) &	/* Output A Match Interrupt */
	
	~(1 << OCIE0B)); 	/* Output B Match Interrupt */

	/* Configuración OCR0A */
	OCR0A = 0;			/* Valor de comparacion en 0 */
	 
} /* Final de la función init_pwm */