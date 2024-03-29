class Solution {
public:
    ListNode* reverseList(ListNode* head)//遍历原链表，向新链表头插 
    {
        ListNode* newHead = nullptr;
        while(head != nullptr)
        {
            //改变新链表的头结点
            ListNode* tmp = newHead;
            newHead = head;

            //保持向后遍历原链表
            head = head -> next;

            //接上新链表
            newHead->next = tmp;
        }
        return newHead;
    }
    //ListNode* reverseList(ListNode* head)//直接反转
    /*{
        if(head == nullptr||head->next == nullptr) return head;
        ListNode* pre = nullptr;
        ListNode* cur = head;
        while(cur)
        {
            ListNode* tmp = cur->next;
            cur->next = pre;
            pre = cur;
            cur = tmp;
        }
    //    return pre;
    //}*/
};
