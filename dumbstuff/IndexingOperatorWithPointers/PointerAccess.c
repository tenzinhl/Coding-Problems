/*
 * PointerAccess.c
 * 
 * Copyright 2021 tenzi <tenzi@LAPTOP-U355A8BD>
 * 
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301, USA.
 * 
 * 
 */


#include <stdio.h>


int withinArray(int* intArray, int size, int* ptr) {
	char* endPtr = (char*)(intArray + size) - 1;
	long long d1 = (char*)ptr - (char*)intArray;
	long long d2 = endPtr - (char*)ptr;
	
	d1 >>= 63;
	d2 >>= 63;
	
	// printf("d1 = %lu and d2 = %lu\n", d1, d2);
	return ((d1 + d2) == 0);
}

int main(int argc, char **argv)
{	
	// Checking the size of an int using pointers
	int intArray[10];
	// char* intptr1 = (char*)intArray;
	// char* intptr2 = (char*)(intArray + 1);
	// long intSize = (long)intptr2 - (long)intptr1;
	// printf("The size of int is%ld\n", intSize);
	
	// char *msg = "Hello, my name is Jeff.";
	// printf("The first character of msg is %c\n", msg[0]);
	
	// Doing withinArray() here where I know my environment.
	// Quick sanity check:
	printf("size of int is: %lu\n", (long unsigned)sizeof(int));
	char* arr = (char*)intArray;
	int r1 = withinArray(intArray, 2, (int*)(arr + 8));
	printf("Result of check 1 is %d\n", r1); 
	
	// Checking results of ternary
	printf("\n~5 = %d, ~20 = %d, ~351 = %d\n", ~5, ~20, ~351);
	printf("~(-5) = %d, ~(-20) = %d, ~(-351) = %d\n", ~-5, ~-20, ~-351);
	
	// Results of !
	printf("\n!5 = %d, !20 = %d, !351 = %d\n", !5, !20, !351);
	printf("!-5 = %d, !-20 = %d, !-351 = %d\n", !-5, !-20, !-351);
	return 0;
}

