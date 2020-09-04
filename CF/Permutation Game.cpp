
// Problem : C. Permutation Game
// Contest : Codeforces - Lyft Level 5 Challenge 2018 - Elimination Round
// URL : https://codeforces.com/problemset/problem/1033/C
// Memory Limit : 256 MB
// Time Limit : 1000 ms
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
vint arr;
int dp[100001][2];
int go(int pos,int chance)
{
	int val=arr[pos];
	if(val==n)return 1-chance;
	if(dp[pos][chance]!=-1)return dp[pos][chance];
	if(dp[pos][1-chance]!=-1)return 1-dp[pos][1-chance];
	int i=pos+val;
	while(i<n)
	{
		if(arr[i]>arr[pos])
		{
			int X=go(i,1-chance);
			if(X==chance)
			{
				return dp[pos][chance]=chance;
			}
		}
		i+=val;
	}
	i=pos-val;
	while(i>=0)
	{
		if(arr[i]>arr[pos])
		{
			int X=go(i,1-chance);
			if(X==chance)
			{
				return dp[pos][chance]=chance;
			}
		}
		i-=val;
	}
	return dp[pos][chance]=1-chance;
}
void solve(){
	rd(n);
	arr.resize(n);
	for(int& v:arr)rd(v);
	for(int i=0;i<n;i++)
	{
		int winner=go(i,0);
		if(winner==0)cout<<"A";
		else cout<<"B";
	}
	return;	
}


int32_t main() {
    // fint{
    	fast;
    	memset(dp,-1,sizeof(dp));
    	solve();
    // }
    return 0;
}
