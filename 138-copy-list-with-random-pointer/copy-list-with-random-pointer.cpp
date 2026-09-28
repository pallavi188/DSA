/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    void insertNode(Node* head){
        Node* temp = head;
        while(temp != NULL){
            Node* copyNode = new Node(temp->val);
            copyNode->next = temp->next;
            temp->next = copyNode;
            temp = temp->next->next;
        }
    }
    //step 2 . connect random pointer
    void connectRandomPointers(Node* head){
        Node* temp = head;
        while(temp != NULL){
        Node* copyNode = temp->next;
        if(temp->random != NULL){
            copyNode->random = temp->random->next;
        }else{
            copyNode->random = NULL;
        }
        temp = temp->next->next;
    }
    }
    //step 3. 
    Node* deepCopyNode(Node* head){
        Node* temp = head;
        Node*dNode = new Node(-1);
        Node* res = dNode;
        while(temp != NULL){
            res->next = temp->next;
            temp->next = temp->next->next;
            res = res->next;
            temp = temp->next;
        }
        return dNode->next;
    }
    Node* copyRandomList(Node* head) {
       //step 1. insert nodes in between 
       insertNode(head);
       //step2. connect random pointers to the copied/inserted node
       connectRandomPointers(head);
       //step 3 . connect next pointer and return the new cloned ll
       return deepCopyNode(head);
    }
};