
// Problem : E. Accidental Victory
// Contest : Codeforces - Codeforces Round #702 (Div. 3)
// URL : https://codeforces.com/contest/1490/problem/E
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
#define input(a,n) int n;cin>>n;vint a(n);for(int&v:a)rd(v);
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

void solve(){
	int n;
	rd(n);
	vector<pint>A;

	rep(i,1,n+1)
	{
		int t;
		rd(t);
		A.pb({t,i});
	}
	
	if(n==1)
	{
		pp(1);
		pp(1);
		return ;
	}
	sort(all(A));
	vint temp,ans;
	int sum=A[0].ft;
	temp.pb(A[0].se);
	
	rep(i,1,n)
	{
		if(sum>=A[i].ft){
			temp.pb(A[i].se);
			sum+=A[i].ft;
		}
		else{
			sum+=A[i].ft;
			temp.clear();
			temp.pb(A[i].se);
		}
	}
	
	sort(all(temp));
	pp(temp.size());
	for(int v:temp)cout<<v<<" ";
	pp("");
	return;	
}


int32_t main() {
    fint{
    	solve();
    }
    return 0;
}
