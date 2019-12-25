#include<iostream>
using namespace std;
int n,m;
int g[110][110];
int dis[110];
int vis[110];

int main(){
    int a,b,c;
    while(cin>>n>>m){
        if(n==0&&m==0) break;
        //memset(g,0,sizeof(g))
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                g[i][j]=1001001;
                g[j][i]=1001001;
            }
        }
        for(int i=0;i<m;i++){
            cin>>a>>b>>c;
            g[a][b]=c;
            g[b][a]=c;
        }//
        for(int i=1;i<=n;i++){
            vis[i]=0;
            //if(g[1][i+1]==0) g[1][i]=1001001;
            dis[i]=g[1][i];
        }
        vis[1]=1;
        for(int i=1;i<n;i++){
            int tmp=10010005,flag=1;
            for(int j=1;j<=n;j++){
                if(vis[j]==0&&dis[j]<tmp){
                    tmp=dis[j];
                    flag=j;
                }//if
            }
            vis[flag]=1;
            for(int j=1;j<=n;j++){
                if(j==flag||j==1||g[flag][j]==1001001) continue;
                if(dis[flag]+g[flag][j]<dis[j]){
                    dis[j]=dis[flag]+g[flag][j];
                }
            }
        }//
        cout<<dis[n]<<endl;
    }//while
}
