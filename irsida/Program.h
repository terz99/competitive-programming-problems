//
// Created by dushan on 1/11/18.
//

#ifndef IRSIDA_PROGRAM_H
#define IRSIDA_PROGRAM_H


#include <bits/stdc++.h>
using namespace std;

class Person{

private:

    int age;

protected:

    string phone;

public:

    string firstName;
    string lastName;
    string race;

    // abstract methods

    virtual void OutputIdentity() = 0;
    virtual void OutputAge();

    // constructors and destructor

    Person();
    Person(string firstName, string lastName, string race, string phone, int age);

    virtual ~Person();

    // getters

    string getFirstName() const;
    string getLastName() const;
    string getRace() const;
    string getPhone() const;
    int getAge() const;

    // setters

    void setFirstName(const string& firstName);
    void setLastName(const string& lastName);
    void setPhone(const string& phone);
    void setRace(const string& race);
    void setAge(const int& age);
};

class Student : public Person{

public:
    void OutputIdentity();
    void OutputAge();

    Student();
    ~Student();
    Student(string firstName, string lastName, string race, string phone, int age);
};

class Teacher : public Person{

public:
    void OutputAge();
    void OutputIdentity();

    Teacher();
    ~Teacher();
    Teacher(string firstName, string lastName, string race, string phone, int age);
};




#endif //IRSIDA_PROGRAM_H
