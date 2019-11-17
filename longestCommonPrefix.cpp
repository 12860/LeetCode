/*
 * @lc app=leetcode id=14 lang=cpp
 *
 * [14] Longest Common Prefix
 */

// @lc code=start
#include <string>
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int min_len=1000000;
        string min_str="";
        for(int i=0;i<strs.size();i++){
            if(strs[i].size()<min_len){
                min_len=strs[i].size();
                min_str=strs[i];
            }
        }
        for(int i=0;i<min_len;i++){
            string str=min_str.substr(0,min_len-i);
            int flag=0;
            for(int j=0;j<strs.size();j++){
                if(strs[j].find(str)==0) {
                    flag++;
                }
            }
            if(flag==strs.size()) return str;
        }
        return "";
    }
};
// @lc code=end

