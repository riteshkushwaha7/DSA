class Solution{
public:
    void Heapify(int i, vector<int> &arr, int N){
        int largest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        if (left < N && arr[left] > arr[largest]) 
            largest = left;
        if (right < N && arr[right] > arr[largest]) 
            largest = right;

        if (largest != i) {
            swap(arr[i], arr[largest]);
            Heapify(largest, arr, N);
        }
    }

    void convertMinToMaxHeap(vector<int> &arr, int N){
        for (int i = (N/2) - 1; i >= 0; i--) {
            Heapify(i, arr, N);
        }
    }
};
