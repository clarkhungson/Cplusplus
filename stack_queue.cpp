#include <bits/stdc++.h>

using namespace std;

int main(){
    long first;
    long last;
    cin >> first >> last;
    // your code goes here

    // int count = 0;
    // for(int i = first; i <= last; i++){
    //     int N = i;
    //     while(N > 0){
    //         int digit = N % 10;
    //         // if (!(digit == 2 || digit == 3 || digit == 5 || digit == 7)){
    //         if ((digit - 2)*(digit - 3)*(digit - 5)*(digit - 7) == 0){
    //             break;
    //         }
    //         N = N / 10;
    //     }
    //     if (N == 0){
    //     float ss = sqrt(i);
    //     for (int j = 2; j <= ss; j++){
    //         if (i % j == 0){
    //             N = -1;
    //             break;
    //         }
    //     }
    //     if (N > -1)
    //         count++;
    //     }
    // }
    // cout << count << endl;

    int count = 0;
    int digit[4] = {2, 3, 5, 7};
    int number_of_digit_first = log10(first) + 1;
    int number_of_digit_last = log10(last) + 1;
    cout << number_of_digit_first << endl;
    cout << number_of_digit_last << endl;
    cout << "--- "<< endl;
    for (int i = number_of_digit_first; i <= number_of_digit_last; i++){  
        int N = 0;
        for (int j = 1; j <= i; j++){    
            for(int k = 0; k < 4; k++){
                // cout << N << endl;
                int M = N;
                M = M * 10 + digit[k];
                if (M >= first && M <= last){
                    cout << N << endl;
                    if ( N == 2 || N == 3){
                        count++;
                        continue;
                    }
                    float ss = sqrt(N);
                    int a = 0;
                    for (int jj = 2; jj <= ss; jj++){
                        if (N % jj == 0){
                            a = 1;
                            break;
                        }
                    }
                    if (a == 0) 
                        count++;
                }
            }
        }
    }
    cout << count << endl;
    
    return 0;
}