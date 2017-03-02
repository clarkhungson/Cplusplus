#include <bits/stdc++.h>
using namespace std;
#include <math.h>
// #define PI 3.1415926535897932384626433832795028841971693993751
#define PI 3.1415926535897932384626433832795028841971693993751


int main(){
    long min;
    long max;
    cin >> min >> max;
    // your code goes here
    int d = 10;
    int n = 1;
    for(int d1 = min; d1 <= max; d1++){
        int n1 = PI * d1;
        cout << "n = " << n1 << ", d = " << d1 << endl; 
        cout << abs(n1*1.0/d1 - PI) << endl;
        cout << "------------------" << endl;
        if (abs(n1*1.0/d1 - PI) < abs(n*1.0/d - PI)){
        	n = n1;
        	d = d1;
        }
        if (abs((n1 + 1)*1.0/d1 - PI) < abs(n*1.0/d - PI)){
        	n = n1 + 1;
        	d = d1;
        }
    }
    cout << "n = " << n << ", d = " << d << endl;
    //cout << abs(22*1.0/7 - PI) << endl;
    return 0;
}
