class Solution {
private:
    vector<int> nextSmaller(vector<int>& heights) {
        int n=heights.size();
        stack<int> s;
        vector<int> ans(n);
        s.push(-1);
        for(int i=n-1;i>=0;i--){
            int cur = heights[i];
            while(s.top() != -1 && heights[s.top()]>=cur){
                s.pop();
            }
            ans[i] = s.top();
            s.push(i);
        }
        return ans;
    };
        vector<int> prevSmaller(vector<int>& heights ) {
        int n=heights.size();
        stack<int> s;
        vector<int> ans(n);
        s.push(-1);
        for(int i=0;i<n;i++){
            int cur = heights[i];
            while(s.top() != -1 && heights[s.top()]>=cur){
                s.pop();
            }
            ans[i] = s.top();
            s.push(i);
        }
        return ans;
    };

    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<int> s;
        int ans=INT_MIN;
        vector<int> prev(n,0);
        prev = prevSmaller(heights);
        vector<int> next(n,0);
        next = nextSmaller(heights);
        for(int i=0;i<n;i++){
            int l = heights[i];
            if(next[i]==-1){
                next[i]=n;
            }
            int b = next[i]-prev[i]-1;
            int newArea = l*b; 
            ans = max(ans, newArea);
        }
        return ans;
    };

public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        vector<int>histogram(matrix[0].size(),0);

        int maxi= INT_MIN; 
        for(int i=0;i<matrix.size();i++)
        {
            for(int j=0;j<matrix[0].size();j++)
            {
                if(matrix[i][j]=='1') histogram[j]++;
                else histogram[j]=0;
            }
            maxi= max(maxi,largestRectangleArea(histogram));
        }
        return maxi;
    }
};