بسم الله الرحمن الرحیم

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

در این بخش از کد ابتدا سر فایل ها و سپس تعریف دو استراکچر اصلی پروژه 
دانشجو و درس های دانشجو را داریم و طبق خواسته های پروژه تنظیم شده است.


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

در این بخش از کد  دو تابع داریم.
تابع اول وظیفه این را دارد که تعداد دروس دانشجو را در ابتدا صفر تنظیم کند.

و  تابع دوم وظیفه اضافه کردن دروس برای دانشجو را دارد که تعداد دروس دانشجو را با یک گزاره شرطی چک کرده و اگر هنوز امکان اضافه کردن درس وجود داشت این تابع اطلاعات درس یعنی نام تعداد واحد ها و نمره درس را در آرایه ذخیره می کند.
و در آخر هم یک عدد به تعداد دروس اضافه می شود.


float calculateGPA(const Student &student) { 
    float totalPoints = 0; 
    int totalUnits = 0; 
 
    for (int i = 0; i < student.courseCount; i++) { 
        totalPoints += student.courses[i].courseGrade * student.courses[i].courseUnits; 
        totalUnits += student.courses[i].courseUnits; 
    } 
 
    return (totalUnits > 0) ? (totalPoints / totalUnits) : 0.0; 
} 

در این قسمت تابعی برای محاسبه ی معدل داریم که طبق فرمول محاسبه معدل نمره ها را در واحد ها ضرب کرده و در نهایت پس از جمع کردنشان بر مجموع واحد ها تقسیم می کند.


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

در این قسمت از کد تابع چاپ کارنامه را داریم که ابتدا شکل بصری کارنامه و سپس چاپ قسمت های مختلف آن مانند نام درس نمره و واحد آن و درنهایت معدل دانشجو را چاپ می کند.


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

در این بخش تابع چاپ لیست کلی دانشجویان را داریم که در ابتدای تابع به مرتب کردن دانشجویان بر اساس معدل و سپس به تنظیم شکل بصری لیست پرداخته است.

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


