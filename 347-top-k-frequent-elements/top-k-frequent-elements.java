class Solution {
    public int[] topKFrequent(int[] nums, int k) {
        HashMap<Integer,Integer> hm = new HashMap<>();
        for(int i : nums) {
            hm.put(i,hm.getOrDefault(i,0)+1);
        }
        PriorityQueue<Integer> pq = new PriorityQueue<>((a,b) -> hm.get(a)-hm.get(b));
        for(int i : hm.keySet()) {
            pq.add(i);
            if(pq.size() > k) pq.remove();
        }
        int[] ans = new int[k];
        for(int i = k-1;i>=0;i--) {
            ans[i] = pq.peek();
            pq.remove();
        }
        return ans;
    }
}