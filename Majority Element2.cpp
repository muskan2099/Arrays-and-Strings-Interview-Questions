class Solution {
public:
    vector<int> majorityElement(vector<int>& input) {
        int n = input.size();
        
        if(n == 0){
            vector<int> output;
            return output;
        }
        
        int count1 = 0;
        int count2 = 0;
        int val1 = 0;
        int val2 = 1;
        
        for(int i = 0; i < n; i++){
            if(input[i] == val1){
                count1 ++;
            }
            else if(input[i] == val2){
                count2++;
            }
            else{
                if(count1 == 0){
                    val1 = input[i];
                    count1 = 1;
                }
                else if(count2 == 0){
                    val2 = input[i];
                    count2 = 1;
                }
                else{
                    count1--;
                    count2--;
                }
            }
        }
        cout << val1 << " " << val2 << endl;
        count1 = 0;
        count2 = 0;
        for(int i = 0; i < n; i++){
            if(input[i] == val1){
                count1++;
            }
            if(input[i] == val2){
                count2++;
            }
        }
        vector<int> ans;
        if(count1 > n/3){
            ans.push_back(val1);
        }
        if(count2 > n/3){
            ans.push_back(val2);
        }
        return ans;
    }
};