class Solution {
public:
    int minimumSum(int num) {
        int res = 0;
        int arr[4];
        int i = 0;
        for(char c: to_string(num)){
            arr[i++] = c-48;  
        }   
        sort(arr,arr+4);
        return res = arr[0]*10+arr[1]*10+arr[2]+arr[3];
    }
};
