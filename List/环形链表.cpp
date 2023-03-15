class Solution {
public:
    bool hasCycle(ListNode *head) //快慢指针
    {
        ListNode* fast = head;
        ListNode* slow = head;

        //若存在环,fast永远!= nullptr 并且fast->next != nullptr
        while(fast != nullptr && fast->next != nullptr)
        {
            //快指针一次走两步
            fast = fast->next->next;
            slow = slow->next;

            //因为存在环，就变成了操场追及问题 —— 假设快指针落后一圈
            //快指针和慢指针同时走
            //每次走完，快指针到慢指针的距离减少一，最后一定会相遇
            if(fast == slow)
                return true;
        }
        return false;
    }
};
