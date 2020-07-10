// File: mywc.c
// Purpose: Reads words and characters that the user inputs, counts the number
// of lines, words and characters, and returns those numbers to the user in the
// order -lines, words, characters-.
// Written by: Marilyn Harbert
// Date: 2/12/19

#include <stdio.h>
#include <ctype.h>

int main () {

	int char_length = 0; // variable to hold number of characters
	int word_length = 0; // variable to hold number of words
	int line_length = 0; // variable to hold number of lines
	char ch; // variable for user input character currently being looked at

	// loops through user input characters until the user inputs 
	// EOF AKA ctrl-d	
	while ((ch = getchar()) != EOF) {

		// if ch is not a new line character or a space 
		// then increment the number of characters
		if (ch != '\n' && ch != ' ') {
			char_length++;
		} //end if
	
		// if ch is a new line character or a space
		// then that is the end of a word
		// so increment the number of words
		else {
			word_length++;	
		} //end else

		// if ch is a new line character
		// then increment the number of lines
		if (ch == '\n') {
			line_length++;
		} //end if

	} //end while

	// print the number of lines, number of words, number of characters	
	printf("%d %d %d", line_length, word_length, char_length);

	return 0;
} //end main
