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
    void level(TreeNode* root,vector<int> &temp)
    {
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            int size=q.size();
            for(int i=0;i<size;i++)
            {
                
                TreeNode* node = q.front();
                //right view means the rightmmost nodes of each level(last node)
                if(i==size-1)
                    temp.push_back(node->val);
                if(node->left !=NULL)
                    q.push(node->left);
                 if(node->right!=NULL)
                    q.push(node->right);
                q.pop();
            }
        }
    }
    vector<int> rightSideView(TreeNode* root) {
        if(root==NULL)
            return {};
        vector<int> temp;
        //call the level order traversal
        level(root,temp);
        return temp;
    }
};
