
#include <iostream> 
#include <string> 
#include <iomanip> 
 
using namespace std; 
 
const int MAX_STUDENTS = 300; 
const int MAX_COURSES = 10; 
 
struct Course { 
    string courseName; 
    float courseGrade; 
    int courseUnits; 
}; 
 
struct Student { 
    string name; 
    string studentID; 
    string major; 
    Course courses[MAX_COURSES]; 
    int courseCount; 
}; 
 
void initializeStudent(Student &student) { 
    student.courseCount = 0; 
} 
 
void addCourse(Student &student, string courseName, float courseGrade, int courseUnits) { 
    if (student.courseCount < MAX_COURSES) { 
        student.courses[student.courseCount].courseName = courseName; 
        student.courses[student.courseCount].courseGrade = courseGrade; 
        student.courses[student.courseCount].courseUnits = courseUnits; 
        student.courseCount++; 
    } else { 
        cout << "Cannot add more courses. Maximum limit reached." << endl; 
    } 
} 
 
float calculateGPA(const Student &student) { 
    float totalPoints = 0; 
    int totalUnits = 0; 
 
    for (int i = 0; i < student.courseCount; i++) { 
        totalPoints += student.courses[i].courseGrade * student.courses[i].courseUnits; 
        totalUnits += student.courses[i].courseUnits; 
    } 
 
    return (totalUnits > 0) ? (totalPoints / totalUnits) : 0.0; 
} 
 
void printReportCard(const Student& student) { 
    cout << "===================================" << endl; 
    cout << "          Report Card           " << endl; 
    cout << "===================================" << endl; 
    cout << "Name: " << student.name << endl << endl; 
    cout << "ID: " << student.studentID << "     Major: " << student.major << endl; 
    cout << "-----------------------------------" << endl; 
    cout << left << setw(20) << "Course" << setw(10) << "Grade" << setw(10) << "Units" << endl; 
    cout << "-----------------------------------" << endl; 
 
    for (int i = 0; i < student.courseCount; i++) { 
        cout << left << setw(20) << student.courses[i].courseName 
             << setw(10) << fixed << setprecision(2) << student.courses[i].courseGrade 
             << setw(10) << student.courses[i].courseUnits << endl; 
    } 
    cout << "-----------------------------------" << endl; 
    cout << "  GPA = " << fixed << setprecision(2) << calculateGPA(student) << endl; 
    cout << "===================================" << endl; 
} 
 

void printSortedStudents(Student students[], int studentCount) { 
    
    for (int i = 0; i < studentCount - 1; i++) { 
        for (int j = i + 1; j < studentCount; j++) { 
            if (calculateGPA(students[i]) < calculateGPA(students[j])) { 
                Student temp = students[i]; 
                students[i] = students[j]; 
                students[j] = temp; 
            } 
        } 
    } 
 
    cout << "===================================" << endl; 
    cout << "          Sorted Students         " << endl; 
    cout << "===================================" << endl; 
    cout << left << setw(20) << "Name" << setw(15) << "ID" << setw(15) << "Major" << setw(10) << "GPA" << endl; 
    cout << "-----------------------------------" << endl; 
 
    for (int i = 0; i < studentCount; i++) { 
        cout << left << setw(20) << students[i].name 
             << setw(15) << students[i].studentID 
             << setw(15) << students[i].major 
             << setw(10) << fixed << setprecision(2) << calculateGPA(students[i]) << endl; 
    } 
    cout << "===================================" << endl; 
} 
 
void printStudentsByMajor(Student students[], int studentCount) { 
    string major; 
    cout << "Enter the major to filter students: "; 
    getline(cin, major); 
 
    Student filteredStudents[MAX_STUDENTS]; 
    int filteredCount = 0; 
 
    for (int i = 0; i < studentCount; i++) {


if(students[i].major == major) { 
            filteredStudents[filteredCount] = students[i]; 
            filteredCount++; 
        } 
    } 
 
    for (int i = 0; i < filteredCount - 1; i++) { 
        for (int j = i + 1; j < filteredCount; j++) { 
            if (calculateGPA(filteredStudents[i]) < calculateGPA(filteredStudents[j])) { 
                
                Student temp = filteredStudents[i]; 
                filteredStudents[i] = filteredStudents[j]; 
                filteredStudents[j] = temp; 
            } 
        } 
    } 
 
    
    cout << "===================================" << endl; 
    cout << "          Students in Major       " << major << endl; 
    cout << "===================================" << endl; 
    cout << left << setw(20) << "Name" << setw(15) << "ID" << setw(15) << "Major" << setw(10) << "GPA" << endl; 
    cout << "-----------------------------------" << endl; 
 
    for (int i = 0; i < filteredCount; i++) { 
        cout << left << setw(20) << filteredStudents[i].name 
             << setw(15) << filteredStudents[i].studentID 
             << setw(15) << filteredStudents[i].major 
             << setw(10) << fixed << setprecision(2) << calculateGPA(filteredStudents[i]) << endl; 
    } 
    cout << "===================================" << endl; 
} 
 
int main() { 
    Student students[MAX_STUDENTS]; 
    int studentCount = 0; 
    int choice; 
 
    do { 
        cout << "**************************" << endl; 
        cout << "1. Register Student\n2. Add Course\n3. Print Report Card for Student\n4. Print Students List \n5. Print Students List by Major\n6. Exit\n"; 
        cout << "Enter your choice: "; 
        cin >> choice; 
        cin.ignore(); 
 
        if (choice == 1) { 
            if (studentCount < MAX_STUDENTS) { 
                string name, id, major; 
                cout << "Enter student name: "; 
                getline(cin, name); 
                cout << "Enter student ID: "; 
                getline(cin, id); 
                cout << "Enter major: "; 
                getline(cin, major); 
 
                students[studentCount].name = name; 
                students[studentCount].studentID = id; 
                students[studentCount].major = major; 
                initializeStudent(students[studentCount]); 
                studentCount++; 
                cout << "Student registered successfully!" << endl; 
            } else { 
                cout << "Cannot register more students. Maximum limit reached." << endl; 
            } 
        } else if (choice == 2) { 
            string id, courseName; 
            float courseGrade; 
            int courseUnits; 
            cout << "Enter student ID to add course: "; 
            getline(cin, id); 
 
            bool found = false; 
            for (int i = 0; i < studentCount; i++) { 
                if (students[i].studentID == id) { 
                    found = true; 
                    cout << "Enter course name: "; 
                    getline(cin, courseName); 
                    cout << "Enter course grade: "; 
                    cin >> courseGrade; 
                    cout << "Enter course units: "; 
                    cin >> courseUnits; 
                    cin.ignore(); 
                    addCourse(students[i], courseName, courseGrade, courseUnits); 
                    cout << "Course added successfully!" << endl; 
                    break; 
                } 
            } 
            if (!found) { 
                cout << "Student ID not found." << endl; 
            } 
        } else if (choice == 3) { 
            string id; 
            cout << "Enter student ID to print Student report card: "; 
            getline(cin, id); 
 
            bool found = false; 
            for (int i = 0; i < studentCount; i++) { 
                if (students[i].studentID == id) { 
                    found = true; 
                    printReportCard(students[i]); 
                    break;}
            } 
            if (!found) { 
                cout << "Student ID not found." << endl; 
            } 
        } else if (choice == 4) { 
            printSortedStudents(students, studentCount); 
        } else if (choice == 5) { 
            printStudentsByMajor(students, studentCount); 
        } 
    } while (choice != 6); 
 
    return 0; 
}