class Solution {
  public:
    // Function which returns the  root of the flattened linked list.
    Node* mergeLL(Node *list1, Node *list2){
        Node *dummy = new Node(-1);
        Node *temp = dummy;
        
        while(list1!=NULL && list2!=NULL){
            
            if(list1->data > list2->data){
                temp->bottom = list2;
                temp = list2;
                list2 = list2->bottom;
            }
            else{
                temp->bottom = list1;
                temp=list1;
                list1 = list1->bottom;
            }
            temp->next=NULL;
        }  
            if(list1!=NULL)
                temp->bottom = list1;
            else
                temp->bottom = list2;
                
            if(dummy->bottom)
            dummy->bottom->next = NULL;

        return dummy->bottom;
        
    }
    Node *flatten(Node *head) {
        // Your code here
        if(head==NULL || head->next == NULL)
            return head;
            
        Node* mergedHead = flatten(head->next);
        head = mergeLL(head, mergedHead);
        return head;
    }
};
