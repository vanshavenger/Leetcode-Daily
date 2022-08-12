class NumArray {
public:
    int n;
    
    vector<int> tree;
    void buildTree(vector<int>& nums,int start,int end,int treeNode){
        if(start == end){
            tree[treeNode] = nums[start];
            return;
        }
        int mid = start + (end - start)/2;
        buildTree(nums,start,mid,2*treeNode);
        buildTree(nums,mid+1,end,2*treeNode+1);
        tree[treeNode] = tree[2*treeNode] + tree[2*treeNode + 1];
    }
    int query(int start,int end,int left,int right,int treeNode){
        if(start > right || left > end){
            return 0;
        }
        if(start >= left && right >= end){
            return tree[treeNode];
        }
        int mid = start + (end - start)/2;
        int ans1 = query(start,mid,left,right,2*treeNode);
        int ans2 = query(mid+1,end,left,right,2*treeNode+1);
        return ans1+ans2;
    }
    void update(int index,int val,int start,int end,int treeNode){
        if(start >= end){
            tree[treeNode] = val;
            return;
        }
        int mid = start + (end - start)/2;
        if(index > mid){
            update(index,val,mid+1,end,2*treeNode+1);
        }else{
            update(index,val,start,mid,2*treeNode);
        }
        tree[treeNode] = tree[2*treeNode] + tree[2*treeNode + 1];
    }
    NumArray(vector<int>& nums) {
        n = nums.size();
        tree.resize(4*n);
        buildTree(nums,0,n-1,1);
    }
    
    void update(int index, int val) {
        update(index,val,0,n-1,1);
    }
    
    int sumRange(int left, int right) {
        return query(0,n-1,left,right,1);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */
