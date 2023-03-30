class Solution {
public:
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) 
    {
        if(root1 == nullptr) return root2;
        if(root2 == nullptr) return root1;
        //后序遍历

        //先合并左子树和右子树
        auto* leftTree = mergeTrees(root1->left,root2->left);
        auto* rightTree = mergeTrees(root1->right,root2->right);
        //合并根
        TreeNode* newRoot = new TreeNode;
        newRoot->val = root1->val+root2->val;
        //释放空间
        delete root1;
        delete root2;
        newRoot->left = leftTree;
        newRoot->right = rightTree;
        return newRoot;
    }
};
