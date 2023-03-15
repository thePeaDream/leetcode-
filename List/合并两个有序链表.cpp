class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) //归并思路
    {
        //作为新链表的头结点
        ListNode* reList = new ListNode;
        ListNode* head = reList;
        reList->next = nullptr;
        //接下来要接的结点都放到reList->next中

        //从头遍历两个链表
        while(list1 != nullptr || list2 != nullptr)
        {
            //如果有一个链表遍历完成，将另一个链表的剩下结点直接接到reList->next中
            if(list1 == nullptr)
            {
                reList->next = list2;
                break;
            }
            else if(list2 == nullptr)
            {
                reList->next = list1;
                break;
            }

            //选出较小的结点接到新链表后面
            if(list1->val > list2->val)
            {
                reList->next = list2;
                
                //list2向后一个结点
                list2 = list2->next;

                //更新reList,保证 接下来要接的结点都放到reList->next中
                reList = reList->next;
                reList->next = nullptr;
            }
            else
            {
                reList->next = list1;

                list1 = list1->next;

                reList = reList->next;
                reList->next = nullptr;
            }
        }
        //防止内存泄漏
        ListNode* re = head->next;
        delete head;
        return re;    
    }
};
