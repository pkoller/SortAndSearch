// C++ program for implementation of Bubble sort
//#include <bits/stdc++.h>
#include <iostream>
using namespace std;

/* Function to print an array */
void printArray(int arr[], int size)
{
	int i;
	for (i = 0; i < size; i++)
		cout << arr[i] << " ";
	cout << endl;
}

// A function to implement bubble sort
int bubbleSort(int arr[], int n)
{
	int arrayCounter = 0;
	int i, j;
	for (i = 0; i < n - 1; i++)
	{
		// Last i elements are already in place
		for (j = 0; j < n - i - 1; j++)
		{
			arrayCounter++;
			if (arr[j] > arr[j + 1])
			{
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
		printArray(arr, n);
	}
	return arrayCounter;
}

int binarySearch(int arr[], int n, int target)
{
	int stepcounter = 0;
	int low = 0;
	int high = n - 1;

	while (low <= high)
	{
		stepcounter++;

		int center = (low + high) / 2;
		if (target == arr[center])
		{
			cout << "Gefunden! Arrayzugriffe: " << stepcounter << endl;
			return stepcounter;
		}
		else
		{
			if (target < arr[center])
				high = center - 1;
			else
				low = center + 1;
		}
	}
	cout << "Nicht gefunden! Arrayzugriffe: " << stepcounter << endl;
	return stepcounter;
}

int linearSeach(int arr[], int n, int target)
{
	int stepcounter = 0;

	for (int i = 0; i < n; i++)
	{
		stepcounter++;
		if (arr[i] == target)
		{
			cout << "Gefunden! Arrayzugriffe: " << stepcounter << endl;
			return stepcounter;
		}
	}
	cout << "Nicht gefunden! Arrayzugriffe: " << stepcounter << endl;
	return stepcounter;
}

int main()
{				
	int arr[] = { 64, 8, 25, 12, 22, 11, 9, 64, 32, 23, 66, 78, 99 };
	int n = sizeof(arr) / sizeof(arr[0]);
	
	
	printArray(arr, n);
	int sortZugriffe = bubbleSort(arr, n);

	cout << "Sorted array: \n";
	printArray(arr, n);


	int allBinarySearch = 0;
	int allLinearSearch = 0;


	for (int i = 0; i < 1000; i++)
	{
		allBinarySearch += binarySearch(arr, n, i);

		allLinearSearch += linearSeach(arr, n, i);
	}

	cout << "binary zugriffe: " << allBinarySearch <<" with sort: "<< sortZugriffe << endl;
	cout << "linear zugriffe: " << allLinearSearch << endl;

	return 0;
}