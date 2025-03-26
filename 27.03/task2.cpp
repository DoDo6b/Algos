#include <iostream>
#include <queue>
#include <vector>

int tracksCalculated(const std::vector<std::pair<int, int>>& schedule){
    std::priority_queue<int, std::vector<int>, std::greater<int>> tracks;
    size_t res{0};
    for(auto& train : schedule){
        while(!tracks.empty()&&tracks.top()<=train.first) tracks.pop();
        tracks.push(train.second);
        res=std::max(res, tracks.size());
    }
    return res;
}

int main(){
    size_t n;
    std::cin >> n;
    std::vector<std::pair<int, int>> vector(n);
    for(size_t i{0}; i<n; ++i) std::cin >> vector[i].first >> vector[i].second;
    std::cout << tracksCalculated(vector) << std::endl;
}