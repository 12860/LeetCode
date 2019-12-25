class Solution {
public:
    /**
     * @param grid: a list of lists of integers
     * @return: An integer, minimizes the sum of all numbers along its path
     */
    //int dp[110][110];
    int minPathSum(vector<vector<int>> &grid) {
        // write your code here
        int m=grid.size();
        if(m==0) return 0;
        int n=grid[0].size();
        if(n==0) return 0;
        
        vector<vector<int> > dp(m,vector<int>(n));
        dp[0][0]=grid[0][0];
        //if(n>1) dp[0][1]=dp[0][0]+grid[0][1];
        //if(m>1) dp[1][0]=dp[0][0]+grid[1][0];
        for(int i=1;i<n;i++){
            dp[0][i]=dp[0][i-1]+grid[0][i];
        }
        for(int i=1;i<m;i++){
            dp[i][0]=dp[i-1][0]+grid[i][0];
        }//
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                dp[i][j]=min(dp[i-1][j],dp[i][j-1])+grid[i][j];
            }
        }
        return dp[m-1][n-1];
    }
};
