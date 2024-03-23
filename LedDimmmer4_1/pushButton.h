/***************************************
 *                                     *  
 *  pushButton.h                       *
 *                                     *
 *  Detección de push button           *
 *  Detecta al oprimir alguno de los   *
 *	dos pusbuton de "-" o "+" para     *
 *	disminuir o atenuar la intencidad  *
 *  de los LEDs                        *
 *                                     *
 *  Dispositivo: ATmega328P            *
 *  Frecuencia: 8 MHz a 5V             *
 *  Pruebas: Realizadas en Protoboard  *
 *                                     *
 ***************************************/

/* Directivas */
#include <xc.h>
#include <avr/io.h>

/* Inicio de la función push_button */
int8_t push_button (int8_t *count)
{
	/* Atenuacíon de LEDs - Detección del PIND0 */
	if ((PIND & (1 << PIND0)) == 0)
	{
		(*count)--;
		/* Limitador */
		if (*count <= 0 )
		{
			*count = 0;
		}
		
		/* Ciclo antirrebote mecanico de push button */
		while ((PIND & (1 << PIND0)) == 0)
		{
			
		}
	}
	
	/* Aumento de LEDs - Detección del PIND1 */
	if ((PIND & (1 << PIND1)) == 0)
	{
		(*count)++;
		
		/* Limitador */
		if (*count >= 5 )
		{
			*count = 5;
		}
		
		/* Ciclo antirrebote mecanico de push button */
		while ((PIND & (1 << PIND1)) == 0)
		{
			
		}
	}
	
	return *count;
} /* Fin de la función push_button */