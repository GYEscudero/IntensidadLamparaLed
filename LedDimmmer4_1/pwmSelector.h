/***************************************
 *                                     *
 *  pwmSelector.h                      *
 *                                     *
 *  Ciclo del trabajo de la PWM.       *
 *  Mediante un switch-case se elige   *  
 *  el ciclo de trabajo de la señal    *
 *  PWM                                *
 *                                     *
 *  Dispositivo: ATmega328P            *
 *  Frecuencia: 8 MHz a 5V             *
 *  Pruebas: Realizadas en Protoboard  *
 *                                     *
 ***************************************/

/* Directivas */
#include <xc.h>
#include <avr/io.h>

/* Inicio de la función pwm_selector */
double pwm_selector (int8_t count, double *d_c)
{
	/* Inicio del switch-case */
	switch (count)
	{	/* Selección de dutys a trabajar */
		case 0:
		{
			*d_c = 100;
		}
		break;
		
		case 1:
		{
			*d_c = 20;
		}
		break;
		
		case 2:
		{
			*d_c = 40;
		}
		break;
		
		case 3:
		{
			*d_c = 60;
		}
		break;
		
		case 4:
		{
			*d_c = 80;	
		}
		break;
		
		case 5:
		{
			*d_c = 0;
		}
		break;
	} /* Fin del switch-case */
	
	return *d_c;	/* Retorno de duty_cycle */
	
} /* Fin de la función pwm_selector */