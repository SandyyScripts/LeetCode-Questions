/**
 * @param {number[]} nums1
 * @param {number[]} nums2
 * @return {number}
 */
var findMedianSortedArrays = function(nums1, nums2) {
    const arr = nums1.concat(nums2).sort((a, b) => a - b);
     const n = parseInt(arr.length / 2);
     return (arr.length % 2 == 0) ? (arr[n - 1] + arr[n]) / 2 : arr[n];
};