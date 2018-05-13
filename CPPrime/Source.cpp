#include <iostream>
#include <vector>

using namespace std;

int *PrimeList = NULL;

void PrimeNumbers(int arraySize);
bool isPrime(int testNumber, int maximum);

int main()
{
	cout << "How many of the first prime numbers(starting at 0) do you want?" << endl;
	int numberOfPrimes;
	cin >> numberOfPrimes;
	cout << endl;
	PrimeList = new int[numberOfPrimes];
	PrimeNumbers(numberOfPrimes);
	for (int x = 0; x < numberOfPrimes; x++)
	{
		cout << PrimeList[x] << endl;
	}
	system("pause");
	return 0;
}

void PrimeNumbers(int arraySize)
{
	int x = 0;
	int maximum;
	int number = 2;
	PrimeList[x] = number;
	x++;
	number++;
	while (x < 4 && x < arraySize)
	{
		PrimeList[x] = number;
		x++;
		number += 2;
	}
	while (x < arraySize)
	{
		maximum = (number + 1) / 3;
		if (isPrime(number, maximum))
		{
			PrimeList[x] = number;
			x++;
			number += 2;
		}
		else
		{
			number += 2;
		}
	}
}

bool isPrime(int testNumber, int maximum)
{
	int x = 0;
	int primeNumber = PrimeList[x];
	while (primeNumber <= maximum)
	{
		if (testNumber % primeNumber == 0)
		{
			return false;
		}
		x++;
		primeNumber = PrimeList[x];
	}
	return true;
}