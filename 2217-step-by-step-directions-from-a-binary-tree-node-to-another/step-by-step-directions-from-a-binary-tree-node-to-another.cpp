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
private:
    bool findPath(TreeNode* root, int tar, string& path){

        if(root == nullptr) return false;
        if(root->val == tar) return true;

        bool left = findPath(root->left,tar,path);
        if(left){
            path += 'L';
            return true;
        }

        bool right = findPath(root->right,tar,path);
        if(right){
            path += 'R';
            return true;
        }

        return false;

    }
public:
    string getDirections(TreeNode* root, int startValue, int destValue) {
        
        string pathRootToSt = "";
        findPath(root,startValue,pathRootToSt);

        string pathRootToDt = "";
        findPath(root,destValue,pathRootToDt);

        int i = pathRootToSt.size() - 1;
        int j = pathRootToDt.size() - 1;

        while(i>=0 && j>=0 && pathRootToSt[i] == pathRootToDt[j]){
            pathRootToSt.pop_back();
            pathRootToDt.pop_back();
            i--;
            j--;
        }

        i = pathRootToSt.size();

        for(int j=0; j<i; j++){
            pathRootToSt[j] = 'U';
        }

        reverse(pathRootToDt.begin(),pathRootToDt.end());

        return pathRootToSt + pathRootToDt;
    }
};