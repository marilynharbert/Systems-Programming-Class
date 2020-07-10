// File: shout.c
// Purpose: The program takes user input and prints it out in
// uppercase until the user enters ctrl-d.
// Written by: Marilyn Harbert
// Date: 2/12/19

#include <stdio.h>
#include <ctype.h>

int main () {
	// initialize the variable to hold the characters that the program
	// will read from the user and write to the terminal
	char ch;

	// while loop gets the user input one character at a time and puts
	// the character in ch until the user inputs EOF AKA ctrl-d
	while ((ch = getchar()) != EOF) {
		if (isalpha(ch) != 0) { // if ch is a letter
			ch = toupper(ch); //make ch uppercase
		} //end if

		putchar(ch); //outputs the character ch to the terminal
	} //end while 

	return 0;
} // end main
