#include <queue>
#include <vector>
#include <iostream>

std::vector<int> slidingWindowMax(const std::vector<int>& vec, int w){
    std::vector<int> res;
    std::priority_queue<std::pair<int, int>> heap;
    for(int i{0}; i<vec.size(); ++i){
        heap.push({vec[i], i});
        if(i>=w-1){
            while(heap.top().second<=i-w) heap.pop();
            res.push_back(heap.top().first);
        }
    }
    return res;
}

int main(){
    size_t n;
    std::cin >> n;
    std::vector<int> vector(n);
    for(size_t i{0}; i<n; ++i) std::cin >> vector[i];
    int w;
    std::cin >> w;
    std::vector<int> result = slidingWindowMax(vector, w);
    for(auto i : result) std::cout << i << " ";
    std::cout << std::endl;
}