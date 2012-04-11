#line 5 "PrimeContainers.cpp"
#include <algorithm>
#include <iostream>
#include <iterator>
#include <sstream>
#include <fstream>
#include <cassert>
#include <climits>
#include <cstdlib>
#include <cstring>
#include <string>
#include <cstdio>
#include <vector>
#include <cmath>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#include <set>
using namespace std;

class PrimeContainers {
	public:
	int containerSize(int N) {
		vector<bool> arr(false,N+5);
//		cout<<".";
		for(int i=2;i<N>>1+1; i++)
		{
			for(int j=i*2;j<=N;j+=i)
			{
				arr[j]=true;
//				cout<<"!"<<j<<endl;
//				cout<<j<<endl;
			}
		}
		int count=0;
		for(int i=N;i>=1;i=i>>1)
		{
			if(arr[i]==false){ cout<<count+1<<" "<<i<<endl;count++;}
		}
		return count;
	}
};
int main()
{
     PrimeContainers d;
     cout<<d.containerSize(479);
     system("pause");
return 0;
}


// Powered by FileEdit
// Powered by TZTester 1.01 [25-Feb-2003]
// Powered by CodeProcessor
