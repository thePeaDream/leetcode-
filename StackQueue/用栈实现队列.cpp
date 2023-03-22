class MyQueue 
{
public:
    
    void push(int x) 
    {
        forImport.push(x);
    }
    
    int pop() 
    {
        if(forExport.empty())
        {
            //将forImport中的元素，（一次次取栈顶元素）有序导入forExport
            //同时删除forImport的元素
            while(!forImport.empty())
            {
                forExport.push(forImport.top());
                forImport.pop();
            }
        }
        int ret = forExport.top();
        forExport.pop();
        return ret;
    }
    
    int peek() 
    {
        if(forExport.empty())
        {
            //将forImport中的元素，（一次次取栈顶元素）有序导入forExport
            //同时删除forImport的元素
            while(!forImport.empty())
            {
                forExport.push(forImport.top());
                forImport.pop();
            }
        }
        return forExport.top();
    }
    
    bool empty() 
    {
        return forImport.empty()&&forExport.empty();
    }

private:
     stack<int> forImport;//用来入队列（导入元素）
     stack<int> forExport;//用来出队列（导出元素）
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
