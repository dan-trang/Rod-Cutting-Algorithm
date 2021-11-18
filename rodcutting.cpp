/*********************************************
 * Daniel Trang
 * CS350: Rod-cutting algorithm
 * 11/18/2021
 *
 * This file contains the implementation of a
 * bottom-up dynamic programming approach to the
 * rod-cutting problem. The execution time is in
 * O(n^2). The space efficiency is in O(n).
 * The user is asked for some rod length "n". The
 * price list is then created with size of "n" as
 * well. The value of the type of cuts (based on
 * length) is then displayed for the user. The
 * optimal sale value of the rod is then calculated
 * and printed out for the user at the end.
 * ******************************************/

#include <stdio.h>
#include <iostream>
#include <string>
#include <algorithm>
#include <random>

using namespace std;

int bottomUpCutRod(int p[], int n);
void pricing(int p[], int size);

int main(){
	int n;		//length of original rod
	cout<<"Enter the length of rod to cut and sell: ";
	cin>>n;

	int p[n];	//initialize integer array for prices
	int solution = -1;

	pricing(p, n);			//fill price array using user input
	solution = bottomUpCutRod(p, n);	//find optimal price
	cout << "The maximum total sale price from the ";
	cout << n << "-length rod is $" << solution << ".";
        cout <<	endl;
	return 0;
}


//function to initialize price array
void pricing(int p[], int size){
	//randomize number generator
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<> distr(1, size*3);

	//initialize price array with random int
	for(int i=0; i<size; i++){
		p[i] = distr(gen);
	}	

	//sort the price array in ascending order
	sort(p, p+size);

	//print out price list for user
	cout << "-------------------\n";
	cout << "PRICE LIST\n";
	cout << "-------------------\n";
	for(int i=0; i<size; i++){
		cout << i+1 <<"-length cut = $" << p[i]<<endl;
	}	
}


//main function to calculate optimal price of rod
int bottomUpCutRod(int p[], int n){
	int r[n], q;
	r[0] = 0;
	for(int j=1; j<=n; j++){
		q = -1;
		for(int i=1; i<=j; i++){
			q = max(q, p[i-1] + r[j-i]);
		}
		r[j] = q;
	}
	return r[n];
}
