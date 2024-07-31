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
    bool isIdentical(TreeNode* p, TreeNode* q){
        if(!p && !q) return true;
        if( p && !q) return false;
        if(!p &&  q) return false;

        bool left = isIdentical(p->left, q->left);
        bool right = isIdentical(p->right, q->right);

        bool samevalue = p->val == q->val;

        if(left & right & samevalue) return true;
        else return false;
    }
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        return isIdentical(p, q);
    }
};