// Grammar Elimination.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
using namespace std;
float Detm(float A[3][5]) {
	float count1 = 2, count2 = 0, mult1, mult2, sum1=0, sum2=0, detm;
	for (int i = 1; i<=3; i++)
	{
		mult1 = 1, mult2 = 1;
	   int k = count1, h = count2;
		for (int j = 0; j <= 2; j++)
		{
			mult1 *= A[j][h];
			h++;
		}
		for (int j = 0; j <=2; j++)
		{
			mult2 *= A[j][k];
		  k--;
		} 
		sum1 += mult1;
		sum2 += mult2;
		count1++;
		count2++;
	}
	detm = sum1 - sum2;
	return detm;
}
void output(float A[3][5]) {
	for (int i = 0; i<3; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			cout << "\t" << A[i][j];
		}
		cout << endl;
	}
	cout << endl << endl;
}
int main()
{
	float a[3][3],b[3], da[3][5], da1[3][5], da2[3][5], da3[3][5];
	for (int i = 0; i < 3; i++) {
		cout << " Row " << i + 1 << " : ";
		for (int j = 0; j < 3; j++) {
			cin>> a[i][j];
		}
	}
	for (int i = 0; i < 3; i++) {
		cout << " b[" << i << "] : ";
		cin >> b[i];
	}
	cout << endl;
	for(int i=0;i<3;i++)
	{
		for (int j = 0; j < 3; j++)
		{
			da[i][j] = a[i][j];
			da1[i][j] = a[i][j];
			da2[i][j] = a[i][j];
			da3[i][j] = a[i][j];
		}
	}
	for (int i = 0; i < 3; i++) {
		da1[i][0] = b[i];
		da2[i][1] = b[i];
		da3[i][2]= b[i];
	}
	for (int j = 0; j <= 1; j++) {
		for (int i = 0; i < 3; i++) {
			da[i][j+3]=da[i][j];
			da1[i][j+3] = da1[i][j];
			da2[i][j+3] = da2[i][j];
			da3[i][j+3] = da3[i][j];
		}
	}
	output(da);
	output(da1);
	output(da2);
	output(da3);
	float X1, X2, X3,A;
	A = Detm(da);
	if (A == 0) {
		cout << "\t ==========================" << endl;
		cout << "\t | Matrix has no solution |";
		cout << "\t ==========================" << endl;
		return 0;
	}
	X1 = Detm(da1) / A;
    X2= Detm(da2) / A;
	X3= Detm(da3) / A;
	cout << "\t ================" << endl;
	cout << "\t | X1 : " << X1<<"\t|" << endl;
	cout << "\t | X2 : " << X2 <<"\t|"<< endl;
	cout << "\t | X3 : " << X3 <<"\t|"<< endl;
	cout << "\t ================" << endl;
	cout << "\n\n\n";
    return 0;
}

