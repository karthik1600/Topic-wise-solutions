# 56. Merge Intervals
```cpp
    # define vvi vector<vector<int>>
    # define vi vector<int>
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vvi ans;
        if(intervals.size()==0)return ans;
        sort(intervals.begin(),intervals.end());
        vi currint = intervals[0];
        for(int i=1;i<intervals.size();i++){
            vi interval = intervals[i];
            if(interval[0]>currint[1]){
                ans.push_back(currint);
                currint=interval;
            }else{
                if(interval[1]>currint[1]){
                    currint[1]=interval[1];
                }
            }
        }
        ans.push_back(currint);
        return ans;
    }
```
---
# Non-overlapping Intervals
no. of min intervals to remove to make it non overlapping
```cpp
    static bool compare(vector<int> &a,vector<int> &b){
        return a[1]<b[1]; //according to end time
    }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),compare);
        int end=intervals[0][1];
        int count=1; //including first one
        for(int i=1;i<intervals.size();i++){
            if(intervals[i][0]>=end){  // e]  [s  =>valid
                count++;
                end=intervals[i][1];
            }
        }
        return intervals.size()-count;
    }
```
---
# interval intersections of 2 lists
```cpp
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        int i=0,j=0;
        vector<vector<int>> res;
        while(i<firstList.size()&&j<secondList.size()){
            int lb=max(firstList[i][0],secondList[j][0]);
            int ub=min(firstList[i][1],secondList[j][1]);
            if(lb<=ub)
                res.push_back({lb,ub});
            if(firstList[i][1]<secondList[j][1]){
                i++;
            }else{
                j++;
            }
        }
        return res;
    }
```
# minimum number of meeting rooms reqd
```cpp
    int minMeetingRooms(vector<Interval> &intervals) {
        vi start,end;
        for(auto interval:intervals){
            start.push_back(interval.start);
            end.push_back(interval.end);
        }
        sort(start.begin(),start.end());
        sort(end.begin(),end.end());
        int endInd=0;
        int rooms=0;
       for(int st:start){ //all meeting that starts we assume it needs one room atleast
           rooms++;
            if(st>=end[endInd]){ //if a previous meeting is done we move the current meeting there 
            // so we remove the room we prev allocated 
                endInd++; //move to the next meeting which can be ended
                rooms--; //we remove one room as that meeting is done
            }
        }
        return rooms;
        
    }
```
# min number of platforms reqd
```cpp
int calculateMinPatforms(int at[], int dt[], int n) {
    if(n==0)return 0;
    sort(at,at+n);
    sort(dt,dt+n);
    int platforms=0,deptInd=0;
    for(int i=0;i<n;i++){
        platforms++;
        if(at[i]>=dt[deptInd]){
            platforms--;
            deptInd++;
        }
    }
    return platforms;
}
```