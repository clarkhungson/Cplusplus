#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define N 16*4*4
int inData[4] = {2,3,4,5};
int main(){
    int n = 4,i,j,k,ind,x;
    int * outData = new int(N);
    int * temp = new int(N);
    memset(outData, -1, N*sizeof(int));
    outData[0] = 0;
    for (i = 0;i < n;i++){
        int *temp = malloc(N*sizeof(int));
        ind = 0;
        for(j = 0; j <N; j++){
            if(outData[j] == -1)
                break;
            for(k = 0; k < 4; k++){
                temp[ind] = outData[j]*10 + inData[k];
                ind ++;
            }
            
        }
        memcpy(outData, temp, (ind) * sizeof(int));
    }
    for(j = 0; j < N; j++){
        printf("%d ", outData[j]);
    }

    return 0;
}