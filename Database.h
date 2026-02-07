#ifndef DATABASE_H
#define DATABASE_H

#include <vector>
#include "Student.h"
#include "Course.h"

class Database {
private:
    vector<Student> students;
    vector<Course> courses;
    
    // Helper function to find student index
    int findStudentIndex(int rollNo);
    int findCourseIndex(string courseCode);

public:
    // Constructor
    Database();
    
    // Student operations
    void addStudent(int rollNo, string name, int age);
    void deleteStudent(int rollNo);
    void updateStudent(int rollNo);
    Student* searchStudent(int rollNo);
    void displayAllStudents();
    
    // Course operations
    void addCourse(string code, string name, int credits);
    void deleteCourse(string courseCode);
    Course* searchCourse(string courseCode);
    void displayAllCourses();
    
    // Enrollment operations
    void enrollStudentInCourse(int rollNo, string courseCode);
    void addGradeToStudent(int rollNo, string courseCode, float grade);
    
    // File operations
    void saveToFile();
    void loadFromFile();
};

#endif
