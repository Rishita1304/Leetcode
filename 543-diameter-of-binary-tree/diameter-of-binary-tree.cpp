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
    int maxi = INT_MIN;
    int solve(TreeNode* root, int& maxi){
        if(root==NULL){
            return 0;
        }
        int l = solve(root->left, maxi);
        int r = solve(root->right, maxi);

        maxi = max(maxi, l+r);
        return 1+max(l, r);

    }    
    int diameterOfBinaryTree(TreeNode* root) {
        solve(root,maxi);
        return maxi;
    }
};