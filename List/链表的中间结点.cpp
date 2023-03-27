class Solution {
public:
    ListNode* middleNode(ListNode* head)//双指针 
    {
        if(head == nullptr) return head;

        auto* fast = head;
        auto* slow = head;
        //快指针一次两步，慢指针一次一步

        //fast最终=nullptr,说明偶数个结点；最终fast->next == nullptr,说明奇数个结点
        while(fast != nullptr && fast->next != nullptr)
        {
            fast = fast->next->next;
            slow = slow->next;
        }

        //最终slow就是中间结点
        return slow;

    }
};
