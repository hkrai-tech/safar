/*In a linked list of size n, where n is even, the ith node (0-indexed) of the linked list is known as the twin of the (n-1-i)th node, if 0 <= i <= (n / 2) - 1.

For example, if n = 4, then node 0 is the twin of node 3, and node 1 is the twin of node 2. These are the only nodes with twins for n = 4.
The twin sum is defined as the sum of a node and its twin.

Given the head of a linked list with even length, return the maximum twin sum of the linked list.*/

class Solution
{
public:
    int pairSum(ListNode *head)
    {
        ListNode *slow = head;
        ListNode *fast = head;
        ListNode *prev = NULL;

        while (slow && fast && fast->next)
        {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        prev->next = NULL; // detaching the 1st half.
        reverse(&slow);
        ListNode *ptr1 = head;
        ListNode *ptr2 = slow;

        int maxi = 0;

        while (ptr1 && ptr2)
        {
            maxi = max(maxi, (ptr1->val + ptr2->val));
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }

        reverse(&slow);
        prev->next = slow;

        return maxi;
    }

    void reverse(ListNode **head) // taking the reverse of the second half head is pointing to slow and slow is pointing to first node of second half i.e the node afyer the middle node.
    {
        ListNode *curr = *head;
        ListNode *nxt;
        ListNode *prev = NULL;

        while (curr)
        {
            nxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nxt;
        }
        *head = prev;
    }

    /*Tc O(n) but SC is O(1)*/

    /*
    vector<int> v;
    while(head!=NULL)
        {
            v.push_back(head->val);
            head=head->next;
        }

        int i=0,j=v.size()-1;

        int maxi=0;

        while(i<v.size()-1 && j>=0 && i<j)
        {
            maxi=max(maxi,(v[i]+v[j]));
            i++;j--;
        }

        return maxi;*/
};