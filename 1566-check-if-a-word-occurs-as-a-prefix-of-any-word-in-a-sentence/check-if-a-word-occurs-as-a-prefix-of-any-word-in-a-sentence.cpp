class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        istringstream ss(sentence);
        string word;
        int ind = 1;
        
        while(ss >> word){
            if(word.find(searchWord) == 0) return ind;
            ind++;
        }
        return -1;
    }
};