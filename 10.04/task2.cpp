#include <iostream>
#include <vector>
#include <algorithm>

bool XYcomparator(const std::pair<bool, bool> a, const std::pair<bool, bool> b){
    if(a.first==b.first) return a.second<b.second;
    return a.first<b.first;
}

int main(){
    size_t n;
    std::cin >> n;
    std::vector<std::pair<bool, bool>> set(n);
    for(size_t i{0}; i<n; i++) std::cin >> set[i].first >> set[i].second;
    std::cout << "Line: \n";
    std::sort(set.begin(), set.end(), XYcomparator);
    for(auto v : set) std::cout << v.first << " " << v.second << " " << std::endl;
}