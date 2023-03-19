class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) //队列先进先出
    {
        vector<vector<int>> ret;
        if(root == nullptr)
            return ret;

        //根结点入队列
        queue<TreeNode*> q;
        q.push(root);


        while(!q.empty())
        {
            //当前层结点的个数
            int size = q.size();
            //当前层遍历的数字放到v中
            vector<int> v;

            //把当前层的所有结点取出，并把当前层所有结点的孩子结点添加到队列中
            for(int i = 0; i < size; i++)
            {
                TreeNode* tmp = q.front();
                v.push_back(tmp->val);
                q.pop();    
                
                if(tmp->left!= nullptr)
                    q.push(tmp->left);
                if(tmp->right!= nullptr)
                    q.push(tmp->right);
            }

            //把遍历完当前层的v添加到ret中
            ret.push_back(v);
        }

        return ret;
    }
};
