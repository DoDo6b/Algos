#include <iostream>
#include <vector>

int greater_or_equal(std::vector<int>& A, int B){
    int n=A.size();
    if(n==0||A[n-1]<B) return n;
    int lp{0}, rp{1};
    while(rp<n&&A[rp]<B){
        lp=rp;
        rp*=2;
    }
    rp=std::min(n-1, rp);
    while(lp<=rp){
        int mp=(lp+rp)/2;
        if(A[mp]>=B) rp=mp-1;
        else lp=mp+1;
    }
    return lp;
}

int main(){
    int n, m;
    std::cin >> n >> m;
    std::vector<int> A(n), B(m);
    for(int i{0}; i<n; ++i) std::cin >> A[i];
    for(int i{0}; i<m; ++i) std::cin >> B[i];
    for(auto i : B) std::cout << greater_or_equal(A, i) << " ";
    std::cout << std::endl;
}