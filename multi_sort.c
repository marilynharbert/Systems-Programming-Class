// File: multi_sort.c
// Purpose: Creates an array full of random numbers of length 20, and runs the quicksort
// 	bubblesort, selectionsort, and mergesort and shuffles the numbers in between sorts.
// Written by: Marilyn Harbert
// Date: 2/20/19

#include <stdio.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>

// non-sorting functions
int sorted(int len, int A[]);
int randint(int a, int b);
void shuffle(int len, int A[]);
void swap(int A[], int i, int j);
// sorting functions
void quicksort(int A[], int low, int high);
int split(int A[], int low, int high);
void bubblesort(int len, int A[]);
void selectionsort(int len, int A[]);
void mergesort(int len, int A[]);

int main () {
	// initialize variable to declare array length
	int arr_len = 20;
	// create array of size 20 to hold our random ints
	int rand_arr[arr_len];
	
	// initialize random number generator
	srand(time(NULL));	

	// Fill the array with random ints between 1 and 100 inclusive
	int i;
	for (i = 0; i < arr_len; i++) {
		rand_arr[i] = randint(1,101);		
	} //end for	

	// check whether the array is currently sorted, and print it
	printf("Initial array: \n");
	sorted(arr_len, rand_arr);

	// call quick sort on array, check whether array is sorted, and print it
	printf("Quicksorted array: \n");
        quicksort(rand_arr, 0, arr_len-1);
	sorted(arr_len, rand_arr);

	// shuffle array, check whether array is sorted, and print it
	printf("Shuffled array: \n");
	shuffle(arr_len, rand_arr);
	sorted(arr_len, rand_arr);

	// call bubble sort on array, check whether array is sorted, and print it
	printf("Bubblesorted array: \n");
	bubblesort(arr_len, rand_arr);
	sorted(arr_len, rand_arr);

	// shuffle array, check whether array is sorted, and print it
	printf("Shuffled array: \n");
	shuffle(arr_len, rand_arr);
	sorted(arr_len, rand_arr);

	// call selection sort on array, check whether array is sorted, and print it
	printf("Selectionsorted array: \n");
	selectionsort(arr_len, rand_arr);
	sorted(arr_len, rand_arr);

	// shuffle array, check whether array is sorted, and print it
	printf("Shuffled array: \n");
	shuffle(arr_len, rand_arr);
	sorted(arr_len, rand_arr);

	// call merge sort on the array, check whether array is sorted, and print it
	printf("Mergesorted array: \n");
	mergesort(arr_len, rand_arr);
	sorted(arr_len, rand_arr);	
}

// definition of the sorted function taken from my Assignment 2
int sorted (int len, int A[]) {
	// declare variable to hold 1 if the array is sorted, 0 if not
	int array_sorted = 1;

	// for loop iterates through array A
	int i;
	for (i = 0; i < len; ++i) {
		// if i is not the last value
		if (i < len - 1) {
			// if A[i] is larger than the next value in the
			// array then the array is not sorted from smallest
			// to largest
			if (A[i] > A[i+1]) {
				array_sorted = 0; // array is not sorted
			} // end if
		} // end if

		// print the current value in the array to list all values in A
		printf("%d ", A[i]);

	} // end for

	// look at the value of the array_sorted to see whether it's sorted
	switch (array_sorted) {
		// if array_sorted is 1, print that it's sorted
		case 1: 
			printf(" Sorted \n");
			break;
		case 0:
			printf(" Unsorted \n");
			break;
	} // end switch
} // end sorted definition

int randint (int a, int b) { // inclusive of a, excludes b
	//returns random integer between a and b
	return (int) (a + (rand() % (b-a)));

} // end randint definition

void shuffle (int len, int A[]) { // from the sort.c program you gave us
	int i;
	// run a for loop to the second to last item
	for (i = 0; i < len-1; i++) {
		int j = randint(i, len); // make j a random int between i and the end
		swap(A, i, j);
	} // end for	
} // end shuffle

void swap (int A[], int i, int j) { // swaps A[i] and A[j]
	int temp = A[j]; // puts A[j] in a temp array
	A[j] = A[i]; // writes over A[i] with A[j]
	A[i] = temp; // puts temp in A[i]
} // end swap

