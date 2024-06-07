class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n = boxes.size(), c=0, op=0;
        vector<int> ans(n);

        for(int i=0;i<n;i++){
            ans[i]+=op;
            if(boxes[i]=='1') c++;
            op+=c;
        }

        c=0; op=0;

        for(int i=n-1;i>=0;i--){
            ans[i]+=op;
            if(boxes[i]=='1') c++;
            op+=c;
        }

        return ans;
    }
};