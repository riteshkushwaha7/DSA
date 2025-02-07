class Solution {
public:
    void Heapify(vector<int>& nums, int N, int i) {
        int largest = i;
        int l = 2 * i + 1;
        int r = 2 * i + 2;

        if (l < N && nums[l] > nums[largest])
            largest = l;

        if (r < N && nums[r] > nums[largest])
            largest = r;

        if (largest != i) {
            swap(nums[i], nums[largest]);
            Heapify(nums, N, largest);
        }
    }

    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();

        for (int i = (n - 1) / 2; i >= 0; i--) {
            Heapify(nums, n, i);
        }

        for (int i = n - 1; i >= n - k; i--) {  
            swap(nums[0], nums[i]);
            Heapify(nums, i, 0);
        }

        return nums[n - k];  
    }
};
