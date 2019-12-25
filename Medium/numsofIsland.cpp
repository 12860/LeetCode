class Solution {
public:
    /**
     * @param grid: a 2d boolean array
     * @param k: an integer
     * @return: the number of Islands
     */
    int vis[205][205];
    int dx[4]={1,-1,0,0};
    int dy[4]={0,0,1,-1};
    int ans=0;
    int R,C;
    int cnt=0;
    void dfs(int x,int y,int k,int s){
        for(int i=0;i<4;i++){
            int nx=x+dx[i];
            int ny=y+dy[i];
            if(nx>=0&&ny>=0&&nx<R&&ny<C&&vis[nx][ny]==1){
                vis[nx][ny]=0;
                cnt++;
                dfs(nx,ny,k,s+1);
                //vis[nx][ny]=1;
            }
        }//
        //if(s>=k) ans++;
        }

    int numsofIsland(vector<vector<bool>> &grid, int k) {
        // Write your code here
        R=grid.size();
        if(R==0) return 0;
        C=grid[0].size();
        if(C==0) return 0;
        
        for(int i=0;i<R;i++)
        for(int j=0;j<C;j++)
        vis[i][j]=grid[i][j];
        
        for(int i=0;i<R;i++){
            for(int j=0;j<C;j++){
                cnt=0;
                if(vis[i][j]==1){
                    vis[i][j]=0;
                    cnt++;
                    dfs(i,j,k,1);
                }
                if(cnt>=k) ans++;
            }
        }//
        return ans;
    }
};
