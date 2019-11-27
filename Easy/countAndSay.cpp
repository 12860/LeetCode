class Solution {
public:
    string countAndSay(int n) {
        if(n==1) return "1";
        string last = countAndSay(n-1);
        int cnt=0;
        char cur=last[0];
        string ans="";
        for(int i=0;i<last.size();i++){
            if(cur!=last[i]){
                ans.append(to_string(cnt));
                ans.append(to_string(int(cur-'0')));
                //cout<<"ans "<<ans<<endl;
                cur = last[i];
                cnt = 1;
            }
            else cnt++;
        }//got
        ans.append(to_string(cnt)+to_string(int(cur-'0')));
        return ans;
    }
};
