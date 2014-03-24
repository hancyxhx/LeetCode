//     Given a binary tree containing digits from 0-9 only, each root-to-leaf path could represent a number.
//     An example is the root-to-leaf path 1->2->3 which represents the number 123.
//     Find the total sum of all root-to-leaf numbers.

//     For example,
//         1
//        / \
//       2   3
//     The root-to-leaf path 1->2 represents the number 12.
//     The root-to-leaf path 1->3 represents the number 13.
//     Return the sum = 12 + 13 = 25.


 /* 
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

/**************************
 ***  First Solution  *****
 **************************/
class Solution {
public:
    int sumNumbers(TreeNode *root) {
	if (root == NULL)
	    return 0;
	
	return sum_numbers(root, 0);
    }

    /* p为根子树的所有路径的和 */
    int sum_numbers(TreeNode *p, int ancestor_sum){
	if (p->left == NULL && p->right == NULL)
	    return ancestor_sum * 10 + p->val;

	int sum = 0;
	if (p->left != NULL)
	    sum += sum_numbers(p->left, ancestor_sum * 10 + p->val);
	if (p->right != NULL)
	    sum += sum_numbers(p->right, ancestor_sum * 10 + p->val);

	return sum;
    }
};



/***************************
 ***  Second Solution  *****
 **************************/
typedef struct {
    TreeNode *pnode;
    int ancestor_value;
} item_t;

class Solution {
public:
    int sumNumbers(TreeNode *root) {
	if (root == NULL)
	    return 0;

	queue<item_t> q;
	item_t item = {root, 0};
	q.push(item);
	int sum = 0;
	while (!q.empty()){
	    item = q.front(); q.pop();
	    if (item.pnode->left == NULL && item.pnode->right == NULL){
		sum += item.ancestor_value * 10 + item.pnode->val;
		continue;
	    }

	    if (item.pnode->left != NULL){
		item_t tmp_item = {item.pnode->left, item.ancestor_value * 10 + item.pnode->val};
		q.push(tmp_item);
	    }
	    if (item.pnode->right != NULL){
		item_t tmp_item = {item.pnode->right, item.ancestor_value * 10 + item.pnode->val};
		q.push(tmp_item);
	    }
	}
	return sum;
    }

};
