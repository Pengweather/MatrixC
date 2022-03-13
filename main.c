/*
 * main.c
 *
 *  Created on: Oct 21, 2021
 *      Author: andy
 */

#include "matrix.h"
#include <time.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
	clock_t t;
    t = clock();

	// Put code here
	
	t = clock() - t;
    double time_taken = ((double)t)/CLOCKS_PER_SEC;

	return 0;
}