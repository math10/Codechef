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
//int dx[]={1,1,0,-1,-1,-1,0,1};int dy[]={0,1,1,1,0,-1,-1,-1};//8 direction
//int dx[]={2,1,-1,-2,-2,-1,1,2};int dy[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction
//int dx[6]={2,1,-1,-2,-1,1};int dy[6]={0,1,1,0,-1,-1}; //Hexagonal Direction

const int INF = 1<<29;
const int mx = 1e5 + 7;
const int mod = 1000000007 ;
const db pi = PI;
int EQ(double d) {
    if ( fabs(d) < EPS ) return 0;
    return d > EPS ? 1 : -1 ;
}
vector<int >V1[mx],V2[mx];
int arr[mx];
struct node {
    int maxNum,cnt;
    node *left;
    node *right;
    node() {
        maxNum = cnt = 0;
        left = NULL;
        right = NULL;
    }
};

node *nn[mx];

int id;
void build(int lf,int rt,node *t) {
    if(lf == rt) {
        t->maxNum = V1[id][lf];
        t->cnt = 1;
        return;
    }
    int mid = (lf+rt)>>1;
    t->left = new node();
    build(lf,mid,t->left);
    t->right = new node();
    build(mid+1,rt,t->right);
    t->maxNum = max(t->left->maxNum,t->right->maxNum);
    t->cnt = 0;
    if(t->maxNum == t->left->maxNum) t->cnt += t->left->cnt;
    if(t->maxNum == t->right->maxNum) t->cnt += t->right->cnt;

}


pii query(int lf,int rt,node *t,int x,int y) {
    //cout << lf << " " << rt << " " << x << " " << y << endl;
    if(x<=lf && y>=rt) {
        return pii(t->maxNum,t->cnt);
    }
    int mid = (lf+rt)>>1;
    pii ret = pii(0,0),tmp;
    if(x<=mid){
        ret = query(lf,mid,t->left,x,y);
    }
    if(y>mid){
        tmp = query(mid+1,rt,t->right,x,y);
        if(tmp.first > ret.first) ret = tmp;
        else if(tmp.first == ret.first) ret.second += tmp.second;
    }
    return ret;
}


int main() {
#ifdef Sanim
    freopen ("in.txt", "r", stdin);
    // freopen ("output.txt", "w", stdout);
#endif
    int n = II,m = II;
    rep(i,mx-6) V1[i].pb(-1),V2[i].pb(-1);
    rep(i,n) {
        int num = II;
        arr[i] = num;
        int tmp = num;
        for(int j = 2; j<=sqrt(num); j++) {
            if(num%j==0) {
                V1[j].pb(tmp);
                V2[j].pb(i);
                while(num%j==0) num /= j;
            }
        }
        if(num > 1) {
            V1[num].pb(tmp);
            V2[num].pb(i);
        }
    }
    rep(i,mx-6) {
        if(V1[i].size()>1) {
            id = i;
            nn[i] = new node();
            build(0,V1[i].size()-1,nn[i]);
            V2[i].pb(INF);
            V1[i].pb(INF);
        }
    }
    vector<int >fact;
    while(m--) {

        fact.clear();
        int G = II,x = II-1,y = II-1;
        for(int j = 2; j<=sqrt(G); j++) {
            if(G%j==0) {
                fact.pb(j);
                while(G%j==0) G /= j;
            }
        }

        if(G > 1) fact.pb(G);
        bool flag = false;
        pii ans = pii(0,0);

        forstl(it,fact) {

            int num = *it;
            if(V1[num].size()>1) {
                int low = lower_bound(all(V2[num]),x) - V2[num].begin();

                while(V2[num][low] < x) low++;

                if(V2[num][low] <= y) {
                    flag = true;
                    int high = upper_bound(all(V2[num]),y) - V2[num].begin();
                    while(V2[num][high] > y) high--;
                    //cout << nn[num]->cnt << endl;
                    if(low<=high){
                        pii tmp = query(0,V1[num].size()-2,nn[num],low,high);
                        if(ans.first <= tmp.first) ans = tmp;
                    }

                }
            }
        }
        if(flag) {
            printf("%d %d\n",ans.first,ans.second);
        }
        else {
            printf("-1 -1\n");
        }
    }
}
