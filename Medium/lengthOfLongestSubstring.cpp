
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int mlen = 0;
        int left = 0;
        string str = "";
        int cnt = 0;
        for(int i=0;i<s.size();i++){
            if(str.find(s[i],left)!=-1){//找到重复
                //if(cnt>mlen) mlen=cnt;
                mlen = mlen>str.size()?mlen:str.size();
                cnt = 0;
                i = s.find_first_of(s[i],left);
                left = i+1;
                str = "";
            }
            else{//没有找到重复的
                cnt++;
                str =str+ s[i];
            }
        }//for
        //if(cnt>mlen) mlen = cnt;
        mlen = mlen>str.size()?mlen:str.size();
        return mlen;
    }
};


class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int mlen = 0;
        int left = 0;
        int m[256]={0};
        for(int i=0;i<s.size();i++){
            if(m[s[i]]==0||m[s[i]]<left){//之前没有找到
                mlen = max(mlen,i-left+1);
            }
            else{
                left = m[s[i]];
            }
            m[s[i]] = i+1;
        }
        return mlen;
    }
};
