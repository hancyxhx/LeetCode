// Sort a linked list using insertion sort.

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
    ListNode *insertionSortList(ListNode *head) {
	if(head == NULL)
	    return NULL;

	ListNode virNode(0);
	virNode.next = head;

	ListNode *p1_current = head;
	ListNode *p2_current = head->next; // p2_current is the comparing Node, p1_current is the Node before it
	while(p2_current != NULL){

	    ListNode *p1_travel = &virNode;
	    ListNode *p2_travel = p1_travel->next;
	    while ( p2_travel != p2_current ){
		if(p2_travel->val < p2_current->val){
		    p1_travel = p1_travel->next;
		    p2_travel = p2_travel->next;
		}
		else{
		    //remove p2_current
		    removeNextNode(p1_current);

		    //insert p2_current between p1_travel and p2_travel
		    p1_travel->next = p2_current;
		    p2_current->next = p2_travel;

		    //update p2_current
		    p2_current = p1_current->next;
		    break;
		}

		if(p2_travel == p2_current){
		    p1_current = p1_current->next;
		    p2_current = p2_current->next;
		    break;
		}
	    }
	}
	return virNode.next;

    }

    void removeNextNode(ListNode *p){
	if (p->next != NULL)
	    p->next = p->next->next;
    }
};



