class Solution {
public:
   int getSum(int n){
    int sum = 0;
    while(n>0){
    int digit = n%10;
    sum = sum+digit*digit;
    n = n/10;
    }
    return sum;
   }
    bool isHappy(int n) {
        unordered_set<int>st;
        while(n!=1){
            if(st.find(n)!=st.end()){
                return false;
            }
            st.insert(n);
            n = getSum(n);
        }
        return true;
    }
};