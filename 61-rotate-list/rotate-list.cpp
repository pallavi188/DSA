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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head ==NULL || head->next == NULL || k==0) return head;
        ListNode* temp = head;
        ListNode* tail = head;
        int lenLL = 1;
        while(tail->next != NULL){
            tail = tail->next;
            lenLL++;
        }
        if(k%lenLL == 0) return head;
        tail->next = head;
        k = k%lenLL;
        int n = lenLL - k -1;
        while(n != 0){
            temp = temp->next;
            n--;
        }
        head = temp->next;
        temp->next = NULL;
        return head;
    }
};