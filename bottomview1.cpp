void bottomview(Node*root)
{
    if(!root)
    return;
    int hd=0;
    root->hd=0;
    while(!q.empty())
    {
        Node *temp=q.front();
        q.pop();
        m[hd]=temp->data;
        if(temp->left)
        {
            temp->left->hd=hd-1;
            q.push(temp->left);
        }
        if(temp->right)
        {
            temp->right->hd=hd+1;
            q.push(temp->right);
        }
    }
    for(auto it:m)
    {
        cout<<it->second;
    }
}