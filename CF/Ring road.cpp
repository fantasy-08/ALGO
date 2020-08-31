
// Problem : A. Ring road
// Contest : Codeforces - Codeforces Beta Round #24
// URL : https://codeforces.com/problemset/problem/24/A
// Memory Limit : 256 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

//#pragma GCC optimize "trapv"//  WA to RE int!!
#include <bits/stdc++.h>
#define FOR(i,n) for(int i=0;i<n;i++)
#define FORR(i,n) for(int i=n;i>=0;i--)
#define pb push_back
#define vint vector<int>
#define sint set<int>
#define mint map<int,int>
#define pint pair< int,int >
#define int long long int 
#define test int tt1234; cin>>tt1234;while(tt1234--)
#define endl "\n"
#define SI(a,n) int a[n];FOR(i,n) cin>>a[i];
#define input(a,n) int n;cin>>n; SI(a,n)
#define all(zz) zz.begin(),zz.end()
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define error(x) cerr << #x <<" is " << x << endl;
#define Error(a,b) cerr<<"( "<<#a<<" , "<<#b<<" ) = ( "<<(a)<<" , "<<(b)<<" )\n";
#define precision(x) cout<<fixed<<setprecision(x);
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);
#define present(container, element) (container.find(element)!=container.end())
#define fint fast;test
#define set(a,x) memset(a,x,sizeof(a))
#define L(x)	((x)<<1)
#define R(x)	(((x)<<1)+1)
#define ft first
#define se second
#define MOD 1000000007
using namespace std;
template<typename... T> void rd(T&... args) { ((cin >> args), ...); }
template<typename... T> void pp(T... args) { ((cout << args << " "), ...); cout<<"\n"; }
int n;
vector<vint>adj;
vector<bool>vis;
map<pint,int>cost;
pint dfs(int node,int par)
{
	// error(node);
	vis[node]=true;
	int cnt=0;
	pint temp={0,0};
	for(auto child:adj[node]){
		if(!vis[child]){
			int C=cost[{node,child}];
			auto x=dfs(child,node);
			cnt++;
			if(C==0){
				temp.ft+=x.ft;
				temp.se+=x.se+cost[{child,node}];
			}
			else{
				temp.ft+=x.ft+C;
				temp.se+=x.se;
			}
		}
	}
	if(cnt==0){
		for(auto child:adj[node]){
			if(child!=par){
				int C=cost[{node,child}];
				if(C==0){
					// temp.ft+=x.ft;
					temp.se+=cost[{child,node}];
				}
				else{
					temp.ft+=C;
					// temp.se+=x.se;
				}
			}
		}
	}
	return temp;	
}
void solve(){
	rd(n);
	adj.resize(n+1,vint());
	vis.resize(n+1);
	int Leaf;
	FOR(i,n){
		int u,v,c;
		rd(u,v,c);
		cost[{u,v}]=0;
		cost[{v,u}]=c;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	auto Y=dfs(1,-1);
	pp(min(Y.ft,Y.se));
	return;	
}


int32_t main() {
    // fint{
    	fast;
    	solve();
    // }
    return 0;
}
