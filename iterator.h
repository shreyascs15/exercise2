/**
 * @file iterator.h
 * @author Shreyas CS
 * @brief  It is a headerfile containing declarations of the all functions
 * @date 2024-08-06
 * 
 */
#include<stdio.h>
#include<string.h>
#include<stdbool.h>
#include<stdlib.h> 
/**
 * @def UINT32
 * @brief Defines a 32-bit unsigned integer type
 */
#define UINT32 unsigned int
/**
 * @def UINT16
 * @brief Defines a 16-bit unsigned character type
 */
#define UCHAR8  unsigned char
/**
 * @brief Function to initialize the iterator with a string containing multiple substrings separated by white space.
 * 
 * @param arg This is used to pass the command line arguments.
 * @return Nothing
 */
void iter_init(UCHAR8 *arg);
/**
 * @brief Each call to the function returns the next substring from the string provided during the initialization till the last substring. After returning the last substring, the function should return NULL for subsequent calls.
 * 
 * @param Nothing
 * @return This function returns the next substring. 
 */
UCHAR8* iter_next(void);
/**
 * @brief This function checks whether the last substring has been returned or not.
 * 
 * @return true when last substring had returned
 * @return false when last substring had not returned
 */
bool iter_done(void);