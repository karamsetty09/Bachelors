// HelloWorld.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Write a program to find the solution for the maximum subsequence sum problem using Linear Algorithm
//
#include <iostream>
using namespace std;

int main()
{
	int i, j, n, sum, a[20];
	int alg4(int a[20], int n);
	n = 0;
	std::cout << "\n\t Enter n value:";
	std::cin >> n;
	std::cout << "\n\t Enter array values: \n";
	for (i = 0; i < n; i++) {
		std::cout << "\n \t Enter array value" << ":";
		std::cin >> a[i];
	}

	sum = alg4(a, n);
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
		thissum += a[j];
		if (thissum > maxsum)
			maxsum = thissum;
		else if (thissum < 0)
			thissum = 0;
	}
	return maxsum;
}
