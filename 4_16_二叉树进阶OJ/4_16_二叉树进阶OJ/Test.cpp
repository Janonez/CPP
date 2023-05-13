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

//class Solution {
//public:
//    string tree2str(TreeNode* root) {
//        if (root == nullptr)
//        {
//            return "";
//        }
//        string str = to_string(root->val);
//        // 左子树省略时，左右都为空，省略
//        // 左子树不为空，进入if，不省略
//        // 左子树为空，右子树不为空，进入if，不省略
//        // 左子树为空，右子树也为空时，省略，不进入if
//        if (root->left || root->right)
//        {
//            str += "(";
//            str += tree2str(root->left);
//            str += ")";
//        }
//        // 何时省略右子树，只要右子树不存在时就省略
//        if (root->right)
//        {
//            str += "(";
//            str += tree2str(root->right);
//            str += ")";
//        }
//        return str;
//        // if(root == nullptr)
//        //     return "";
//        // if(root->left == nullptr && root->right == nullptr)
//        // {
//        //     return to_string(root->val);
//        // }
//        // if(root->right == nullptr)
//        // {
//        //     return to_string(root->val) + "(" + tree2str(root->left) + ")";
//        // }
//        // return to_string(root->val) + "(" + tree2str(root->left) + ")"+ "(" + tree2str(root->right) + ")";
//    }
//};

