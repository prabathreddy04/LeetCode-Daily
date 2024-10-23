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
    TreeNode* replaceValueInTree(TreeNode* root) {
        vector<int> sums;
        queue<TreeNode *> q;
        q.push(root);

        while(!q.empty()) {
            int s= q.size();
            int sum = 0;
            for(int i=0; i<s; i++){
                TreeNode *temp = q.front();
                q.pop();
                sum+=temp->val;
                if(temp->left)  q.push(temp->left);
                if(temp->right) q.push(temp->right);
            }
            sums.push_back(sum);
        }
        cout<<sums.size()<<endl;
        root->val=0;
        q.push(root);
        int level = 0;
        while(!q.empty()){
            int s=q.size();
            int sum;
            level++;
            for(int i=0; i<s; i++){
                TreeNode *temp = q.front();
                q.pop();
                sum=0;
                if(temp->left){
                  q.push(temp->left);
                  sum= sum + temp->left->val;
                }
                if(temp->right){
                     sum+= temp->right->val;
                     q.push( temp->right);
                }
                if(temp->left)  temp->left->val = abs( sums[level]- sum);
                if(temp->right) temp->right->val = abs( sums[level] - sum);
            }
        }
        cout<<level;
        return root;
    }
};
