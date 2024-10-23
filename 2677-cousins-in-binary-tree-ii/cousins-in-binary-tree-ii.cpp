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
    TreeNode* replaceValueInTree(TreeNode* root) {
        root->val = 0;
        queue<TreeNode*> q; 
        q.push(root);
        while(!q.empty()){
            int n = q.size(), sum = 0;
            vector<TreeNode*> ans;
            while(n--){
                TreeNode* node = q.front(); q.pop();
                ans.push_back(node);
                if(node->left) {
                    q.push(node->left);
                    sum += node->left->val;
                }
                if(node->right){
                    q.push(node->right);
                    sum += node->right->val;
                }
            }
            for(auto node:ans){
                int temp = sum;
                if(node->left) temp -= node->left->val;
                if(node->right) temp -= node->right->val;
                if(node->left) node->left->val = temp;
                if(node->right) node->right->val = temp;
            }
        }
        return root;
    }
};