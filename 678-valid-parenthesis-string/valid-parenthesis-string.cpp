class Solution {
public:
    bool checkValidString(string s) {
        stack<char> ch, par;
        for(int c=0;s[c]!='\0';++c){
            if(s[c]=='('){
                par.push(c);
            }
            else if(s[c]=='*'){
                ch.push(c);
            }
            else{
                if(!par.empty()) par.pop();
                else if(!ch.empty()) ch.pop();
                else return false;
            }
        }
        while(!par.empty()){
            if(ch.empty()) return false;
            else if(par.top()<ch.top()){
                par.pop();
                ch.pop();
            }
            else return false;
        }
        return true;
    }
};