#include <iostream>
#include <vector>

int first_repeat(std::vector<int>& A){
    int i=A.size()-1;
    int j=i;
    while(true){
        i=A[i];
        j=A[A[j]];
        if(i==j) break;
    }
    j=A.size()-1;
    while(true){
        i=A[i];
        j=A[j];
        if(i==j) return i;
    }
}

int main(){
    int n;
    std::cin >> n;
    std::vector<int> A(n);
    for(int i{0}; i<n; ++i) std::cin >> A[i];
    std::cout << first_repeat(A) << std::endl;
}