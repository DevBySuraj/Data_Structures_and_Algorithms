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
        stack <ListNode*> st;
        head = reverseInPlace(head);

        ListNode*current = head;
        while(current != nullptr){
            if(st.empty()){//node survived so push it in stack
                st.push(current);
                current = current->next;
            }      

            while(!st.empty() && st.top()->val <= current->val){//not next greater then pop
            // chotta hai ya equal toh kaam ka nhi hai pop 
                st.pop(); //can't be previous greater so remove it from stack
            }
            //previous greater found or stack empty


            if(st.empty()){
                st.push(current);
                current = current->next;
            }

            else{ // not empty greater element exits so delte current
                 ListNode* topNode = st.top();
                 topNode->next = current->next;
                 current = current->next;
            }

        }

        return reverseInPlace(head);

    }
};