class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head) return head;
        Node* temp = head;
        while(temp){
            Node* n = new Node(temp->val);
            n->next=temp->next;
            temp->next=n;
            temp=n->next;
        }
        temp=head;
        while(temp){
            if(temp->random!=NULL){
                temp->next->random=temp->random->next;
            }
            temp=temp->next->next;
        }
        Node* h = head->next;
        temp=h;
        while(head){
            head->next=temp->next;
            head=head->next;
            if(head==NULL) break;
            temp->next=head->next;
            temp=temp->next;
        }
        return h;
    }
};
