#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

struct Line{
    std::string label;
    std::vector<int> attributes;
};

std::vector<int> priority;

bool jumpComparator(const Line& a, const Line& b){
    for(int id : priority) if(a.attributes[id]!=b.attributes[id]) return a.attributes[id]>b.attributes[id];
    return false;
}

int main(){
    int n, k;
    std::cin >> n >> k;

    priority.resize(k);
    for(int i{0}; i<k; i++){
        std::cin >> priority[i];
        priority[i]--;
    }

    std::vector<Line> lines(n);
    for(int i{0}; i<n; ++i){
        std::cin >> lines[i].label;
        lines[i].attributes.resize(k);
        for(int j{0}; j<k; j++){
            std::cin >> lines[i].attributes[j];
        }
    }

    std::sort(lines.begin(), lines.end(), jumpComparator);

    for(const auto& l : lines) std::cout << l.label << std::endl;
}