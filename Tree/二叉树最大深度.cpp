class Solution {
public:
    int maxDepth(TreeNode* root) //递归 —— 左子树+1高度 与 右子树+1高度 作比较
    {
        if(root == nullptr)
            return 0;
        int leftTreeDepth = maxDepth(root->left);
        int rightTreeDepth = maxDepth(root->right);
        return leftTreeDepth > rightTreeDepth?leftTreeDepth+1:1+rightTreeDepth;
    }
};
