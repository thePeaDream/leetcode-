class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum)//递归
    {
        //在这棵树中，可以找到一条路径，使targetSum沿着该条路径往下减，最后为0


        if(root == nullptr) return false;
        TreeNode* cur = root;
        
        //如果当前结点为叶子结点，并且能把targetSum减到0
        if(cur->left == nullptr&&cur->right == nullptr&& targetSum - cur->val == 0)
            return true;
        
        //往左子树找是否存在一条路径，使targetSum - cur->val沿着这条路径往下减，最后为0
        if(hasPathSum(cur->left, targetSum - cur->val))
            return true;

        if(hasPathSum(cur->right, targetSum - cur->val))
            return true;
        
        return false;
    }

};
