int SIZE;
vector<int> seg;
void build(vector<int> &nums, int node, int l, int r) {
    if (l == r) {
        seg[node] = nums[l];
        return;
    }
    int mid = (l + r) / 2;
    build(nums, 2*node + 1, l, mid);
    build(nums, 2*node + 2, mid + 1, r);
    seg[node] = seg[2*node + 1] + seg[2*node + 2];
    return;
}
void seg_update(int node, int start, int end, int idx, int val) {
    if (start == end) {
        seg[node] = val;
        return;
    }
    int mid = (start + end) / 2;
    if (start <= idx && idx <= mid) {
        seg_update(2*node + 1, start, mid, idx, val);
    } else {
        seg_update(2*node + 2, mid + 1, end, idx, val);
    }
    seg[node] = seg[2 * node + 1] + seg[2 * node + 2];
}
int query (int node, int start, int end, int left, int right) {
    if(left <= start && end <= right) {
        return seg[node];
    } else if (end < left || right < start) {
        return 0;
    } else {
        int mid = (start + end) / 2;
        int _left = query (2 * node + 1, start, mid, left, right);
        int _right = query (2 * node + 2, mid + 1, end, left, right);
        return _left + _right;
    }
}
