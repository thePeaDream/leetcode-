class Solution {
public:
    Node* connect(Node* root)//递归 
    {
        if(root == nullptr) return root;
        //连接左子树和右子树
        connectChildTree(root->left, root->right);
        return root;
    }
private:
    void connectChildTree(Node* leftTree,Node* rightTree)
    {
        if(leftTree == nullptr || rightTree == nullptr) return;
        leftTree->next = rightTree;
        
        connectChildTree(leftTree->left, leftTree->right);
        connectChildTree(rightTree->left,rightTree->right);
        connectChildTree(leftTree->right, rightTree->left);
    }
};
