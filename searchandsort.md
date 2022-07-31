# median of 2 arrays that are sorted
```cpp
double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.size()>nums2.size())return findMedianSortedArrays(nums2,nums1);
        bool isodd=(nums1.size()+nums2.size())%2;
        int k=(nums1.size()+nums2.size()+1)/2;
        int l=0;
        int r=nums1.size();
        while(l<=r){
            int mid=(l+r)/2;
            int cut1=mid;
            int cut2=k-mid;
            int l1,l2,r1,r2;
            l1=cut1==0?INT_MIN:nums1[cut1-1]; //if no ele in num1 selected
            l2=cut2==0?INT_MIN:nums2[cut2-1];
            r1=cut1==nums1.size()?INT_MAX:nums1[cut1];// if all ele of num1 selected
            r2=cut2==nums2.size()?INT_MAX:nums2[cut2];
            if(l1<=r2&&l2<=r1){
                if(!isodd){
                    return (double)(max(l1,l2)+min(r1,r2))/2;
                }
                return max(l1,l2);
            }else if(l1>r2){
                r=mid-1;
            }else if(l2>r1){
                l=mid+1;
            }
        }
        return 0.0;
    }
    // num1<num2 
```
- `num1<num2 `
- if all ele in any are selected then r of that is +inf as l of other will then always be less than r

---
# dutch national flag
```cpp
void sortColors(vector<int>& nums) {
        int start=0,end=nums.size()-1;
        int curr=0;
        while(curr<=end){       /// tricky here as when end-- curr===end so we need to check curr again 
            if(nums[curr]==0){
                swap(nums[start],nums[curr]);
                curr++;
                start++;
            }else if(nums[curr]==1){
                curr++;
            }else{
                swap(nums[curr],nums[end]);
                end--;
            }
        }
    }
```
---
# `find pivot in sorted array`
eg: `[4,5,6,7,0,1,2]` pivot = `0`
```cpp
int pivot(vector<int>& nums) {
        int left=0,right=nums.size()-1;
        while(left<right)
        {
            int mid=(left+right)/2;
            if(nums[mid]>nums[right])
                left=mid+1;
            else
                right=mid;
        }
        return left;
    }
```
# search in rot sorted array with dupl
![](pics\srotsort.png)
```cpp
bool search(vector<int>& nums, int target) {
        int start=0,end=nums.size()-1;
        int l=start,r=end;
        while(l<=r){
            int mid=(l+r)/2;
            if(nums[mid]==target)return true;
            else if(nums[mid]>nums[l]){ //when target in first half of array 
                if(target<nums[mid]&&target>=nums[l]){
                    r=mid-1;
                }else {
                    l=mid+1;
                }
            }else if(nums[mid]<nums[r]){
                if(target>nums[mid]&&target<=nums[r]){
                    l=mid+1;
                }else{
                    r=mid-1;
                }
            }else{
                if(nums[mid]==nums[l]){  //to exclude if 
                    l++;
                }
                if(nums[mid]==nums[r]){
                    r--;
                }
            }
        }
        return false;
    }
```
---
# `Find Peak Element`
```
Input: nums = [1,2,1,3,5,6,4]
Output: 5
Explanation: Your function can return either index number 1 where the peak element is 2, or index number 5 where the peak element is 6.
```
![](https://assets.leetcode.com/users/images/d2fdc688-542e-434c-8969-f151b2286313_1624387000.3221495.png)
```cpp
    int getleft(int mid,vector<int> nums){
        if(mid==0)return INT_MIN;
        else
            return nums[mid-1];
    }
    int getright(int mid,vector<int> nums){
        if(mid+1==nums.size())return INT_MIN;
        else
            return nums[mid+1];
    }
    int findPeakElement(vector<int>& nums) {
        int l=0,r=nums.size()-1;
        while(l<=r){
            int mid=(l+r)/2;
            int midl=getleft(mid,nums);
            int midr=getright(mid,nums);
            if(nums[mid]>=midl&&nums[mid]>=midr){
                return mid;
            }else if(nums[mid]<midl){
                r=mid-1;
            }else if(nums[mid]<midr){
                l=mid+1;
            }
        }
        return -1;
    }
```
---
# largest array sum
```
Given an array nums which consists of non-negative integers and an integer `m`, you can split the array into `m` non-empty continuous subarrays.Write an algorithm to minimize the largest sum among these m subarrays.
```
```cpp
int Parts(vector<int>& nums,int maxp){
        int sum=0,parts=1;
        for(int num:nums){
            if(sum+num>maxp){
                parts++;
                sum=num;
            }else{
                sum+=num;
            }
        }
        return parts;
    }
    int splitArray(vector<int>& nums, int m) {
        int l=INT_MIN,r=0;
        for(int num:nums){
            l=max(num,l);
            r+=num;
        }
        int ans=-1;
        while(l<=r){
            int mid=(l+r)>>1;
            int parts=Parts(nums,mid);
            if(parts>m){
                l=mid+1;
            }else{
                ans=mid;
                r=mid-1;
            }
        }
        return ans;
    }
```