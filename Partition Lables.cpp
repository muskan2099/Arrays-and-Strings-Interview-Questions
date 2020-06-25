class Solution {
public:
    vector<int> partitionLabels(string S) {
        
        int n = S.length();
        
        if(n == 1){
            vector<int> output;
            output.push_back(1);
            return output;
        }
        unordered_map<char, int> hash;
        for(int i = 0; i < n; i++){
        	hash[S[i]] = i;
        }

        int end = hash[S[0]];
        int start = 0;
        int upperlimit;

        vector<int> res;
        
        if(end == 0){
            res.push_back(1);
            start = 1;
        }

        for(int i = 1; i < n; i++){
        	upperlimit= hash[S[i]];
        	if(upperlimit > end){
        		end = upperlimit;
        	}
        	if(i == end){
        		res.push_back(i - start + 1);
        		start = i + 1;
        	}
        }
        return res;
    }
};