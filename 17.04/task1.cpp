#include <iostream>
#include <vector>

struct Date{
    unsigned short day;
    unsigned short month;
    unsigned int year;
    bool is_happy{0};
};

bool compareDates(const Date& a, const Date& b){
    if(a.year!=b.year) return a.year<b.year;
    if(a.month!=b.month) return a.month<b.month;
    return a.day<b.day;
}

int countPossibleMeetings(std::vector<Date>& dates){
    int maxPossibleMeetings{0}, possibleMeetings{0};
    std::sort(dates.begin(), dates.end(), compareDates);
    for(size_t i{0}; i<dates.size()-1; i++){
        if(dates[i].is_happy) possibleMeetings++;
        else possibleMeetings--;
        maxPossibleMeetings = std::max(possibleMeetings, maxPossibleMeetings);
    }

    return maxPossibleMeetings;
}

int main(){
    size_t n;
    std::cin >> n;
    std::vector<Date> dates(2*n);
    for(size_t i{0}; i<2*n; i++){
        std::cin >> dates[i].day >> dates[i].month >> dates[i].year;
        if(i%2==0){
            dates[i].is_happy = true;
            dates[i].year += 18;
        }
    }
    std::cout << countPossibleMeetings(dates) << std::endl;

    return 0;
}