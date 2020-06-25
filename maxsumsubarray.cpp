#include <bits/stdc++.h>
using namespace std;
vector<int> kadane(int input[], int n){
	int start = 0;
	int s = 0;
	int end = 0;  
	int sum = 0;
	int maxsum = INT_MIN;

	for(int i = 0; i < n; i++){
		sum += input[i];
		if(sum > maxsum){
			maxsum = sum;
			end = i;
		}
		if(sum < 0){
			sum = 0;
			start = i+1;
		}
	}
	vector<int> output;
	for(int i = start; i <= end; i++){
		output.push_back(input[i]);
	}
	return output;
}
int main(){
	int input[4] = {-2,-3,-4,1};
	
	vector<int> output = kadane(input,4);
	for(int i = 0; i < output.size(); i++){
		cout << output[i] << endl;
	}
	return 0;
}