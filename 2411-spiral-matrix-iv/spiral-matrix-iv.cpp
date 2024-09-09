class Solution {
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>> ans(m, vector<int>(n, -1)); // Initialize with -1
        int rs = 0, re = m - 1, cs = 0, ce = n - 1;
        ListNode* temp = head;
        
        while (rs <= re && cs <= ce) {
            // Fill the top row
            for (int i = cs; i <= ce; i++) {
                if (temp) {
                    ans[rs][i] = temp->val;
                    temp = temp->next;
                } else {
                    ans[rs][i] = -1;
                }
            }
            rs++;
            
            // Fill the right column
            for (int i = rs; i <= re; i++) {
                if (temp) {
                    ans[i][ce] = temp->val;
                    temp = temp->next;
                } else {
                    ans[i][ce] = -1;
                }
            }
            ce--;
            
            // Fill the bottom row (if still within bounds)
            if (rs <= re) {
                for (int i = ce; i >= cs; i--) {
                    if (temp) {
                        ans[re][i] = temp->val;
                        temp = temp->next;
                    } else {
                        ans[re][i] = -1;
                    }
                }
                re--;
            }
            
            // Fill the left column (if still within bounds)
            if (cs <= ce) {
                for (int i = re; i >= rs; i--) {
                    if (temp) {
                        ans[i][cs] = temp->val;
                        temp = temp->next;
                    } else {
                        ans[i][cs] = -1;
                    }
                }
                cs++;
            }
        }
        
        return ans;
    }
};
