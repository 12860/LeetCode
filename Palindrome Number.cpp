/*
 * @lc app=leetcode id=9 lang=cpp
 *
 * [9] Palindrome Number
 */

// @lc code=start
class Solution {
public:
    bool isPalindrome(int x) {
        string s = std::to_string(x);
        if(x>=0){
            int len = s.size();
            for(int i=0;i<len;i++){
                int j= len-1-i;
                if(s[i]!=s[j]) return 0;
            }
            return 1;
        }
        return 0;
    }
};
// @lc code=end

