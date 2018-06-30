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
#include<stddef.h>
#include "stats.h"
#include "platform.h"
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
	#if !defined (VERBOSE) && defined (HOST)
	#undef PRINTF
	#define PRINTF(...)  
	#endif
	PRINTF("Printing Array\n");
	for( i = 0; i < size; i++)
		PRINTF("%u\t",(unsigned char)temp[i]);
	PRINTF("\n");
	#if defined (VERBOSE) && defined (HOST)
	#undef PRINTF 
	#define PRINTF(...) printf(__VA_ARGS__)
	#endif
}

unsigned char find_median(unsigned char * temp, int size){

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

  PRINTF("\nThe statistics of the array:\n");
  PRINTF(" 		Maximum = %u \n",maximum);
  PRINTF(" 		Minimum = %u \n",minimum);
  PRINTF(" 		mean = %u \n",mean);
  PRINTF(" 		Median = %u \n",median);

}

