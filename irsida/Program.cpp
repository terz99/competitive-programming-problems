#include <bits/stdc++.h>
#include "Program.h"

using namespace std;

void Person::OutputAge(){
    cout << "I am " << age << " years old.\n";
}

Person::Person(){}

Person::~Person(){
    cout << "Deleting person\n";
}

Person::Person(string firstName, string lastName, string race, string phone, int age){
    this->firstName = firstName;
    this->lastName = lastName;
    this->race = race;
    this->phone = phone;
    this->age = age;
    cout << "Calling param constructor of person\n";
}

string Person::getFirstName() const{
    return firstName;
}

string Person::getLastName() const {
    return lastName;
}

string Person::getRace() const {
    return race;
}

string Person::getPhone() const {
    return phone;
}

int Person::getAge() const {
    return age;
}

void Person::setFirstName(const string &firstName) {
    this->firstName = firstName;
}

void Person::setLastName(const string &lastName) {
    this->lastName = lastName;
}

void Person::setPhone(const string &phone) {
    this->phone = phone;
}

void Person::setRace(const string &race) {
    this->race = race;
}

void Person::setAge(const int &age) {
    this->age = age;
}


void Student::OutputIdentity() {
    cout << "I am a student\n";
}

void Student::OutputAge() {
    cout << "I am a student. ";
    Person::OutputAge();
}

Student::Student() {

}

Student::~Student() {
    cout << "Deleteing student\n";
}

Student::Student(string firstName, string lastName, string race, string phone, int age) : Person(firstName, lastName,
                                                                                                 race, phone, age) {
    cout << "Calling params constructor of Student\n";
}

void Teacher::OutputAge() {
    cout << "I am a teacher. ";
    Person::OutputAge();
}

void Teacher::OutputIdentity() {
    cout << "I am a teacher\n";
}

Teacher::Teacher() {

}

Teacher::~Teacher() {
    cout << "Deleting teacher\n";
}

Teacher::Teacher(string firstName, string lastName, string race, string phone, int age) : Person(firstName, lastName,
                                                                                                 race, phone, age) {
    cout << "Calling a param constructor of teacher\n";
}
