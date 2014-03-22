/*  Given a binary tree, return the preorder traversal of its nodes' values. */

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> preorderTraversal(TreeNode *root) {
	vector<int> v;
	stack<TreeNode*> s;
	s.push(root);

	while(!s.empty()){
	    TreeNode* node = s.top();
	    s.pop();
	    if(node != NULL){
		v.push_back(node->val);
		s.push(node->right);
		s.push(node->left);
	    }
	}

	return v;
    }
};
