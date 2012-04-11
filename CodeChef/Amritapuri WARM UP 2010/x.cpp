#include <iostream>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <vector>
#include <string>
#include <set>
#include <stack>
#include <map>
#include <queue>
#include <list>
#include <algorithm>
using namespace std;

#define ULL unsigned long long

inline void read_num(int &num)
{
	num = 0;

	char ch = getchar();

	while(ch<'0' && ch>'9')
		ch = getchar();

	do{
		num = (num<<3)+(num<<1)+(ch-'0');
		ch = getchar();
	}while(ch>='0' && ch<='9');
}

int main()
{
	int m,n,i,j,k,l,p,q;
	int x[10010];
	int t,res;

	read_num(t);

	while(t--){
		bool flag = true;
		res = 0;

		read_num(n);
		read_num(m);

		memset(x,0,sizeof(int)*10010);

		for(i=0;i<m;i++){
			read_num(p);
			read_num(q);

			if(x[p]==0){
				x[p] = 1;
			}

			if(x[q]==0){
				x[q] = x[p]+1;
			}

			if(x[q]<x[p])
				flag = false;

			if(res<x[q])
				res = x[q];
		}

		if(flag)
			printf("%d\n",res);
		else
			puts("IMPOSSIBLE");
	}

	return 0;
}
