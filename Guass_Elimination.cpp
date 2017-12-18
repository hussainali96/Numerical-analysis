#include "stdafx.h"
#include <iostream>
using namespace std;
void Input(float A[3][4]) {
	cout << "Enter Values For Array (Space Seperated):" << endl;
	for (int i = 0; i < 3; i++)
	{
		cout << "Row " << i + 1 << ":  ";
		for (int j = 0; j < 4; j++)
		{
			cin >> A[i][j];
		}
	}
}
void Output(float A[3][4]) {
	cout << endl << "Our Array Is:"  << endl;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			cout << "\t" << A[i][j];
		}
		cout << endl;
	}
	cout << endl;
}
int main()
{
	float A[3][4], s;
	Input(A);
	cout << endl;
	if (A[0][0] == 0)
	{

		if (A[1][0] != 0)
		{
			for (int j = 0; j < 4; j++) {

				s = A[0][j];
				A[0][j] = A[1][j];
				A[1][j] = s;
			}
		}

		else if (A[2][0] != 0)
		{
			for (int j = 0; j < 4; j++) {

				s = A[0][j];
				A[0][j] = A[2][j];
				A[2][j] = s;
			}
		}
			
	}
	if (A[1][1] == 0) {
		for (int j = 0; j < 4;j++) {
			s = A[1][j];
			A[1][j] = A[2][j];
			A[2][j] = s;
		}
	}

	float k;
	for (int i = 1; i <= 2; i++) {
		 k = 0;
		 k = -( A[i][0] / A[0][0]);
		for (int j = 0; j < 4; j++) {
			A[i][j] = (k*A[0][j]) + A[i][j];
		}
	}
		k = -(A[2][1] / A[1][1]);
		for (int j = 0; j < 4; j++) {
			A[2][j] = (k*A[1][j]) + A[2][j];
		}
		Output(A);
		cout << endl;
	float arr1[4], arr2[4], arr3[4],count=0;
	for (int j = 0; j < 4; j++) {
		arr1[j] = A[0][j];
		arr2[j] = A[1][j];
		arr3[j] = A[2][j];
		if (arr1[j] == 0 || arr2[j] == 0 || arr3[j] == 0)
			count++;
	}
	float x1, x2, x3;
	if (count >= 3) {
		cout << "\t==========================" << endl;
		cout << "\t| Matrix has no solution |" << endl;
		cout << "\t==========================" << endl;
		return 0;
	}
	else {
		x3 = A[2][3] / A[2][2];
		x2 = (A[1][3]-(A[1][2]*x3)) / A[1][1];
		x1 = (A[0][3] - (A[0][1] * x2) - (A[0][2] * x3)) / A[0][0];
	}
	cout << " ================" << endl;
	cout << " | x1 : " << x1 << "\t|"<<endl;
	cout << " | x2 : " << x2 << "\t|"<<endl;
	cout << " | x3 : " << x3 << "\t|"<< endl;
	cout << " ================" << endl;
	cout << "\n\n\n";
    return 0;
}
