class Solution:
    def rotate(self, arr: List[List[int]]) -> None:
        """
        Do not return anything, modify matrix in-place instead.
        """

        
        n = len(arr)
        for i in range(n):
            for j in range(n):
                if(i<=j):
                    arr[i][j], arr[j][i] = arr[j][i], arr[i][j]
        
        for i in range(n):
            for j in range(n//2):
                arr[i][j], arr[i][n-j-1] = arr[i][n-j-1], arr[i][j]

        for i in arr:
            print(i)
            