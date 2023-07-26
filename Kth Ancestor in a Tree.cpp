void find(unordered_map<int,int>&mp,Node*root,int node,int parent){
    
    if(root==NULL) return;
    
    mp[root->data]=parent;
    
    if(root->data==node) return;
    
    find(mp,root->left,node,root->data);
    find(mp,root->right,node,root->data);
    
}

int kthAncestor(Node *root, int k, int node)
{
    // searching for the node and storing parent of each node in an unordered map.
    unordered_map<int,int>mp;
    find(mp,root,node,-1);
    
    int ans=0;
    
    while(k--){
        ans=mp[node];
        node=ans;
    }
    
    if(ans==0) return -1;
    
    return ans;   
}
