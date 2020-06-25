class Solution {
public:
	int tonum(int *input, int n){
		int ans = 0;
		for(int i = 0; i < n; i++){
			ans = ans*10 + input[i];
		}
		return ans;
	}
    int maximumSwap(int num) {
    	int n = 0;
    	int temp = num;
    	while(temp > 0){
    		temp = temp/10;
    		n++;
    	}
        if(n == 1){
        	return num;
        }
       // cout<< n << endl;
        int* input = new int[n];
        int count = n-1;
        while(count >= 0){
        	input[count] = num%10;
        	num = num/10;
        	count--;
        }
        
        
        int partition = 0;
        int i = 1;
        while(i < n && input[i] <= input[partition]){
        	partition++;
        	i++;
        }
        if(partition == n-1){
        	return tonum(input, n);
        }
        cout << partition << endl;
        
        int maxelement = INT_MIN;
        int maxindex = -1;
        for(int j = partition + 1; j < n; j++){
        	if(input[j] >= maxelement){
        		maxelement = input[j];
        		maxindex = j;
        	}
        }
        int toswap = -1;
        int toswapindex = -1;
        for(int j = 0; j < maxindex; j++){
        	if(input[j] < maxelement){
        		toswap = input[j];
        		toswapindex = j;
        		break;
        	}
        }
        swap(input[toswapindex], input[maxindex]);
        return tonum(input, n);
    }
};