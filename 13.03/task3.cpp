#include <vector>
#include <stack>

class Solution {
    public:
    int largestRectangleArea(std::vector<int>& heights) {
        std::stack<int> stack;
        int maxArea{0};
        for(int i{0}; i <= heights.size(); ++i){
            int currentHeight=(i == heights.size()) ? 0 : heights[i];
            while(!stack.empty() && heights[stack.top()] > currentHeight){
                int height=heights[stack.top()];
                stack.pop();
                int width=stack.empty() ? i : i - stack.top() - 1;
                maxArea=std::max(maxArea, height * width);
            }
            stack.push(i);
        }
        return maxArea;
    }
};