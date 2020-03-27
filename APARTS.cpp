// Problem : Washing Windows
// Contest : CodeChef - November Lunchtime 2019 Division 1
// URL : https://www.codechef.com/LTIME78A/problems/APARTS
// Memory Limit : 256 MB
// Time Limit : 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)
//#pragma GCC optimize "trapv"//  WA to RE int!!
#include<bits/stdc++.h>
using namespace std;
int T , n , m , dp[1003][1003] , timestamp[1003][1003] , ans[1003][1003];
int main(){
    scanf("%d",&T);
    while(T--){
        scanf("%d %d",&n,&m);
        for(int j = 1 ; j <= n ; j++){
            for(int i = 1 ; i <= m ; i++){
 
                scanf("%d",&timestamp[j][i]);
 
                dp[j][i] = max(0 , max(dp[j-1][i-1] , max(dp[j-1][i] , dp[j-1][i+1])));
 
                if(dp[j][i] > timestamp[j][i])
                    ans[j][i] = 0;
                else ans[j][i] = 1;
 
                dp[j][i] = max(dp[j][i] , timestamp[j][i]);
            }
        }
 
        for(int j = 1 ; j <= n ; j++){
            for(int i = 1 ; i <= m ; i++){
                dp[j][i] = 0;
                printf("%d",ans[j][i]);
            }
            puts("");
        }
    }
 
} 