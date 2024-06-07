class Solution {
public:
    string solve(string word, unordered_set<string> &st){
        for(int i=1;i<word.size();i++){
            string root = word.substr(0,i);
            if(st.count(root)){
                return root;
            }
        }
        return word;
    }
    string replaceWords(vector<string>& dic, string s) {
        unordered_set<string> st(dic.begin(), dic.end()); 
        stringstream ss(s);
        string word;
        string result;

        while(getline(ss, word, ' ')){
            result+= solve(word,st) + " ";
        }
        result.pop_back();
        return result;
    }
};