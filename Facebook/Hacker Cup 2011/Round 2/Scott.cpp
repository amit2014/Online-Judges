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
    freopen("Scott.in","r",stdin);
    freopen("Scott.out","w",stdout);
    int test,p,l,i,j,k,q;
    int m,n,a1,a2,a3,a4,a5,b1,b2,b3,b4,b5;
    cin>>test;
    while(test--) {
        cin>>p>>l;
        map<int, int> m1; map<int, int> m2;
        cin>>n>>a1>>a2>>a3>>a4>>a5;
        cin>>m>>b1>>b2>>b3>>b4>>b5;
        m1[a1%p]++; m1[a2%p]++;
        int last2=a1;
        int last=a2;
        FOR(i,3,n+1) {
            int k=((a3%p*last2%p)%p + (a4%p*last%p)%p + a5%p)%p;
            m1[k]++;
            last2=last;
            last=k;
        }
        m2[b1%p]++; m2[b2%p]++;
        int _last2=b1;
        int _last=b2;
        FOR(i,3,m+1) {
            int k=((b3%p*_last2%p)%p + (b4%p*_last%p)%p + b5%p)%p;
            m2[k]++;
            _last2=_last;
            _last=k;
        }
        int count=0;
        map<int, int> ::iterator it2;map<int, int> ::iterator it1;
       // for(it1=m1.begin();it1!=(m1).end();it1++)
       // cout<<(*it1).first<<"   "<<(*it1).second<<endl;
       // cout<<"!#@#"<<endl;
        //for(it2=m2.begin();it2!=(m2).end();it2++)
        //cout<<(*it2).first<<"   "<<(*it2).second<<endl;

        for(it1=m1.begin();it1!=(m1).end();it1++) {
            for(it2=m2.begin();it2!=(m2).end();it2++) {
                if ((((*it1).first)%p * ((*it2).first)%p) % p < l) {
                    count+= (*it1).second * (*it2).second ;
                }
            }
        }
        cout<<count<<endl;
    }
//	system("pause");
	return 0;
}




























