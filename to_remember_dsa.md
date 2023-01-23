# HashMap in JAVA:

```
HashMap<Integer,Integer> hm =  new HashMap<>();
for(int n : arr) {
		hm.put(n,hm.getOrDefault(n,0)+1);
}
```

## Power mod:
```
int power_mod(int x,int y,int m){
    int res = 1;
    x = x%m;
    if(x == 0) 
        return 0;
    while(y>0){
        if(y&1) res = (res * x)%p;
        y >>= 1;
        x = (x * x)%p; 
    }
}

int fun(int a,int b) {
	if(b == 0) return 1;
	int temp = fun(a,b/2);
	if(b%2 != 0) return temp*temp*a;
	return temp*temp;
}
```

## Linear Search:
```
bool fun(vector<int> &arr,int n,int key){
    for(int i = 0;i < n;i++){
        if(key == arr[i])return true;
    }
    return false;
}
```

## Binary search:
```
bool fun(vector<int> &arr,int n,int key){
    int l = 0, h = n-1;
    while(l <= h){
        int mid = (h-l)/2 + l;
        if(arr[mid] == key) return true;
        else if(arr[mid] > key)
            h = mid-1;
        else 
            l = mid+1;
    }
}

```

## Subarrays sum:
```

int fun(vector<int> &arr,int n){
    int res = INT_MIN;
    for(int i = 0;i < n;i++){
        int sum = 0;
        for(int j = 0;j < n;j++){
            sum+=arr[j];
        }
        res = max(sum,res);
    }
    return res;
}
```

## Subsets sum
```
vector<int> fun(vector<int> &arr,int n){
	vector<int> res;
	int sum = 0;
}
```

## Sieve of Eratosthenes
```
void fun(int n){
	vector<bool> pr(n+1,true);
	for(int i = 2;i*i <= n;i++){
		if(pr[i] == true){
			for(int j = i*i;j<=n;j+=i){
					pr[j] = false;
			}
		}
	}
	for(int i = 2;i<=n;i++){
		if(pr[i]) cout<<i<<" ";
	}
}
```
# Linked List Class:
```
class Node{
	int val;
	Node prev,next;
	Node (int ele){
		this.val = ele;
		this.prev = this.next = null;
	}
}
```
# Binary Tree:
```
class Node{
	int val;
	Node left,right;
	Node (int ele){
		this.val = ele;
		this.left = this.right = null;
	}
}
```

# Flatening a BST:
```
Node rightmost(Node root){
	if(root == null)return root;
	return rightmost(root.right);
}
void flatten(Node root){
	if(root == null)return;
	while(root != null){
		if(root.left != null){
			rmost = rightmost(root.left);
			nextr = root.right;
			root.right = root.left;
			root.left = null;
			rmost.right = nextr;
		}
		root = root.right;
	}
}
```
# Iterative (in,pre,post):
```


public List<Integer> preorderTraversal(TreeNode root) {
	List<Integer> ans = new ArrayList<>();
	Stack<TreeNode> st = new Stack<>();
	st.push(root);
	while(true) {
		root = st.pop();
		if(root!=null) ans.add(root.val);
		if(root!=null && root.right != null) st.push(root.right);
		if(root!=null && root.left != null) st.push(root.left);
		if(st.isEmpty()) break;  
	}
	return ans;
}


public List<Integer> inorderTraversal(TreeNode root) {
	List<Integer> ans = new ArrayList<Integer>();
	Stack<TreeNode> st = new Stack<>();
	while(true) {
		if(root != null) {
			st.push(root);
			root = root.left;
		}else {
			if(!st.isEmpty()) {
				root = st.pop();
				ans.add(root.val);
				root = root.right;
			}else {
				break;
			}
		}
	}
	return ans;
}
```

# Strings and Hashing

## XOR of SUM:
##### 1. Brute force: 
```
	void fun(vector<int> &arr,int n){
		int ans = 0;
		for(int i = 0;i < n ;i++){
			for(int j = 0;j < n;j++){
				ans = ans^(arr[i]+arr[j]);
			}
		}
	}
    T,S : N^2 , 1
```

##### 2. Optimised: 
```
	Only the diagonal elements are to be computed.
	int ans = 0;
	for(int i = 0;i < n ; i++){
		ans = ans^(arr[i]*2);
	}
	return ans; 
	T,s : N,1             
```    

## SUM of XOR:
##### 1. Bruteforce:
```
	void fun(vector<int> &arr,int n){
		int ans = 0;
		for(int i = 0;i < n ;i++){
			for(int j = 0;j < n;j++){
				ans = ans + (arr[i]^arr[j]);
			}
		}
	}
    T,S : N^2 , 1
```

##### 2. Optimised:
```
	void fun(vector<int> &arr,int n){
		int ans = 0;
		for(int i = 0;i <32;i++){
			int c1 = 0;
			for(int j = 0;j<n;j++){
				if(checkBit(a[j],i) == 1) c1++;
			}
			ans += ((set)*(n-set)*(1<<i)*2);
		}
	}
    T,S : N^2 , 1
```

## Problem1:
A[N] : a x y y b x y b a 
B[M] : y b y y a x y

for Q queries:
	i j k l
check if A[i:j] == B[k:l]
##### 1.Bruteforce:
for every query check A[i:j] == B[k:l]
T,S  :     Q * min(N,M),1
##### Subproblem:
A[N] : [8,10,12,8,14,-9]
-> find the cummulative sum
A[N] : [8,18,30,38,52,43]
```
for(i = 0;i<n;i++){
	if(i!=0){
		pre[i] = pre[i-1] + arr[i];
	}
	else{
		pre[i] = arr[i];
	}
}
if((pre[j] - pre[i-1]) == pre[l] - pre[k-1]) cout<<"true";
```

##### 2.Optimised:
Compute the hash function for the strings.
1.   h(x) = summation((int)str[i])%m;
2.   h(x) = summation((int)str[i] * (i+1))%m;
3.   h(x) = summation((int)str[i] * power(p,i+1))%m;
	p is usually a prime number.
```
if(i == 0){
	pha[i] = a[i]*p;
}
else{
	pha[i] = ( pha[i-1] + (a[i] * pow(p,i+1)) )%m;
}
```

say:
	A : a b c q e f d
		0 1 2 3 4 5 6
		      i
	B : q e f d r t s
		0 1 2 3 4 5 6
		k
	qefd of b has different indices 
	Hence we need to multiply with pow(p,i-k) to B.

```
if(diff<0){
	ha = (ha * pow(p,diff))%m;
}
else{
	hb = (hb * pow(p,diff))%m;
}
T,S : max(N,M) + N + M + Q   ,   max(N,M)+N+M
```
## Problem2:
A[N] : a b x y y x a x y a 
B[M] : a x y x

check if B is substring of A.

##### 1.Brute force:
```
for(i = 1 to n-m-1){
	for(j = i to i+m){
		check;
	}
}
T,S : (N-M+1)*M , 1
```
##### 2.Robin Karp String Matching Algorithm
##### 3.Two pointer:
T,S : N,1
##### 4.Double Hashing