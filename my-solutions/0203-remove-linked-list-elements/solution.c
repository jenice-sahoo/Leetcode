/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* removeElements(struct ListNode* head, int val)
{
    struct ListNode *current = head;
    struct ListNode *temp;

    // Remove nodes from the beginning
    while (current != NULL && current->val == val)
    {
        temp = current;
        current = current->next;
        free(temp);
    }

    head = current;

    // Remove nodes from the remaining list
    while (current != NULL && current->next != NULL)
    {
        if (current->next->val == val)
        {
            temp = current->next;
            current->next = current->next->next;
            free(temp);
        }
        else
        {
            current = current->next;
        }
    }

    return head;
}
