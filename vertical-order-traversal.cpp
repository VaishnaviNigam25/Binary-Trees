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
    void vertical(TreeNode* root,vector<vector<int>> &ans)
    {
        map<int,map<int,multiset<int>>> nodes;
        queue<pair<TreeNode*,pair<int,int>>> q;
        q.push(make_pair(root,make_pair(0,0)));
        
        if(root==NULL)
            return;
        while(!q.empty())
        {
           pair<TreeNode*,pair<int,int>> front = q.front();
            TreeNode* temp = front.first;
            int hd =front.second.first;
            int ld =front.second.second;
            nodes[hd][ld].insert(temp->val);
            q.pop();
            if(temp->left)
                q.push(make_pair(temp->left,make_pair(hd-1,ld+1)));
             if(temp->right)
                q.push(make_pair(temp->right,make_pair(hd+1,ld+1)));
            
        }
        for(auto i :nodes)
        {
            vector<int> vec;
            for(auto j:i.second)
            {
               
                for(auto k:j.second)
                    
                {  vec.push_back(k);
                  
                }
            }
           
            ans.push_back(vec);
        }
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
         vector<vector<int>> ans;
        vertical(root,ans);
        return ans;
    }
};
