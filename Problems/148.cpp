/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* getMid(ListNode* head)
    {
        ListNode* fast = head->next;
        ListNode* slow = head;
        while (fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next;
        }
        fast = slow->next;
        slow->next = nullptr;
        return fast;
    }
    ListNode* mergeList(ListNode* front, ListNode* back)
    {
        if (front == nullptr)
            return back;
        if (back == nullptr)
            return front;
        auto* dummyHead = new ListNode(0);
        ListNode* temp = dummyHead;
        while (front != nullptr && back != nullptr) {
            if (front->val <= back->val) {
                temp->next = front;
                temp = front;
                front = front->next;
            }
            else {
                temp->next = back;
                temp = back;
                back = back->next;
            }
        }
        if (front != nullptr)
            temp->next = front;
        if (back != nullptr)
            temp->next = back;
        return dummyHead->next;
    }
    ListNode* sortList(ListNode* head)
    {
        if (!head || !head->next)
            return head;
        ListNode* back = getMid(head);
        head = sortList(head);
        back = sortList(back);
        return mergeList(head, back);
    }
};
