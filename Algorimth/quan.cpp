#include <iostream>
using namespace std;

void dequy(int *aarray, int k, int sum, int nSo)
{
 for(int i = 0; i < nSo; i++)
 {
  //cout<<"a[i] = "<<array[i]<<endl;
  int mul = 1;
  for(int j = 1; j < k; j++)
  {
   mul = mul*10;
  }
  sum = sum + aarray[i]*mul;
  
  //cout<<sum<<endl;
  if(k == 1)
  {
   cout<<"sum = "<<sum<<endl;
   sum = sum - aarray[i]*mul;
  }
  else
  {
   dequy(aarray, k - 1, sum, nSo);
   sum = sum - aarray[i]*mul;
  } 
 }
}

int main()
{
 int nSo = 4;
 int aarray[4] = {2,3,5,7};
 int *p = aarray;
 int k = 2;
 int sum = 0;
 
 dequy(p, k, sum, nSo);
 return 0;
}