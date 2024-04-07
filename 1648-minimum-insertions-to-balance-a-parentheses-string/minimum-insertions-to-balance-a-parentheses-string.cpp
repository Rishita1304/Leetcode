class Solution {
public:
    int minInsertions(string s) {
        stack<char>st;
		int count=0;
		for(int i=0;i<s.size();i++){
			if(s[i]=='(') st.push('(');
			else if(i+1<s.size() && s[i+1]==')'){
				if(st.empty())count++;
				else st.pop();
				i++;
			}
            else{
                if(!st.empty()){
                    st.pop();
                    count++;
                }
                else count+=2;
            }
        }
        if(!st.empty()) count+=2*st.size();
        return count;
    }
};