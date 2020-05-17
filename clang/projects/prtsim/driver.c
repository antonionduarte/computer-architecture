
/**
 * AC - 2019/2020 MIEI FCT/UNL
 **/
#include <stdio.h>
#include <unistd.h>

#include "hw.h"
#include "driver.h"

int sendByte( unsigned char c ) {

	unsigned char status; // status of the printer

	/* Send the byte to print */

	out (0x101, 1); // place the correct command on the COMMAND register (0x101)
	out (0x100, c); // places the byte to print in the BYTE_TX register (0x100)

	/* Waits until the printer has the correct value (0b100) in the STATUS register (0x102) to send the next Byte */

	do {
		status = in(0x102); // gets the correct status from STATUS register (0x102)
		if ( (status & 0b100) == 0 ) return 0; // If the printer is offline, returns 0 
	} while (status != 0b100);

	return 1; // returns 1 when the printer is ready for the next Byte
}