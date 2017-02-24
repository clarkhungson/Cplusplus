#include <bits/stdc++.h>
using namespace std;
#include <math.h>
#define N (int) pow(4, n)

int main(){

    int digit[4] = {2, 3, 5, 7};
    int n = 4;
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
        cresult << result[i] << " ";
    }
    cresult << endl;
    
    return 0;
}