/*
POWER OF AN ELEMENT:
	Given two elements a and n, It will return a^n. (using divide and conquer)

	Time Complexity		: O(log(n))
	Auxiliary Space 	: O(1)
*/

#include <iostream>
using namespace std;

long long power(int NUM, int POW) {
	if(POW == 1)	return NUM;

	long long b = power(NUM, POW/2);
	if(POW%2 == 0)	return b*b;
	else 			return NUM*b*b;
}

int main() {
	int NUM, POW;
	cout << "Enter the value of NUM : "; cin >> NUM;
	cout << "Enter the value of POW : "; cin >> POW;
	cout << NUM << " raised to the power of " << POW << " = " << power(NUM, POW);
	return 0;
}