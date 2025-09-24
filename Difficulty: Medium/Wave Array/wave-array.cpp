class Solution {
  public:
    void sortInWave(vector<int>& arr) {
        // code here
        for(int i= 0 ; i < arr.size() - 1 ; i++){
            if(i % 2 == 0 && arr[i] < arr[i + 1] || i % 2 == 1 && arr[i] > arr[i + 1])swap(arr[i], arr[ i  + 1]);
        }
        
    }
};