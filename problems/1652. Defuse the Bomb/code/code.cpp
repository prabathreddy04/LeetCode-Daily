class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        vector<int> result(code.size());
        int n = code.size();
        if(k==0){
            result = vector<int>(code.size(), 0);
            return result;
        }
        int l = k;
        if(k<0){
            k*=-1;
            reverse(code.begin(), code.end());
        }
        cout<< k;
        for(int i=0; i<n; i++){
            int s=0;
            for(int j=1; j<=k; j++){
                if(i+j >= n){
                   s+=code[abs(n-(i+j)) ] ;
                }else{
                    s+=code[i+j];
                }
            }
            result[i]=s;
        }
        if(l<0) reverse(result.begin(), result.end());
        return result;
    }
};
