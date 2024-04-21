class Solution {
public:
    int myAtoi(string s) {
        int i=0;
        int n=s.size();
        bool sign = 1;
        long int ans=0;
        while(i<n && s[i]==' '){
            i++;
        }
        if(i==n) return 0;
        if(s[i]=='-'){
            sign = 0;
            i++;
        }
        else if(s[i]=='+'){
            i++;
        }
        while(i<n && s[i]>='0' && s[i]<='9'){
            ans=ans*10;
            if(ans>=INT_MAX || ans<=INT_MIN) break;
            ans += (s[i]-'0');
            i++;
        }
        if(sign==0) ans = -1*ans;
        if(ans>=INT_MAX) return INT_MAX;
        else if(ans<=INT_MIN) return INT_MIN;
        return (int)ans;
    }
};