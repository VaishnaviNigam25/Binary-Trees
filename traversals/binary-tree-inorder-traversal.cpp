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
public: void helper(vector<int> &traversal,TreeNode* root)
    {
        //BASE CONDITION
        if(root==NULL)
        {
            return;
        }
         // left root right
          helper(traversal,root->left);
    traversal.push_back(root->val);
       
        helper(traversal,root->right);
    }
    vector<int> inorderTraversal(TreeNode* root) {
       
        vector<int> traversal;
        helper(traversal,root);
        return traversal;
    }
       
};
