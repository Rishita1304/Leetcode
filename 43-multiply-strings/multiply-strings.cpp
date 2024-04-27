class Solution {
public:
    string multiply(string num1, string num2) {
        if(num1=="0" || num2=="0") return "0";
        string s1 = "";
        string s2 = "";
        if(num1[0] == '-'){
            s1 = "-";
            num1 = num1.substr(1);
        }
        if(num2[0] == '-'){
            s2 = "-";
            num2 = num2.substr(1);
        }
        if(s2 == "-" && s1 == "-") s1=s2="";

        int n=num1.size();
        int m=num2.size();
        string ans(n+m, '0');

        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                int num = (num1[i]-'0')*(num2[j]-'0') + (ans[i+j+1]-'0');
                ans[i+j+1] = num%10+'0';
                ans[i+j] += num/10;
            }
        }
        int i=0;
        while(i<ans.size() && ans[i]=='0') i++;
        return s1+s2+ans.substr(i);
    }
};