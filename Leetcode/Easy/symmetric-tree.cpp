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
    bool checkSymmetry(TreeNode* left, TreeNode* right) {
        if (left == NULL && right == NULL) return true;
        if (left == NULL || right == NULL) return false;
        if (left->val != right->val || !checkSymmetry(left->left, right->right) || !checkSymmetry(left->right, right->left)) return false;
        return true;
            
    }
    bool isSymmetric(TreeNode* root) {
        if (!root) return true;
        if (checkSymmetry(root->left, root->right)) return true;
        return false;
    }
};