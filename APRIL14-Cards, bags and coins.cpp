/*
Author :: MD. Musfiqur Rahman Sanim
Aust cse 28th Batch
ID:11.02.04.097
*/


//{ Template
#include<bits/stdc++.h>
using namespace std;
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
#define gc getchar
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

const int64 INF = (1ll)<<50;
const int mx = 1e5 + 7;
const int mod = 1000000009 ;
const db pi = PI;
int EQ(double d) {
    if ( fabs(d) < EPS ) return 0;
    return d > EPS ? 1 : -1 ;
}
template<class T>inline bool read(T &x) {
    int c=gc();
    int sgn=1;
    while(~c&&c<'0'||c>'9') {
        if(c=='-')sgn=-1;
        c=gc();
    }
    for(x=0; ~c&&'0'<=c&&c<='9'; c=gc())x=x*10+c-'0';
    x*=sgn;
    return ~c;
}

int freq[110],n;
int afreq[110];
int occur[110][110];
int64 F[mx],Inv[mx];
int arr[mx],Mod;
int64 dp[110];
int64 pre[110];

int64 nCr(int64 x , int64 y ) {
    int64 r = ( F[x] * Inv[y] )% mod ;
    r = ( r * Inv[x-y] ) % mod;
    return r ;
}
int64 BigMod(int64  b,int64  p ,int64  m ) {
    int64  ret = 1 ;
    while(p)  {
        if(p&1) ret = (ret * b ) % m ;
        p >>= (1ll) , b = (b*b)%m ;
    }
    return ret ;
}
void preGen() {
    F[0] = 1 ;
    For(i,mx-2) F[i] = (F[i-1] * i ) % mod;
    rep(i,mx-2) Inv[i] = BigMod(F[i],mod-2,mod);
}

int main() {
#ifdef Sanim
    freopen ("in.txt", "r", stdin);
    //freopen ("output.txt", "w", stdout);
#endif
    preGen();
    int t ;
    read(t);
    For(cs,t) {
        read(n);
        int q ;
        read(q);
        //cout << n << " " << q << endl;
        rep(i,n) read(arr[i]);
        rep(i,q) {
            read(Mod);
            memo(freq,0);
            memo(occur,0);
            memo(dp,0);
            memo(pre,0);
            pre[0] = 1;
            rep(j,n) {
                int tmp = arr[j]%Mod;
                if(tmp<0) tmp += Mod;
                freq[tmp]++;
            }
            rep(k,Mod) {
                rep(j,freq[k]+1) {
                    occur[k][(k*j)%Mod] = (occur[k][(k*j)%Mod] + nCr(freq[k],j))%mod;
                }
            }
            rep(l,Mod) {
                rep(j,Mod) {
                    rep(k,Mod) {
                        dp[j] = (dp[j] + (pre[(j-k+Mod)%Mod]*occur[l][k])%mod)%mod;
                    }
                }
                rep(k,Mod) {
                    pre[k] = dp[k];
                    dp[k] = 0;
                }
            }
            cout << pre[0] << endl;
        }
    }
}
