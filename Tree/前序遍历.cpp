class Solution {
public:
    vector<int> v;
    vector<int> preorderTraversal(TreeNode* root) 
    {
        if(root != nullptr)
        {
            //根 左子树 右子树
            v.push_back(root->val);
            preorderTraversal(root->left);
            preorderTraversal(root->right);
        }
        return v;
    }
};
