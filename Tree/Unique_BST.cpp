class Solution {
public:
    std::vector<TreeNode*> generateTrees(int n) {
        if (n == 0) {
            return {};
        }
        return generateTreesHelper(1, n);
    }

private:
    std::unordered_map<std::string, std::vector<TreeNode*>> memo;

    std::vector<TreeNode*> generateTreesHelper(int start, int end) {
        std::string key = std::to_string(start) + "-" + std::to_string(end);
        if (memo.find(key) != memo.end()) {
            return memo[key];
        }

        std::vector<TreeNode*> trees;
        if (start > end) {
            trees.push_back(nullptr);
            return trees;
        }

        for (int rootVal = start; rootVal <= end; rootVal++) {
            std::vector<TreeNode*> leftTrees = generateTreesHelper(start, rootVal - 1);
            std::vector<TreeNode*> rightTrees = generateTreesHelper(rootVal + 1, end);

            for (auto leftTree : leftTrees) {
                for (auto rightTree : rightTrees) {
                    TreeNode* root = new TreeNode(rootVal);
                    root->left = leftTree;
                    root->right = rightTree;
                    trees.push_back(root);
                }
            }
        }

        memo[key] = trees;
        return trees;
    }
};