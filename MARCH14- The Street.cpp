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

const int64 INF = (1ll)<<61;
const int mx = 600000 + 7;
const int mod = 1000000007 ;
const db pi = PI;
int EQ(double d) {
    if ( fabs(d) < EPS ) return 0;
    return d > EPS ? 1 : -1 ;
}
map<int64 ,int >M;
struct node {
    int64 type,u,v,a,b;
    node() {}
    node(
        int64 _type,
        int64 _u,
        int64 _v,int64 _a,
        int64 _b) {
        type = _type;
        u = _u;
        v = _v;
        a = _a;
        b= _b;
    }
};
vector<node >V;
struct tree {
    int64 a,b;
};
tree T[mx<<4],T1[mx<<4];
int64 lazy[mx<<4];
int64 iddx[mx];
int64 lazy1[mx<<4];
void update(int lf,int rt,int idx,int x,int y,int64 a,int64 b);
void update1(int lf,int rt,int idx,int x,int y,int64 a,int64 b);
void propagate(int lf,int rt,int idx);
void propagate1(int lf,int rt,int idx);
int64 query(int lf,int rt,int idx,int x);
int64 query1(int lf,int rt,int idx,int x);
int64 bs1(int64 a1,int64 b1,int64 a2,int64 b2,int lf,int rt);
int64 bs2(int64 a1,int64 b1,int64 a2,int64 b2,int lf,int rt);
bool flag ;

int main() {
#ifdef Sanim
    freopen ("in.txt", "r", stdin);
    freopen ("output1.txt", "w", stdout);
#endif
    memo(lazy,0);
    memo(lazy1,0);
    int64 n = II,m = II;
    rep(i,m) {
        int64 type = II;
        if(type == 3) {
            int64 a = II;
            M[a] = 1;
            V.pb(node(type,a,-1,-1,-1));
        } else {
            int64 u = II,v = II,a = II,b = II;
            M[u] = 1;
            M[v] = 1;
            V.pb(node(type,u,v,a,b));
        }
    }
    int cnt = 0;
    forstl(it,M) {
        M[it->first] = cnt;
        iddx[cnt++] = it->first;
    }
    rep(i,m) {
        if(V[i].type == 1) update(0,cnt-1,1,M[V[i].u],M[V[i].v],V[i].a,V[i].b);
        else if(V[i].type == 2) update1(0,cnt-1,1,M[V[i].u],M[V[i].v],V[i].a,V[i].b);
        else if(V[i].type == 3) {
            flag = false;

            int64 ans = query(0,cnt-1,1,M[V[i].u]);
            if(flag) {
                flag = false;

                int64 tmp = query1(0,cnt-1,1,M[V[i].u]);
                //cout << tmp << " ";
                if(flag) ans += tmp;
                cout << ans << endl;
            } else printf("NA\n");
        }
    }

}

void propagate(int lf,int rt,int idx) {
    int mid = (lf+rt)>>1;
    update(lf,mid,idx*2,lf,mid,T[idx].a,T[idx].b);
    update(mid+1,rt,idx*2+1,mid+1,rt,T[idx].a,T[idx].b + (iddx[mid+1]-iddx[lf])*T[idx].a);
    lazy[idx] = 0;
}

