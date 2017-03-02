#include <bits/stdc++.h>

using namespace std;

int my_compare(string n1, string n2){
    if (n1.length() > n2.length()) return 1;
    else if (n1.length() < n2.length()) return -1;
        else
        return n1.compare(n2);
}
void qs(vector<string> & a, int left, int right)
{
    int i,j;
    string x,y;
    i = left; 
    j = right;
    x = a[(left + right)/2];
    do
    {
        while(my_compare(a[i], x) < 0 && i < right) 
            i++;
        while(my_compare(a[j], x) > 0 && j > left) 
            j--;
        if(i <= j)
        {
            y = a[i]; 
            a[i] = a[j]; 
            a[j] = y;
            i++;
            j--;
        }
    }
    while (i <= j);
    if (left < j) qs(a, left, j);
    if (i < right) qs(a, i, right);
}
vector<string> quick_sort(vector<string> & a, int n)
{
    qs(a, 0, n-1);
    vector<string> b = a;
    return b;
}
int main(){
    int n;
    cin >> n;
    vector<string> unsorted(n);
    for(int unsorted_i = 0; unsorted_i < n; unsorted_i++){
       cin >> unsorted[unsorted_i];
    }
    
    vector<string> sorted = quick_sort(unsorted, n);

    for (int i = 0; i < n; i++){
        cout << sorted[i] << endl;
    }
    return 0;
}