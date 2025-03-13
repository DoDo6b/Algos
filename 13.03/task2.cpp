#include <string>
#include <deque>
#include <sstream>

class Solution {
    public:
    std::string simplifyPath(std::string path) {
        std::deque<std::string> pathTrace;
        std::stringstream stream(path);
        std::string buf, res{"/"};
        while(getline(stream, buf, '/')){
            if(buf==""||buf==".") continue;
            if(buf==".."){
                if(!pathTrace.empty()) pathTrace.pop_back();
            }else{
                pathTrace.push_back(buf);
            }
        }
        for(int i{0}; i<pathTrace.size(); i++){
            if(i>0) res+="/";
            res+=pathTrace[i];
        }
        return res;
    }
};