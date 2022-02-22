void level(Node* root,vector<int> &temp)
    {
        queue<Node*> q;
        q.push(root);
        while(!q.empty())
        {
            int size=q.size();
            for(int i=0;i<size;i++)
            {
                
                Node* node = q.front();
                //right view means the rightmmost nodes of each level(last node)
                if(i==0)
                    temp.push_back(node->val);
                if(node->left !=NULL)
                    q.push(node->left);
                 if(node->right!=NULL)
                    q.push(node->right);
                q.pop();
            }
        }
    }
    vector<int> leftView(Node *root)
{
  
        if(root==NULL)
            return {};
        vector<int> temp;
        //call the level order traversal
        level(root,temp);
        return temp;
    }

