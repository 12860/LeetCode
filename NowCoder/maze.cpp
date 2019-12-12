#include<iostream>
#include<queue>
using namespace std;

int vis[100][100];
int g[100][100];
int m,n;
int dir[4][2]={{0,1},{0,-1},{1,0},{-1,0}};


struct Node{
    int x,y;
    int step;
    int pathx[100],pathy[100];
};
Node ans;

int main(){
    
    cin>>m>>n;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin>>g[i][j];
            vis[i][j]=0;
        }
            
    }
    Node in;
    in.x=0,in.y=0,in.step=0;
    in.pathx[0]=0;
	in.pathy[0]=0; //
    queue<Node> qq;
    qq.push(in);
    while(!qq.empty()){
        Node now=qq.front();
        qq.pop();
        //cout<<"test0  :"<<now.x<<"  "<<now.y<<endl;
        if(now.x==m-1&&now.y==n-1){
            ans=now;
            break;
        }
        for(int i=0;i<4;i++){
            int nx=now.x+dir[i][0];
            int ny=now.y+dir[i][1];
            if(nx>=0&&nx<m&&ny>=0&&ny<n&&g[nx][ny]==0&&vis[nx][ny]==0){
                Node next;
                next.x=nx,next.y=ny,next.step=now.step+1;
                next.pathx[next.step]=nx;
                next.pathy[next.step]=ny;
                qq.push(next);
                vis[nx][ny]=1;
            }
        }
    }//while
    int cnt=ans.step;
    //cout<<"cnt: "<<cnt<<endl;
    ans.pathy[0]=0;
    for(int i=0;i<=cnt;i++){
    	//cout<<"i :"<<i;
    	//cout<<"ii: "<<i<<endl;
        cout<<"("<<ans.pathx[i]<<","<<ans.pathy[i]<<")"<<endl;
    }
}
