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
#define null nullptr
#define l left
#define r right
class Solution {
public:
    TreeNode* rrot (TreeNode* root){
        if(root==null) return null;
        TreeNode* x = root->l;
        root->l=x->r;
        x->r=root;
        root=x;
        return root;
    }
    
    TreeNode* lrot (TreeNode* root){
        if(root==null) return null;
        TreeNode* x = root->r;
        root->r=x->l;
        x->l=root;
        root=x;
        return root;
    }
    
    int height (TreeNode* root){
        if(root==null) return -1;
        return 1 + max(height(root->l),height(root->r));
    }
    
    TreeNode* helper (TreeNode* root){
        if (root==null) return null;
        root->l=helper(root->l);
        root->r=helper(root->r);
        int l = height(root->l), r = height(root->r);
        int bf = l -r ;
        if(bf > 1){
            if (height(root->l->l)<height(root->l->r)){
                root->l=lrot(root->l);
            }
            return helper(rrot(root));
        }else if (bf<-1){
            if (height(root->r->r)<height(root->r->l)){
                root->r=rrot(root->r);
            }
            return helper(lrot(root));
        }
        return root;
    }
    
    TreeNode* balanceBST(TreeNode* root) {
        if(root==null) return root;
        return helper(root);
    }
};