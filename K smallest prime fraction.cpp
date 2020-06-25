class Point{ 
        
    public : 
       int x; 
       int y; 
       double val;
    
       Point(int m, int n, double calc){ 
           
          x = m; 
          y = n; 
          val = calc;
           
       } 
    }; 
    bool operator>(Point p1, Point p2){
        return p1.val > p2.val;
    }
class Solution {
public:
   
    vector<int> kthSmallestPrimeFraction(vector<int>& A, int K) {

        priority_queue<Point, vector<Point>, greater<Point>> heap;
        for(int i = 1; i < A.size(); i++){
        	           
            double calc = double(A[0])/double(A[i]);
            
            Point temp(0, i, calc);
        	heap.push(temp);
        }
        int denominator;
        int numerator;

        int count = 0;
        vector<int> output;

        while(count < K){
        	Point front = heap.top();
        	heap.pop();

        	numerator = front.x;
        	denominator = front.y;

        	count++;
            double calc = double(A[numerator + 1])/double(A[denominator]);
            
            Point temp(numerator + 1, denominator, calc);
            
            heap.push(temp);
        }
        
        output.push_back(A[numerator]);
        output.push_back(A[denominator]);
        return output;
    }
};

// binary Search Approach
class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
      int n = arr.size();
       double low = 0;
       double high = 1;

       int count = 0;
       int p = 0;
       int q = 1;

       while(true){
          double mid = (low + high)/2;
          count = 0;
          int j = i;
          int temp = n - j;
          for(int i = 0; i < n; i++){
            while(j < n && arr[i] < mid*arr[j]){
              j++;
              temp--;
            }
            count += temp;
            if(p*arr[j] < q*arr[i]){
              p = arr[i];
              q = arr[j];
            }
          }

          if(count < k){
            low = mid;
          }
          else if(count > k){
            high = mid;
          }
          else{
            vector<int> output;
            output.push_back(p);
            output.push_back(q);

            return output;
          }
       } 
    }
};