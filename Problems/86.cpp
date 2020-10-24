class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        if(!head || !head->next) return head;
        ListNode* smaller = new ListNode();
        ListNode* greater = new ListNode();
        ListNode* small=smaller;
        ListNode* big = greater;
        while(head){
            if(head->val<x){
                small->next=head;
                head=head->next;
                small=small->next;
            }else{
                big->next=head;
                head=head->next;
                big=big->next;
            }
        }
        small->next=greater->next;
        big->next=nullptr;
        return smaller->next;
    }
};
