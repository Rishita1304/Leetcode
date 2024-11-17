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
    // vector<int> answer;

    // void inorder(TreeNode* root){
    //     if(!root) return;
        
    //     inorder(root->left);
    //     answer.push_back(root->val);
    //     inorder(root->right);
        
    // }
    vector<int> inorderTraversal(TreeNode* root) {
        // inorder(root);
        vector<int> answer;
        TreeNode* cur = root;
        while(cur){
            if(!cur->left){
                answer.push_back(cur->val);
                cur=cur->right;
            }
            else{
                TreeNode* prev = cur->left;
                while(prev->right && prev->right!=cur){
                    prev = prev->right;
                }
                if(!prev->right){
                    prev->right = cur;
                    cur = cur->left;
                }
                else{
                    prev->right = NULL;
                    answer.push_back(cur->val);
                    cur = cur->right;
                }
            }
        }
        return answer;
    }
};