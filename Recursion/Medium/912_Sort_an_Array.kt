/**
 * Question:
 * https://leetcode.com/problems/sort-an-array/description/
 */


private fun merge(nums: IntArray, low: Int, mid: Int, high: Int) {
    var l1 = low
    var l2 = mid + 1
    val res = mutableListOf<Int>()
    while (l1 <= mid && l2 <= high) {
        if (nums[l1] <= nums[l2]) {
            res.add(nums[l1])
            l1++
        } else {
            res.add(nums[l2])
            l2++
        }
    }

    while (l1 <= mid) {
        res.add(nums[l1])
        l1++
    }

    while (l2 <= high) {
        res.add(nums[l2])
        l2++
    }

    for (i in low..high) {
        nums[i] = res[i - low]
    }
    return;
}

private fun sortt(nums: IntArray, low: Int, high: Int) {
    if (low >= high) return;
    val mid = (high - low) / 2 + low
    sortt(nums, low, mid)
    sortt(nums, mid + 1, high)
    return merge(nums, low, mid, high)
}

fun sortArray(nums: IntArray): IntArray {
    sortt(nums, 0, nums.size - 1)
    return nums
}
