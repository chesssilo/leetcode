class Solution {
    class Iterator {
        vector<TreeNode*> path;

        void pathToFirst(TreeNode *root) {
            while (true) {
                path.push_back(root);
                if (root->left != nullptr) {
                    root = root->left;
                } else if (root->right != nullptr) {
                    root = root->right;
                } else {
                    return;
                }
            }
        }

public:
        Iterator(TreeNode *root) {
            if (root == nullptr) {
                return;
            }
            pathToFirst(root);
        }

        bool hasNext() const {
            return !path.empty();
        }

        int next() {
            assert(!path.empty());
            TreeNode* ans = path.back();
            while (true) {
                TreeNode* last = path.back();
                path.pop_back();
                if (path.empty()) {
                    break;
                }
                TreeNode* parent = path.back();
                if (parent->left == last) {
                    if (parent->right != nullptr) {
                        pathToFirst(parent->right);
                        break;
                    } else {
                        continue;
                    }      
                } else {
                    assert(parent->right == last);
                }
            }
            return ans->val;
        }
    };

public:
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        Iterator it1(root1);
        Iterator it2(root2);
        while (true) {
            if (!it1.hasNext() && !it2.hasNext()) {
                return true;
            }
            if (!it1.hasNext() || !it2.hasNext()) {
                return false;
            }
            if (it1.next() != it2.next()) {
                return false;
            }
        }
    }
};