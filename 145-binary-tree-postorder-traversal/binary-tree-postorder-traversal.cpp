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

       //recursive
//     vector<int> answer;

//     void postorder(TreeNode* root){
//         if(!root) return;
        
//         postorder(root->left);
//         postorder(root->right);
        
//         answer.push_back(root->val);
//     }
//     vector<int> postorderTraversal(TreeNode* root) {
//         postorder(root);
//         return answer;
//     }
// };


vector<int> postorderTraversal(TreeNode* root) {
    vector<int> ans;
    stack<TreeNode*> st;
    TreeNode* prev = NULL;
    while (root || !st.empty()) {
      while (root) {
        st.push(root);
        root = root->left;
      }

      auto curr = st.top();
      if (!curr->right || curr->right == prev) {
        ans.push_back(curr->val);
        st.pop();
        prev = curr;
      }
      else {
        root = curr->right;
      }
    }
    return ans;
    }
};