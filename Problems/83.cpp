class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode* dummyHead = new ListNode();
        ListNode* temp=dummyHead;
        ListNode* curr=head;
        ListNode* duplicate = nullptr;
        while(curr){
            if(curr->next && curr->next->val==curr->val){
                while(curr->next && curr->next->val==curr->val){
                    duplicate = curr;
                    curr=curr->next;
                    delete(duplicate);
                }
            }else{
                temp->next=curr;
                temp=temp->next;
                curr=curr->next;
                temp->next=nullptr;
            }
        }
        return dummyHead->next;
    }
};
