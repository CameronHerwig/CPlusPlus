#include "stdafx.h"
#include "stdio.h"
#include <stdlib.h>
#include <iostream>
#include <array>
#include <chrono>

using namespace std;
using namespace std::chrono;

void InsertionSort(int Arr[], int n);
void QuickSort(int Arr[], int p, int r);
int Partition(int Arr[], int p, int r);
void HeapSort(int Arr[], int n);
void Heapify(int Arr[], int n, int i);

//due to 0 indexing most code has been adjusted to fit compiler standard

int main()
{
	int m = 10;
	int ns = 1000;
	int nf = 20000;
	int S = 1000;
	int A[10][20000] = {};
	int B[20000] = {};
	double Times[10][20] = {};
	double avgTimes[20] = {};

	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < nf; j++)
		{
			A[i][j] = rand();
		}
	}

	cout << "Size of A: " << sizeof(A)/sizeof(int) << "\n"; //debug text
	
	for (int n = ns; n <= nf; n += S)
	{
		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++)
			{
				B[j] = A[i][j];			//splits A into relevant n sized B segment
			}

			high_resolution_clock::time_point t1 = high_resolution_clock::now();
			InsertionSort(B, n);												//gets time before and after in micro
			high_resolution_clock::time_point t2 = high_resolution_clock::now();

			auto duration = duration_cast<microseconds>(t2 - t1).count();
			Times[i][(n / 1000) - 1] = duration; //pushes time into array to be averaged
		}
		avgTimes[(n/1000)-1] = (Times[0][(n/1000)-1] + Times[1][(n/1000)-1] + Times[2][(n/1000)-1] + Times[3][(n/1000)-1] + Times[4][(n/1000)-1] + Times[5][(n/1000)-1] + Times[6][(n/1000)-1] + Times[7][(n/1000)-1] + Times[8][(n/1000)-1] + Times[9][(n/1000)-1]) / 10;
		cout << B[n - 1] << " "; //debug text
	}

	cout << "\nInsertion Times: \n";
	for (int i = 0; i < 20; i++)
	{
		cout << (i + 1) * 1000 << " Values: " << avgTimes[i] << "\n";
	}


	for (int n = ns; n <= nf; n += S)
	{
		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++)
			{
				B[j] = A[i][j];			//splits A into relevant n sized B segment
			}

			high_resolution_clock::time_point t1 = high_resolution_clock::now();
			QuickSort(B, 0, n-1);												//gets time before and after in micro
			high_resolution_clock::time_point t2 = high_resolution_clock::now();

			auto duration = duration_cast<microseconds>(t2 - t1).count();
			Times[i][(n / 1000) - 1] = duration; //pushes time into array to be averaged
		}
		avgTimes[(n / 1000) - 1] = (Times[0][(n / 1000) - 1] + Times[1][(n / 1000) - 1] + Times[2][(n / 1000) - 1] + Times[3][(n / 1000) - 1] + Times[4][(n / 1000) - 1] + Times[5][(n / 1000) - 1] + Times[6][(n / 1000) - 1] + Times[7][(n / 1000) - 1] + Times[8][(n / 1000) - 1] + Times[9][(n / 1000) - 1]) / 10;
		cout << B[n - 1] << " "; //debug text
	}

	cout << "\nQuickSort Times: \n";
	for (int i = 0; i < 20; i++)
	{
		cout << (i + 1) * 1000 << " Values: " << avgTimes[i] << "\n";
	}
	

	for (int n = ns; n <= nf; n += S)
	{
		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++)
			{
				B[j] = A[i][j];			//splits A into relevant n sized B segment
			}

			high_resolution_clock::time_point t1 = high_resolution_clock::now();
			HeapSort(B, n);														//gets time before and after in micro
			high_resolution_clock::time_point t2 = high_resolution_clock::now();

			auto duration = duration_cast<microseconds>(t2 - t1).count();
			Times[i][(n / 1000) - 1] = duration; //pushes time into array to be averaged
		}
		avgTimes[(n / 1000) - 1] = (Times[0][(n / 1000) - 1] + Times[1][(n / 1000) - 1] + Times[2][(n / 1000) - 1] + Times[3][(n / 1000) - 1] + Times[4][(n / 1000) - 1] + Times[5][(n / 1000) - 1] + Times[6][(n / 1000) - 1] + Times[7][(n / 1000) - 1] + Times[8][(n / 1000) - 1] + Times[9][(n / 1000) - 1]) / 10;
		cout << B[n - 1] << " "; //debug text
	}

	cout << "\nHeapSort Times: \n";
	for (int i = 0; i < 20; i++)
	{
		cout << (i + 1) * 1000 << " Values: " << avgTimes[i] << "\n";
	}
	return 0;
}


void InsertionSort(int Arr[], int n)
{
	for (int i = 1; i < n; i++)
	{
		int key = Arr[i];
		int j = i - 1;
		while (j > 0 && Arr[j] > key)  //if element over key move ahead of current position
		{                                 
			Arr[j + 1] = Arr[j];
			j = j - 1;
		}
		Arr[j + 1] = key;
	}
}


int Partition(int Arr[], int p, int r)
{
	int piv = Arr[r]; //pivot
	int i = (p - 1); //index of lower
	int temp = 0;

	for (int j = p; j <= r - 1; j++) 
	{
		if (Arr[j] <= piv) //if element under pivot
		{
			i++; //increment index of smaller
			temp = Arr[i];
			Arr[i] = Arr[j];
			Arr[j] = temp;
		}
	}
	temp = Arr[i + 1];
	Arr[i + 1] = Arr[r];
	Arr[r] = temp;
	return (i + 1);
}

void QuickSort(int Arr[], int p, int r)
{
	if (p < r)
	{
		int part = Partition(Arr, p, r);  //build partition

		QuickSort(Arr, p, part - 1); //sort before and after part
		QuickSort(Arr, part + 1, r);
	}
}

void Heapify(int Arr[], int n, int i)
{
	int largest = i; //makes largest root (compiler error when used as else, same execution)
	int l = 2 * i + 1;  
	int r = 2 * i + 2;  
	int temp;

	if (l < n && Arr[l] > Arr[largest]) //if left child larger than room
		largest = l;

	if (r < n && Arr[r] > Arr[largest]) //if right child over root
		largest = r;

	if (largest != i) //if largest is not root
	{
		temp = Arr[i];
		Arr[i] = Arr[largest];
		Arr[largest] = temp;

		Heapify(Arr, n, largest); //recursively heapify subtree
	}
}

void HeapSort(int Arr[], int n)
{
	int temp = 0;
	for (int i = n / 2 - 1; i >= 0; i--)  //BuildMaxHeap
		Heapify(Arr, n, i);

	for (int i = n - 1; i >= 0; i--) //extract elements
	{
		temp = Arr[0];
		Arr[0] = Arr[i];  //move root to end
		Arr[i] = temp;
		Heapify(Arr, i, 0); //Max heapify
	}
}


