
struct Node{
    int rr,cc,step;
    Node(int x,int y,int z):rr(x),cc(y),step(z) {};
};

class Solution {
public:
    /**
     * @param Maze: 
     * @return: nothing
     */
    int sr,sc,er,ec;
    int vis[205][205];
    int dx[4]={-1,1,0,0};
    int dy[4]={0,0,1,-1};
    int Portal(vector<vector<char>> &maze) {
        // 
        int n=maze.size();
        int m=maze[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(maze[i][j]=='S'){
                    sr=n,sc=m;
                }
                if(maze[i][j]=='E'){
                    er=n,ec=m;
                }
                vis[i][j]=0;
            }
        }//
        Node s=Node(sr,sc,0);
        queue<Node> qq;
        qq.push(s);
        while(!qq.empty()){
            Node now=qq.front();
            qq.pop();
            int tr=now.rr,tc=now.cc;
            for(int i=0;i<4;i++){
                int nr=tr+dx[i];
                int nc=tc+dy[i];
                //if(nr==er&&nc==ec)
                if(maze[nr][nc]=='E')
                {
                    return now.step+1;
                }
                if(nr>=0&&nc>=0&&nr<n&&nc<m&&vis[nr][nc]==0&&maze[nr][nc]=='*'){
                    qq.push(Node(nr,nc,now.step+1));
                }
            }
        }//
        return -1;
    }
};
