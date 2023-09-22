# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    res = []
    def __init__(self):
        self.res = []
    def fun(self,root):
        if(root == None):
            return
        self.fun(root.left)
        self.fun(root.right)
        self.res.append(root.val)

    def postorderTraversal(self, root):
        """
        :type root: TreeNode
        :rtype: List[int]
        """
        self.fun(root)
        return self.res
        