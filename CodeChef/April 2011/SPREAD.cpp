
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
#include <bitset>
#include <cmath>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#include <set>
#include <ctime>


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

typedef pair<int,int>   PII;
typedef pair<char,int>  PCI;
typedef pair<int,PII>   TRI;
typedef V( int )        VI;
typedef V( PII )        VII;
typedef V( TRI )        VTRI;
typedef V( string )     VS;
typedef map<int,VI>     MAP;
typedef long long       LL;
typedef long double     LD;

inline void input( int &n ) { n=0; int ch=getchar(); while( ch < '0' || ch > '9' ) ch=getchar(); while( ch >= '0' && ch <= '9' ) n = (n<<3)+(n<<1) + ch-'0', ch=getchar(); }

inline string i2s(int number) { stringstream ss; ss << number; return ss.str(); }

struct node {
    int left,right;
    LL up;
}tree[5000000];
int n,m,c;

void init(int idx, int l, int r)
{
    if(l==r)
    {
        tree[idx].left=l;
        tree[idx].right=r;
        tree[idx].up=c;
    }
    else
    {
        tree[idx].left=l;
        tree[idx].right=r;
        tree[idx].up=0;
        init((idx<<1),l,(l+r)>>1);
        init((idx<<1)+1,((l+r)>>1)+1,r);
    }
}
void print(int idx, int l, int r)
{
    //cout<<idx<<" "<<l<<" "<<r<<endl;
    cout<<tree[idx].left<<" "<<tree[idx].right<<" -> "<<tree[idx].up<<"\n";
    //getchar();
    if(tree[idx].left==tree[idx].right) return;
    print((idx<<1),l,(l+r)>>1);
    print((idx<<1)+1,((l+r)>>1)+1,r);
}
void update(int idx, int l, int r, LL k)
{
    if (tree[idx].left==l && tree[idx].right==r) tree[idx].up+=k;
    else
    {
        if (l>tree[idx<<1].right)
        {
            update((idx<<1)+1, l,r,k);
        }
        else if (r<=tree[idx<<1].right)
        {
            update(idx<<1, l, r, k);
        }
        else
        {
            update(idx<<1,l,tree[idx<<1].right,k);
            update((idx<<1)+1,tree[idx<<1].right+1,r,k);
        }
    }
}
LL query(int idx, int q)
{
//    if(tree[idx].left==tree[idx].right && tree[idx].left==q) return tree[idx].up;
    LL cnt=0;
    for(;tree[idx].left!=q || tree[idx].right!=q;)
    {
        cnt+=tree[idx].up;
  //      cout<<tree[idx].left<<" "<<tree[idx].right<<" -> "<<tree[idx].up<<" = "<<cnt<<endl;
        if(q>=tree[idx<<1].left && tree[idx<<1].right>=q) idx<<=1;
        else idx=(idx<<1)+1;
    }
//    cout<<"return at "<<tree[idx].left<<" "<<tree[idx].right<<" "<<tree[idx].up+cnt<<endl;
    return tree[idx].up+cnt;

}
int main()
{
  //  int qq=0;
//    for(int i=1;i<=1000000;i=*2) qq
//    clock_t start, stop;
  //  start = clock();
//    scanf("%d%d%d",&n,&m,&c);
    input(n);input(m);input(c);
    init(1,1,n);
 //   print(1,1,n);
    char ch;
    int q,l,r,k;
    while(m--)
    {
        cin>>ch;
        if(ch=='Q') { input(q); printf("%lld\n",query(1,q)); }
        else if(ch=='S') {
            input(l);input(r);input(k);
//            scanf("%d%d%d",&l,&r,&k);
            update(1,l,r,k);
//            print(1,1,n);
        }
    }
//    cout<<(double) (stop-start)<<" "<<(double) (stop-start)/CLOCKS_PER_SEC;

    return 0;
}






















