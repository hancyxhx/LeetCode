// Sort a linked list in O(n log n) time using constant space complexity.


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
    ListNode *sortList(ListNode *head) {
	int length = 0;
	ListNode *p = head;
	while(p != NULL){
	    length++;
	    p = p->next;
	}

	return sortList(head, length);
    }


    ListNode* merge(ListNode *l1, ListNode *l2, ListNode *last_tail){

	while(l1 || l2){
	    if (l1 != NULL && (l2 == NULL || l1->val < l2->val)){
		last_tail->next = l1;
		l1 = l1->next;
	    }
	    else{
		last_tail->next = l2;
		l2 = l2->next;
	    }
	    last_tail = last_tail->next;
	}
	return last_tail;
    }

    ListNode* cut(ListNode *head, int width){
	ListNode *new_head;

	while(head!=NULL && --width != 0){
	    head = head->next;
	}

	if (!head)
	    return new_head = NULL;

	new_head = head->next;
	head->next = NULL;
	return new_head;
    }

    ListNode* sortList(ListNode *head, int length){
	ListNode virtual_head(0);
	virtual_head.next = head;

	for (int width = 1; width < length; width*=2){
	    ListNode *left, *right;
	    ListNode *last_tail = &virtual_head;
	    head = virtual_head.next;

	    while(head != NULL){
		left = head;
		right = cut(head, width);
		head = cut(right, width);
		last_tail = merge(left, right, last_tail);
	    }
	}

	return virtual_head.next;
    }
};


