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

این تابع برای چاپ لیست دانشجویان به صورت تفکیک شده است.
سپس در یک آرایه ای برای دانشجویان فیلتر شده بر اساس رشته تعریف کرده و در حلقه یا آنها را فیلتر کرده و به آرایه اضافه می کند.
سپس دانشجویان را بر اساس معدل مرتب کرده و درنهایت به شکل بصری و خروجی های لازم برای لیست می پردازد‌.


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

از این قسمت به بعد کد وارد تابع اصلی یا تابع main شده و در این قسمت کد به چاپ منوی اولیه برای ارتباط با کاربر می پردازد.

در قسمت های بعدی شرط های لازم برای وارد کردن هر کدام از اعداد منو را توسط مخاطب ایجاد می کند.

 
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

گزینه اول منو اضافه کردن دانشجو است.
در این عملیات از کاربر نام شماره دانشجویی و رشته ی دانشجو را گرفته و سپس وارد قسمت مناسب از استراکچر در آرایه می کند.
و در صورت با موفقیت انجام شدن عملیات پیام عملیات با موفقیت انجام شد را چاپ می کند.

            
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

به دادن دستورات لازم برای گزینه دوم منو یعنی اضافه کردن درس می پردازد.
برای تسهیل روند پیدا کردن دانشجو از کاربر شماره دانشجویی دانشجوی مورد نظر را گرفته و در خانه های آرایه جستجو می کند. اگر آن را یافت به ادامه فرآیند پرداخته و در غیر اینصورت پیام پیدا نکردن شماره دانشجویی را چاپ می کند.
سپس از کاربر درس، واحد و نمره درس را گرفته و به خانه مورد نظر از آرایه وصل می کند.


            
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

در این بخش هم گزینه سوم منو که چاپ کارنامه است انجام می شود.
مانند قسمت قبل ابتدا کد دانشجویی را گرفته و جستجو را انجام داده و در صورت موفقیت آمیز بودن تابع چاپ کارنامه را برای دانشجوی مورد نظر اجرا می کند.
و در غیر اینصورت پیام یافت نشدن شماره دانشجویی را ارسال می کند.

            
        } else if (choice == 4) { 
            printSortedStudents(students, studentCount); 
        } else if (choice == 5) { 
            printStudentsByMajor(students, studentCount); 
        } 
    } while (choice != 6); 
 
    return 0; 
}
و در آخرین بخش کد گزینه ۴ و ۵ لیست که چاپ لیست کلی و تفکیک شده است را اجرا کرده و توابع آن را فراخوانی می کند.
در نهایت هم گزینه ۶ که خارج شدن است را اجرا می کرده و درنهایت هم کد به پایان می رسد.



