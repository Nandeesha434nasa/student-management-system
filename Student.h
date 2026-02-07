#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include <vector>
#include <map>
using namespace std;

class Student {
private:
    int rollNo;
    string name;
    int age;
    vector<string> courses;  // stores course codes
    map<string, float> grades;  // course code -> grade mapping

public:
    // Constructor
    Student();
    Student(int roll, string studentName, int studentAge);
    
    // Getters
    int getRollNo() const;
    string getName() const;
    int getAge() const;
    vector<string> getCourses() const;
    
    // Setters
    void setName(string newName);
    void setAge(int newAge);
    
    // Core functions
    void addCourse(string courseCode);
    void addGrade(string courseCode, float grade);
    float calculateGPA() const;
    void displayInfo() const;
    
    // For file operations
    string serialize() const;  // convert to string for saving
    void deserialize(string data);  // load from string
};

#endif
