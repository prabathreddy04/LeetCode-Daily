class Solution {
public:
    long long minEnd(int n, int x) {
        vector<short> vec;
        long long cur = x;
        long long calc = n - 1;

        for(int i = 0; i < 32; i++) 
            if(!((1 << i) & x))
                vec.push_back(i);

        for(int i = 32; i < 64; i++)
            vec.push_back(i);

        for(int i = 0; calc > 0; i++, calc >>= 1) {
            cur += (calc & 1) << vec[i];
        }

        return cur;
    }
};
