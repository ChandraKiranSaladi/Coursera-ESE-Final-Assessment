/******************************************************************************
 * Copyright (C) 2017 by Alex Fosdick - University of Colorado
 *
 * Redistribution, modification or use of this software in source or binary
 * forms is permitted as long as the files maintain this copyright. Users are 
 * permitted to modify this and use it to learn about the field of embedded
 * software. Alex Fosdick and the University of Colorado are not liable for any
 * misuse of this material. 
 *
 *****************************************************************************/
/**
 * @file stats.c
 * @brief Simple Program to print the statistics of the given data such as 
 					- Maximum
 					- Minimum
 					- Mean
 					- Median
 *  
 *	 
 *
 * @author Chandra Kiran Saladi
 * @date 06/13/2018
 *
 */


// Header Files. 
#include <stdio.h>
#include "stats.h"

/* Size of the Data Set */
#define SIZE (40)

void main() {

/* Set of 40 numbers */
  unsigned char test[SIZE] = { 34, 201, 190, 154,   8, 194,   2,   6,
                              114, 88,   45,  76, 123,  87,  25,  23,
                              200, 122, 150, 90,   92,  87, 177, 244,
                              201,   6,  12,  60,   8,   2,   5,  67,
                                7,  87, 250, 230,  99,   3, 100,  90};

/* Statistics Variables */
  unsigned char maximum;
  unsigned char minimum;
  unsigned char mean;
  unsigned char median;
 
  printf("The Given Array is \n");

  /* Priting the given Array  */
  print_array(test, SIZE);    

  /* Calculating the statistics using the functions defined. */
  maximum = find_maximum(test, SIZE);
  minimum = find_minimum(test, SIZE);
  mean = find_mean(test, SIZE);
  median =  find_median(test, SIZE);

  /* Printing the statistics using the function print_statistics */
  print_statistics(test, SIZE, maximum, minimum, mean, median);

  /* The array is sorted upon calling this function */
  sort_array(test, SIZE);

  printf("The Array after sorting: \n");
  print_array(test, SIZE);

}

unsigned char find_mean(unsigned char * temp, int size)
{
	int i;
	int sum = 0;

	if(temp == NULL)
		return 0;

	if(size <= 0)
		size = 1;

	for( i = 0; i < size; i++){

		sum += temp[i];  // Sum of all the values in the array

	}

	return (sum/size);
}

unsigned char find_maximum(unsigned char * temp, int size){
	int i;

	/* Maximum value of the array is stored in max*/
	unsigned char max;

	if(temp == NULL)
		return 0;

	max = temp[0];

	for( i = 1; i < size; i++){

		if(temp[i] > max)
			max = temp[i];    
	
	}

	return max;

}

unsigned char find_minimum(unsigned char * temp, int size){
	int i;
	unsigned char min;

	if(temp == NULL)
		return 0;

	min = temp[0];

	for( i = 1; i < size; i++){

		if(temp[i] < min)
			min = temp[i];
	
	}

	return min;

}

void print_array(unsigned char * temp, int size){

	int i;

	if(temp == NULL)
		return;
	printf("\n");
	for( i = 0; i < size; i++)
		printf("%u\t",(unsigned char)temp[i]);
	printf("\n");
}

unsigned char find_median(unsigned char * temp, int size){

	int i;
	unsigned char median;

	sort_array(temp, size);
	/* Even Sized array */
	if( size%2 == 1 )
		median = temp[ (size -1)/2 ];  // For odd values, median is at the middle element. 
	/* Odd Sized Array */
	else{
		/* For Even values, the median is the Mean values of the 2 center values*/
		median = ( temp[ (size - 1)/2 ] + temp[ (size + 1)/2 ] )/2 ;
	} 

	return median;
}

void sort_array(unsigned char * temp, int size){

	int i,j,tempVar;

	/* Insertion Sort */
	for( i = 0; i < size; i++){

		tempVar = temp[i];

		for( j = i-1; j >= 0 && tempVar > temp[j] ; j--){
			
				temp[j+1] = temp[j]; 
		
		}

		temp[j+1] = tempVar; 
	}

}

void print_statistics(unsigned char * temp, int size, unsigned char maximum,
							 unsigned char minimum, unsigned char mean, unsigned char median){

  printf("\nThe statistics of the array:\n");
  printf(" 		Maximum = %u \n",maximum);
  printf(" 		Minimum = %u \n",minimum);
  printf(" 		mean = %u \n",mean);
  printf(" 		Median = %u \n",median);

}

