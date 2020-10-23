// k= number of lists, n = number of nodes in final list
//Recursive merging, time comlexity O(nk)
class Solution {
public:
    ListNode* mergeList(ListNode* l1,ListNode* l2){
        if(!l1) return l2;
        if(!l2) return l1;
        ListNode* head;
        if(l1->val<=l2->val){
            head=l1;
            head->next=mergeList(l1->next,l2);
        }else{
            head=l2;
            head->next= mergeList(l1,l2->next);
        }
        return head;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int k = lists.size();
        if(k==0) return nullptr;
        ListNode* curr = lists[0];
        for(int i=1;i<k;i++){
            curr = mergeList(curr,lists[i]);
        }
        return curr;
    }
};

//Iterative merging without dummy head, time complexity O(nk)

class Solution {
public:
    ListNode* mergeList(ListNode* l1,ListNode* l2){
        if(!l1) return l2;
        if(!l2) return l1;
        ListNode* head=nullptr;
        if(l1->val<=l2->val){
            head=l1;
            l1=l1->next;
        }else{
            head=l2;
            l2=l2->next;
        }
        ListNode* curr=head;
        while(l1 && l2){
            if(l1->val<=l2->val){
                curr->next=l1;
                l1=l1->next;
            }else{
                curr->next=l2;
                l2=l2->next;
            }
            curr= curr->next;
        }
        if(l1) curr->next=l1;
        if(l2) curr->next=l2;
        return head;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int k = lists.size();
        if(k==0) return nullptr;
        ListNode* curr = lists[0];
        for(int i=1;i<k;i++){
            curr = mergeList(curr,lists[i]);
        }
        return curr;
    }
};

//Iterative merging using dummy head, time complexity O(nk)

class Solution {
public:
    ListNode* mergeList(ListNode* l1,ListNode* l2){
        if(!l1) return l2;
        if(!l2) return l1;
        ListNode* dummyHead = new ListNode();
        ListNode* curr= dummyHead;
        while(l1 && l2){
            if(l1->val<=l2->val){
                curr->next=l1;
                l1=l1->next;
            }else{
                curr->next=l2;
                l2=l2->next;
            }
            curr= curr->next;
        }
        if(l1) curr->next=l1;
        if(l2) curr->next=l2;
        return dummyHead->next;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int k = lists.size();
        if(k==0) return nullptr;
        ListNode* curr = lists[0];
        for(int i=1;i<k;i++){
            curr = mergeList(curr,lists[i]);
        }
        return curr;
    }
};

// Using Priority Queue , time complexity O(nlogk) and space complexity O(k)

class Solution {
public:
    typedef pair<int,ListNode*> pi;
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int k=lists.size();
        priority_queue<pi,vector<pi>,greater<pi>> pq;
        ListNode* dummyHead = new ListNode();
        ListNode* curr=dummyHead;
        for(int i=0;i<k;i++){
            if(lists[i]){
                pq.push({lists[i]->val,lists[i]});
            }
        }
        while(!pq.empty()){
            auto node = pq.top().second;
            pq.pop();
            curr->next=node;
            node=node->next;
            curr=curr->next;
            if(node){
                pq.push({node->val,node});
            }
        }
        return dummyHead->next;
    }
};

//Using Divide and Conquer Iterative, time comlexity O(nk), space complexity O(1)


class Solution {
public:
    ListNode* mergeList(ListNode* l1,ListNode* l2){
        if(!l1) return l2;
        if(!l2) return l1;
        ListNode* head=nullptr;
        if(l1->val<=l2->val){
            head=l1;
            l1=l1->next;
        }else{
            head=l2;
            l2=l2->next;
        }
        ListNode* curr=head;
        while(l1 && l2){
            if(l1->val<=l2->val){
                curr->next=l1;
                l1=l1->next;
            }else{
                curr->next=l2;
                l2=l2->next;
            }
            curr= curr->next;
        }
        if(l1) curr->next=l1;
        if(l2) curr->next=l2;
        return head;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int k = lists.size()-1;
        if(lists.empty()) return nullptr;
        while(k>0){
            int i=0,j=k;
            while(i<j){
                lists[i]=mergeList(lists[i],lists[j]);
                i++;
                j--;
                if(i>=j){
                    k=j;
                }
            }
        }
        return lists[0];
    }
};

//Using Divide and Conquer Recursive, time comlexity O(nk), space complexity O(1)

class Solution {
public:
    ListNode* mergeList(ListNode* l1,ListNode* l2){
        if(!l1) return l2;
        if(!l2) return l1;
        ListNode* head=nullptr;
        if(l1->val<=l2->val){
            head=l1;
            l1=l1->next;
        }else{
            head=l2;
            l2=l2->next;
        }
        ListNode* curr=head;
        while(l1 && l2){
            if(l1->val<=l2->val){
                curr->next=l1;
                l1=l1->next;
            }else{
                curr->next=l2;
                l2=l2->next;
            }
            curr= curr->next;
        }
        if(l1) curr->next=l1;
        if(l2) curr->next=l2;
        return head;
    }
    ListNode* merge(vector<ListNode*> &lists,int start,int end){
        if(start==end) return lists[start];
        if(start+1==end) return mergeList(lists[start],lists[end]);
        int mid = (start+end)/2;
        return mergeList(merge(lists,start,mid),merge(lists,mid+1,end));
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int k = lists.size();
        if(lists.empty()) return nullptr;
        return merge(lists,0,k-1);
    }
};
