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
    vector<int> answer;

    // void preorder(TreeNode* root){
    //     if(!root) return;

    //     answer.push_back(root->val);
    //     preorder(root->left);
    //     preorder(root->right);
    // }

    void iterative(TreeNode* root){
        if(!root) return;
        stack<TreeNode*> st;
        TreeNode* curr = root;
        while(curr || !st.empty()){
            if(curr){
                answer.push_back(curr->val);
                st.push(curr);
                curr = curr->left;
            }
            else{
                if(st.empty()) break;
                else{
                    TreeNode* top = st.top();
                    st.pop();
                    curr = top->right;
                }
            }
        }
    }
    vector<int> preorderTraversal(TreeNode* root) {
        // preorder(root);

        iterative(root);
        return answer;


    }
};