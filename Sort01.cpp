#include <bits/stdc++.h>
using namespace std;
void sort12(int *input , int n){
    
    int i = 0;
    int j = 0;
    
    while(i < n && j < n){
        
        if(input[j] == 1){
            j++;
        }
        else{
            swap(input[i], input[j]);
            i++;
            j++;
        }
    }
}
int main(){
    
    int n;
    cin >> n;
    
    int *input = new int[n];
    for(int i = 0; i < n; i++){
        cin >> input[i];
    }
    sort12(input, n);
    
    for(int i = 0; i< n; i++){
        cout << input[i] << endl;
    }
    return 0;
}