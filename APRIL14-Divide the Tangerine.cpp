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
#define ff first
#define ss second
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
template <class T, class U> inline T max (T &a, U &b)
{
    return a > b ? a : b;
}
template <class T, class U> inline T min (T &a, U &b)
{
    return a < b ? a : b;
}
template <class T, class U> inline T swap (T &a, U &b)
{
    T tmp = a;
    a = b;
    b = tmp;
}
//int dx[]={1,0,-1,0};int dy[]={0,1,0,-1}; //4 Direction
//int dx[]={1,1,0,-1,-1,-1,0,1};int dy[]={0,1,1,1,0,-1,-1,-1};//8 direction
//int dx[]={2,1,-1,-2,-2,-1,1,2};int dy[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction
//int dx[6]={2,1,-1,-2,-1,1};int dy[6]={0,1,1,0,-1,-1}; //Hexagonal Direction

const int64 INF = (1ll)<<50;
const int mx = 1e5 + 7;
const int mod = 1000000007 ;
const db pi = PI;
int EQ(double d) {
    if ( fabs(d) < EPS ) return 0;
    return d > EPS ? 1 : -1 ;
}
vector<pii >chef,boy;
map<int ,int >m;
int lazy[mx],A[mx];

void propagate(int lf,int rt,int idx){
    int mid = (rt+lf)>>1;
    A[idx*2] += (mid-lf+1)*lazy[idx];
    A[idx*2 + 1] += (rt-mid)*lazy[idx];
    lazy[idx*2] += lazy[idx];
    lazy[idx*2+1] += lazy[idx];
    lazy[idx] = 0;
}

void update(int lf,int rt,int idx,int x,int y,int val){
    if(lf>=x && rt<= y){
        A[idx] += (rt -lf + 1)*val;
        lazy[idx] += val;
        return;
    }
    if(lazy[idx]) propagate(lf,rt,idx);
    int mid = (lf+rt)>>1;
    if(x<=mid) update(lf,mid,idx*2,x,y,val);
    if(y>mid) update(mid+1,rt,idx*2+1,x,y,val);
    A[idx] = A[idx*2] + A[idx*2 + 1];
}

int query(int lf,int rt,int idx,int x,int y){
    if(lf>=x && rt<=y){
        return A[idx];
    }
    if(lazy[idx]) propagate(lf,rt,idx);
    int mid = (lf+rt)>>1,ret = 0;
    if(x<=mid) ret = query(lf,mid,idx*2,x,y);
    if(y>mid) ret += query(mid+1,rt,idx*2+1,x,y);
    return ret;
}

int main() {
#ifdef Sanim
    freopen ("in.txt", "r", stdin);
    // freopen ("output.txt", "w", stdout);
#endif
    int t = II;
    For(cs,t){
        int n = II,k = II,p = II;
        chef.clear();boy.clear();m.clear();
        memo(A,0);
        memo(lazy,0);
        rep(i,k){
            int x = II,y = II;
            m[x] = 1;
            m[y] = 1;
            if(x>y){
                y = n + y;
                m[y] = 1;
            }
            chef.pb(pii(x,y));
        }
        rep(i,p){
            int x = II,y = II;
            m[x] = 1;
            m[y] = 1;
            if(x>y){
                y = n + y;
                m[y] = 1;
            }
            boy.pb(pii(x,y));
        }
        int cnt = 0;
        forstl(it,m) m[it->ff] = cnt++;
        rep(i,p){
            update(0,cnt,1,m[boy[i].ff],m[boy[i].ss],i+1);
        }
        int flag = true;
        rep(i,k){

                int num = query(0,cnt,1,m[chef[i].ff],m[chef[i].ff]);
               // cout << num << " ";
                int tmp = query(0,cnt,1,m[chef[i].ff],m[chef[i].ss]);
                //cout << tmp << endl;
                if(num*(m[chef[i].ss] - m[chef[i].ff] + 1) != tmp) flag = false;

        }
        if(flag) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
}
