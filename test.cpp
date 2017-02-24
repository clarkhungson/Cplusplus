#include <bits/stdc++.h>

using namespace std;

int my_compare(string n1, string n2){
    if (n1.length() > n2.length()) return 1;
    else if (n1.length() < n2.length()) return -1;
        else
        return n1.compare(n2);
}

int main(){
    int n;
    cin >> n;
    vector<string> unsorted(n);
    for(int unsorted_i = 0; unsorted_i < n; unsorted_i++){
       cin >> unsorted[unsorted_i];
    }
    // your code goes here
    for (int i = 0; i < n - 1; i++){
        for (int j = i; j < n; j++){
            string tmp;
            if ((my_compare(unsorted[i], (unsorted[j])) > 0)){
                tmp = unsorted[i];
                unsorted[i] = unsorted[j];
                unsorted[j] = tmp;
            }
        }
    }
    for (int i = 0; i < n; i++){
        cout << unsorted[i] << endl;
    }
    return 0;
}