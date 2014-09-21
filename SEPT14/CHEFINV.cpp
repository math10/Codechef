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
const int mx = 2e5 + 7;
const int mod = 1000000007 ;
const db pi = PI;
int EQ(double d) {
    if ( fabs(d) < EPS ) return 0;
    return d > EPS ? 1 : -1 ;
}

int64 tree[mx+1];
void update(int64 idx ,int64 val) {
    while (idx <= mx) {
        tree[idx] += val;
        idx += (idx & -idx);
    }
}
/*
void update(int x , int y , int val){  // if val == 1 dot is set && if val = -1 dot is removed
	int y1;
	while (x <= mx){
		y1 = y;
		while (y1 <= mx){
			tree[x][y1] += val;
			y1 += (y1 & -y1);
		}
		x += (x & -x);
	}
}*/

int64 read(int64 idx) {
    int64 sum = 0;
    while (idx > 0) {
        sum += tree[idx];
        idx -= (idx & -idx);
    }
    return sum;
}
/*
int query(int x , int y ){
	int ret = 0;
	int y1;
	while (x>0){
		y1 = y;
		while (y1 > 0){
			ret += tree[x][y1];
			y1 -= (y1 & -y1);
		}
		x -= (x & -x);
	}
	return ret;
}*/
int64 arr[mx],ans[mx];
int64 lf[mx],rt[mx];
vector<pii >vl[mx],vr[mx];
map<int ,int >M;
void print(int m){
    rep(i,m)printf("%lld\n",ans[i]);
   // NL;
}

int main() {
#ifdef Sanim
    //freopen ("3.in", "r", stdin);
    // freopen ("output.txt", "w", stdout);
#endif
    int n = II,m = II;
    rep(i,n) {
        arr[i] = II;
        M[arr[i]] = 1;
    }

    int64 cnt= 1;
    forstl(it,M){
        (*it).second = cnt++;
    }
    rep(i,n){
        arr[i] = M[arr[i]];
    }
    cnt = 0;
    rep(i,n) {
        lf[i] = read(mx) - read(arr[i]);
        cnt += lf[i];
        update(arr[i],1);
    }
    memo(tree,0);
    per(i,n) {
        rt[i] = read(arr[i]-1);
        update(arr[i],1);
    }
    //cout << cnt << endl;
    rep(i,m){
        int x = II-1,y = II-1;
        if(x == y){
            ans[i] = cnt;
            continue;
        }
        if(x>y)swap(x,y);
        vr[y].pb(pii(x,i));
        vl[x].pb(pii(y,i));
        ans[i] = cnt;
        ans[i] -= (lf[x]+rt[x]);
        ans[i] -= (lf[y]+rt[y]);
        ans[i] += (arr[x]>arr[y]);

    }
    //print(m);
    memo(tree,0);
    rep(i,n){
        if(vr[i].size()){
            int len = vr[i].size();
            rep(j,len){
                pii p = vr[i][j];
                ans[p.second] += read(mx) - read(arr[p.first]);
                //cout << p.second << ' ' << ans[p.second] << endl;
            }
        }
        if(vl[i].size()){
            int len = vl[i].size();
            rep(j,len){
                pii p = vl[i][j];
                ans[p.second] += read(mx) - read(arr[p.first]);
                //cout << p.second << ' ' << ans[p.second] << endl;
            }
        }
        update(arr[i],1);
    }
    //print(m);
    memo(tree,0);
    per(i,n){
        if(vr[i].size()){
            int len = vr[i].size();
            rep(j,len){
                pii p = vr[i][j];
                ans[p.second] += read(arr[p.first]-1);
            }
        }
        if(vl[i].size()){
            int len = vl[i].size();
            rep(j,len){
                pii p = vl[i][j];
                ans[p.second] += read(arr[p.first]-1);
            }
        }
        update(arr[i],1);
    }
    rep(i,n){
        if(vr[i].size()){
            forstl(it,vr[i]){
                pii p = *it;
                ans[p.second] += (arr[p.first] < arr[i]);
            }
        }
    }
    print(m);

}

