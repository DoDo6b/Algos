#include <iostream>
#include <string>

bool is_reacheble(int n, int k, std::string& route, int L){
    int position{0}, stamina{0};
    while(position<n){
        int move=std::min(position+L, n);
        if(move==n && stamina<k) return true;
        while((route[move-1]=='0' || move>n) && move>position) --move;
        if(move==position||(stamina++)>k) return false;
        position=move;
    }
}

int bin_search(int n, int k, std::string& route){
    int lp{0}, rp{n};
    int longjump{n};
    while(lp<=rp){
        int mid=(lp+rp)/2;
        if(is_reacheble(n, k, route, mid)){
            longjump=mid;
            rp=mid-1;
        }
        else lp=mid+1;
    }
    return longjump;
}

int main(){
    int n, k;
    std::cin >> n >> k;
    std::string route;
    std::cin >> route;
    std::cout << bin_search(n, k, route) << std::endl;
}