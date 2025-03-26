#include <queue>
#include <vector>
#include <iostream>

int solution(std::vector<int>& vec){
    int res{0};
    int buf;
    std::priority_queue<int, std::vector<int>, std::greater<int>> heap(vec.begin(), vec.end());
    while(heap.size()>2){
        buf=heap.top();
        heap.pop();
        buf+=heap.top();
        heap.pop();
        res+=buf;
        heap.push(buf);
    }
    buf=heap.top();
    heap.pop();
    return res+buf+heap.top();
}

int main(){
    size_t n;
    std::cin >> n;
    std::vector<int> vector(n);
    for(size_t i{0}; i<n; ++i) std::cin >> vector[i];
    std::cout << solution(vector) << std::endl;
}