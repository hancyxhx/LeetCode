/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
	unordered_map<RandomListNode*, RandomListNode*> node_map;
	RandomListNode newhead(0);

	RandomListNode *p = head;
	RandomListNode *q = &newhead;
	while(p != NULL){
	    q->next = new RandomListNode(p->label);
	    node_map[p] = q->next;

	    p=p->next; q=q->next;
	}


	for(p=head, q=newhead.next; p!=NULL; p=p->next,q=q->next){
	    q->random = node_map[p->random];
	}

	return newhead.next;
    }
};
