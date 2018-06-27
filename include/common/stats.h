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
 * @file stats.h 
 * @brief Simple Program to print the statistics of the given data such as 
 					- Maximum
 					- Minimum
 					- Mean
 					- Median
 *
 * <Add Extended Description Here>
 *
 * @author Chandra Kiran Saladi
 * @date 06/13/2018
 *
 */
#ifndef __STATS_H__
#define __STATS_H__

/**************************************************************
 * @brief Prints the array to the screen
 *		Takes an array and size as input. 
 *
 * @param temp   A unsigned char pointer to an n-element data array 
 * @param size   An unsigned integer as the size of the array
 *
 *
 * @return void
 *
 *************************************************************/
void print_array(unsigned char * temp, int size);

/**************************************************************
 * @brief Prints maximum, minimum, median and Mean to the screen
 *		  Takes an array, size, all the statistics as input. 
 *
 * @param temp   A unsigned char pointer to an n-element data array 
 * @param size   An unsigned integer as the size of the array
 * @param maximum An integer which has the maximum value of the array
 * @param minimum An integer which has the minimum value of the array
 * @param mean An integer which has the Mean value of the array
 * @param median An integer which has the median value of the array
 * @return void
 *
 *************************************************************/
void print_statistics(unsigned char * temp, int size, unsigned char maximum,
						 unsigned char minimum, unsigned char average, unsigned char median); 

/**************************************************************
 * @brief Calculates the maximum value of the array
 		Takes an array and the size as input
 *
 * @param temp   A unsigned char pointer to an n-element data array 
 * @param size   An unsigned integer as the size of the array
 
 * @return An integer, maximum value of the array.
 *
 *************************************************************/
unsigned char find_maximum(unsigned char * temp, int size);

/**************************************************************
 * @brief Calculates the minimum value of the array
 		Takes an array and the size as input
 *
 * @param temp   A unsigned char pointer to an n-element data array 
 * @param size   An unsigned integer as the size of the array
 
 * @return An integer, minimum value of the array.
 *
 *************************************************************/
unsigned char find_minimum(unsigned char * temp, int size);

/**************************************************************
 * @brief Calculates the mean of the array
 		Takes an array and the size as input
 *
 * @param temp   A unsigned char pointer to an n-element data array 
 * @param size   An unsigned integer as the size of the array
 
 * @return an integer, mean of the array.
 *
 *************************************************************/
unsigned char find_mean(unsigned char * temp, int size);

/**************************************************************
 * @brief Calculates the median of the array
 		Takes an array and the size as input
 *
 * @param temp   A unsigned char pointer to an n-element data array 
 * @param size   An unsigned integer as the size of the array
 
 * @return an integer, median of the array.
 *
 *************************************************************/
unsigned char find_median(unsigned char * temp, int size);

/**************************************************************
 * @brief Sorts the array, in non increasing values. 
 		Takes an array and the size as input
 *
 * @param temp   A unsigned char pointer to an n-element data array 
 * @param size   An unsigned integer as the size of the array
 
 * @return void
 *
 *************************************************************/
void sort_array(unsigned char * temp, int size);
#endif /* __STATS_H__ */
