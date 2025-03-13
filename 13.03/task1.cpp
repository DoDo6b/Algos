#include <vector>

class Solution {
    public:
    int trap(std::vector<int>& height){
        int lp{0}, water{0};
        int rp=height.size()-1;
        int lmax=height[lp];
        int rmax=height[rp];
        while(lp<rp){
            if(lmax<rmax){
                lp++;
                lmax=std::max(lmax, height[lp]);
                water+=lmax-height[lp];
            }
            else{
                rp--;
                rmax=std::max(rmax, height[rp]);
                water+=rmax-height[rp];
            }
        }
        return water;        
    }
};