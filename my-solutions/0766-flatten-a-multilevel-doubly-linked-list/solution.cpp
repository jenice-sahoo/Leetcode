class Solution {
public:
    Node* flatten(Node* head) {
        if (head == NULL)
            return head;

        Node* curr = head;

        while (curr != NULL) {
            if (curr->child != NULL) {
                // Save the next node
                Node* nextNode = curr->next;

                // Flatten the child list
                Node* childList = flatten(curr->child);

                // Connect curr to child list
                curr->next = childList;
                childList->prev = curr;

                // Child pointer is no longer needed
                curr->child = NULL;

                // Find the last node of the child list
                Node* tail = childList;
                while (tail->next != NULL)
                    tail = tail->next;

                // Connect child list to original next
                tail->next = nextNode;

                if (nextNode != NULL)
                    nextNode->prev = tail;
            }

            curr = curr->next;
        }

        return head;
    }
};
