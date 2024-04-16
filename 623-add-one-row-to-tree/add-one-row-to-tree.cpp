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
    TreeNode* solve(TreeNode* root, int val, int depth, int level){
        if(root==NULL) return root;
        level++;
        if(level==depth){
            TreeNode* leftNode = new TreeNode(val);
            leftNode->left = root->left;
            root->left = leftNode;

            TreeNode* rightNode = new TreeNode(val);
            rightNode->right = root->right;
            root->right = rightNode;
            return root;
        }
        solve(root->left, val, depth, level);
        solve(root->right, val, depth, level);
        return root;
    }
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth==1){
            TreeNode* node = new TreeNode(val);
            node->left = root;
            return node;
        }
        return solve(root, val, depth, 1);
    }
};