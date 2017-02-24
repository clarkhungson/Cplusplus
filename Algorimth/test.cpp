#include <bits/stdc++.h>

using namespace std;

int my_compare(string n1, string n2){
    if (n1.length() > n2.length()) return 1;
    else if (n1.length() < n2.length()) return -1;
        else
        return n1.compare(n2);
}

void print_arr(vector<string> a){
    for(int i = 0; i < 7; i++){
        cout << a[i] << " ";
    }
    cout << endl;
}

int main(){
    int n;
    cin >> n;
    vector<string> unsorted(n);
    for(int unsorted_i = 0; unsorted_i < n; unsorted_i++){
       cin >> unsorted[unsorted_i];
    }
    // your code goes here
    int i = 0;
    int j = n - 1;
    int k = round((i + j) * 1.0 / 2);
    while(i < j - 1){
        int f = 0;
        for(int ii = i; ii <= j; ii++){
            if(my_compare(unsorted[ii], unsorted[k]) > 0){
                string tmp = unsorted[ii];
                unsorted[ii] = unsorted[k];
                unsorted[k] = tmp;
                print_arr(unsorted);
                f = 1;
                i = ii;
                break;
            }
            
        }
        if (f == 0){
                string tmp = unsorted[j];
                unsorted[j] = unsorted[k];
                unsorted[k] = tmp; 
                print_arr(unsorted); 
                j--;
            }
        int k = round((i + j) * 1.0 / 2);
    }
    for (int i = 0; i < n; i++){
        cout << unsorted[i] << endl;
    }
    return 0;
}