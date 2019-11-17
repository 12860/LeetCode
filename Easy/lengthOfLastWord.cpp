/*
 * @lc app=leetcode id=58 lang=cpp
 *
 * [58] Length of Last Word
 */

// @lc code=start
class Solution {
public:
    int lengthOfLastWord(string s) {
        int len=s.size();
        if(len==0) return 0;  // 空串
        int begin=0,end=0;
        int cnt=0;
        for(int i=len-1;i>=0;i--){
            if(s[i]!=' '){
                end=i;
                break;
            }
            cnt++;
        }
        if(cnt==len) return 0; //全是空格
        for(int j=end-1;j>=0;j--){
            if(s[j]==' '){
                begin=j+1;
                break;
            }
        }
        //if(begin==end) return 0;
        return end-begin+1;
    }
};
// @lc code=end

