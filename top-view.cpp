 if(root==NULL)
        return {};
         map<int,int> mp;
         queue<pair<Node*,int>> q;
         q.push(make_pair(root,0));
         while(!q.empty())
        {
            pair<Node*,int> temp = q.front();
            
            int hd=temp.second;
           Node* node =temp.first;
            
            //if there exists any value for a particular horizontal distance,thn do nothing
            if(mp.count(hd)==0)
            mp[hd]=node->data;
            
            if(node->left)
            q.push(make_pair(node->left,hd-1));
            if(node->right)
            q.push(make_pair(node->right,hd+1));
            
            q.pop();
            
        }
         vector<int> ans;
        for(auto i :mp)
        {
            ans.push_back(i.second);
        }
    
        return ans;
