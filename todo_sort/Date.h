//
// Created by dushan on 20.10.17.
//

#ifndef TODO_SORT_DATE_H
#define TODO_SORT_DATE_H

#include <string>


class Date {

public:

    // constructors
    Date();
    Date(const std::string&, const std::string&);


    // getters and setters
    int getDay() const;

    void setDay(int day);

    int getMonth() const;

    void setMonth(int month);

    int getYear() const;

    void setYear(int year);

    const std::string &getData() const;

    void setData(const std::string &data);

    // service methods
    int getInt(const std::string&) const;

    std::string getDate();

    // operators

    bool operator<(const Date&) const;

    bool operator>(const Date&) const;

private:

    int day;
    int month;
    int year;
    std::string data;

};


#endif //TODO_SORT_DATE_H
