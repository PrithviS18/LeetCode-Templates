class NumArray {
private:
    vector<int> Seg;
    int n;
public:
    void buildSeg (int index, int start, int end, vector<int>& nums){
        if (start==end){
            Seg[index]=nums[start];
            return;
        }
        int mid = (start+end)/2;
        buildSeg(2*index+1,start,mid,nums);
        buildSeg(2*index+2,mid+1,end,nums);
        Seg[index]=Seg[2*index+1]+Seg[2*index+2];
        return;
    }
    void updateSeg (int index,int idx,int val, int start, int end){
        if (start==end){
            Seg[index]=val;
            return;
        }
        int mid = (start+end)/2;
        if (idx<=mid)updateSeg(2*index+1,idx,val,start,mid);
        else updateSeg(2*index+2,idx,val,mid+1,end);

        Seg[index] = Seg[2*index+1] + Seg[2*index+2];
    }

    int querySeg(int index, int start, int end, int l, int r){
        if (r<start || l>end)return 0;
        if (start>=l && end<=r)return Seg[index];
        int mid = (start+end)/2;
        int left = querySeg(2*index+1,start,mid,l,r);
        int right = querySeg(2*index+2,mid+1,end,l,r);

        return left+right;
    }
    NumArray(vector<int>& nums) {
        n = nums.size();
        Seg = vector<int> (n*4,0);
        buildSeg(0,0,n-1,nums);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */
