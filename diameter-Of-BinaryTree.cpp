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
    
    //DIAMETER  OF TREE MEANS MAXDISTANCE BETWEEN ANY TWO NODES OF THE TREE
    int height(TreeNode* root , int &dia)
    {
        //if node is null
        if(!root)
            return 0;
        //FINDING LEFT SUBTREE HEIGHT
        int lh =height(root->left,dia);
        //FINDING RIGHT SUBTYEE HEIGHT
        int rh =height(root->right,dia);
        
        //FINDING THE MAX diameter FOR THT particular ROOT NODE, AND STORING THAT IN "DIA"
        dia = max(dia,lh+rh); 
        
        //FIND THE height BY ADDING 1 TO THE MAX OF LEFT/RIGHT SUBTREE HEIGHT
        return max(rh,lh)+1;
        
        
    }
    
    
    int diameterOfBinaryTree(TreeNode* root) {
       //handling the edge case of empty tree
      int dia=0;
        
        //calling the height function which returns the diameter 
        height(root,dia);
        return dia;
    }
};
