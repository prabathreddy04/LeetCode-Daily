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
    long long kthLargestLevelSum(TreeNode* root, int k) {
        queue<TreeNode*> q;
        q.push(root);
        vector<long long> sum ;
        priority_queue<int , vector<int> , greater<int>> pq;
        while(!q.empty()){
            int s = q.size();
            long long sums = 0;
            for(int i=0; i<s; i++){
                TreeNode *temp = q.front();
                q.pop();
                if(temp->left)  q.push(temp->left);
                if(temp->right) q.push(temp->right);
                sums += temp->val;
            }
            if(pq.size()<k) pq.push(sums);
            else{
                long long l = pq.top();
                pq.pop();
                pq.push(max(l, sums));
            }
            sum.push_back(sums);
        }
        sort(sum.begin(), sum.end());
        if(k>sum.size())    return -1;
        return sum[sum.size()-k];
    }
};
