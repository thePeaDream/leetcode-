class Solution {
public:
    //二叉搜索树 中序遍历得到升序
    bool isValidBST(TreeNode* root) 
    {
       InOrder(root);

       //遍历vector,若不是升序则不是二叉搜索树
       for(int i = 0; i < v.size()-1; i++)
       {
           if(v[i] >= v[i+1])
            return false;
       }
       return true;
    }

    //把中序遍历到的数放到vector中  
    void InOrder(TreeNode* root)
    {
        if(root == nullptr)
            return;
        InOrder(root->left);
        v.push_back(root->val);
        InOrder(root->right);
    }
private:
    vector<int> v;
};
