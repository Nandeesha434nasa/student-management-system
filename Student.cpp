#include "Student.h"
#include <iostream>
#include <iomanip>
#include <sstream>

// Default constructor
Student::Student() {
    rollNo = 0;
    name = "";
    age = 0;
}

// Parameterized constructor
Student::Student(int roll, string studentName, int studentAge) {
    rollNo = roll;
    name = studentName;
    age = studentAge;
}

// Getter methods
int Student::getRollNo() const {
    return rollNo;
}

string Student::getName() const {
    return name;
}

int Student::getAge() const {
    return age;
}

vector<string> Student::getCourses() const {
    return courses;
}

// Setter methods
void Student::setName(string newName) {
    name = newName;
}

void Student::setAge(int newAge) {
    age = newAge;
}

// Add a course to student's course list
void Student::addCourse(string courseCode) {
    // Check if course already exists
    for(int i = 0; i < courses.size(); i++) {
        if(courses[i] == courseCode) {
            cout << "Course already enrolled!" << endl;
            return;
        }
    }
    courses.push_back(courseCode);
    cout << "Course " << courseCode << " added successfully!" << endl;
}

// Add grade for a specific course
void Student::addGrade(string courseCode, float grade) {
    // Validate grade (0-10 scale or 0-4 GPA scale)
    if(grade < 0 || grade > 10) {
        cout << "Invalid grade! Please enter between 0-10" << endl;
        return;
    }
    
    grades[courseCode] = grade;
    cout << "Grade added successfully!" << endl;
}

// Calculate GPA based on all course grades
float Student::calculateGPA() const {
    if(grades.empty()) {
        return 0.0;
    }
    
    float total = 0.0;
    int count = 0;
    
    // Iterate through all grades
    for(auto it = grades.begin(); it != grades.end(); it++) {
        total += it->second;
        count++;
    }
    
    return total / count;
}

// Display student information
void Student::displayInfo() const {
    cout << "\n========================================" << endl;
    cout << "Roll No: " << rollNo << endl;
    cout << "Name: " << name << endl;
    cout << "Age: " << age << endl;
    
    cout << "\nEnrolled Courses: ";
    if(courses.empty()) {
        cout << "No courses enrolled" << endl;
    } else {
        cout << endl;
        for(int i = 0; i < courses.size(); i++) {
            cout << "  - " << courses[i];
            
            // Display grade if available
            auto it = grades.find(courses[i]);
            if(it != grades.end()) {
                cout << " (Grade: " << fixed << setprecision(2) << it->second << ")";
            }
            cout << endl;
        }
    }
    
    // Display GPA
    float gpa = calculateGPA();
    if(gpa > 0) {
        cout << "\nGPA: " << fixed << setprecision(2) << gpa << endl;
    }
    cout << "========================================\n" << endl;
}

// Convert student data to string for file storage
string Student::serialize() const {
    stringstream ss;
    ss << rollNo << "|" << name << "|" << age << "|";
    
    // Add courses
    for(int i = 0; i < courses.size(); i++) {
        ss << courses[i];
        if(i < courses.size() - 1) ss << ",";
    }
    ss << "|";
    
    // Add grades
    int count = 0;
    for(auto it = grades.begin(); it != grades.end(); it++) {
        ss << it->first << ":" << it->second;
        if(count < grades.size() - 1) ss << ",";
        count++;
    }
    
    return ss.str();
}

// Load student data from string
void Student::deserialize(string data) {
    stringstream ss(data);
    string token;
    
    // Read roll number
    getline(ss, token, '|');
    rollNo = stoi(token);
    
    // Read name
    getline(ss, name, '|');
    
    // Read age
    getline(ss, token, '|');
    age = stoi(token);
    
    // Read courses
    getline(ss, token, '|');
    if(!token.empty()) {
        stringstream courseStream(token);
        string course;
        while(getline(courseStream, course, ',')) {
            courses.push_back(course);
        }
    }
    
    // Read grades
    getline(ss, token, '|');
    if(!token.empty()) {
        stringstream gradeStream(token);
        string gradeData;
        while(getline(gradeStream, gradeData, ',')) {
            int colonPos = gradeData.find(':');
            string courseCode = gradeData.substr(0, colonPos);
            float grade = stof(gradeData.substr(colonPos + 1));
            grades[courseCode] = grade;
        }
    }
}
