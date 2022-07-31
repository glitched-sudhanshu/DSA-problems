/*Brute force*/
// TC: O(N)
// SC: O(1)

NumArray(vector<int> &nums)
{
    nms = nums;
}

void update(int index, int val)
{
    if (index < nms.size())
        nms[index] = val;
}

int sumRange(int left, int right)
{
    int sum = 0;
    for (int i = left; i <= right; i++)
        sum += nms[i];
    return sum;
}

/*Square root decompostion*/
// Want to know how this method works
// TC: O(n) - preprocessing, O(sqrt{N}) - range sum query, O(1) - update query
// SC: Space complexity : O(sqrt{N})
private:
int[] b;
int len;
int[] nums;

public:
NumArray(int[] nums)
{
    this.nums = nums;
    double l = Math.sqrt(nums.length);
    len = (int)Math.ceil(nums.length / l);
    b = new int[len];
    for (int i = 0; i < nums.length; i++)
        b[i / len] += nums[i];
}

public:
int sumRange(int i, int j)
{
    int sum = 0;
    int startBlock = i / len;
    int endBlock = j / len;
    if (startBlock == endBlock)
    {
        for (int k = i; k <= j; k++)
            sum += nums[k];
    }
    else
    {
        for (int k = i; k <= (startBlock + 1) * len - 1; k++)
            sum += nums[k];
        for (int k = startBlock + 1; k <= endBlock - 1; k++)
            sum += b[k];
        for (int k = endBlock * len; k <= j; k++)
            sum += nums[k];
    }
    return sum;
}

public:
void update(int i, int val)
{
    int b_l = i / len;
    b[b_l] = b[b_l] - nums[i] + val;
    nums[i] = val;
}


/*Segment tree*/
// TC: O(N) - Build, O(logN) - Query sum, O(logN) - Update
// SC: O(4N)
class NumArray
{

    vector<int> seg;
    int querySum(int idx, int low, int high, int l, int r)
    {
        // for complete overlap
        // l low high r
        if (l <= low && high <= r)
        {
            return seg[idx];
        }
        // no overlap
        // l r low high || low high l r
        if (r < low || high < l)
        {
            return 0;
        }

        // partial overlap
        int mid = (low + high) / 2;
        int left = querySum(2 * idx + 1, low, mid, l, r);
        int right = querySum(2 * idx + 2, mid + 1, high, l, r);

        // seg[idx] = left + right;
        return left + right;
    }

    void build(int idx, int low, int high, vector<int> arr)
    {
        // putting ith element of array into the segment tree.
        if (low == high)
        {
            seg[idx] = arr[low];
            return;
        }

        int mid = (low + high) / 2;
        build(2 * idx + 1, low, mid, arr);
        build(2 * idx + 2, mid + 1, high, arr);
        seg[idx] = seg[2 * idx + 1] + seg[2 * idx + 2];
    }

    void upd(int idx, int low, int high, int i, int val)
    {
        if (low == high)
        {
            seg[idx] = val;
            return;
        }

        int mid = (high + low) / 2;
        if (i <= mid)
            upd(2 * idx + 1, low, mid, i, val);
        else
            upd(2 * idx + 2, mid + 1, high, i, val);

        seg[idx] = seg[2 * idx + 1] + seg[2 * idx + 2];
        return;
    }

public:
    int n = 0;
    // vector<int> arr;

    NumArray(vector<int> &nums)
    {
        int n = nums.size();
        seg.resize(4 * n + 1);
        build(0, 0, n - 1, nums);
    }

    void update(int index, int val)
    {
        return upd(0, 0, n - 1, index, val);
        // arr[index] = val;
    }

    int sumRange(int left, int right)
    {
        return querySum(0, 0, n - 1, left, right);
        // return 2;
    }
};