/**
 * @param {number[]} nums1
 * @param {number[]} nums2
 * @return {number}
 */
var findMedianSortedArrays = function(nums1, nums2) {
    // var arr=[];
    // let i=0,j=0;
    // while(i<nums1.length && j<nums2.length){
    //     if(nums1[i]<nums2[j]){
    //         arr.push(nums1[i]);
    //         i++;
    //     }
    //     if(nums1[i]>nums2[j]){
    //         arr.push(nums2[j]);
    //         j++;
    //     }
    // }
    // while(i!=nums1.length){
    //    arr.push(nums1[i]);
    //    i++; 
    // }
    // while(j!=nums2.length){
    //    arr.push(nums2[j]);
    //    j++; 
    // }
    // var n=arr.length;
    // if(arr.length%2!=0){
    //     return arr[(n-1)/2];
    // }
    // return (arr[n/2]+arr[(n/2)-1])/2;
     const arr = nums1.concat(nums2).sort((a, b) => a - b);
     const n = parseInt(arr.length / 2);

  return (arr.length % 2 == 0) ? (arr[n - 1] + arr[n]) / 2 : arr[n];
};