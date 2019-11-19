/*
 * @lc app=leetcode id=20 lang=cpp
 *
 * [20] Valid Parentheses
 *
 * https://leetcode.com/problems/valid-parentheses/description/
 *
 * algorithms
 * Easy (37.57%)
 * Likes:    3625
 * Dislikes: 175
 * Total Accepted:    757.5K
 * Total Submissions: 2M
 * Testcase Example:  '"()"'
 *
 * Given a string containing just the characters '(', ')', '{', '}', '[' and
 * ']', determine if the input string is valid.
 * 
 * An input string is valid if:
 * 
 * 
 * Open brackets must be closed by the same type of brackets.
 * Open brackets must be closed in the correct order.
 * 
 * 
 * Note that an empty string is also considered valid.
 * 
 * Example 1:
 * 
 * 
 * Input: "()"
 * Output: true
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: "()[]{}"
 * Output: true
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: "(]"
 * Output: false
 * 
 * 
 * Example 4:
 * 
 * 
 * Input: "([)]"
 * Output: false
 * 
 * 
 * Example 5:
 * 
 * 
 * Input: "{[]}"
 * Output: true
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    bool isValid(string s) {
        int len = s.size();
        //if(len==0) return false;
        //cout<<"len: "<<len;
        if(len%2) return false;
        stack<char> st;
        for(int i=0;i<len;i++){
            char c= s[i];
            if(c ==')' || c==']' || c=='}'){
                if(st.size()==0) return false;
                if(c==')' && st.top()!='(') return false;
                if(c==']' && st.top()!='[') return false;
                if(c=='}' && st.top()!='{') return false;
                st.pop();
            }
            else{
                st.push(c);
            }
        }
        if(st.size()==0) return true;
        return false;
    }
};
// @lc code=end

