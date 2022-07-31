# min window substring
```
Given two strings s and t of lengths m and n respectively, return the minimum window substring of s such that every character in t (including duplicates) is included in the window. If there is no such substring, return the empty string "".
```
```cpp
    string minWindow(string s, string t) {
        unordered_map<char,int> need;    //used to hold the count of each character in 
        int minlen=s.size()+1,minstart=-1;
        int start=0,end=0;
        int counter = t.size();
        for(char c:t){
            need[c]++; 
        }
        while(end<s.size()){
            if(need[s[end]]>0){ // if the character is needed thenn we can decrease
                counter--;
            }
            need[s[end]]--;
            while(counter==0){
                int currLen = end-start+1;
                if(minlen>currLen){
                   minlen=currLen;
                   minstart=start;
                }
                need[s[start]]++; // we dont use use  start character now so inc need
                if(need[s[start]]>0){ // as this character is needed then we increase the counter while moving the window
                    counter++;
                }
                start++; //moving the window
            }
            end++;
        }
        return minlen==s.size()+1?"":s.substr(minstart,minlen);
         
    }
```
# min window with sum greater than equal to target
```cpp
    int minSubArrayLen(int target, vector<int>& nums) {
        int start=0,end=0,minlen=nums.size()+1;
        long long int windowSum=0;
        while(end<nums.size()){
            windowSum+=nums[end];
            while(windowSum>=target){
                int currWindowSize = end-start+1;
                minlen=min(minlen,currWindowSize);
                windowSum=windowSum-nums[start];
                start++;
            }
            end++;
        }
        return minlen==nums.size()+1?0:minlen;
        
    }
```
# Longest Substring with At Most Two Distinct Characters
```cpp
    int lengthOfLongestSubstringTwoDistinct(string &s) {
        unordered_map<char,int> count;
        int end=0,start=0;
        int maxlen  = 0;
        int distinct = 0;
        while(end<s.size()){
            count[s[end]]++;
            if(count[s[end]]==1)distinct++;
            while(distinct>2){
                if(count[s[start]]==1)distinct--;
                count[s[start]]--;
                start++;
            }
            int currLen= end - start + 1;
            maxlen= max(maxlen,currLen);
            end++;
        }
        return maxlen;
    }
```
# Longest Substring with At Most K Distinct Characters
```cpp
    int lengthOfLongestSubstringKDistinct(string &s, int k) {
        unordered_map<char,int> count;
        int end=0,start=0;
        int maxlen  = 0;
        int distinct = 0;
        while(end<s.size()){
            count[s[end]]++;
            if(count[s[end]]==1)distinct++;
            while(distinct>k){
                if(count[s[start]]==1)distinct--;
                count[s[start]]--;
                start++;
            }
            int currLen= end - start + 1;
            maxlen= max(maxlen,currLen);
            end++;
        }
        return maxlen;
    }
```
# sliding window maximum
```
Input: nums = [1,3,-1,-3,5,3,6,7], k = 3
Output: [3,3,5,5,6,7]
Explanation: 
Window position                Max
---------------               -----
[1  3  -1] -3  5  3  6  7       3
 1 [3  -1  -3] 5  3  6  7       3
 1  3 [-1  -3  5] 3  6  7       5
 1  3  -1 [-3  5  3] 6  7       5
 1  3  -1  -3 [5  3  6] 7       6
 1  3  -1  -3  5 [3  6  7]      7
```
```cpp
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;
        vector<int> res;
        int ans=INT_MAX;
        for(int i=0;i<nums.size();i++){
            while(dq.size()>0 && nums[dq.back()]<=nums[i]){
                dq.pop_back();
            }
            dq.push_back(i);
            if(i>=k-1){
                int currAns = nums[dq.front()];
                res.push_back(currAns);
                int stInd = i - k + 1; // +1 as 0 indexed
                if(dq.front()==stInd){
                    dq.pop_front();
                }
            }
        }
        return res;
    }
```