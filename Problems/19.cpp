//Time Complexity linear, two pass

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int sz =0;
        ListNode* curr = head;
        while(curr){
            sz++;
            curr=curr->next;
        }
        if(sz==n){
            ListNode* temp = head;
            head=head->next;
            delete(temp);
        }else{
            n=sz-n;
            curr = head;
            for(int i=1;i<n;i++){
                curr=curr->next;
            }
            ListNode* temp = curr->next;
            curr->next=temp->next;
            delete(temp);
        }
        return head;
        
    }
};

// Time Complexity linear, one pass

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* fast = head;
        ListNode* curr = head;
        for(int i=0;i<n;i++){
            fast=fast->next;
        }
        if(!fast) return head->next;
        while(fast->next){
            fast=fast->next;
            curr=curr->next;
        }
        curr->next=curr->next->next;
        return head;
    }
};
