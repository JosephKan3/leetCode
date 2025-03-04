function findMedianSortedArrays(nums1: number[], nums2: number[]): number {
  let length1: number = nums1.length;
  let length2: number = nums2.length;

  // Sets nums1 to larger array
  if (length2 > length1) {
    return findMedianSortedArrays(nums2, nums1)
  }

  let low: number = 0;
  let high: number = length2 * 2;
  while (low <= high) {
    let cut2: number = Math.trunc((low + high) / 2);
    let cut1: number = Math.trunc(length1 + length2 - cut2);

    let L1: number = (cut1 == 0) ? Number.NEGATIVE_INFINITY : nums1[Math.trunc((cut1 - 1) / 2)];
    let L2: number = (cut2 == 0) ? Number.NEGATIVE_INFINITY : nums2[Math.trunc((cut2 - 1) / 2)];
    let R1: number = (cut1 == length1 * 2) ? Number.POSITIVE_INFINITY : nums1[Math.trunc((cut1) / 2)];
    let R2: number = (cut2 == length2 * 2) ? Number.POSITIVE_INFINITY : nums2[Math.trunc((cut2) / 2)];
    
    if (L1 > R2) low = cut2 + 1;		// A1's lower half is too big; need to move C1 left (C2 right)
    else if (L2 > R1) high = cut2 - 1;	// A2's lower half too big; need to move C2 left.
    else return (Math.max(L1,L2) + Math.min(R1, R2)) / 2;	// Otherwise, that's the right cut.
  }
  return -1;
};  