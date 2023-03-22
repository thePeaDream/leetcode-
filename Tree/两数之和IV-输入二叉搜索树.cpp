class Solution {
public:
    
    bool findTarget(TreeNode* root, int k) 
    {
        InOrder(root);
        if(v.size() < 2)
            return false;
        
        //在有序vector中是否有两个数和=k

        //双指针指向头尾
        int end = v.size()-1;
        int front = 0;
        while(end > front)
        {
            //如果和>target,说明要v[end]要减小,反之增大v[front]
            if(v[end] + v[front] > k)
                end--;
            else if(v[end]+v[front] < k)
                front++;
            else
                return true;
        }
        return false;
    }

    //中序遍历搜索二叉树，得到有序vector
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
