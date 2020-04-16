// HelloWorld.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Write a program to find the solution for the maximum subsequence sum problem using Linear Algorithm
//
#include <iostream>
using namespace std;

int main()
{
	int i, j, n, sum, a[20];      // Data variable initialization
	int alg4(int[], int);	      
	n = 0;		              // Assigning
	std::cout << "\n\t Enter n value:";	
	std::cin >> n;
	std::cout << "\n\t Enter array values:";
	for (i = 0; i < n; i++) {
		std::cout << "Enter array value" << i << ":";
		std::cin >> a[i];                // Getting user array data
	}

	sum = alg4(a, n);      // calling function module and getting value
	std::cout << "\n\t sum of linear algorithams is:" << sum;


	return 0;
}
int alg4(int a[20], int n)
{
	int j, maxsum, thissum;
	thissum = 0;
	maxsum = 0;
	for (j = 0; j < n; j++)
	{
		thissum += a[j];	// summing next value	
		if (thissum > maxsum)   // checking whether next is postive or not ?
			maxsum = thissum;    // if +ve update maxsum
		else if (thissum < 0)	// if its negative
			thissum = 0;    // -ve leave the number update this number
	}
	return maxsum;     
}
