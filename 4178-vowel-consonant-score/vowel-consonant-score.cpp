class Solution {
public:
    bool isVowel(char c){
        string str = "aeiou";
        if(str.contains(c)) return true;
        return false;
    }
    int vowelConsonantScore(string s) {
        int vowel = 0;
        int con = 0;
        for(char c:s){
            if(isalpha(c)){
                if(isVowel(c)) vowel++;
                else con++;
            }
        }
        if(con == 0) return 0;
        else return floor(vowel/con);
        
    }
};