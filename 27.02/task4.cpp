#include <iostream>
#include <vector>

double findMedianSortedArrays(std::vector<int>& nums1, std::vector<int>& nums2) {
    if (nums1.size()<nums2.size()) return findMedianSortedArrays(nums2, nums1);
    int lo=0, hi=nums2.size()*2;
    while(lo<=hi){
        int mid2=(lo+hi)/2;
        int mid1=nums1.size()+nums2.size()-mid2;
        double L1=(mid1==0) ? INT_MIN : nums1[(mid1-1)/2];
        double L2=(mid2==0) ? INT_MIN : nums2[(mid2-1)/2];
        double R1=(mid1==nums1.size()*2) ? INT_MAX : nums1[(mid1)/2];
        double R2=(mid2==nums2.size()*2) ? INT_MAX : nums2[(mid2)/2];
        
        if(L1>R2) lo=mid2+1;
        else if(L2>R1) hi=mid2-1;
        else return (std::max(L1,L2) + std::min(R1, R2))/2;
    }
    return -1;
} 