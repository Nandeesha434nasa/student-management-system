#include "Database.h"
#include <iostream>
#include <fstream>
#include <algorithm>

// Constructor
Database::Database() {
    // Load existing data when program starts
    loadFromFile();
}

// Helper function to find student by roll number
int Database::findStudentIndex(int rollNo) {
    for(int i = 0; i < students.size(); i++) {
        if(students[i].getRollNo() == rollNo) {
            return i;
        }
    }
    return -1;  // Not found
}

// Helper function to find course by code
int Database::findCourseIndex(string courseCode) {
    for(int i = 0; i < courses.size(); i++) {
        if(courses[i].getCourseCode() == courseCode) {
            return i;
        }
    }
    return -1;  // Not found
}

// Add a new student to the database
void Database::addStudent(int rollNo, string name, int age) {
    // Check if student already exists
    if(findStudentIndex(rollNo) != -1) {
        cout << "Error: Student with Roll No " << rollNo << " already exists!" << endl;
        return;
    }
    
    Student newStudent(rollNo, name, age);
    students.push_back(newStudent);
    cout << "Student added successfully!" << endl;
    saveToFile();  // Save after adding
}

// Delete a student from database
void Database::deleteStudent(int rollNo) {
    int index = findStudentIndex(rollNo);
    
    if(index == -1) {
        cout << "Error: Student with Roll No " << rollNo << " not found!" << endl;
        return;
    }
    
    students.erase(students.begin() + index);
    cout << "Student deleted successfully!" << endl;
    saveToFile();  // Save after deleting
}

// Update student information
void Database::updateStudent(int rollNo) {
    int index = findStudentIndex(rollNo);
    
    if(index == -1) {
        cout << "Error: Student with Roll No " << rollNo << " not found!" << endl;
        return;
    }
    
    cout << "\nWhat do you want to update?" << endl;
    cout << "1. Name" << endl;
    cout << "2. Age" << endl;
    cout << "Enter choice: ";
    
    int choice;
    cin >> choice;
    cin.ignore();  // Clear newline from buffer
    
    if(choice == 1) {
        string newName;
        cout << "Enter new name: ";
        getline(cin, newName);
        students[index].setName(newName);
        cout << "Name updated successfully!" << endl;
    } else if(choice == 2) {
        int newAge;
        cout << "Enter new age: ";
        cin >> newAge;
        students[index].setAge(newAge);
        cout << "Age updated successfully!" << endl;
    } else {
        cout << "Invalid choice!" << endl;
        return;
    }
    
    saveToFile();  // Save after updating
}

// Search for a student
Student* Database::searchStudent(int rollNo) {
    int index = findStudentIndex(rollNo);
    
    if(index == -1) {
        return nullptr;  // Not found
    }
    
    return &students[index];
}

// Display all students
void Database::displayAllStudents() {
    if(students.empty()) {
        cout << "\nNo students in the database!" << endl;
        return;
    }
    
    cout << "\n========== ALL STUDENTS ==========" << endl;
    for(int i = 0; i < students.size(); i++) {
        students[i].displayInfo();
    }
}

// Add a new course
void Database::addCourse(string code, string name, int credits) {
    // Check if course already exists
    if(findCourseIndex(code) != -1) {
        cout << "Error: Course with code " << code << " already exists!" << endl;
        return;
    }
    
    Course newCourse(code, name, credits);
    courses.push_back(newCourse);
    cout << "Course added successfully!" << endl;
    saveToFile();
}

// Delete a course
void Database::deleteCourse(string courseCode) {
    int index = findCourseIndex(courseCode);
    
    if(index == -1) {
        cout << "Error: Course with code " << courseCode << " not found!" << endl;
        return;
    }
    
    courses.erase(courses.begin() + index);
    cout << "Course deleted successfully!" << endl;
    saveToFile();
}

// Search for a course
Course* Database::searchCourse(string courseCode) {
    int index = findCourseIndex(courseCode);
    
    if(index == -1) {
        return nullptr;
    }
    
    return &courses[index];
}

// Display all courses
void Database::displayAllCourses() {
    if(courses.empty()) {
        cout << "\nNo courses available!" << endl;
        return;
    }
    
    cout << "\n========== ALL COURSES ==========" << endl;
    for(int i = 0; i < courses.size(); i++) {
        courses[i].displayCourseInfo();
    }
}

// Enroll a student in a course
void Database::enrollStudentInCourse(int rollNo, string courseCode) {
    // Check if student exists
    int studentIndex = findStudentIndex(rollNo);
    if(studentIndex == -1) {
        cout << "Error: Student not found!" << endl;
        return;
    }
    
    // Check if course exists
    if(findCourseIndex(courseCode) == -1) {
        cout << "Error: Course not found!" << endl;
        return;
    }
    
    students[studentIndex].addCourse(courseCode);
    saveToFile();
}

// Add grade to a student for a course
void Database::addGradeToStudent(int rollNo, string courseCode, float grade) {
    int studentIndex = findStudentIndex(rollNo);
    
    if(studentIndex == -1) {
        cout << "Error: Student not found!" << endl;
        return;
    }
    
    students[studentIndex].addGrade(courseCode, grade);
    saveToFile();
}

// Save all data to files
void Database::saveToFile() {
    // Save students
    ofstream studentFile("students.txt");
    if(studentFile.is_open()) {
        for(int i = 0; i < students.size(); i++) {
            studentFile << students[i].serialize() << endl;
        }
        studentFile.close();
    }
    
    // Save courses
    ofstream courseFile("courses.txt");
    if(courseFile.is_open()) {
        for(int i = 0; i < courses.size(); i++) {
            courseFile << courses[i].serialize() << endl;
        }
        courseFile.close();
    }
}

// Load data from files
void Database::loadFromFile() {
    // Load students
    ifstream studentFile("students.txt");
    if(studentFile.is_open()) {
        string line;
        while(getline(studentFile, line)) {
            if(!line.empty()) {
                Student s;
                s.deserialize(line);
                students.push_back(s);
            }
        }
        studentFile.close();
    }
    
    // Load courses
    ifstream courseFile("courses.txt");
    if(courseFile.is_open()) {
        string line;
        while(getline(courseFile, line)) {
            if(!line.empty()) {
                Course c;
                c.deserialize(line);
                courses.push_back(c);
            }
        }
        courseFile.close();
    }
}
