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
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root==NULL)
            return false;
        //if at leaf node the target happens to be zero,path is found
        if(root->left==NULL and root->right==NULL)
        {
            if(targetSum-root->val==0)
                return true;
            else 
                return false;
        }
        
        //either the left subtree has the target sum
       bool leftpath = hasPathSum(root->left,targetSum-root->val);
        
        
        //or the right subtree has the targets sum path
         bool rightpath = hasPathSum(root->right,targetSum-root->val);
       
        //if both donot have target sum as 0, then path not found
        if(leftpath || rightpath)
            return true;
        else 
            return false;
    }
};
