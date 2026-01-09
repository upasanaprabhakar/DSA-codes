class Solution {
public:
    unordered_map<int,int> mp;
    int maxD = 0;

    TreeNode* LCA(TreeNode* root){
        if(root == NULL || mp[root->val] == maxD){
            return root;
        }

        TreeNode* l= LCA(root->left);
        TreeNode* r= LCA(root->right);

        if(l && r){
            return root;
        }

        return l != NULL ? l : r;
    }

    void depth(TreeNode* root, int d){
        if(!root){
            return;
        }

        maxD = max(maxD, d);
        mp[root->val] = d;
        depth(root->left, d+1);
        depth(root->right, d+1); 
    }

    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        depth(root, 0);

        return LCA(root);
    }   
};