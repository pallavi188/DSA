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
    class compare{
        public:
        bool operator()(ListNode* a,ListNode* b){
            return a->val > b->val;
        }
    };
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*,vector<ListNode*>,compare>pq;
        //push heads of all LL in the min heap
        for(auto list : lists){
            if(list != NULL){
                pq.push(list);
            }
        }
        ListNode* dummyNode = new ListNode(-1);
        ListNode* tail = dummyNode;
        while(!pq.empty()){
            ListNode* newNode = pq.top();
            pq.pop();
            tail->next = newNode;
            tail = tail->next;
            if(newNode->next)pq.push(newNode -> next);
        }
        return dummyNode->next;
    }
};