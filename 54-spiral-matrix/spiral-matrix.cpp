class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int rs = 0;
        int re = matrix.size()-1;
        int cs = 0;
        int ce = matrix[0].size()-1;

        vector<int> ans;

        while(rs<=re && cs<=ce){
            for(int i=cs;i<=ce && rs<=re;i++){
                ans.push_back(matrix[rs][i]);
            }
            rs++;
            for(int i=rs;i<=re && cs<=ce;i++){
                ans.push_back(matrix[i][ce]);
            }
            ce--;
            for(int i=ce;i>=cs && rs<=re;i--){
                ans.push_back(matrix[re][i]);
            }
            re--;
            for(int i=re;i>=rs && cs<=ce;i--){
                ans.push_back(matrix[i][cs]);
            }
            cs++;
        }
        return ans;
    }
};