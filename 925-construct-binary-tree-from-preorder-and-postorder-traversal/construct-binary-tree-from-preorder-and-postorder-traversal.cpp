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
    int ind = 0;

    int search(vector<int>& post, int start, int end, int temp){
        for(int i=start ;i<=end ;i++) if(post[i] == temp) return i;
        return -1;
    }

    TreeNode* solve(vector<int>& pre, vector<int>& post, int start, int end){
        if(start > end || ind >= pre.size()) return NULL; //out of bound

        TreeNode* root = new TreeNode(pre[ind++]);
        if(ind >= pre.size() || start == end) return root; //completed

        int p = search(post, start, end, pre[ind]); //search the index

        root->left = solve(pre, post, start, p);
        root->right = solve(pre, post, p+1, end-1);

        return root;
    }
    TreeNode* constructFromPrePost(vector<int>& pre, vector<int>& post) {
        int n = pre.size();
        return solve(pre, post, 0, n-1);
    }
};