// Author: thson
// Program: 
// One thread always listens to a charater from keyboard. 
// One thread always checks this character to print screen in Upercase

// build command: g++ -o lowwerToUpperCase lowwerToUpperCase.cpp -lpthread

#include <pthread.h>
#include <stdio.h>
#include <pthread.h>
#include <cstdlib>
#include <iostream>
using namespace std;

// global character
char c;
bool isUsed = false;

void * inputFunc(void * arg)
{
	while (1)
	{
		if (isUsed)
			continue;

		cout << "Input: ";
		cin >> c;
		isUsed = true;
	}
}

void * outputFunc(void * arg)
{
	while (1)
	{
		if (!isUsed)
			continue;

		if (c >= 97)
		{
			cout << (char) (c - 32) << endl;
		}
		else
		{
			cout << (char) c << endl;
		}
		isUsed = false;
	}
}

int main()
{
	pthread_t inputThread;
	pthread_t outputThread;
	int rc;
	int i;
	void * status;

	cout << "main(): creating thread.. " << endl;
	// create input thread
	rc = pthread_create(&inputThread, NULL, inputFunc, NULL);
	if (rc)
	{
		cout << "Error: Unable to create input thread, " << rc << endl;
		exit(-1);
	}

	rc = pthread_create(&outputThread, NULL, outputFunc, NULL);
	if (rc)
	{
		cout << "Error: Unable to create output thread, " << rc << endl;
		exit(-1);
	}

	// joining

	rc = pthread_join(inputThread, &status);
	if (rc)
	{
		cout << "Error: Unable to join, " << rc << endl;
		exit(-1);
	}

	rc = pthread_join(outputThread, &status);
	if (rc)
	{
		cout << "Error: Unable to join, " << rc << endl;
		exit(-1);
	}

	pthread_exit(NULL);
	return 0;
}