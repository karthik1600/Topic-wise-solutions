# inorder traversal
- need stack ,curr=root
- while `stack ! empty or curr!=NULL`
  - while curr!=NULL : 
    - push curr to stck , curr=curr->left
  - curr=stck.top()
  - add curr to res
  - curr=curr->right;

---
# unique BSTS
## `find all possibe unique BSTS with nodes 1 to n`
![](pics\bstuniq.png)

- `vector<tree*>` func(start,end):
    - if start>end :
        - add NULL to list an return it
    - for i = start to end :
        - left=`func`(start,i-1)
        - right=`func`(i+1,end)
        - for L : left:
            - for R : right:
                - node= `new` Node(`i`); // to create new add
                - node->left=L;
                - node->right=R;
                - list.push_back(node);
    - return list 
---
# swap 2 incorrect pos nodes
![](pics\BSTswap.png)
- prev = INT_MIN;
- func(root):
    - do inorder traversal
    - if first==NULL and prev>root :
        - first = prev
    if first!=NULL and prev>root :  // `first time this occurs both f and s will get initialized as f= prev befor`
        - second = root
    prev=root
---
# constr bst from inorder and post order
![](pics\constructBSTfromprein.png)

---
# preorder and postorder
## `preorder`
![](pics\preorder.png)
## `postorder `
![](pics\postorderbst.png)

---
# Children Sum Property
```
 1. You can only increment the value of the nodes, in other words, the modified value must be at least equal to the original value of that node.
 2. You can not change the structure of the original binary tree.
 3. A binary tree is a tree in which each node has at most two children.      
 4. You can assume the value can be 0 for a NULL node and there can also be an empty tree.
```
```cpp
void changeTree(BinaryTreeNode < int > * &root) {
    if(root==NULL)return;
    int curr=0;
    if(root->left)curr+=root->left->data;
    if(root->right)curr+=root->right->data;
    if(root->data>curr){
        if(root->left)root->left->data=root->data;
        if(root->right)root->right->data=root->data;
    }
    changeTree(root->left);
    changeTree(root->right);
    int tot=0;
    if(root->left)tot+=root->left->data;
    if(root->right)tot+=root->right->data;
    if(root->left || root->right)root->data=tot;
}  
```

---
# Boundry traversal of tree
```cpp
vector<int> res;
    void traverseLeft(TreeNode* root){
        if(root==NULL)return;
        vector<int> temp;
        while(root->left || root->right){
            temp.push_back(root->val);
            if(root->left){
                root=root->left;
            }else{
                root=root->right;
            }
        }
        for(int i=0;i<temp.size();i++){
            res.push_back(temp[i]);
        }
    }
    void traverseRight(TreeNode* root){
        if(root==NULL)return;
        vector<int> temp;
        while(root->left || root->right){
            temp.push_back(root->val);
            if(root->right){
                root=root->right;
            }else{
                root=root->left;
            }
        }
        for(int i=temp.size()-1;i>=0;i--){
            res.push_back(temp[i]);
        }
    }
    void LeafNode(TreeNode* root){
        if(root==NULL)return;
        if(!root->left && !root->right)res.push_back(root->val);
        LeafNode(root->left);
        LeafNode(root->right);
    }
    vector<int> boundaryOfBinaryTree(TreeNode * root) {
            if(root==NULL)return res;
            if(root->left || root->right)res.push_back(root->val); // if not leaf
            traverseLeft(root->left);
            LeafNode(root);
            traverseRight(root->right);
            
        return res;
    }
```