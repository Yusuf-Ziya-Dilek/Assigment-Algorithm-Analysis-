#include <iostream>
#include <ctime>
#include <stdlib.h>
using namespace std;

// This code is taken from slides as requested
int sequentialSearch(int* arr, int N, int value) {
	for (int i = 0; i < N; i++) 
		if (arr[i] == value) 
			return i;
	return -1;
}

// This code is taken from slides as requested
int binarySearch(int* arr, int N, int value) {
	int low = 0, high = N - 1;  
	while (low <= high) {
		int mid = (low + high) / 2;   
		if (arr[mid] < value)     
			low = mid + 1;     
		else if (arr[mid] > value)  
			high = mid - 1;    
		else       
			return mid; 
	}  
	return -1; 
}


const int N = 100000000;
//const int N = 10000000;
//const int N = 1000000;
//const int N = 100000;
//const int N = 10000;
//const int N = 1000;
//const int N = 100;
//const int N = 10;
static int* arr1 = new int[N];

int main(){
	// Sorted array	
	for (int i = 0; i < N; i++) {
		arr1[i] = i;	
	}

	//Store the starting time  double duration; 
	double duration;
	clock_t startTime = clock();


	for (int i = 0; i < 1000000; i++) {
		binarySearch(arr1, N, 5); // Close to beginnig
	}	

	//Compute the number of seconds that passed since the starting time  
	duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;  
	cout << "1.Execution took (Key close to beginning)" << duration << " nanoseconds." << endl;

	//Store the starting time  double duration; 
	double duration1;
	for (int i = 0; i < 1000000; i++) {
		binarySearch(arr1, N, N/2 - 1);// close to middle
	}

	//Compute the number of seconds that passed since the starting time  
	duration1 = 1000 * double(clock() - startTime- duration) / CLOCKS_PER_SEC;
	cout << "2.Execution took (Key close to middle) " << duration1 << " nanoseconds." << endl;

	
	//Store the starting time  double duration; 
	double duration2;
	for (int i = 0; i < 1000000; i++) {
		binarySearch(arr1, N, N - 1); //close to end
	}

	//Compute the number of seconds that passed since the starting time  
	duration2 = 1000 * double(clock() - startTime - duration - duration1) / CLOCKS_PER_SEC;
	cout << "3.Execution took (Key close to end) " << duration2 << " nanoseconds." << endl;

	//Store the starting time  double duration; 
	double duration3;
	for (int i = 0; i < 1000000; i++) {
		binarySearch(arr1, N, -10); // not found
	}

	//Compute the number of seconds that passed since the starting time  
	duration3 = 1000 * double(clock() - startTime - duration - duration1 - duration2) / CLOCKS_PER_SEC;
	cout << "4.Execution took (Key is not found) " << duration3 << " nanoseconds." << endl;

	delete[] arr1;
}


