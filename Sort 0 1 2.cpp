class Solution {
public:
    void sortColors(vector<int>& input) {
        
        int n = input.size();
        int i = 0;
        int j = 0;
        int k = n-1;
        while(j <= k){

            if(input[j] == 0){
                swap(input[i], input[j]);
                i++;
                j++;
            }
            else if(input[j] == 1){
                j++;
            }
            else{
                swap(input[j], input[k]);
                k--;
            }
        }
    }
};8jjjjj