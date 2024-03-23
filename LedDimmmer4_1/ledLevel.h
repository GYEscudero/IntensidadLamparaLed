/*****************************************
 *                                       *
 *  ledLevel.h                           *
 *                                       *
 *  Nivel de luminicidad                 *
 *  Mediante 6 led indicara a que nivel  *
 *  de intencida se encuentra los LEDs   *
 *                                       *
 *  Dispositivo: ATmega328P              *
 *  Frecuencia: 8 MHz a 5V               *
 * Pruebas: Realizadas en Protoboard     *
 *****************************************/

/* Directivas */
#include <xc.h>
#include <avr/io.h>

/* Inicio de la función  led_level */
void led_level (int8_t count)
{
	/* variable */
	int8_t indicator [7] = {0b00000001,
							0b00000011,
							0b00000111,
							0b00001111,
							0b00011111,
							0b00111111,
							0b01111111};
	
	PORTC = indicator [count]; /* Nivel de iluminicidad de Leds se muestra por el PUERTO C */
} /* Fin de la función led_level */
