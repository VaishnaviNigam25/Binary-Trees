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
    
     bool isSameTree(TreeNode* p, TreeNode* q) {
        
        
        /***Two binary trees are considered the same if they are structurally identical, and the nodes have the same value.*/
        
        // USING PREORDER TRAVERSAL//
        
        
      //if both/any one reaches NULL return after comparing
        if(p==NULL or q==NULL)
            return (p==q);//when only one is NULL return false,if both NULL return true
        
        //if the root,left & right all are identical for each node in both treeS, RETURN TRUE
        return ( p->val==q->val) and isSameTree(p->left,q->left) and isSameTree(p->right,q->right);
          
    }
    
    bool isSubtree(TreeNode* root, TreeNode* subroot) {
        if(root==NULL)
            return false;
          
        if(root->val ==  subroot->val)
        {    //check if root and subroot are identical trees,if not then we will check in left & right subtrees
       
          if( isSameTree(root,subroot))
              return true;
        }    
      //we check for in left & right subtree of the root and return trrue if we find in either of the two
       
         return  isSubtree(root->left,subroot)  or isSubtree(root->right,subroot);
            
        
        return false;
    }
};
