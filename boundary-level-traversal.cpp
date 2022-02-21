/************************************************************

    Following is the Binary Tree node structure:
    
    template <typename T>
    class TreeNode {
        public :
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~TreeNode() {
            if(left)
                delete left;
            if(right)
                delete right;
        }
    };

************************************************************/
void traverseleft(TreeNode<int>* root,vector<int>& ans)
{
    if(root==NULL)
        return;
    //if leaf return bcak
   if(root->left==NULL and root->right==NULL)
       return;
    //else keep storing and move leftwards
    ans.push_back(root->data);
    //if left node exists,go left
    if(root->left)
    traverseleft(root->left,ans);
    //else go right
    else
      traverseleft(root->right,ans);   
}
void traverseright(TreeNode<int>* root,vector<int>& ans)
{
    if(root==NULL)
        return;
    //if leaf return bcak
   if(root->left==NULL and root->right==NULL)
       return;
    //if right node exists,go right first
    if(root->right)
    traverseright(root->right,ans);
    //else go left
    else
      traverseright(root->left,ans);  
    //store while returning back,(revesre order)
    ans.push_back(root->data);
}
void traverseleaf(TreeNode<int>* root,vector<int>& ans)
{
    if(root==NULL)
        return;
    if(root->left==NULL and root->right==NULL)
        ans.push_back(root->data);
    
    traverseleaf(root->left,ans);
    traverseleaf(root->right,ans);
    
}
vector<int> traverseBoundary(TreeNode<int>* root){
   vector<int> ans;
    //push the root data in ans
    ans.push_back(root->data);
    
    //traverse left subtree nodes  except the leaf nodes
    traverseleft(root->left,ans);
    
 //traverse all the leaf nodes of left part
     traverseleaf(root->left,ans);
//traverse all the leaf nodes of right part
    traverseleaf(root->right,ans);
    
    //traverse all the right subtree nodes in reverse order except the leaf nodes
     traverseright(root->right,ans);
    
    return ans;
}
