/*
https://leetcode.com/problems/sum-of-root-to-leaf-binary-numbers/
2019-04-07
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int findSum(TreeNode* node, long int sum) {
        long int ans = 0;
        if (node->left == NULL && node->right == NULL) return sum;
        if (node->left != NULL) ans += findSum(node->left, sum*2%1000000007 + node->left->val);
        if (node->right != NULL) ans += findSum(node->right, sum*2%1000000007 + node->right->val);
        return ans;
    }
    int sumRootToLeaf(TreeNode* root) {
        return findSum(root, root->val);    
    }
};