class Solution {
public:
    vector<string> solve(string s){
        vector<string> words;
        string word = "";
        for(char c:s){
            if(c==' '){
                if(!word.empty()){
                    words.push_back(word);
                    word = "";
                }
            }
            else{
                word += c;
            }
        }
        if(!word.empty()) words.push_back(word);
        return words;
    }
    bool areSentencesSimilar(string sentence1, string sentence2) {
        vector<string> w1 = solve(sentence1);
        vector<string> w2 = solve(sentence2);

        if(w1.size() < w2.size()) swap(w1, w2);

        int start = 0, end = 0;
        int n1 = w1.size(), n2 = w2.size();

        while(start< n2 && w1[start] == w2[start]) start++;

        while(end< n2 && w1[n1-end-1] == w2[n2-end-1]) end++;

        return start + end >= n2;
    }
};