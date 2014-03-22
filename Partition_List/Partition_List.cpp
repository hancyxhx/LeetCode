// iven a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.

//     You should preserve the original relative order of the nodes in each of the two partitions.

//     For example,
//     Given 1->4->3->2->5->2 and x = 3,
//     return 1->2->2->4->3->5.


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *partition(ListNode *head, int x) {
	ListNode *less_list_head = NULL, *less_list_tail = NULL;
	ListNode *greater_list_head = NULL, *greater_list_tail = NULL;

	if (head == NULL)
	    return NULL;

	ListNode *current_node = head, *next_node = head->next;
	while (current_node != NULL){
	    if (current_node->val < x){
		//insert to less_list
		if (less_list_head == NULL && less_list_tail == NULL){
		    less_list_head = less_list_tail = current_node;
		    less_list_tail->next = NULL;
		}
		else{
		    less_list_tail->next = current_node;
		    less_list_tail = less_list_tail->next;
		    less_list_tail->next = NULL;
		}
	    }
	    else{
		//inset to greater_list
		if (greater_list_head == NULL && greater_list_tail == NULL){
		    greater_list_head = greater_list_tail = current_node;
		    greater_list_tail->next = NULL;
		}
		else{
		    greater_list_tail->next = current_node;
		    greater_list_tail = greater_list_tail->next;
		    greater_list_tail->next = NULL;
		}
	    }

	    current_node = next_node;
	    next_node = (next_node != NULL?next_node->next:NULL);
	}

	if (less_list_tail == NULL)
	    return greater_list_head;
	else{
	    less_list_tail->next = greater_list_head;
	    return less_list_head;
	}
    }
};
