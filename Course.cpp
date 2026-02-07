#include "Course.h"
#include <iostream>
#include <sstream>

// Default constructor
Course::Course() {
    courseCode = "";
    courseName = "";
    credits = 0;
}

// Parameterized constructor
Course::Course(string code, string name, int credit) {
    courseCode = code;
    courseName = name;
    credits = credit;
}

// Getter methods
string Course::getCourseCode() const {
    return courseCode;
}

string Course::getCourseName() const {
    return courseName;
}

int Course::getCredits() const {
    return credits;
}

// Display course information
void Course::displayCourseInfo() const {
    cout << "Course Code: " << courseCode << endl;
    cout << "Course Name: " << courseName << endl;
    cout << "Credits: " << credits << endl;
    cout << "--------------------------------" << endl;
}

// Convert course data to string for file storage
string Course::serialize() const {
    return courseCode + "|" + courseName + "|" + to_string(credits);
}

// Load course data from string
void Course::deserialize(string data) {
    stringstream ss(data);
    string token;
    
    getline(ss, courseCode, '|');
    getline(ss, courseName, '|');
    getline(ss, token, '|');
    credits = stoi(token);
}
