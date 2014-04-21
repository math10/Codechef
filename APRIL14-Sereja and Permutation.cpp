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
//int dx[]={1,1,0,-1,-1,-1,0,1};int dy[]={0,1,1,1,0,-1,-1,-1};//8 direction
//int dx[]={2,1,-1,-2,-2,-1,1,2};int dy[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction
//int dx[6]={2,1,-1,-2,-1,1};int dy[6]={0,1,1,0,-1,-1}; //Hexagonal Direction

const int64 INF = 1ll<<50;
const int mx = 1e5 + 7;
const int mod = 1000000007 ;
const db pi = PI;
int EQ(double d) {
    if ( fabs(d) < EPS ) return 0;
    return d > EPS ? 1 : -1 ;
}
pii arr[2002],ans[2002];
int64 num[2002];
int main() {
#ifdef Sanim
    freopen ("in.txt", "r", stdin);
    //freopen ("in.txt", "w", stdout);
#endif
    int t = II;
    For(cs,t) {
        int n = II,k = II,s = II;
        rep(i,n) {
            int u = II;
            arr[i] = pii(u,i+1);
        }
        sort(arr,arr+n);
        int64 f = INF;
        int cnt = 500000000 / (t*n*k);
        cnt += 1;
        For(l,cnt) {
            int64 num = 0;
            rep(i,k) {
                int64 tmp = s;
                forab(j,i,n-1) {
                    if(tmp - arr[j].first >= 0) tmp -= arr[j].first;
                    else break;
                }
                num += tmp;
            }
            if(num<f) {
                f = num;
                rep(i,n) ans[i] = arr[i];
            }
            random_shuffle(arr,arr+n);
        }
        sort(arr,arr+n);
        rep(i,n) {
            if(i) num[i] = num[i-1] + arr[i].first;
            else num[i] = arr[i].first;
        }
        int first = 0;
        rep(i,n) {
            int64 prev = num[i-1];
            while(num[i] > s) {
                num[i] -= arr[first].first;
                first++;
            }
            if(first) {
                if(num[i] <= prev) first = 0;
                break;
            }
        }
        rotate(arr,arr+first,arr+n);
        int64 num = 0;
        rep(i,k) {
            int64 tmp = s;
            forab(j,i,n-1) {
                if(tmp - arr[j].first >= 0) tmp -= arr[j].first;
                else break;
            }
            num += tmp;
        }
        if(num<f) {
            f = num;
            rep(i,n) ans[i] = arr[i];
        }
        rep(i,n) {
            if(i) printf(" ") ;
            printf("%d",ans[i].second) ;
        }
        NL;
    }
}
