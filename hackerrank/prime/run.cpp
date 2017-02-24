#include <bits/stdc++.h>
using namespace std;
#include <math.h>
#define N (int) pow(4, n)

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
    for (int n = number_of_digit_first; n <= number_of_digit_last; n++){  
        int result[N];
        for (int i = 0; i < N; i++){
            result[i] = 0;
        }
        for(int i = 1; i <= n; i++){
            int index = 0;
            int tmp[N];
            for(int j = 0; j < N / 4; j++){
                for(int k = 0; k < 4; k++){
                    tmp[index] = result[j] * 10 + digit[k];
                    index++;
                }
            }
            for(int t = 0; t < N; t++){
                result[t] = tmp[t];
            }
        }
        for(int i = 0; i < N; i++){
            //cout << result[i] << " ";
            if (result[i] < first || result[i] > last)
                continue;
            float ss = sqrt(result[i]);
            int f = 0;
            for(int jj = 2; jj <= ss; jj++){
                if(result[i] % jj == 0){
                    f = 1;
                    break;
                }
            }
            if (f == 0){
                count++;

            cout << result[i] << " ";
            }
        }
    }
    cout << count << endl;
    
    return 0;
}