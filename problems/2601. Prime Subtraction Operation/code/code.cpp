class Solution {
public:
    bool isPrime(int n) {
    if (n <= 1) return false;  // Handle small cases
    if (n == 2 || n == 3) return true;  // 2 and 3 are primes
    if (n % 2 == 0 || n % 3 == 0) return false;  // Handle divisibility by 2 and 3
    
    for (int i = 5; i * i <= n; i += 6) {  // Check up to sqrt(n)
        if (n % i == 0 || n % (i + 2) == 0) return false;
    }
    return true;
}

    bool func(int &a, int b){
        cout<<a<<" "<<b<<endl;
        for(int i= a-b+1 ; i<a; i++){
            if(isPrime(i) && a-i < b){
                a-=i;
                cout<<a;
                return true;
            }
        }
        return false;
    }
    bool primeSubOperation(vector<int>& nums) {
        int n = nums.size();
        for(int i= n-2; i>=0 ; i--){
            if(nums[i]<nums[i+1])   continue;
            bool flag = func(nums[i], nums[i+1]);
            cout<<nums[0];
            if(!flag)   return false;
        }
        return true;
    }
};
