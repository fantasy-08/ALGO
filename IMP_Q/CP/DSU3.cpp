
// Problem : A. Learning Languages
// Contest : Codeforces - Codeforces Round #170 (Div. 1)
// URL : https://codeforces.com/problemset/problem/277/A
// Memory Limit : 256 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

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
#define Error(a,b) cerr<<"( "<<#a<<" , "<<#b<<" ) = ( "<<(a)<<" , "<<(b)<<" )\n";
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

void dfs(int node,vlli graph[],vector<bool>&vis){
	vis[node]=true;
	for(auto child:graph[node]){
		if(vis[child]==false)dfs(child,graph,vis);
	}
}

void solve(){
	int n,l;
	cin>>n>>l;
	vlli adj[l+1];
	rep(i,1,n+1){
		int x;
		cin>>x;
		FOR(j,x){
			int t;
			cin>>t;
			adj[t].pb(i);
		}
	}
	// rep(i,1,l+1){
		// cout<<i<<"-";
		// for(auto x:adj[i])cout<<x<<" ";
		// cout<<endl;
	// }
	vector<bool>vis(n+1 ,true);
	vlli graph[n+1];
	for(auto v:adj){
		int N=v.size();
		if(N==1)
		vis[v[0]]=false;
		FOR(i,N-1){
			graph[v[i]].pb(v[i+1]);
			graph[v[i+1]].pb(v[i]);
			vis[v[i]]=false;
			vis[v[i+1]]=false;
		}
	}
	int count=0;
	int nw=0;
	rep(i,1,n+1){
		// error(vis[i]);
		if(vis[i]==true)nw++;
	}
	rep(i,1,n+1){
		if(vis[i]==false){
			dfs(i,graph,vis);
			count++;
		}
	}
	// Error(count,nw);
	cout<<max(0LL,count-1)+nw<<endl;
	return;	
}


int32_t main() {
    // fint{
    	fast;
    	solve();
    // }
    return 0;
}
