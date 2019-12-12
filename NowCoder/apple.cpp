#include<iostream>
#include<queue>
using namespace std;

int ma,np;

struct Node{
    int pan;  //pan left
    int apple;  //apple left
    int last;  // last used apple
};

int main(){
	while(cin>>ma>>np){
		    
    queue<Node> qq;
    Node st;
    st.pan=np,st.apple=ma,st.last=0;
    qq.push(st);
    int ans=0;
    int cnt=0;
    while(!qq.empty()){
    	cnt++;
    	//cout<<"cnt: "<<cnt<<endl;
    	//if(cnt>100) break;
        Node now=qq.front();
        qq.pop();
        //cout<<"pan: "<<now.pan<<"  ap: "<<now.apple<<endl;
        if(now.apple==0&&now.pan==0){
            ans++;
        }
        if(now.pan<=0) continue;
        for(int i=now.last;i<=ma;i++){
            if(i<=now.apple){
            	if(now.pan<=0) break;
                Node next;
                next.pan=now.pan-1;
                next.apple=now.apple-i;
                next.last=i;
                //cout<<"qq: "<<next.pan<<"  "<<next.apple<<" "<<i<<endl;
                //qq.push(next);
                if(next.pan==0&&next.apple!=0) continue;
                qq.push(next);
            }
        }
    }//while
    cout<<ans;
	}
}
