class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) //将!=val的结点尾插到一个新链表中
    {
        //创建一个头结点，用于尾插
        ListNode* newHead = new ListNode;
        newHead->next = nullptr;
        
        //保存头结点，之后的newHead会改变
        ListNode* newHeadTmp = newHead;

        while(head != nullptr)//遍历原链表
        {
            if(head->val != val)//若当前结点!=val
            {
                //接入到新链表中
                newHead->next = head;
                
                //更新head
                head = head->next;

                //保证newHead->next继续要接入新结点
                newHead = newHead->next;
                newHead->next = nullptr;
            }
            else//若 node.val== val
            {
                //保存下一个结点地址（以便继续遍历），删除当前结点
                ListNode* tmp = head->next;
                delete head;
                head = tmp;
            }
        }
        
        //防止内存泄漏
        ListNode* tmp = newHeadTmp->next;
        delete newHeadTmp;
        return tmp;
    }
};
