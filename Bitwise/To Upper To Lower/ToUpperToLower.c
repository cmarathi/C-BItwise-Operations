 /*
 Date:         07/06/17
 Description:  Use Bitwise & and | to convert charactors to upper and lower case.
 One function uses array notation to iterate the string array and the other function uses pointer notation.
 
 This works because the hex value for lower case letters and upper case letters are the same except for bit 5
 If bit 5 is 1 then the letter is lower case. We then mask the 8 bit letter with 0010 0000 by OR-ing it. This turns on bit 5
 If bit 5 is 0 then the letter is upper case. We then unmask the 8 bit letter with 1101 1111 by AND-ing it. This turns off bit 5
 
 Source:       Daryl Newell
 */

#include <stdio.h>
#include <conio.h>	// for clrscr() function
//#include <iostream>


//const int TO_LOW = 0x20;
//const int TO_UP = 0xDF;

#define TO_LOWER 0x20              //-- 0010 0000 in binary
#define TO_UPPER 0xDF              //-- 1101 1111 in binary

void aLower(char *_array);         //-- use array notation to iterate the array
void pLower(char *_array);         //-- use pointer notation to iterate the array
void aUpper(char *_array);
void pUpper(char *_array);

 int main(int argc, char* argv[])
{
	char strArry[81] = {};         //-- declare and initialize string array

	printf("Enter a string < 80 chars or less > of both upper and lower case letters\n");
	scanf("%80[^\n]s", strArry);   //-- get a string from user up to 80 chars and stop on '\n'

	printf("The string of chars you entered are: \n%s\n", strArry);
	aLower(strArry);
	 
	printf("The string of chars after they are converted to lower case: \n%s\n", strArry);
	aUpper(strArry);
	 
	printf("The string of chars after they are converted to upper case: \n%s\n", strArry);

	getch();
	return 0;
}

//-- this function uses array notation to iterate the array.
void aLower(char *strArry)
{
	int i = 0;

	while(strArry[i] != '\0')
	{
		strArry[i++] |= TO_LOWER;
	}
}

//-- this function uses pointer notation to iterate the array
void pLower(char *strArry)
{
	while(*strArry != '\0')               //-- test for NULL in string
	{
		*strArry++ |= TO_LOWER;       //-- bitwise "OR" *strArry with 0x20 - Hex
/*
if you were to enter the char A = 0x41 = 0100 0001 and " | " it with
                                  0x20 = 0010 0000
                                  or ----------------
                                  0x61 = 0110 0001 = a
*/
	}
}

//-- this function uses array notation to iterate the array
void aUpper(char *strArry)
{
	int i = 0;

	while(strArry[i] != '\0')
	{
		if(strArry[i] == ' ')
		{
			i++;
			continue;
		}
        strArry[i++] &= TO_UPPER;
	}
}

//-- this function uses pointer notation to iterate the array
void pUpper(char *strArry)
{
	while(*strArry != '\0')               //-- test for NULL in string
	{
		if(*strArry == ' ')           //-- if the pointer is pointing to a "space"
		{
			strArry++;            //-- incriment the pointer
			continue;             //-- continue looping
		}
		*strArry++ &= TO_UPPER;       //-- bitwise "and" *strArry with 0xDF - Hex
					      //-- incriment the pointer
/*
if you were to enter the char a = 0x61 = 0110 0001 and " & " it with
                                  0xDF = 1101 1111
                              and ----------------
                                  0x41 = 0100 0001 = A
*/
	}
}
