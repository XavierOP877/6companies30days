class Solution {
public:
    struct SubtreeInfo {
        bool isBST;
        int sum, minVal, maxVal;
    };

    int maxSumBST(TreeNode* root) {
        int maxSum = 0;
        traverse(root, maxSum);
        return maxSum;
    }

    SubtreeInfo traverse(TreeNode* node, int &maxSum) {
        if (!node) {
            return {true, 0, INT_MAX, INT_MIN};
        }

        auto left = traverse(node->left, maxSum);
        auto right = traverse(node->right, maxSum);

        if (left.isBST && right.isBST && node->val > left.maxVal && node->val < right.minVal) {
            int sum = node->val + left.sum + right.sum;
            maxSum = max(maxSum, sum);
            int minVal = left.minVal != INT_MAX ? left.minVal : node->val;
            int maxVal = right.maxVal != INT_MIN ? right.maxVal : node->val;
            return {true, sum, minVal, maxVal};
        } else {
            return {false, 0, 0, 0};
        }
    }
};
