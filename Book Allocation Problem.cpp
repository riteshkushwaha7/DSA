class Solution {
  public:
  
    int students(vector<int> arr,int pages){
        int stu = 1; 
        int pagesstu = 0;
        for(int i = 0; i<arr.size(); i++){
            if(pagesstu+arr[i]<=pages){
                pagesstu +=arr[i];
            }else {
                pagesstu = arr[i];
                stu++;
            }
        }
        return stu;
    }
    
    int findPages(vector<int> &arr, int k) {
        if(k>arr.size()) return -1;
        int low = *max_element(arr.begin(), arr.end());
        int high = accumulate(arr.begin(), arr.end(), 0);
        
        while(low<=high){
            int mid = (low + high)/2;
            if(students(arr,mid)>k) low = mid+1;
            else high = mid-1;
        }
    
        return low;
    }
    
};
