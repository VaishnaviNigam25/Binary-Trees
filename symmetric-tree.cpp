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
    bool check(TreeNode* leftnode,TreeNode* rightnode){
        
        //if any of them gets NULL, other has to be null or else return false
        if(leftnode==NULL or rightnode==NULL)
            return leftnode==rightnode;
        //if at any point the values donot match the symmetry, return false 
        if(leftnode->val!=rightnode->val)
            return false;
        //check the same in root's left and right simultaneously
        return check(leftnode->left,rightnode->right) and check(leftnode->right,rightnode->left);
        
    }
    bool isSymmetric(TreeNode* root) {
     if(root == NULL)
         return true;
        
        return check(root->left,root->right);
    }
};
