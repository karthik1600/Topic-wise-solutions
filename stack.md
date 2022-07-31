# `Next Greatest variation`
```cpp
vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n=temperatures.size();
        stack<int> st;
        vector<int> res(temperatures.size(),0);
        for(int i=0;i<n;i++){
            while(st.size()&&temperatures[i]>temperatures[st.top()]){
                res[st.top()]=i-st.top();
                st.pop();
            }
            st.push(i);
        }
        return res;
    }
```
- at any i we are
    - checking if `cur[i]` > `st.top()` as then the curr ele is next greater of top as in stack all are in descending order
---
# `largest rectangle in histogram`
![]()
```cpp
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        heights.push_back(0); //so thaat we can check with last bar too
        st.push(-1); //for easier calculation of left boundry
        int maxArea=0;
        for(int i=0;i<heights.size();i++){
            int currh= heights[i];
            while(st.top()!=-1 && currh<heights[st.top()]){ //when currheight < st height and this makes it so stack is always increasing
                int height = heights[st.top()];
                st.pop(); //as we need point location and not bar location
                int left = st.top();  //left part of recangle
                int right = i-1; // right part of rectangle
                int base = right - left;
                int area = base*height;
                maxArea=max(maxArea,area);
            }
            st.push(i);
        }
        return maxArea;
    }
```
---
# `maximal rectangle`
![](pics\maxrectangleinmatrix.png)
```cpp

int maximalRectangle(vector<vector<char>>& matrix) {
        if(matrix.size()==0)return 0;
        vector<int> heights(matrix[0].size(),0);
        int area=0;
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                heights[j]=matrix[i][j]=='1'?heights[j]+1:0;
            }
            int currarea=largestRectangleArea(heights); //previous ques
            area=max(area,currarea);
        }
        return area;
    }
```
---
# remove duplicate letters
![](pics\st3.png)
```cpp
string removeDuplicateLetters(string s) {
    vector<int> count(26,0),seen(26,0);
    for(int i=0;i<s.size();i++){
        count[s[i]-'a']++;
    }
    stack<char> ans;
    for(int i=0;i<s.size();i++){
        count[s[i]-'a']--;
        if(seen[s[i]-'a'])continue;
        seen[s[i]-'a']=1;
        while( !ans.empty() && ans.top()>s[i] && count[ans.top()-'a']>0 ){
            //ans stack not empty
            //the curr char has lesser val than one in ans so we can hope to make it replace the character of ans
            // to be able to delete a character from ans that character should be present after current character
            seen[ans.top()-'a']=0;
            ans.pop();
        }
        ans.push(s[i]);
    }
    string res="";
    while(!ans.empty()){
        res=res+ans.top();
        ans.pop();
    }
    reverse(res.begin(),res.end());
    return res;
}
```