// Complete the countTriplets function below.
long countTriplets(vector<long> arr, long r) {
    long result = 0;
    if(arr.size()<3) return result;
    
    unordered_map<long, long> left, right;
    
    for(long num : arr) right[num]++;
    
    for(long mid : arr){
        right[mid]--;
        if(mid%r == 0){
            int a = mid / r;
            int b = mid * r;
            
            result += (left[a] * right[b]);
        }
        left[mid]++;
    }
    
    return result;
}
