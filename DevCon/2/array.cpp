#include<iostream>
#include<string>
#include<cstdlib>
#include<cstdio>
using namespace std;
int main()
{
    int r,c;
    cin>>r>>c;
    int a[25][25]={{0,0}};
    string str;
    int i,j;
    while(cin>>str && str[0]!=0)
    {
        int l=str.length();
        if(l==1)
        break;
        string str1=str.substr(0,l-1);
        int v=atoi(str1.c_str());
        if(str[l-1]=='H')
        {
                for(i=0;i<c;i++)
                {
                int out=0;
                for(j=0;j<r;j++)
                {
                                if(a[j][i]==1)
                                continue;
                                int k=1,count=0;
                                if(i+v>c){
                                          out=1;
                                break;}
                                while(k<v)
                                {
                                          if(a[j][i+k]==1)
                                          {count++;
                                          break;}
                                          k++;
                                }
                                if(count==0)
                                {
                                            while(k>0)
                                            {
                                           k--;
                                           a[j][i+k]=1;        
                                           }
                                  out=1;
                                  break;
                                  } 
                                         
                }
                if(out==1)
                break;
                }
        } 
        else if(str[l-1]=='V')
        {
             for(i=0;i<c;i++)
                {
                int out=0;
                for(j=0;j<r;j++)
                {
                                if(a[j][i]==1)
                                continue;
                                int k=1,count=0;
                                if(j+v>r)
                                {
                                         break;
                                }
                                while(k<v)
                                {
                                          if(a[j+k][i]==1)
                                          {count++;
                                          break;}
                                          k++;
                                }
                                if(count==0)
                                {
                                            while(k>0)
                                          {
                                           k--;
                                           a[j+k][i]=1;        
                                           }
                                  out=1;
                                  break;
                                  } 
                }
                if(out==1)
                break;
                }
        }
        else if(str[l-1]=='S')
        {
            for(i=0;i<c;i++)
                {
                int out=0;
                for(j=0;j<r;j++)
                {
                                if(a[j][i]==1)
                                continue;
                                int k=1,k1=1,count1=0,count=0;
                                 if(i+v>c){
                                          out=1;
                                break;}
                                if(j+v>r)
                                {
                                         break;
                                }
                                
                                while(k<v)
                                {
                                          if(a[j+k][i]==1)
                                          {count++;
                                          break;}
                                          k++;
                                }
                                while(k1<v)
                                {
                                          if(a[j][i+k1]==1)
                                          {count1++;
                                          break;}
                                          k1++;
                                }
                                if(count1==0 && count==0)
                                {
                                          k=0;
                                          while(k<v)
                                          {
                                                    k1=v;
                                                    while(k1>0)
                                                    {
                                                              k1--;
                                                               a[j+k][i+k1]=1;
                                                    }
                                                    k++;
                                          }
                                out=1;
                                break;
                                }
                }
                if(out==1)
                break;
                }
        }
                   
    }
    for(i=r-1;i>=0;i--)
    {
      for(j=0;j<c;j++)
      cout<<a[i][j];
      cout<<endl;
    }
    system("pause");
        return 0;
        }           
    