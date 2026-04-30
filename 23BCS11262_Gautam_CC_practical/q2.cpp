#include <bits/stdc++.h>
using namespace std;

int tsp(vector<vector<int>>& cost){
    int n=cost.size();
    int N=1<<n;
    vector<vector<int>> dp(N,vector<int>(n,1e9));
    dp[1][0]=0;

    for(int mask=1;mask<N;mask++){
        for(int u=0;u<n;u++){
            if(mask&(1<<u)){
                for(int v=0;v<n;v++){
                    if(!(mask&(1<<v))){
                        int nmask=mask|(1<<v);
                        dp[nmask][v]=min(dp[nmask][v],dp[mask][u]+cost[u][v]);
                    }
                }
            }
        }
    }

    int ans=1e9;
    for(int u=0;u<n;u++){
        ans=min(ans,dp[N-1][u]+cost[u][0]);
    }
    return ans;
}

int main(){
    vector<vector<int>> cost = {{0, 111}, {112, 0}};
    int ans = tsp(cost);
    cout << ans << endl;
}