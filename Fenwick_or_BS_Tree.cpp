//#pragma GCC optimize "trapv"//  WA to RE int!!
#include <bits/stdc++.h>
#define FOR(i,n) for(int i=0;i<n;i++)
#define FORR(i,n) for(int i=n;i>=0;i--)
#define pb push_back
#define vlli vector<int>
#define slli set<int>
#define mlli map<int,int>
#define int long long int 
#define test int tt1234; cin>>tt1234;while(tt1234--)
#define endl "\n"
#define all(zz) zz.begin(),zz.end()
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define error(x) cerr << #x <<" is " << x << endl;
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);
#define fint fast;test
#define SI(a,n) int a[n];FOR(i,n) cin>>a[i];
#define input(a,n) int n;cin>>n; SI(a,n)
#define set(a,x) memset(a,x,sizeof(a))
#define L(x)	((x)<<1)
#define R(x)	(((x)<<1)+1)
#define ft first
#define se second
#define MOD 1000000007
using namespace std;
int arr[100001],tree[100001];
int n;
void add(int x,int val){
    for(;x<=n;x+=(x&(-x)))tree[x]+=val;
}
int query(int x){
    int ans=0;
    for(;x>0;x-=(x&(-x)))ans+=tree[x];
    return ans;
}
void init(){
    for(int i=1;i<=n;i++){
        add(i,arr[i-1]);
    }
}
void solve(){
    cin>>n;
    FOR(i,n) cin>>arr[i];
    init();
    int q;
    cin>>q;
    while(q--){
        int r;
        cin>>r;
        cout<<query(r)<<endl;
    }
    return;	
}


int32_t main() {
    fint{
        solve();
    }
    return 0;
}