void update(int lf,int rt,int idx,int x,int y,int64 a,int64 b) {
    if(lf>rt) return;
    if(lf>=x && rt<=y) {
        if(lazy[idx] == 0) {
            T[idx].a = a;
            T[idx].b = b + (iddx[lf] - iddx[x])*a;
            lazy[idx] = 1;
        } else {

            int64 tmp[4];
            tmp[0] = T[idx].b;
            tmp[1] = T[idx].b + (iddx[rt] - iddx[lf])*T[idx].a;
            tmp[2] = b + (iddx[lf] - iddx[x])*a;
            tmp[3] = b + (iddx[rt] - iddx[x])*a;
            if(tmp[0] <= tmp[2] && tmp[1] <= tmp[3]) {
                T[idx].a = a;
                T[idx].b = b + (iddx[lf] - iddx[x])*a;
                lazy[idx] = 1;
            } else if(tmp[0] >= tmp[2] && tmp[1] >= tmp[3]) {
                return;
            } else {
                if(tmp[0]<tmp[2] && tmp[1] >= tmp[3]) {

                    int64 id = bs1(T[idx].a,T[idx].b,a,tmp[2],lf,rt);
                    update(lf,rt,idx,lf,id,a,tmp[2]);
                } else if(tmp[0] >= tmp[2] && tmp[1] < tmp[3]) {

                    int id = bs2(T[idx].a,T[idx].b,a,tmp[2],lf,rt);
                    //cout << lf << " " << rt << " " << id << endl;
                    int64 bb = b + (iddx[id] - iddx[x])*a;
                    update(lf,rt,idx,id,rt,a,bb);
                }
            }
        }
        lazy[idx] = 1;
        return;
    }
    if(lazy[idx]) propagate(lf,rt,idx);

    int mid = (lf+rt)>>1;
    if(x<=mid)update(lf,mid,idx*2,x,y,a,b);
    if(y>mid)update(mid+1,rt,idx*2+1,x,y,a,b);
}

int64 query(int lf,int rt,int idx,int x) {
    if(lf==x && rt==x) {
        flag = lazy[idx];
        return T[idx].b;
    }
    if(lazy[idx]) propagate(lf,rt,idx);
    int mid = (lf+rt)>>1;
    if(x<=mid) return query(lf,mid,idx*2,x);
    else return query(mid+1,rt,idx*2+1,x);
}

int64 bs1(int64 a1,int64 b1,int64 a2,int64 b2,int lf,int rt) {
    int low = lf, high = rt,ans = -1;
    while(low<=high) {
        int mid = (low+high)>>1;

        int64 x = b1 + (iddx[mid]-iddx[lf])*a1,y = b2 + (iddx[mid]-iddx[lf])*a2;
        if(x<y) {
            low = mid + 1;
            ans = max(ans,mid);
        } else {
            high = mid - 1;
        }
    }
    return ans;
}

int64 bs2(int64 a1,int64 b1,int64 a2,int64 b2,int lf,int rt) {
    int low = lf, high = rt,ans = rt+1;
    while(low<=high) {
        int mid = (low+high)>>1;
        int64 x = b1 + (iddx[mid]-iddx[lf])*a1,y = b2 + (iddx[mid]-iddx[lf])*a2;
        if(x<y) {
            high = mid - 1;
            ans = min(ans,mid);
        } else {
            low = mid + 1;
        }
    }
    return ans;
}

void propagate1(int lf,int rt,int idx) {
    int mid = (lf+rt)>>1;
    update1(lf,mid,idx*2,lf,mid,T1[idx].a,T1[idx].b);
    update1(mid+1,rt,idx*2+1,mid+1,rt,T1[idx].a,T1[idx].b + (iddx[mid+1]-iddx[lf])*T1[idx].a);
    lazy1[idx] = 0;
}

void update1(int lf,int rt,int idx,int x,int y,int64 a,int64 b) {
    if(lf>rt) return;
    if(lf >= x && rt<=y ) {
        if(lazy1[idx]) {
            T1[idx].a += a;
            T1[idx].b += b + (iddx[lf] - iddx[x])*a;
        } else {
            lazy1[idx] = 1;
            T1[idx].a = a;
            T1[idx].b = b + (iddx[lf] - iddx[x])*a;
        }
        return;
    }
    if(lazy1[idx]) propagate1(lf,rt,idx);
    int mid = (lf+rt)>>1;
    if(x<=mid) update1(lf,mid,idx*2,x,y,a,b);
    if(y>mid) update1(mid+1,rt,idx*2+1,x,y,a,b);
}

int64 query1(int lf,int rt,int idx,int x) {
    if(lf==x && rt==x) {
        flag = lazy1[idx];
        return T1[idx].b;
    }
    if(lazy1[idx]) propagate1(lf,rt,idx);
    int mid = (lf+rt)>>1;
    if(x<=mid) return query1(lf,mid,idx*2,x);
    else return query1(mid+1,rt,idx*2+1,x);
}
