/*
ID: vermapr1
PROG: <prog_name>
LANG: C++
*/

// #define TRUE FALSE haha now debug this
using namespace std;
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
//BEGIN_TEMPLATE_BY_PRATYUSH_VERMA

//CONSTANT
#define INF (1<<31)-1
#define PI 3.1428571428571428571428571428571

//FUNC
#define MAX(i,j) (i)>(j)?(i):(j)
#define MIN(i,j) (i)<(j)?(i):(j)
#define REP(i,a) for((i)=0;(i)<(a);(i)++)
#define REP_(i,a) for((i)=0;(i)<=(a);(i)++)
#define FOR(i,a,b) for((i)=(a);(i)<(b);(i)++)
#define FOR_(i,a,b) for((i)=(a);(i)<=(b);(i)++)
#define VAR(V,init) __typeof(init) V=(init)
#define FOREACH(I,C) for(VAR(I,(C).begin());I!=(C).end();I++)
#define ALL(x) (x).begin(),(x).end()
#define SIZE(x) ((int)(x.size()))
#define LENGTH(x) ((int)(x.length()))
#define SZ(x) sizeof(x)
#define MEM(m,i) memset((m),(i),SZ(m))
#define PB(x,y) (x).push_back(y)
#define MP(x,y) make_pair(x,y)
#define V(x) vector < x >

//BITWISE
#define LASTSETBIT(x) x & ~(x-1)
#define TRAILZERO(x) __builtin_ctz(x)
#define LEADZERO(x) __builtin_clz(x)
#define COUNTSETBIT(x) __builtin_popcount(x)
#define GCD(x,y) __gcd(x,y)

typedef pair<int,int>   PII;
typedef pair<char,int>  PCI;
typedef pair<int,PII>   TRI;
typedef V( int )        VI;
typedef V( PII )        VII;
typedef V( TRI )        VTRI;
typedef V( string )     VS;
typedef long long       LL;
typedef long double     LD;

template<class T> void print(const vector<T> &v){ostringstream os; for(int i=0; i<v.size(); ++i){if(i)os<<' ';os<<v[i];} cout<<os.str()<<endl;}
template<class T, class U> T cast (U x) { ostringstream os; os<<x; T res; istringstream is(os.str()); is>>res; return res; }
template<class T> vector<T> split(string s, string x=" ") {vector<T> res; for(int i=0;i<s.size();i++){string a; while(i<(int)s.size()&&x.find(s[i])==string::npos)a+=s[i++]; if(!a.empty())res.push_back(cast<T>(a));} return res;}

inline void input( int &n ) { n=0; int ch=getchar(); while( ch < '0' || ch > '9' ) ch=getchar(); while( ch >= '0' && ch <= '9' ) n = (n<<3)+(n<<1) + ch-'0', ch=getchar(); }

//END_TEMPLATE_BY_PRATYUSH_VERMA

int main()
{
    int i,j,n,k;
    int test,mx;
//    REP(i,20) cout<<ax[i]<<" "<<ay[i]<<endl;
    scanf("%d",&test);
    while(test--) {
        scanf("%d",&n);
        mx=-1;
        int tab[n];
        int arr[n][n];
        int dd[n][n];
        int dd_[n][n];
        double K,L,min,max,max1,min1,K1,L1,loop=100;
        double bb[n][n];
        min=min1=1000005;
        max=max1=-1;
        REP(k,n)
        REP(j,n) {
            scanf("%d",&arr[k][j]);
            if(i!=j && arr[k][j]>max) max=arr[k][j];
            if(i!=j && arr[k][j]<min) min=arr[k][j];
        }
        REP(i,n) {
            dd[i][0]=arr[0][i];
            dd[i][1]=rand();
        }
        REP(i,n) {
            REP(j,n) {
                bb[i][j]=(((dd[i][0]-dd[j][0])*(dd[i][0]-dd[j][0])) + ((dd[i][0]-dd[j][0])*(dd[i][0]-dd[j][0])));
                if(i!=j && bb[i][j]>max1) max1=bb[i][j];
                if(i!=j && bb[i][j]<min1) min1=bb[i][j];
            }
        }
        K=min1/max;
        L=max1/min;
        bool save=true;
        while(loop--) {
            REP(i,n) {
                if(save) dd_[i][0]=dd[i][0];
                if(save) dd_[i][1]=dd[i][0];
                dd[i][0]-=10;
                dd[i][1]-=10;
            }
            REP(i,n) {
                REP(j,n) {
                    bb[i][j]=(((dd[i][0]-dd[j][0])*(dd[i][0]-dd[j][0])) + ((dd[i][0]-dd[j][0])*(dd[i][0]-dd[j][0])));
                    if(i!=j && bb[i][j]>max1) max1=bb[i][j];
                    if(i!=j && bb[i][j]<min1) min1=bb[i][j];
                }
            }
            K1=min1/max;
            L1=max1/min;
            if(K1>K || L1<L) {
                if(K1>K) K=K1;
                if(L1<L) L=L1;
                save=true;
            }
            else {
                save=false;
            }
        }
        printf("2\n");
        FOR(i,0,n) tab[i]=i;
        FOR(i,0,n) {
//            printf("%d %d\n",ax[i],ay[i]);
//            printf("%d %d\n",i,i%2);
            printf("%d %d\n",dd_[i][0],dd_[i][1]);
        }
    }
//	system("pause");
	return 0;
}


























