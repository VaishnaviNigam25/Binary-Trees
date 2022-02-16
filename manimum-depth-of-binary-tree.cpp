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
    int minDepth(TreeNode* root) {
        //when root itself is null
        if(root==NULL)
            return 0;
        //when it is a leaf node
        if(root->left==NULL and root->right==NULL)
            return 1;
        //if left subtree doesnot exists
        if(root->left==NULL)
          return 1+  minDepth(root->right);
        //if right subtree doesnot exists
        if(root->right==NULL)
             return 1 + minDepth(root->left);
        
        //when it has both left and right subnodes
        return min(minDepth(root->left),minDepth(root->right))+1;
    }
};
