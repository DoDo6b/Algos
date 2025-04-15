#include <iostream>
#include <vector>

uint64_t inversed{0};

void merge(std::vector<int>& vec, size_t begin, size_t mid, size_t end){
    size_t lp = begin, rp = mid+1;
    std::vector<int> buffer;
    while(lp<=mid&&rp<=end){
        if(vec[lp]<=vec[rp])buffer.push_back(vec[lp++]);
        else{
            buffer.push_back(vec[rp++]);
            inversed += mid+1-lp;   //считаем
        }
    }
    while(lp<=mid) buffer.push_back(vec[lp++]);
    while(rp<=end) buffer.push_back(vec[rp++]);
    for(size_t k{0}; k<buffer.size(); k++) vec[begin+k] = buffer[k];
}

void mergeSort(std::vector<int>& vec, size_t begin, size_t end){
    if(begin>=end) return;
    size_t mid = (begin+end)/2;
    mergeSort(vec, begin, mid);
    mergeSort(vec, mid+1, end);
    merge(vec, begin, mid, end);
}

int main(){
    size_t n;
    std::cin >> n;
    std::vector<int> input(n);
    for(size_t i{0}; i<n; i++) std::cin >> input[i];
    mergeSort(input, 0, n-1);
    std::cout << inversed << std::endl;

    return 0;
}