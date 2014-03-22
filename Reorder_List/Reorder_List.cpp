// Given a singly linked list L: L0->L1->...->Ln-1->Ln,
//     reorder it to: L0->Ln->L1->Ln-1->L2->Ln-2...
//     You must do this in-place without altering the nodes' values.
// For example,
// Given {1,2,3,4}, reorder it to {1,4,2,3}.


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
    void reorderList(ListNode *head) {
	if (head == NULL)
	    return;

	//get the length of the list
	int length = 0;
	for(ListNode *i = head; i != NULL; i = i->next)
	    length++;

	//cut the list from the middle & reverse the second half list
	int middle = (length + 1) / 2;
	ListNode *first_half_list = head;
	ListNode *second_half_list = cutList(head, middle);
	second_half_list = reverseList(second_half_list);

	//mix the two half list
	head= mix_two_list(first_half_list, second_half_list);
    }

    ListNode *cutList(ListNode *head, int len){
	if(len <= 0 || head == NULL)
	    return head;

	ListNode *p = head;
	while(len > 1){
	    p = p->next;
	    len--;
	}
	head = p->next;
	p->next = NULL;
	return head;
    }

    ListNode *mix_two_list(ListNode *first_half_list, ListNode *second_half_list){
	ListNode virhead(0);
	ListNode *p = &virhead;
	while(first_half_list != NULL && second_half_list != NULL){
	    p->next = first_half_list;
	    first_half_list= first_half_list->next;
	    p = p->next;
	    p->next = second_half_list;
	    second_half_list = second_half_list->next;
	    p = p->next;
	}
	if(first_half_list != NULL)
	    p->next = first_half_list;

	return virhead.next;
    }

    ListNode *reverseList(ListNode *head){
	ListNode *i = NULL, *j = head, *k;

	while(j != NULL){
	    k = j->next;
	    j->next = i;
	    i = j;
	    j = k;
	}
	return i;
    }
};
