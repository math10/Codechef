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
//int dx[]={1,1,0,-1,-1,-1,0,1};int dy[]={0,1,1,1,0,-1,-1,-1};//8 Direction
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

int n;

//convert String to Integer
int64 toInt(string s){
    int64 r = 0 ;
    istringstream sin(s); sin>>r;
    return r;
}

vector<int64 >v[110],num;
set<int64 >S;
int sz;
//splits String in space
vector<int64 >Split(string s ){
    vector<int64>ret;
    istringstream ss(s) ;
    string token ;
    while(ss >> token) {
        int64 tmp = toInt(token);
        ret.pb( tmp) ;
        S.insert(tmp);
    }
    sort(all(ret));
    return ret;
}

int64 dp[1<<11][110];

int64 call(int mask,int pos){
    if(mask == (1<<n)-1) return 1;
    if(pos == sz) return 0;
    int64 &ret = dp[mask][pos];
    if(ret != -1) return ret;
    ret = 0;
    rep(i,n){
        if(mask & (1<<i)) continue;
        if(binary_search(all(v[i]),num[pos])){
            ret += call(mask|(1<<i),pos+1);
            ret %= mod;
        }
    }
    ret += call(mask,pos+1);
    return ret%mod;
}
char st[mx];
int main() {
    int t = II;
    For(cs,t){
        n = II;
        getchar();
        rep(i,n){
            gets(st);
            v[i] = Split(st);
        }
        forstl(it,S){
            num.pb(*it);
        }
        sz = num.size();
        memo(dp,-1);
        int64 ans = call(0,0)%mod;
        cout << ans << endl;
        num.clear();
        rep(i,n)v[i].clear();
    }
}

