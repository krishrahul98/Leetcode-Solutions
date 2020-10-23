// Time complexity O(n)

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode* curr = head;
        if(!head || !head->next) return head;
        head=head->next;
        ListNode* prev=nullptr;
        ListNode* temp = nullptr;
        while(curr && curr->next){
            //Swaping Nodes
            temp = curr->next;
            curr->next=curr->next->next;
            temp->next=curr;
            //Linking with previous node
            if(prev) prev->next=temp;
            prev=curr;
            curr=curr->next;
        }
        return head;
    }
};
