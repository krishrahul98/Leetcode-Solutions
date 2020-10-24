class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head || k==0 || !head->next) return head;
        ListNode* curr=head;
        ListNode* lastNode=nullptr;
        int n = 0;
        while(curr){
            n++;
            lastNode=curr;
            curr=curr->next;
        }
        k=k%n;
        if(k==0) return head;
        curr=head;
        int pos = 0;
        //One node before newHead node
        while(pos+1<n-k){
            curr=curr->next;
            pos++;
        }
        ListNode* newHead = curr->next;
        curr->next=nullptr;
        lastNode->next=head;
        return newHead;
    }
};
