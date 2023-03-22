class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) 
    {
        //创建新结点
        TreeNode* newNode = new TreeNode;
        newNode->val = val;
        newNode->left = newNode->right = nullptr;

        //空树
        if(root == nullptr) return newNode;

        //非空
        TreeNode* cur = root;
        TreeNode* pre = nullptr;
        int flag = 0;//标定插入到左孩子还是右孩子
        
        while(cur != nullptr)//最后插入到cur处，要有pre
        {
            pre = cur;
            if(val > cur->val)//要到右树找插入位置
            {  
                cur = cur->right;
                flag = 1;
            }
            else//到左树找插入位置
            {
                cur = cur->left;
                flag = 0;
            }
        }

        if(flag == 0)
            pre->left = newNode;
        else
            pre->right = newNode;
        return root;
    }
};
