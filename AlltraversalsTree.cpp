#include<bits/stdc++.h>
using namespace std;
struct TreeNode 
{
    int val;
    TreeNode*left, *right;
    TreeNode(int data)
    {
      val=data;
      left=right=NULL;
    }
};
void Inorder(TreeNode*root)
{
    if(root == NULL)
        return ;    // indent code properly
    Inorder(root->left);
    cout<<root->val;
    Inorder(root->right);

}
void Preorder(TreeNode*root)
{
    if(root == NULL)
        return ;    // indent code properly
    cout<<root->val;
    Inorder(root->left);
    Inorder(root->right);

}
void Postorder(TreeNode*root)
{
    if(!root)
    return ;
    Inorder(root->left);
    Inorder(root->right);
    cout<<root->val;

}
void LevelOrder(TreeNode*root)
{   
    if(!root)
        return; // indent code properly
    queue<TreeNode*>q;
    q.push(root);
    while(!q.empty())
    {
        TreeNode  * t=q.front();
        cout<<t->val<<" ";
        q.pop();
        
        if(t->left)
        q.push(t->left);
         if(t->right)
        q.push(t->right);
    }
}


int main()
{   
    TreeNode *root =new TreeNode(1);    // indent code properly
    root->left = new TreeNode(2); 
    root->right =new  TreeNode(3); 
    root->left->left =new TreeNode(4); 
    root->left->right =new TreeNode(5);
    cout << "\nPreorder traversal of binary tree is \n"; 
    Preorder(root); 
    cout << "\nInorder traversal of binary tree is \n"; 
    Inorder(root);  
    
    cout << "\nPostorder traversal of binary tree is \n"; 
    Postorder(root); 
    
    cout << "\nLevelOrder traversal of binary tree is \n"; 
    LevelOrder(root);
    
    
}
