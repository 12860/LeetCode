//6. ZigZag Conversion

class Solution {
public:
    string convert(string s, int numRows) {

        if(numRows==1) return s;

        int rows = min(numRows,int(s.size()));
        vector<string> res(rows);

        int cur_row = 0;
        bool go_down = false;

        for(char c: s){
            res[cur_row] += c;
            if(cur_row==0||cur_row==numRows-1){
                go_down = !go_down;
            }
            cur_row += go_down?1:-1;
        }//for
        string ans;
        for (string row: res){
            ans += row;
        }
        return ans;
    }
};
