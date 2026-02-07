#ifndef COURSE_H
#define COURSE_H

#include <string>
using namespace std;

class Course {
private:
    string courseCode;
    string courseName;
    int credits;

public:
    // Constructors
    Course();
    Course(string code, string name, int credit);
    
    // Getters
    string getCourseCode() const;
    string getCourseName() const;
    int getCredits() const;
    
    // Display method
    void displayCourseInfo() const;
    
    // For file operations
    string serialize() const;
    void deserialize(string data);
};

#endif
