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
class Solution {
public:
    ListNode* mergeList(ListNode* left, ListNode* right) {
        ListNode* dummyNode = new ListNode(-1);
        ListNode* temp = dummyNode;

        while (left != NULL && right != NULL) {
            if (left->val >= right->val) {
                temp->next = right;
                right = right->next;
            } else {
                temp->next = left;
                left = left->next;
            }
            temp = temp->next;
        }
        if (left != NULL)
            temp->next = left;
        else
            temp->next = right;

        return dummyNode->next;
    }

    ListNode* findMiddle(ListNode* head) {
        if (head == NULL || head->next == NULL)
            return head;
        ListNode *slow = head, *fast = head->next;

        while (fast != NULL&& fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    ListNode* sortList(ListNode* head) {
        if (head == NULL || head->next == NULL)
            return head;

        ListNode* middle = findMiddle(head);

        ListNode* right = middle->next;
        middle->next = NULL;
        ListNode* left = head;

        left = sortList(left);
        right = sortList(right);

        return mergeList(left, right);
    }
};