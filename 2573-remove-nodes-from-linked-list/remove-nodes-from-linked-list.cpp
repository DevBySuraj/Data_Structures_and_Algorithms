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

    ListNode* reverseInPlace(ListNode* head) {
    ListNode* prev = nullptr;
    ListNode* curr = head;
    ListNode* nextNode = nullptr;

    while (curr != nullptr) {
        nextNode = curr->next; // Store next node
        curr->next = prev;     // Reverse the link
        prev = curr;           // Move prev forward
        curr = nextNode;       // Move curr forward
    }
    return prev; // New head
}

    ListNode* removeNodes(ListNode* head) {
        stack<ListNode*> st;

        head = reverseInPlace(head);
        ListNode* temp = head;

        while(temp != NULL){
            // if(st.empty()){
            //     st.push(temp);
            //     temp = temp->next;
            //     // continue;
            // }
            while(!st.empty() && st.top()->val <= temp->val){
                st.pop();
            }

            if(st.empty()){
                st.push(temp);
                temp = temp->next;
            }
            else{
                ListNode* shift = st.top();
                shift->next = temp->next;
                temp = temp->next;
            }

        }

        return reverseInPlace(head);
    }
};