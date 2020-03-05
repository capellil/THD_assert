/**
 * @file THD_assert.hpp
 * @author Ludovic Capelli
 **/

#ifndef THD_ASSERT_HPP_INCLUDED
#define THD_ASSERT_HPP_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int THD_assert_number_of_tests = 0; /* Total number of tests run */
int THD_assert_number_of_successes = 0; /* Total number of tests that succeeded*/
int THD_assert_my_number_of_tests = 0;
int THD_assert_my_number_of_successes = 0;
char* THD_assert_previous_function = NULL; /* Function in which the previous assert was performed. */

/**
 * @param[in] function The name of the function from which the assert is called.
 **/
void thd_assert(bool ARGS, const char* label, const char* function)
{
	// Check if I am first assert in entire program
	if(THD_assert_previous_function == NULL)
	{
		// I am the first assert in the entire program.
		// Allocate the memory for current function name.
		THD_assert_previous_function = (char*)malloc(sizeof(char) * (strlen(function) + 1));
		if(THD_assert_previous_function == NULL)
		{
			printf("Could not allocate the name of the function.\n");
			exit(EXIT_FAILURE);
		}
		// Put current function name in memory
		strncpy(THD_assert_previous_function, function, strlen(function) + 1);
		printf("Unit testing:\n");
		printf(" ├>\x1b[;1m Function %s\x1b[0m\n", function);
	}
	else
	{
		// Get back to the line about the previous function totals and deletes it
		printf("\033[2A\033[2K\r");
	}
	
	// Check if I am in same function as previous assert
	if(strcmp(function, THD_assert_previous_function) != 0)
	{
		// I am in a different function
		// Print the old function-local totals
		printf("\033[2K\r |    └> \x1b[34;1m[RESULTS]\x1b[0m %d tests performed: \x1b[32;1m%d successes\x1b[0m and \x1b[31;1m%d failures\x1b[0m.\n", THD_assert_my_number_of_tests, THD_assert_my_number_of_successes, THD_assert_my_number_of_tests - THD_assert_my_number_of_successes);

		// Store the new function name 
		THD_assert_previous_function = (char*)realloc(THD_assert_previous_function, sizeof(char) * (strlen(function) + 1));
		if(THD_assert_previous_function == NULL)
		{
			printf("Could not reallocate the name of the function.\n");
			exit(EXIT_FAILURE);
		}
		// Put current function name in memory
		strncpy(THD_assert_previous_function, function, strlen(function) + 1);

		THD_assert_my_number_of_successes = 0;
		THD_assert_my_number_of_tests = 0;

		// Print the new function title
		printf("\033[2K\r ├>\x1b[;1m Function %s\x1b[0m\n", function);
	}

	// Do the actual assert
	printf("\033[2K\r |    ├> ");
	if(ARGS)
	{
		THD_assert_my_number_of_successes++;
		THD_assert_number_of_successes++;
		printf("\x1b[32m[PASSED]\x1b[0m ");
	}
	else
	{
		printf("\x1b[31m[FAILED]\x1b[0m ");
	}
	printf("Asserting \"%s\".\n", label);

	// Print the old function-local totals
	THD_assert_my_number_of_tests++;
	printf("\033[2K\r |    └> \x1b[34;1m[RESULTS]\x1b[0m %d tests performed: \x1b[32;1m%d successes\x1b[0m and \x1b[31;1m%d failures\x1b[0m.\n", THD_assert_my_number_of_tests, THD_assert_my_number_of_successes, THD_assert_my_number_of_tests - THD_assert_my_number_of_successes);

	// Print the general totals in case it is the last assert
	THD_assert_number_of_tests++;
	printf(" └> \x1b[34;1m[RESULTS]\x1b[0m %d tests performed: \x1b[32;1m%d successes\x1b[0m and \x1b[31;1m%d failures\x1b[0m.\n", THD_assert_number_of_tests, THD_assert_number_of_successes, THD_assert_number_of_tests - THD_assert_number_of_successes);
}

#define THD_assert(ARGS) thd_assert(ARGS, #ARGS, __func__);

#endif
