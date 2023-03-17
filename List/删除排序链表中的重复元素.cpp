class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) //双指针
    {
        //没有元素或只有1个元素
        if(head == nullptr||head->next == nullptr)
            return head;


        ListNode* fast = head->next;
        ListNode* slow = head;
        //slow之前的结点(包括slow)全是没有重复的元素
        while(fast != nullptr)
        {
            if(fast->val != slow->val)
            {
                //若遍历到的结点不同于slow,接到slow后面，更新slow
                slow->next = fast;
                slow = fast;

                //fast继续向后遍历
                fast = fast->next;
            }
            else
            {
                //若相同，删除fast,防止内存泄漏
                ListNode* delNode = fast;
                fast = fast->next;
                delete delNode;
            }
        }
        slow->next = nullptr;
        return head; 
    }
};
