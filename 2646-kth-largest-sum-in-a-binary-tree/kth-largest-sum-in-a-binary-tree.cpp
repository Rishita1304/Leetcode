/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    long long kthLargestLevelSum(TreeNode* root, int k) {
        vector<long long> ans;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            long long temp=0; 
            int size = q.size();
            while(size--){
                auto node = q.front();
                q.pop();
                temp+=node->val;
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            ans.push_back(temp);
        }
        if(k > ans.size()) return -1;
        sort(ans.begin(), ans.end(), greater<long long>());
        return ans[k-1];
    }
};