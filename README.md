# Student Management System

A comprehensive C++ application for managing student records, courses, and grades using Object-Oriented Programming principles.

## 📋 Project Overview

This Student Management System allows administrators to:
- Manage student records (Add, Delete, Update, Search)
- Manage course catalog
- Enroll students in courses
- Track student grades and calculate GPA
- Persist data to files

## 🎯 Features

### Student Management
- Add new students with roll number, name, and age
- Delete existing student records
- Update student information
- Search students by roll number
- View all students with their enrolled courses and grades

### Course Management
- Create new courses with course code, name, and credits
- Delete courses from the system
- View all available courses

### Enrollment & Grading
- Enroll students in multiple courses
- Add grades for enrolled courses
- Automatic GPA calculation
- Grade tracking per course

### Data Persistence
- Automatic save to text files
- Load data on program startup
- Maintains data between sessions

## 🛠️ Technical Implementation

### Classes Used

#### 1. Student Class
```cpp
- Attributes: rollNo, name, age, courses[], grades[]
- Methods: 
  - addCourse()
  - addGrade()
  - calculateGPA()
  - displayInfo()
  - serialize/deserialize for file I/O
```

#### 2. Course Class
```cpp
- Attributes: courseCode, courseName, credits
- Methods:
  - displayCourseInfo()
  - serialize/deserialize for file I/O
```

#### 3. Database Class
```cpp
- Manages collections of Student and Course objects
- Implements CRUD operations
- Handles file I/O operations
```

## 📊 Data Structures Used

- **Vector**: Dynamic arrays for storing students and courses
- **Map**: Hash map for storing course-grade pairs
- **String Streams**: For data serialization/deserialization

## 🚀 How to Compile and Run

### Compilation
```bash
g++ -std=c++11 main.cpp Student.cpp Course.cpp Database.cpp -o student_system
```

### Run
```bash
./student_system
```

### For Windows
```bash
g++ -std=c++11 main.cpp Student.cpp Course.cpp Database.cpp -o student_system.exe
student_system.exe
```

## 💻 Sample Usage

1. **Add a Course**
   - Select option 6
   - Enter course code (e.g., CS101)
   - Enter course name (e.g., Data Structures)
   - Enter credits (e.g., 4)

2. **Add a Student**
   - Select option 1
   - Enter roll number (e.g., 1001)
   - Enter name
   - Enter age

3. **Enroll Student**
   - Select option 9
   - Enter student roll number
   - Enter course code

4. **Add Grade**
   - Select option 10
   - Enter student roll number
   - Enter course code
   - Enter grade (0-10 scale)

## 📁 File Structure

```
student-management-system/
│
├── main.cpp           # Main program with menu interface
├── Student.h          # Student class declaration
├── Student.cpp        # Student class implementation
├── Course.h           # Course class declaration
├── Course.cpp         # Course class implementation
├── Database.h         # Database class declaration
├── Database.cpp       # Database class implementation
├── README.md          # Project documentation
├── students.txt       # Generated data file (auto-created)
└── courses.txt        # Generated data file (auto-created)
```

## 🔑 Key Concepts Demonstrated

1. **Object-Oriented Programming**
   - Encapsulation (private members, public methods)
   - Classes and Objects
   - Constructors and Destructors

2. **Data Structures & Algorithms**
   - Vector for dynamic storage
   - Map for key-value pairs
   - Linear search for finding records

3. **File Handling**
   - Reading from files
   - Writing to files
   - Data serialization

4. **Error Handling**
   - Input validation
   - Duplicate entry prevention
   - Null pointer checks

## 🎓 Learning Outcomes

By building this project, I learned:
- How to design classes in C++
- Implementing CRUD operations
- Working with STL containers (vector, map)
- File I/O operations
- Menu-driven program design
- Data persistence techniques

## 🔧 Future Enhancements

Possible improvements:
- Add login system with authentication
- Implement database (SQLite)
- Add search by name functionality
- Generate student report cards
- Add course prerequisites system
- Implement binary file storage for better performance

## 📝 Notes

- The system uses a 0-10 grading scale
- GPA is calculated as the average of all course grades
- Data is automatically saved after each operation
- Files are created in the same directory as the executable

## 👨‍💻 Author

Created as part of learning C++ programming and understanding Object-Oriented Programming concepts.

## 📄 License

This project is open source and available for educational purposes.

## 📅 Development Timeline

- Day 1: Designed class structure and implemented Student/Course classes
- Day 2: Built Database management system with CRUD operations
- Day 3: Added file persistence and tested thoroughly
- Day 4: Refined code and added documentation

## 🎓 What I Learned

- Object-Oriented Programming in C++
- Working with STL containers (vector, map)
- File I/O and serialization
- Menu-driven program design
