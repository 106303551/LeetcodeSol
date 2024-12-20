class Solution {
public:
    int integerBreak(int n) {
        vector<int> dp(n+1,0);
        dp[2]=1;
        if(n==2)return 1;
        for(int i =3; i<n+1; i++){
            for(int j =1; j<i; j++){
                dp[i] = max(max(dp[i-j]*j,j*(i-j)),dp[i]);
            }
        }
        return dp[n];
    }
};