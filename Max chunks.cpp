class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int n = arr.size();
        int count = 0;
        int maxelement = INT_MIN;
        for(int i= 0; i < n; i++){
            maxelement = max(maxelement, arr[i]);
            if(maxelement == i){
                count++;
            }
        }
        return count;
    }
};