#include<bits/stdc++.h>
using namespace std;
struct TreeNode 
{
    int val;
    TreeNode*left;
    TreeNode*right;
    TreeNode(int data)
    {
      val=data;
      left=right=NULL;
    }
   

};
void Inorder(TreeNode*root)
{
    if(!root)
    return ;
    Inorder(root->left);
    cout<<root->val;
    Inorder(root->right);

}
void Preorder(TreeNode*root)
{
    if(!root)
    return ;
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
    return;
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
    // if (root == NULL)  return; 
  
    // // Create an empty queue for level order tarversal 
    // queue<TreeNode *> q; 
  
    // // Enqueue Root and initialize height 
    // q.push(root); 
  
    // while (q.empty() == false) 
    // { 
    //     // Print front of queue and remove it from queue 
    //     TreeNode *node = q.front(); 
    //     cout << node->val << " "; 
    //     q.pop(); 
  
    //     /* Enqueue left child */
    //     if (node->left != NULL) 
    //         q.push(node->left); 
  
    //     /*Enqueue right child */
    //     if (node->right != NULL) 
    //         q.push(node->right); 
    // } 
}


int main()
{   
    
    // struct TreeNode *root = new TreeNode(1); 
    // root->left             = new TreeNode(2); 
    // root->right         = new TreeNode(3); 
    // root->left->left     = new TreeNode(4); 
    // root->left->right = new TreeNode(5);  
  TreeNode *root =new TreeNode(1); 
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