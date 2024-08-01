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
    vector<TreeNode*> solve(int s, int e){
        if(s>e) return {NULL};
        vector<TreeNode*> ans;
        for(int i=s;i<=e;i++){
            vector<TreeNode*> left = solve(s, i-1);
            vector<TreeNode*> right = solve(i+1,e);

            for(auto l: left){
                for(auto r:right){
                    TreeNode* curr = new TreeNode(i);
                    curr->left = l;
                    curr->right = r;
                    ans.push_back(curr);
                }
            }
        }
        return ans;
    }
    vector<TreeNode*> generateTrees(int n) {
        return n? solve(1,n) : vector<TreeNode*>();
    }
};