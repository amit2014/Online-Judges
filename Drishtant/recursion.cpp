/* @BEGIN_OF_SOURCE_CODE */
#include <iostream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;
int arr[10][10];
int m,n,count=0;
void func(int i,int j)
{
//     cout<<(i==m-1 && j==n-1)<<endl;
     if(i==m-1 && j==n-1)
     {
                     ::count++;
                     return;
                     }
     if(arr[i][j]==0) return;
     if(i+1<m) func(i+1,j);
     if(j+1<n) func(i,j+1);
 }
int main()
{
    cin>>m>>n;
    for(int i=0;i<m;i++)
    for(i                                                                                                                                