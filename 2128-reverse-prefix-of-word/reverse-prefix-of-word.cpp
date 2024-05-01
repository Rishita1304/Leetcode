class Solution {
public:
    string reversePrefix(string word, char ch) {
        string temp="";
        string ans="";
        int ind;
        for(int i=0;i<word.size();i++){
            if(word[i]==ch){
                temp+=word[i];
                reverse(temp.begin(), temp.end());
                ans+=temp;
                ind=i+1;
                break;
            }
            temp+=word[i];
        }
        while(ind<word.size()){
            ans+=word[ind];
            ind++;
        }
        return ans.size() ? ans : word;
    }
};