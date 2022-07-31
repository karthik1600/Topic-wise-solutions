# `Inversion ccount`
```cpp
long merge(int l,int r,int mid,vector<int>& arr,vector<int> temp){
    long count = 0;
    
    int i=l,j=mid+1,k=l;
    while(i<=mid && j<=r){
        if(arr[i]<=arr[j]){
            temp[k++] = arr[i++];
        }else{ // it is smaller than all elements [i...mid] => len = mid - i + 1
            count+=mid-i+1;
            temp[k++] = arr[j++];
        }
    }
    while(i<=mid)temp[k++]=arr[i++];
    while(j<=r)temp[k++]=arr[j++];
    for(int i=l;i<=r;i++)arr[i] = temp[i];
    return count;
}
long mergeS(int l,int r,vector<int>& arr,vector<int> temp){
    long count = 0;
    if(l<r){
        int mid = l + (r-l)/2;
        count+= mergeS(l,mid,arr,temp);
         count+= mergeS(mid+1,r,arr,temp);
         count+= merge(l,r,mid,arr,temp);
    } 
    return count;
}
long countInversions(vector<int> arr) {
        int l=0,r=arr.size()-1;
        vector<int> temp(r-l+1);
        long count = mergeS(l,r,arr,temp);
        return count;
}
```
- just need to know if `a[i]>a[j]` then every element from `[i...mid]` is greater than `a[j]` = > `mid-i+1`