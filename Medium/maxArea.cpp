# 11. Container With Most Water

class Solution {
public:
    int maxArea(vector<int>& v) {
        int len = v.size();
        int max_area = 0;
        int l = 0, r = len-1;
        while(l<r){
            max_area = max(max_area, min(v[l], v[r]) *(r-l) );
            if(v[l]< v[r]) l++;
            else r--;
        }
        return max_area;
    }
};
