

/*
 * File:   main.c (PERSONALIZACI�N CARACTER)
 * 
 * Autores: Oscar David Poblador Parra      20211005116
 *          Juan David Bello Rodriguez      20211005028 
 *          Manuel Alejandro Guio Cardona   20211005061
 * Intrituci�n: Universidad Distrital Francisco Jos� de Caldas
 */


void UART_init();							//funci�n para iniciar el USART AVR as�ncrono, 8 bits, 9600 baudios,
unsigned char UART_read();					//funci�n para la recepci�n de caracteres
void UART_write(unsigned char);				//funci�n para la transmisi�n de caracteres
void UART_msg(char*);						//funci�n para la transmisi�n de cadenas de caracteres


void UART_init()
{
    
	UCSR1A = (0<<TXC1)|(0<<U2X1)|(0<<MPCM1);  //banderas
	UCSR1B = (1<<RXCIE1)|(0<<TXCIE1)|(0<<UDRIE1)|(1<<RXEN1)|(1<<TXEN1)|(0<<UCSZ12)|(0<<TXB81);// 
	UCSR1C = (0<<UMSEL11)|(0<<UMSEL10)|(0<<UPM11)|(0<<UPM10)|(0<<USBS1)|(1<<UCSZ11)|(1<<UCSZ10)|(0<<UCPOL1);
   // UCSR1D = (0<<CTSEN) || (0<<RTSEN);
    
    UBRR1H = UBRRH_VALUE;
	UBRR1L = UBRRL_VALUE;
	
	
}

unsigned char UART_read(){
    if(UCSR1A&(1<<7)){			//si el bit7 del registro UCSR0A se ha puesto a 1
		return UDR1;			//devuelve el dato almacenado en el registro UDR0
	}
	else
	return 0;
}

void UART_write(unsigned char caracter){
	while(!(UCSR1A&(1<<5)));    // mientras el registro UDR0 est� lleno espera
	UDR1 = caracter;            //cuando el el registro UDR0 est� vacio se envia el caracter
}

void UART_write_txt(char* cadena){			//cadena de caracteres de tipo char
	while(*cadena !=0x00){				//mientras el �ltimo valor de la cadena sea diferente a el caracter nulo
		UART_write(*cadena);			//transmite los caracteres de cadena
		cadena++;						//incrementa la ubicaci�n de los caracteres en cadena
										//para enviar el siguiente caracter de cadena
	}
}



