class Solution {
public:
    int dfs(TreeNode* node, int currentNumber) {
        if (node == NULL) {
            return 0;
        }

        currentNumber = currentNumber * 2 + node->val;

        if (node->left == NULL && node->right == NULL) {
            return currentNumber;
        }

        int leftSum = dfs(node->left, currentNumber);
        int rightSum = dfs(node->right, currentNumber);

        return leftSum + rightSum;
    }

    int sumRootToLeaf(TreeNode* root) { 
        return dfs(root, 0); 
    }
};