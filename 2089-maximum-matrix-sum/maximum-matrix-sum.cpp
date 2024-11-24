class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        long long sum = 0, n = matrix.size(), cnt = 0, mini = INT_MAX;
        for(int row=0;row<n;row++){
            for(int col=0;col<n;col++){
                if(matrix[row][col]<0){
                    cnt++;
                }
                mini = min((long long)abs(matrix[row][col]), mini);
                sum+= abs(matrix[row][col]);
            }
        }
        if(cnt&1){
            sum-= (2*mini);
        }
        return sum;
    }
};