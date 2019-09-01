/*
https://leetcode.com/problems/binary-tree-paths/
2019-08-31
*/
# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def binaryTreePaths(self, root):
        """
        :type root: TreeNode
        :rtype: List[str]
        """
        
        if root is None:
            return []
        
        paths = []
        
        def appendPath(curr, p):
            if curr.left is not None:
                appendPath(curr.left, p + "->" + str(curr.left.val))
            if curr.right is not None:
                appendPath(curr.right, p + "->" + str(curr.right.val))
            if curr.left is None and curr.right is None:
                paths.append(p)
                
        appendPath(root, str(root.val))
        
        return paths