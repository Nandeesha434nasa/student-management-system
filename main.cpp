#include <iostream>
#include <limits>
#include "Database.h"

using namespace std;

// Function to clear input buffer
void clearInputBuffer() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

// Function to display main menu
void displayMenu() {
    cout << "\n╔════════════════════════════════════════╗" << endl;
    cout << "║   STUDENT MANAGEMENT SYSTEM            ║" << endl;
    cout << "╚════════════════════════════════════════╝" << endl;
    cout << "\n--- STUDENT OPERATIONS ---" << endl;
    cout << "1. Add Student" << endl;
    cout << "2. Delete Student" << endl;
    cout << "3. Update Student" << endl;
    cout << "4. Search Student" << endl;
    cout << "5. Display All Students" << endl;
    
    cout << "\n--- COURSE OPERATIONS ---" << endl;
    cout << "6. Add Course" << endl;
    cout << "7. Delete Course" << endl;
    cout << "8. Display All Courses" << endl;
    
    cout << "\n--- ENROLLMENT OPERATIONS ---" << endl;
    cout << "9. Enroll Student in Course" << endl;
    cout << "10. Add Grade to Student" << endl;
    
    cout << "\n0. Exit" << endl;
    cout << "\nEnter your choice: ";
}

int main() {
    Database db;
    int choice;
    
    cout << "\n========================================" << endl;
    cout << "  Welcome to Student Management System  " << endl;
    cout << "========================================\n" << endl;
    
    // Main program loop
    while(true) {
        displayMenu();
        cin >> choice;
        
        // Handle invalid input
        if(cin.fail()) {
            clearInputBuffer();
            cout << "Invalid input! Please enter a number." << endl;
            continue;
        }
        
        clearInputBuffer();
        
        switch(choice) {
            case 1: {
                // Add Student
                int rollNo, age;
                string name;
                
                cout << "\n--- Add New Student ---" << endl;
                cout << "Enter Roll Number: ";
                cin >> rollNo;
                clearInputBuffer();
                
                cout << "Enter Name: ";
                getline(cin, name);
                
                cout << "Enter Age: ";
                cin >> age;
                
                db.addStudent(rollNo, name, age);
                break;
            }
            
            case 2: {
                // Delete Student
                int rollNo;
                cout << "\n--- Delete Student ---" << endl;
                cout << "Enter Roll Number to delete: ";
                cin >> rollNo;
                
                db.deleteStudent(rollNo);
                break;
            }
            
            case 3: {
                // Update Student
                int rollNo;
                cout << "\n--- Update Student ---" << endl;
                cout << "Enter Roll Number to update: ";
                cin >> rollNo;
                
                db.updateStudent(rollNo);
                break;
            }
            
            case 4: {
                // Search Student
                int rollNo;
                cout << "\n--- Search Student ---" << endl;
                cout << "Enter Roll Number to search: ";
                cin >> rollNo;
                
                Student* s = db.searchStudent(rollNo);
                if(s != nullptr) {
                    s->displayInfo();
                } else {
                    cout << "Student not found!" << endl;
                }
                break;
            }
            
            case 5: {
                // Display All Students
                db.displayAllStudents();
                break;
            }
            
            case 6: {
                // Add Course
                string code, name;
                int credits;
                
                cout << "\n--- Add New Course ---" << endl;
                cout << "Enter Course Code (e.g., CS101): ";
                cin >> code;
                clearInputBuffer();
                
                cout << "Enter Course Name: ";
                getline(cin, name);
                
                cout << "Enter Credits: ";
                cin >> credits;
                
                db.addCourse(code, name, credits);
                break;
            }
            
            case 7: {
                // Delete Course
                string code;
                cout << "\n--- Delete Course ---" << endl;
                cout << "Enter Course Code to delete: ";
                cin >> code;
                
                db.deleteCourse(code);
                break;
            }
            
            case 8: {
                // Display All Courses
                db.displayAllCourses();
                break;
            }
            
            case 9: {
                // Enroll Student in Course
                int rollNo;
                string courseCode;
                
                cout << "\n--- Enroll Student in Course ---" << endl;
                cout << "Enter Student Roll Number: ";
                cin >> rollNo;
                
                cout << "Enter Course Code: ";
                cin >> courseCode;
                
                db.enrollStudentInCourse(rollNo, courseCode);
                break;
            }
            
            case 10: {
                // Add Grade
                int rollNo;
                string courseCode;
                float grade;
                
                cout << "\n--- Add Grade ---" << endl;
                cout << "Enter Student Roll Number: ";
                cin >> rollNo;
                
                cout << "Enter Course Code: ";
                cin >> courseCode;
                
                cout << "Enter Grade (0-10): ";
                cin >> grade;
                
                db.addGradeToStudent(rollNo, courseCode, grade);
                break;
            }
            
            case 0: {
                // Exit
                cout << "\nThank you for using Student Management System!" << endl;
                cout << "All data has been saved. Goodbye!\n" << endl;
                return 0;
            }
            
            default:
                cout << "\nInvalid choice! Please try again." << endl;
        }
    }
    
    return 0;
}
