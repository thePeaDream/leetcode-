class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) 
    {
        TreeNode* cur = root;
        while(1)
        {
            if(p->val < cur->val && q->val < cur->val)//说明p和q一定在当前结点的左子树
                cur = cur->left;//去左子树找
            else if(p->val > cur->val && q->val > cur->val)//说明p和q一定在当前结点的右子树
                cur = cur->right;
            else
            {
                //说明p在当前结点的左子树，同时q在当前结点的右子树
                //或者p在当前结点的右子树，q在当前结点的左子树
                //当前结点就是p、q的最近公共祖先
                return cur;
            }
        }
        return nullptr;
    }
};
