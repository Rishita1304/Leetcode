class Solution {
public:
    int residuePrefixes(string s) {
        set<char> st;
        int i=0;
        int j=1;
        int count=0;
        while(j<=s.size()){
            string str = s.substr(i,j);
            for(int k=0;k<str.size();k++){
                st.insert(str[k]);
            }
            if(st.size() == (str.size()%3)){
            count++;
            } 
            st.clear();
            j++;
        }
        return count;
    }
};