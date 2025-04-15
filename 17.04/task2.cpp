#include <iostream>
#include <queue>
#include <stack>

int main(){
    size_t n, k;
    std::cin >> n >> k;

    std::priority_queue<int> heapi;

    for(size_t i{0}; i<n; i++){
        int x;
        std::cin >> x;

        if(i<k) heapi.push(x);
        else if(x<heapi.top()){
            heapi.pop();
            heapi.push(x);
        }
    }

    std::stack<int> reverso;
    while(!heapi.empty()){
        reverso.push(heapi.top());
        heapi.pop();
    }
    while(!reverso.empty()){
        std::cout << reverso.top() << " ";
        reverso.pop();
    }
    std::cout << std::endl;

    return 0;
}