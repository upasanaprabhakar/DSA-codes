class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        stack<TreeNode*>st;
        TreeNode*node=root;
        while(node || st.size()>0){
            if(node){
                st.push(node);
                node=node->left;
            }
            else{
                TreeNode*temp=st.top();
                st.pop();
                ans.push_back(temp->val);
                node=temp->right;
            }
        }
        return ans;
    }
};