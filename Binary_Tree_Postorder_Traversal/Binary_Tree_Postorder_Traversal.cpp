/* Given a binary tree, return the postorder traversal of its nodes' values. */

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */


/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

struct Item{
    Item(TreeNode *p_node, int visted){
	this->p_node = p_node;
	this->visted = visted;
    }

    TreeNode* p_node;
    int visted;
};

class Solution {
public:
    vector<int> postorderTraversal(TreeNode *root) {
	vector<int> v;
	stack<Item> s;
	s.push(Item(root, 0));

	while(!s.empty()){
	    Item item = s.top();
	    s.pop();
	    if (item.p_node != NULL){
		if (item.visted == 1)
		    v.push_back((item.p_node)->val);
		else if (item.visted == 0){
		    item.visted = 1; s.push(item);
		    s.push(Item((item.p_node)->right, 0));
		    s.push(Item((item.p_node)->left, 0));
		}
	    }
	}

	return v;
    }
};
