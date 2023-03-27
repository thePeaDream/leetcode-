class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n)//双指针 
    {
        assert(n > 0);
        auto* fast = head;
        auto* slow = head;
        ListNode* slowPre = nullptr;
        
        //先让fast先走n步，此时fast与slow相距n
        while(n--)
        {
            if(fast == nullptr)
            {
                //说明数字有误，没有倒数第n个结点
                return nullptr;
            }
            fast = fast->next;
        }

        //fast与slow同时走，直到fast为nullptr
        //此时由于fast与slow相距n步，所以slow就是倒数第n个结点
        while(fast != nullptr)
        {
            fast = fast->next;

            slowPre = slow;//更新slow的上一个结点
            slow = slow->next;
        }
        
        //如果slow是头结点
        if(slow == head)
        {
            ListNode* slowNext = slow->next;
            delete slow;
            head = slowNext;
        }
        else
        {
            ListNode* slowNext = slow->next;
            delete slow;
            slowPre->next = slowNext;
        }
        return head;
    }
};
