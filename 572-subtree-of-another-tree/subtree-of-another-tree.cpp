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
    bool isSame(TreeNode* root, TreeNode* s){
        if(!root || !s) return !root && !s;
        else if(root->val == s->val) return isSame(root->left, s->left) && isSame(root->right, s->right);
        else return false;
    }
    bool isSubtree(TreeNode* root, TreeNode* s) {
        if(!root) return false;
        else if(isSame(root,s)) return true;
        else return isSubtree(root->left, s) || isSubtree(root->right, s);
    }
};