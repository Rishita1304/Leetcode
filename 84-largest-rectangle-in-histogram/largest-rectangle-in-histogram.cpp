class Solution {
public:
    vector<int> nse(vector<int>& heights) {
        int n=heights.size(); vector<int> ans(n);
        stack<int> s; s.push(-1);

        for(int i=n-1;i>=0;i--){
            int cur = heights[i];
            //we want next smaller 
            //so we will pop until we are getting the top as > current
            while(s.top() != -1 && cur<=heights[s.top()]) s.pop();            
            ans[i] = s.top();
            s.push(i);
        }
        return ans;
    };
        vector<int> pse(vector<int>& heights ) {
        int n=heights.size(); vector<int> ans(n);
        stack<int> s; s.push(-1);

        for(int i=0;i<n;i++){
            int cur = heights[i];
            //again we want the prev SMALLER
            //so we will pop until we are getting a greater element in the stack
            while(s.top() != -1 && cur<=heights[s.top()]) s.pop();
            ans[i] = s.top();
            s.push(i);
        }
        return ans;
    };

    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        int ans=INT_MIN;
        vector<int> prev(n,0), next(n,0);
        prev = pse(heights);
        next = nse(heights);

        for(int i=0;i<n;i++){
            if(next[i]==-1) next[i]=n;  

            int l = heights[i];
            int b = next[i]-prev[i]-1;
            int newArea = l*b; 
            ans = max(ans, newArea);
        }
        return ans;
    }
};