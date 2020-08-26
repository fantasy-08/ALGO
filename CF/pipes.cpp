
// Problem : C. Pipes
// Contest : Codeforces - Codeforces Round #590 (Div. 3)
// URL : https://codeforces.com/problemset/problem/1234/C
// Memory Limit : 256 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

// God & me
// Fly ...
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
int dp[200001][2];
int go(int n,int m,bool change,vector<vector<int>>&arr){
	if(n<0 || n>1)return 0;
	// cerr<<n<<" "<<m<<" "<<change<<endl;
	if(m==arr[0].size()){
		return n==1;
	}
	if(dp[m][n]!=-1)return dp[m][n];
	if(n==0 && m==0){
		if(arr[n][m]){
			return dp[m][n]=go(n+1,m,true,arr);
		}
		return dp[m][n]=go(n,m+1,false,arr);
	}
	if(arr[n][m]){
		if(change){
			return dp[m][n]=go(n,m+1,false,arr);
		}
		if(n==0)
			return dp[m][n]=go(n+1,m,true,arr);
		else
			return dp[m][n]=go(n-1,m,true,arr);
	}
	if(!change)return dp[m][n]=go(n,m+1,false,arr);
	return dp[m][n]=0;
}
void solve(){
	int n;
	rd(n);
	vector<vector<int>>arr(2,vector<int>());
	FOR(i,n){
		char c;
		rd(c);
		int X=c-'0';
		if(X<=2)arr[0].pb(0);
		else arr[0].pb(1);
		// cout<<arr[0][i];
	}
	FOR(i,n){
		char c;
		rd(c);
		int X=c-'0';
		if(X<=2)arr[1].pb(0);
		else arr[1].pb(1);
		// cout<<arr[1][i];
	}	
	memset(dp,-1,sizeof(dp));
	// error(arr.size());
	if(go(0,0,false,arr))pp("YES");
	else pp("NO");
	return;	
}


int32_t main() {
    fint{
    	solve();
    }
    return 0;
}
