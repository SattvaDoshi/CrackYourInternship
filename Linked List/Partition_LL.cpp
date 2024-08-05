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
int speedup = []{ios::sync_with_stdio(0); cin.tie(0); return 0;}();
class Solution {
public:
    void insert(ListNode* &head,int val){
        if(head==NULL){
            head=new ListNode(val);
            return;
        }
        ListNode *n=new ListNode(val);
        n->next=head;
        head=n;
    }
    void reverse(ListNode *&head){
        ListNode *prev=NULL;
        ListNode *curr=head;
        ListNode *temp;
        while(curr!=NULL){
            temp=curr->next;
            curr->next=prev;
            prev=curr;
            curr=temp;
        }
        head=prev;
        return;
    }
    ListNode* partition(ListNode* head, int x) {
        ListNode* res=NULL;
        ListNode* temp1=head;
        while(temp1){
            if(temp1->val<x){
                insert(res,temp1->val);
            }
            temp1=temp1->next;
        }
        // we have done for all nodes less than x
        ListNode* temp2=head;
        while(temp2){
            if(temp2->val>=x){
                insert(res,temp2->val);
            }
            temp2=temp2->next;
        }
        reverse(res);
        return res;
    }
};