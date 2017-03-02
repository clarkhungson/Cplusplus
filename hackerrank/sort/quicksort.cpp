#include <iostream>
using namespace std;
void qs(int a[], int left,int right)
{
    int i,j, x,y;
    i=left; j=right;
    x= a[(left+right)/2];
    do
        {
        while(a[i]<x && i<right) i++;
        while(a[j]>x && j>left) j--;
        if(i<=j)
            {
            y=a[i];a[i]=a[j];a[j]=y;
            i++;j--;
            }
        }
    while (i<=j);
    if (left<j) qs(a,left,j);
    if (i<right) qs(a,i,right);
}
void quick_sort(int a[], int n)
{
    qs(a,0,n-1);
}
int main()
{
    int n;
    cout <<"Nhap so cac so hang can sap xep:  ";
    cin >> n;
    int a[n];
    cout<<"Nhap cac so hang: "<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<"a"<<i+1<<": " ;
        cin >>a[i];
        cout << endl;
    }
    quick_sort(a,n);
    cout<<"Day sau khi sap xep:  ";
    for(int i=0;i<n;i++)
        cout<<a[i] << "  ";
}