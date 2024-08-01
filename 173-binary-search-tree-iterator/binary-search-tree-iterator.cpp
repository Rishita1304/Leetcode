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
class BSTIterator {
public:
    int cur=0, pos=0,ans[10001];
    void dfs(TreeNode* root){
        if(!root) return;
        dfs(root->left);
        ans[pos++] = root->val;
        dfs(root->right);
    }
    BSTIterator(TreeNode* root) {
        dfs(root);
    }
    
    int next() {
        return ans[cur++];
    }
    
    bool hasNext() {
        return cur < pos;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */