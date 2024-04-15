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
    int sumNodes(TreeNode* root, int curr){
        if(root==NULL) return 0;
        curr = curr*10 + root->val;
        if(root->left==NULL && root->right==NULL) return curr;

        int leftSum = sumNodes(root->left, curr);
        int rightSum = sumNodes(root->right, curr);
        return leftSum+rightSum;
    }
    int sumNumbers(TreeNode* root) {
        return sumNodes(root, 0);
    }
};