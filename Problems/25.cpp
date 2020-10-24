class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(!head || k<=1) return head;
        ListNode* curr=head;
        int count=0;
        while(count<k && curr){
            ++count;
            curr=curr->next;
        }
        if(count<k) return head;
        count=0;
        curr=head;
        ListNode* prev=nullptr;
        ListNode* next = nullptr;
        while(count<k){
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
            count++;
        }
        if(next){
            head->next = reverseKGroup(next,k);
        }
        return prev;
    }
};
