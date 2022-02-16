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
   int height(TreeNode* root){
       //if node is NULL then return 0
    if(root==NULL)
            return 0;
       //find left subtree height
        int lefth = height(root->left);
       //if at any node in left subtree it happens to that it is not balenced return -1
       if(lefth==-1) return -1;
       
       //find right subtree height
        int righth = height(root->right);
        //if at any node in right subtree it happens to that it is not balenced return -1
        if(righth==-1) return -1;
       
       
       //checking the condition for balenced tree
       /**a binary tree in which the left and right subtrees of every node differ in height by no more than 1.**/
        if(abs(lefth-righth)>1)
            return -1;
       
       //find the height of tree 
        return max(lefth,righth)+1;
       }
    bool isBalanced(TreeNode* root) {
       int ans = height(root);
        //not balanced
        if(ans==-1)
            return false;
        
        // balanced
        return true;
    }
};
