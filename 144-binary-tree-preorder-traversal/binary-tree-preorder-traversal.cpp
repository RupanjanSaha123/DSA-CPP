class Solution {
public:
    vector<int> result;

    void preorder(TreeNode* root) {
        if (root == nullptr)
            return;

        // 1. Root
        result.push_back(root->val);

        // 2. Left
        preorder(root->left);

        // 3. Right
        preorder(root->right);
    }

    vector<int> preorderTraversal(TreeNode* root) {
        preorder(root);
        return result;
    }
};