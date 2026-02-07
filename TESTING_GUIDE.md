# Testing Guide - Student Management System

## 🧪 Complete Testing Checklist

### Before Each Test Session
```bash
# Delete old data files
rm students.txt courses.txt

# Compile fresh
g++ -std=c++11 main.cpp Student.cpp Course.cpp Database.cpp -o student_system

# Run
./student_system
```

---

## Test Case 1: Basic Flow ✅

### Steps:
1. **Add Course**
   - Option: 6
   - Code: CS101
   - Name: Data Structures
   - Credits: 4
   - Expected: "Course added successfully!"

2. **Add Another Course**
   - Option: 6
   - Code: MATH201
   - Name: Calculus II
   - Credits: 3
   - Expected: "Course added successfully!"

3. **Display All Courses**
   - Option: 8
   - Expected: Both courses displayed

4. **Add Student**
   - Option: 1
   - Roll: 1001
   - Name: John Doe
   - Age: 20
   - Expected: "Student added successfully!"

5. **Display All Students**
   - Option: 5
   - Expected: Student displayed with no courses

6. **Enroll Student**
   - Option: 9
   - Roll: 1001
   - Course: CS101
   - Expected: "Course CS101 added successfully!"

7. **Enroll in Another Course**
   - Option: 9
   - Roll: 1001
   - Course: MATH201
   - Expected: "Course MATH201 added successfully!"

8. **Add Grade**
   - Option: 10
   - Roll: 1001
   - Course: CS101
   - Grade: 8.5
   - Expected: "Grade added successfully!"

9. **Add Another Grade**
   - Option: 10
   - Roll: 1001
   - Course: MATH201
   - Grade: 9.0
   - Expected: "Grade added successfully!"

10. **Display Student**
    - Option: 4
    - Roll: 1001
    - Expected: Shows both courses with grades and GPA 8.75

---

## Test Case 2: Error Handling ⚠️

### Test 2.1: Duplicate Student
- Add student with roll 1001
- Try to add another student with roll 1001
- Expected: "Error: Student with Roll No 1001 already exists!"

### Test 2.2: Duplicate Course
- Add course CS101
- Try to add CS101 again
- Expected: "Error: Course with code CS101 already exists!"

### Test 2.3: Invalid Grade
- Add grade: -5
- Expected: "Invalid grade! Please enter between 0-10"

### Test 2.4: Student Not Found
- Search roll: 9999
- Expected: "Student not found!"

### Test 2.5: Enroll in Same Course Twice
- Enroll student 1001 in CS101
- Try to enroll again in CS101
- Expected: "Course already enrolled!"

---

## Test Case 3: Data Persistence 💾

### Steps:
1. Add student and courses (as in Test 1)
2. Exit program (option 0)
3. Restart program
4. Display all students (option 5)
5. Display all courses (option 8)
- Expected: All data should be present!

---

## Test Case 4: Update Operations 🔄

### Update Name:
- Option: 3
- Roll: 1001
- Choice: 1
- New name: John Smith
- Expected: "Name updated successfully!"

### Update Age:
- Option: 3
- Roll: 1001
- Choice: 2
- New age: 21
- Expected: "Age updated successfully!"

---

## Test Case 5: Delete Operations 🗑️

### Delete Student:
- Add student roll 2002
- Delete student roll 2002
- Search student 2002
- Expected: "Student not found!"

### Delete Course:
- Add course PHY301
- Delete course PHY301
- Display all courses
- Expected: PHY301 not in list

---

## Test Case 6: Edge Cases 🎯

### Test 6.1: Empty Database
- Start fresh (no data files)
- Display all students
- Expected: "No students in the database!"

### Test 6.2: Student with No Grades
- Add student
- Enroll in course (don't add grade)
- Display student
- Expected: No GPA shown

### Test 6.3: Multiple Students
- Add 5 students
- Display all
- Expected: All 5 displayed correctly

### Test 6.4: Invalid Input
- At menu, type: "abc"
- Expected: "Invalid input! Please enter a number."

---

## Test Case 7: GPA Calculation Verification 🧮

### Scenario 1: One Course
- Grade: 8.0
- Expected GPA: 8.00

### Scenario 2: Two Courses
- Grades: 8.0, 9.0
- Expected GPA: 8.50

### Scenario 3: Three Courses
- Grades: 7.0, 8.0, 9.0
- Expected GPA: 8.00

### Scenario 4: Uneven Grades
- Grades: 10.0, 5.0, 7.5
- Expected GPA: 7.50

---

## 📊 Expected vs Actual Results Template

| Test | Expected | Actual | Status |
|------|----------|--------|--------|
| Add Student | Success message | | ⬜ |
| Duplicate Student | Error message | | ⬜ |
| GPA Calculation | 8.75 | | ⬜ |
| Data Persistence | Data saved | | ⬜ |
| Delete Student | Success + removed | | ⬜ |

---

## 🐛 Common Issues and Fixes

### Issue: Grades not showing
**Fix**: Make sure you enrolled in course BEFORE adding grade

### Issue: GPA shows 0.00
**Fix**: Check if grades were actually added

### Issue: Program crashes on invalid input
**Fix**: Already handled with cin.fail() check

### Issue: Data not persisting
**Fix**: Check if files have write permissions

---

## 🎯 Quick Smoke Test (30 seconds)

Run this sequence to verify basic functionality:
```
1. Add Course: CS101, Programming, 4
2. Add Student: 101, Test Student, 20
3. Enroll: 101 in CS101
4. Add Grade: 101, CS101, 8.5
5. Display Student 101
6. Exit and restart
7. Display Student 101 (should still be there!)
```

If all these work → System is good! ✅

---

## 📝 Test Log Template

```
Date: _____________
Tester: ___________

Test Case 1 - Basic Flow: ⬜ Pass ⬜ Fail
Notes: _________________________________

Test Case 2 - Error Handling: ⬜ Pass ⬜ Fail
Notes: _________________________________

Test Case 3 - Persistence: ⬜ Pass ⬜ Fail
Notes: _________________________________

Overall Status: ⬜ All Pass ⬜ Issues Found
```

---

## 🎓 What to Say About Testing

**Interviewer**: "Did you test your code?"

**You**: "Yes! I tested several scenarios:
1. Basic CRUD operations for students and courses
2. Error handling - duplicate entries, invalid inputs
3. Data persistence by restarting the program
4. GPA calculation with different grade combinations
5. Edge cases like empty database and invalid grades

I also handled input validation to prevent crashes from invalid user input."

---

Good luck with testing! 🚀
