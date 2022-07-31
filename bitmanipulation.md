# to find missing and repeated numbers [1,n] in which one may be repeated
```cpp
    int findDuplicate(vector<int>& nums) {
        int xor_1=nums[0];
        for(int i=1;i<nums.size();i++){
            xor_1=nums[i] ^ xor_1; 
        } 
        // here repeated number and missing number is not present as repeated nuber is cancelled out
        for(int i=1;i<=nums.size();i++){
            xor_1=xor_1 ^ i; 
        }
        // here xorans will be x ^ y where x = repeated number , y = missing number
        int st1=-1,st2=-1;
        int xor_2 = xor_1 & ~(xor_1-1); //right most set bit
        // as it is set thet meanss one of the number is set at that pos and one of them is not set as in xor only 1 is possible is 1 ^ 0 = 1
        for(int num : nums){
            if(xor_2&num){ //xors all numbers with 
                st1=st1==-1?num:st1^num;
            }else{
                st2=st2==-1?num:st2^num;
            }
        }
        for(int i=1;i<=nums.size();i++){
            if(i&xor_2){
                st1=st1 ^ i;
            }else{
                st2=st2^i;
            }
        }
        cout<<st1<<" "<<st2;
    }
```