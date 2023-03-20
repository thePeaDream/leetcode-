class Solution {
public:
    TreeNode* invertTree(TreeNode* root)//递归
    {
        if(root == nullptr)
            return nullptr;
        //左子树翻转
        invertTree(root->left);
        //右子树翻转
        invertTree(root->right);

        //当前树整体翻转
        TreeNode* leftTree = root->left;
        TreeNode* rightTree = root->right;
        root->left = rightTree;
        root->right = leftTree;

        return root;
    }
};
