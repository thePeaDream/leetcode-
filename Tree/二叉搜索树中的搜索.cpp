class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) 
    {
        //左孩子比根要小，右孩子比根要大
        TreeNode* cur = root;
        while(cur!=nullptr)
        {
            if(cur->val == val)
                return cur;
            else if(cur->val < val)//若要找的结点比当前结点大，去右树找
                cur = cur->right;
            else//若要找的结点比当前结点小，去左树找
                cur = cur->left;
        }
        return cur;
    }
};
