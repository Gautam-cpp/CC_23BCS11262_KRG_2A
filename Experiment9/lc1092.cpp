class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        int n=str1.size(), m=str2.size();
        
        vector<vector<int>>dp(n+1, vector<int>(m+1, 0));
        
        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                if(str1[i-1]==str2[j-1]) dp[i][j]=1+dp[i-1][j-1];
                else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
        string ans="";
        while(n>0 && m>0){
            if(str1[n-1]==str2[m-1]){
                ans+=str1[n-1];
                n--; m--;
            }
            else if(dp[n-1][m] > dp[n][m-1]){
                ans+=str1[n-1];
                n--;
            }
            else{
                ans+=str2[m-1];
                m--;
            }

        }
        while(n>0){ans+=str1[n-1];n--;}
        while(m>0){ans+=str2[m-1];m--;}
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
