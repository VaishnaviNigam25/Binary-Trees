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
    void helper(vector<vector<int>>& ans,TreeNode* root)
    {
        queue<TreeNode*> level;
       
        
        level.push(root);
        while(!level.empty())
        {
             vector<int> vec;
            int n= level.size();
            for(int i=0;i<n;i++)
            {
                TreeNode* curr = level.front();
                vec.push_back(curr->val);
                
            
                if(curr->left)
                    level.push(curr->left);
                if(curr->right)
                    level.push(curr->right);
                level.pop();
            }
            
            ans.push_back(vec);
        }
        
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(!root)
            return {};
      vector<vector<int>> ans;
        helper(ans,root);
        return ans;
    }
};