int split (int A[], int low, int high) { // the book's algorithm with a few modifications
	int part_element = A[low]; // copy low into the partion
	
	while (low != high) {
		//move high left across the array until A[high] is less than the partition
		while (low < high && part_element <= A[high]) { 
			high--;
		} // end while
		if (low >= high) break;
		
		// put A[high] in A[low]'s spot
		A[low] = A[high];

		//move low right across the array until A[low is greater than the partition
		low++;
		while (low < high && A[low] <= part_element) {
			low++;
		} // end while	
		if (low >= high) break;

		// put A[low] in A[high]'s spot
		A[high] = A[low];
		high--;
	} // end while 
	
	A[high] = part_element;
	return high;

} // end split

void quicksort (int A[], int low, int high) { // the book's algorithm
	int middle;

	if (low >= high) return; // if low = high, sorting on either side of the partion is done
 	middle = split (A, low, high); //returns high of partly sorted array inputed
	//recursively quicksorts the array split into two by the mid as partition
	quicksort(A, low, middle - 1); 
	quicksort(A, middle + 1, high);

} // end quicksort
	
void bubblesort (int len, int A[]) { 
	int end = len-1; // make end len - 1 so that it can be a pointer to be changed. 
	int i, j; // initializing variables for the for loops
	for (i = 0; i < len-1; i++) { // iterate until end is pointing to A[1]
		for (j = 0; j < end; j++) { // iterate through the array up to end
			// if A[j] is greater than A[j+1] then swap them
			if (A[j] > A[j+1]) { 
				swap(A, j, j+1);
			} // end if
		} // end for
		end--;
	} // end for
} // end bubblesort

void selectionsort (int len, int A[]) {
	int i,j; // initialize for loop variables
	int end = len - 1; // intialize end so that end can be shifted

	for (i = 0; i < len - 1; i++) { // iterate through the loop for the length of A - 1
		int largest = 0; // initialize the index of the largest value to be the first
		for (j = 0; j < end; j++) { // iterate up to the sorted point
			// if A[largest] is less than any value, make that value the new largest
			if(A[largest] <= A[j]) {
				largest = j;
			} // end if
		} // end for

		// if A[largest] is not already in place, then A[end] and A[largest]
		if (A[largest] > A[end]) {
			swap(A, end, largest);
		} // end if
		end--;
	} // end for

} // end selectionsort

void mergesort (int len, int A[]) { // the link to the merge sort example was very helpful 
	if (len > 1) { // base case is len = 1 or 0;
		int mid = len/2; // declare the midpoint
		
		// make two temp arrays to hold each half of the current array 
		// divided at the midpoint
		int left_temp[mid];
		int right_temp[len - mid];
		
		// iterate through the array to assign the first half of array values to
		// left_temp and the other half to right_temp
		int q;
		for (q = 0; q < len; q++) {
			if (q < mid) {
				left_temp[q] = A[q];	
			} // end if
			else {
				right_temp[q - mid] = A[q];
			} // end else

		} // end for
		
		// find the lengths of the left_temp and right_temp array 	
		int left_len = sizeof(left_temp)/sizeof(right_temp[0]);
		int right_len = sizeof(right_temp)/sizeof(right_temp[0]);
		
		// recursively call mergesort on each half of the array
		mergesort(left_len, left_temp);
		mergesort(right_len, right_temp);
		
		// everything below starts to merge back the array
		
		// initialize variables to keep track of how far we've gone through 
		// the real array, and the temp arrays
		int i = 0; // left temp var
		int j = 0; // right temp var
		int k = 0; // real array var

		// compare left and right and place them back in the array left to right
		// in the correct spots
		while (i < left_len && j < right_len) {
			if (left_temp[i] < right_temp[j]) {
				A[k] = left_temp[i];
				i++;
			} // end if
			else {
				A[k] = right_temp[j];
				j++; 
			} // end else
			k++;
		} // end while

		while (i < left_len) {
			A[k] = left_temp[i];
			i++;
			k++;
		} // end while

		while (j < right_len) {
			A[k] = right_temp[j];
			j++;
			k++;
		} // end while

	} // end if

} // end mergesort
