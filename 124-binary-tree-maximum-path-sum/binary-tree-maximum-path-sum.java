/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    public static int res = -30000000;

    public static int fun(TreeNode root) {
        if(root == null) return 0;
        int left = Math.max(fun(root.left),0);
        int right = Math.max(fun(root.right),0);
        int curr = left+right+root.val;
        res = Math.max(res,curr);
        return Math.max(left+root.val,right+root.val);
    }

    public int maxPathSum(TreeNode root) {
        res = -30000000;
        int temp = fun(root);
        return res;
    }
}