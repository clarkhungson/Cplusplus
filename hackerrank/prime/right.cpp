#include <bits/stdc++.h>
using namespace std;

int main(){
    long first;
    long last;
    cin >> first >> last;
    // your code goes here

    int count = 0;
    for(int i = first; i <= last; i++){
        int N = i;
        while(N > 0){
            int digit = N % 10;
            if (!(digit == 2 || digit == 3 || digit == 5 || digit == 7)){
                break;
            }
            N = N / 10;
        }
        if (N == 0){
        float ss = sqrt(i);
        for (int j = 2; j <= ss; j++){
            if (i % j == 0){
                N = -1;
                break;
            }
        }
        if (N > -1)
            count++;
        }
    }
    cout << count << endl;
    
    return 0;
}