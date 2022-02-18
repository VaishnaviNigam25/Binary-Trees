/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        //whenver you find P or Q or Null return Root itself
        if(root==NULL or root==p or root==q)
        return root;
       //ELSE GO TO LEFT SUBTREE
        TreeNode* left = lowestCommonAncestor(root->left,p,q);
         //ELSE GO TO RIGHT SUBTREE
         TreeNode* right = lowestCommonAncestor(root->right,p,q);
        //if left return NULL, return Right
        if(!left)
            return right;
        //if right return NULL, return left
        
        if(!right)
            return left;
    
    //IF BOTH LEFT AND RIGHT ARE NON -NULL MEANS THIS ROOT IS THE LCA OF P & Q
        else    
        return root;
        
    }
};
