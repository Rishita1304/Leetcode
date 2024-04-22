class Solution {
public:
    void fill(queue<string> &q, string &curr, unordered_set<string> &st){
        for(int i=0;i<4;i++){
            char ch = curr[i];
            char inc = ch=='9' ? '0' : ch+1;
            char dec = ch=='0' ? '9' : ch-1;

            curr[i] = dec;
            if(st.find(curr)==st.end()){
                st.insert(curr);
                q.push(curr);
            }

            curr[i] = inc;
            if(st.find(curr)==st.end()){
                st.insert(curr);
                q.push(curr);
            }
        
            curr[i] = ch;
        }
    }
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> st(deadends.begin(), deadends.end());
        string start = "";
        if(st.find("0000")==st.end()) start = "0000";
        else return -1;
        queue<string> q;
        q.push(start);
        int level = 0;
        while(!q.empty()){
            int size = q.size();
            while(size--){
                string front = q.front(); q.pop();
                if(front==target) return level;

                fill(q,front,st);
            }
            level++;
        }
        return -1;
    }
};