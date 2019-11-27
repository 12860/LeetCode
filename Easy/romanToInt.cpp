class Solution {
public:
    int romanToInt(string s) {
        int len = s.size();
        int sum=0;
        for(int i=0;i<len;i++){
            if(s[i]=='I'){
                if(i+1<len&&s[i+1]=='V') sum-=1;
                else if(i+1<len&&s[i+1]=='X') sum--;
                else sum++;
            }
            if(s[i]=='V') sum+=5;
            if(s[i]=='X'){
                if(i+1<len&&s[i+1]=='L') sum-=10;
                else if(i+1<len&&s[i+1]=='C') sum-=10;
                else sum+=10;
            }
            if(s[i]=='L') sum+=50;
            if(s[i]=='C'){
                if(i+1<len&&s[i+1]=='D') sum-=100;
                else if(i+1<len&&s[i+1]=='M') sum-=100;
                else sum+=100;
            }
            if(s[i]=='D') sum+=500;
            if(s[i]=='M') sum+=1000;
        }
        return sum;
    }
};
