/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    stack<int> st;
    int n = 0;
    void inorder(TreeNode* root) {
        if(root == nullptr) return;
        
        inorder(root->left);
        st.push(root->val);
        n++;
        inorder(root->right);

    }
    int kthSmallest(TreeNode* root, int k) {
        inorder(root);
        int x = n-k;
        while(x--) {
            st.pop();
        }
        return st.top();
    }
};