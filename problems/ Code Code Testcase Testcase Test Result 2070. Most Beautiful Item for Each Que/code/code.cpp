class Solution {
public:
    int bin(vector<vector<int>>&ans,int num)
    {
        int l=-1;
        int r=ans.size();

        while(r>l+1)
        {
            int mid=(l+r)/2;
            if(ans[mid][0]<=num)
            l=mid;
            else
            r=mid;
        }
        if(l==-1)
        return 0;

        return ans[l][1];
    }
    vector<int> maximumBeauty(vector<vector<int>>& ans, vector<int>& q) {
        
        vector<vector<int>> res;
        int i=0;
        int n=ans.size();
        sort(ans.begin(),ans.end());

        int num=0;
        while(i<n)
        {
            int j=i+1;
            num=max(num,ans[i][1]);
            while(j<n && ans[i][0]==ans[j][0])
            {
                num=max(num,ans[j][1]);
                j++;
            }
            res.push_back({ans[i][0],num});
            i=j;
        }

        vector<int> v;
        for(auto num:q)
        {
            int n=bin(res,num);
            v.push_back(n);
        }
        return v;
    }
};
