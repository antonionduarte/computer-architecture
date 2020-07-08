
/**
 * AC - 2019/2020 MIEI FCT/UNL
 **/
#include <stdio.h>
#include <unistd.h>

#include "hw.h"
#include "driver.h"

#define BYTE_TX 0x100
#define COMMAND 0x101
#define STATUS 0x102

int sendByte( unsigned char c ) {

	out (BYTE_TX, c); // places the byte to print in the BYTE_TX register (0x100)
	unsigned char status; // status of the printer

	/* Send the byte to print when the printer has the correct STATUS */

	do {
		status = in(STATUS);
	} while (status != 0b100);
	
	out (COMMAND, 1); // place the correct command on the COMMAND register (0x101)

	/* Waits until the printer has the correct value (0b100) in the STATUS register (0x102) and is ready for the next Byte */

	do {
		status = in(STATUS); // gets the correct status from STATUS register (0x102)
		if ( (status & 0b100) == 0 ) return 0; // If the printer is offline, returns 0 
	} while (status != 0b100); // repeats it until the printer is in the correct state to print the byte

	return 1; // returns 1 when the printer is ready for the next Byte
}