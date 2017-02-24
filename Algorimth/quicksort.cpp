#include <stdio.h>
#include <iostream>
using namespace std;
#include <math.h>



void print_arr(int * a){
	for(int i = 0; i < 7; i++){
		cout << a[i] << " ";
	}
	cout << endl;
}
void swap(int *a, int *b){
	int tmp = *a;
	*a = *b;
	*b = tmp;
}
int main(){
	int a[7] = {200, 160, 30, 7, 4, 2, 1};
	// int a[7] = {200, 16, 30, 7, 4, 5, 1};
	// Quick sort
	int i = 0;
	int j = 6;
	int k = round((i + j) * 1.0 / 2);
	while(i < j - 1){
		int f = 0;
		for(int ii = i; ii <= j; ii++){
			if(a[ii] > a[k]){
				swap(a[ii], a[k]); cout << "i = " << i << ", j = " << j << ", k = " << k << endl; print_arr(a); cout << "------" << endl;
				f = 1;
				i = ii;
				break;
			}
			
		}
		if (f == 0){
				swap(a[k], a[j]);  cout << "i = " << i << ", j = " << j << ", k = " << k << endl; print_arr(a);cout << "------" << endl;
				j--;
			}
		int k = round((i + j) * 1.0 / 2);
	}
	// cout << k << endl;
	// print_arr(a);
	return 0;
}