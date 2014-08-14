/*
Author :: MD. Musfiqur Rahman Sanim
Aust cse 28th Batch
ID:11.02.04.097
*/


//{ Template
using namespace std;
//{ C-headers
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <climits>
#include <cfloat>
#include <cctype>
#include <cassert>
#include <ctime>
//}
//{ C++-headers
#include <iostream>
#include <iomanip>
#include <sstream>
#include <algorithm>
#include <utility>
#include <string>
#include <stack>
#include <queue>
#include <vector>
#include <set>
#include <map>
//}
//{ Loops
#define forab(i,a,b) for (__typeof(b) i = (a); i <= (b); ++i)
#define rep(i,n) forab (i, 0, (n) - 1)
#define For(i,n) forab (i, 1, n)
#define rofba(i,a,b) for (__typeof(b) i = (b); i >= (a); --i)
#define per(i,n) rofba (i, 0, (n) - 1)
#define rof(i,n) rofba (i, 1, n)
#define forstl(i,s) for (__typeof ((s).end ()) i = (s).begin (); i != (s).end (); ++i)
//}
//{ Floating-points
#define EPS 1e-7
#define abs(x) (((x) < 0) ? - (x) : (x))
#define zero(x) (abs (x) < EPS)
#define equal(a,b) (zero ((a) - (b)))
#define PI 2*acos (0.0)
//}
typedef long long int64;
typedef unsigned long long int64u;
#define memo(a,v) memset(a,v,sizeof(a))
#define all(a) a.begin(),a.end()
#define db double
#define pb push_back
#define pii pair<int ,int >
#define NL puts("")
//{
//Intput_Output
#define II ({ int a; scanf("%d",&a); a;})
#define IL ({ int64 a; scanf("%lld",&a);  a;})
#define ID ({ db a; scanf("%lf",&a);  a;})
#define IC ({ char a; scanf("%c",&a);  a;})
#define IS ({ string a; cin >> a;  a;})
#define ICA(n) ({ char a[n]; scanf("%s",&a);  a;})
#define OC printf("Case %d:",cs);
//}
//}
template <class T, class U> inline T max (T &a, U &b) {
    return a > b ? a : b;
}
template <class T, class U> inline T min (T &a, U &b) {
    return a < b ? a : b;
}
template <class T, class U> inline T swap (T &a, U &b) {
    T tmp = a;
    a = b;
    b = tmp;
}
//int dx[]={1,0,-1,0};int dy[]={0,1,0,-1}; //4 Direction
//int dx[]={1,1,0,-1,-1,-1,0,1};int dy[]={0,1,1,1,0,-1,-1,-1};//8 Direction
//int dx[]={2,1,-1,-2,-2,-1,1,2};int dy[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction
//int dx[6]={2,1,-1,-2,-1,1};int dy[6]={0,1,1,0,-1,-1}; //Hexagonal Direction

const int64 INF = (1ll)<<50;
const int mx = 8e5 + 7;
const int mod = 1000000007 ;
const db pi = PI;
int EQ(double d) {
    if ( fabs(d) < EPS ) return 0;
    return d > EPS ? 1 : -1 ;
}
int arr[mx][15];
int lazy[mx<<2],A[mx<<2][15];
void build(int lf,int rt,int idx) {

    if(lf == rt) {
        rep(i,12)
            A[idx][i] = arr[lf][i];
        return ;
    }
    int mid = (lf+rt)>>1;
    build(lf,mid,idx*2);
    build(mid+1,rt,idx*2+1);
    rep(i,12)A[idx][i] = max(A[idx*2][i],A[idx*2+1][i]);
}

void propagate(int idx) {
    int lf = idx*2 , rt = idx*2+1;
    int val = lazy[idx];
    lazy[lf] = (lazy[lf]+lazy[idx])%12;
    lazy[rt] = (lazy[rt]+lazy[idx])%12;
    int tmp[15];
    rep(i,12) {
        tmp[i] = A[lf][i];
    }
    rep(i,12) {
        A[lf][i] = tmp[(i+val)%12];
    }
    rep(i,12) {
        tmp[i] = A[rt][i];
    }
    rep(i,12) {
        A[rt][i] = tmp[(i+val)%12];
    }
    lazy[idx] = 0;
}

void update(int lf,int rt,int idx,int x,int y,int val) {
    if(lf>=x && rt<=y) {
        lazy[idx] = (lazy[idx]+val)%12;
        int tmp[15];
        rep(i,12) {
            tmp[i] = A[idx][i];
        }
        rep(i,12) {
            A[idx][i] = tmp[(i+val)%12];
        }
        return;
    }
    if(lazy[idx])propagate(idx);
    int mid = (lf+rt)>>1;
    if(x<=mid)update(lf,mid,idx*2,x,y,val);
    if(y>mid)update(mid+1,rt,idx*2+1,x,y,val);
    rep(i,12)A[idx][i] = max(A[idx*2][i],A[idx*2+1][i]);
}

int query(int lf,int rt,int idx,int x,int y) {
    if(lf>=x && rt<=y) return A[idx][0];
    if(lazy[idx])propagate(idx);
    int mid = (lf+rt)>>1;
    int ret = 0;
    if(x<=mid) ret = max(ret,query(lf,mid,idx*2,x,y));
    if(y>mid) ret = max(ret,query(mid+1,rt,idx*2+1,x,y));
    return ret;
}

int main() {

    int P[] = {1,10,100,1000,10000};
    int n = II,m ;
    rep(i,n) {
        arr[i][0] = II;
        int tmp = arr[i][0],cnt = 0;
        while(tmp) {
            cnt++;
            tmp/=10;
        }
        if(arr[i][0] == 0) cnt = 1;
        For(j,11) {
            tmp = j%cnt;
            if(j == tmp) {
                int p = P[cnt-1];
                arr[i][j] = (arr[i][j-1]%p)*10 + (arr[i][j-1]/p);
            } else {
                arr[i][j] = arr[i][tmp];
            }
            //cout << arr[i][j] << " ";
        }
        //NL;
    }
    build(0,n-1,1);
    m = II;
    For(i,m) {
        int type = II;
        if(type == 0) {
            int lf = II,rt = II,f = II%12;
            if(f == 0) continue;
            update(0,n-1,1,lf,rt,f);
        } else {
            int lf = II,rt = II;
            int ans = query(0,n-1,1,lf,rt);
            printf("%d\n",ans);
        }

    }
}

