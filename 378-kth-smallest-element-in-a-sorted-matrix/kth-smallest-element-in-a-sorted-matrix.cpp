class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        priority_queue<int, vector<int>, greater<int>> min_heap;

        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                min_heap.push(matrix[i][j]);
            }
        }

        // k++;
        int cnt = 0;
        while(cnt!=k-1){
            min_heap.pop();
            cnt++;
        }
        return min_heap.top();
    }
};