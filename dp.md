# catalan number
```cpp
    unordered_map<int,int> dp;
    int findCatalan(int n) {
        if(n<=1)return 1;
        if(dp.find(n)!=dp.end())return dp[n];
        int ans=0;
        for(int i=0;i<n;i++)
        ans=ans+findCatalan(i)*findCatalan(n-1-i);
        return dp[n]=ans;
    }
```