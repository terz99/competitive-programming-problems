//
// Created by dushan on 20.10.17.
//

#include "Date.h"

Date::Date() {

}

Date::Date(const std::string &date, const std::string &data) {
    this->day = getInt(date.substr(0, 2));
    this->month = getInt(date.substr(3, 2));
    this->year = getInt(date.substr(6));
    this->data = data;
}

int Date::getDay() const {
    return day;
}

void Date::setDay(int day) {
    Date::day = day;
}

int Date::getMonth() const {
    return month;
}

void Date::setMonth(int month) {
    Date::month = month;
}

int Date::getYear() const {
    return year;
}

void Date::setYear(int year) {
    Date::year = year;
}

int Date::getInt(const std::string &s) const{
    int res = 0;
    for(unsigned int i = 0; i < s.length(); i++){
        res = res*10 + (int)(s[i]-'0');
    }
    return res;
}

bool Date::operator<(const Date &date) const{
    if(this->year != date.year)
        return this->year < date.year;
    if(this->month != date.month)
        return this->month < date.month;
    if(this->day != date.day)
        return this->day < date.day;
    return this->data < date.data;
}

const std::string &Date::getData() const {
    return data;
}

void Date::setData(const std::string &data) {
    Date::data = data;
}

bool Date::operator>(const Date &date) const {
    if(this->year != date.year)
        return this->year > date.year;
    if(this->month != date.month)
        return this->month > date.month;
    if(this->day != date.day)
        return this->day > date.day;
    return this->data > date.data;
}

std::string Date::getDate() {

    std::string day = std::to_string(this->day);
    if(this->day < 10){
        day = "0" + day;
    }

    std::string month = std::to_string(this->month);
    if(this->month < 10){
        month = "0" + month;
    }

    std::string year = std::to_string(this->year);
    return (day + "." + month + "." + year);
}
