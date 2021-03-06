

/*
    Daryl Newell 01/09/18
    Write a function to print a decimal value into binary form
*/

#include <stdio.h>
#include <limits.h>


#define BYTE 8   //--define the number of bits in a byte.
                 //-- this could also be obtained from your limits.h file by using the macro
                 //-- CHAR_BIT, in my implamantation that value is 8
                 
//-- prototype of functions
void printBinary(unsigned int n);


int main(int argc, char* argv[])
{
	 unsigned x = 7;


  printBinary(x);

	getchar();
	return 0;
}



void printBinary(unsigned int n)
{
	unsigned int i;
	unsigned mask = 1 << (sizeof(unsigned int) * BYTE) - 1;             //-- move the 1 mask to the MSB of a 32 bit #

	for(i = 0; i < sizeof(unsigned int) * BYTE ; ++i){
		putchar(n & mask ? '1' : '0');   //-- if ((n & (mask >> i)) == (mask >> i))

		if ( (i + 1) % 8 == 0)
			printf(" ");
		n <<= 1;						 //-- shift the mask to the left 1 time
	} //-- end for loop
	printf("\n");
} //-- end printBinary
