// File: sort.c
// Purpose: Given an array in the main function, calls the sorted function
// which checks to see if the array is sorted from smallest to largest
// and then prints the contents of the array on one line, and depending on
// whether the array is sorted or not, prints "Sorted" or "Unsorted".
// In the main function, an array of length 10 where A[i] = i is 
// initialized, and the sorted function is called on A. Then A[5] is
// changed to hold the value -9, and sorted is called again on A.
// Written by: Marilyn Harbert
// Date: 2/12/19

#include <stdio.h>

// declares and defines the function sorted()
int sorted (int A[], int n) {
	// declare variable to hold 1 if the array is sorted, 0 if not. 
	int array_sorted = 1;

	//for loop runs interates through the array A 
	int i;
	for (i = 0; i < n; ++i) {
		// if i is not the last value
		if (i < n-1) {
			// if A[i] is larger than the next value in the 
			// array then the array is not sorted from smallest
			// to largest
			if (A[i] > A[i+1]) {
				array_sorted = 0; // array is not sorted
			} //end if
		} //end if
	
	// print the current value in the array to list all values in A
	printf("%d ", A[i]);

	} // end for	

	// look at the value of array_sorted to see whether it's sorted
	switch (array_sorted) {
		// if array_sorted is 1, print that it's sorted
		case 1: 
			printf(": Sorted \n");
			break;
		// if array_sorted is 0, print that it's not sorted
		case 0: 
			printf(": Unsorted \n");
			break;
	} //end switch

} //end sorted

int main() {
	// initialize array A so that A[i] = i;
	int A[10] = {0,1,2,3,4,5,6,7,8,9};
	
	// call sorted on A and feed it A's length which is 10
	sorted(A, 10);

	// change the 6th spot in A to hold the value -9
	A[5] = -9;

	// call sorted on A again and feed it A's length again 
	sorted(A, 10);

	return 0;

} //end main 
