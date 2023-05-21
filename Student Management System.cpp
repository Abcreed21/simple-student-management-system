#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct Student {
    string name;
    int id;
    string course;
    string section;
    string batch;
};

struct Teacher {
    string name;
    int id;
    string course;
    string section;
    string batch;
};

struct Course {
    string course;
    int id;
    string batch;
};

// function to create a student
void createStudent(Student s[], int& count) {
    cout << "Enter student name: ";
    cin >> s[count].name;

    cout << "Enter student id: ";
    cin >> s[count].id;

    cout << "Enter course: ";
    cin >> s[count].course;

    cout << "Enter section: ";
    cin >> s[count].section;

    cout << "Enter batch: ";
    cin >> s[count].batch;

    count++;
}

// function to display student information
void displayStudent(Student s[], int count) {
    for (int i = 0; i < count; i++) {
        cout << "Name: " << s[i].name << endl;
        cout << "ID: " << s[i].id << endl;
        cout << "Course: " << s[i].course << endl;
        cout << "Section: " << s[i].section << endl;
        cout << "Batch: " << s[i].batch << endl;
        cout << endl;
    }
}

// function to search student information
void searchStudent(Student s[], int count) {
    cout << "Enter student id to search: ";
    int id;
    cin >> id;

    bool found = false;
    for (int i = 0; i < count; i++) {
        if (s[i].id == id) {
            found = true;
            cout << "Student found!" << endl;
            cout << "Name: " << s[i].name << endl;
            cout << "ID: " << s[i].id << endl;
            cout << "Course: " << s[i].course << endl;
            cout << "Section: " << s[i].section << endl;
            cout << "Batch: " << s[i].batch << endl;
            break;
        }
    }
    if (!found) {
        cout << "Student not found!" << endl;
    }
}

//function to update student information
void updateStudent(Student s[], int count) {
    int idToUpdate = 0;

    cout << "Enter the ID of the student you want to update: ";
    cin >> idToUpdate;

    bool found = false;
    for (int i = 0; i < count; i++) {
        if (s[i].id == idToUpdate) {
            found = true;
            cout << "Student found!" << endl;
            cout << "Enter new name: ";
            cin >> s[i].name;
            cout << "Enter new course: ";
            cin >> s[i].course;
            cout << "Enter new section: ";
            cin >> s[i].section;
            cout << "Enter new batch: ";
            cin >> s[i].batch;
            break;
        }
    }
    if (!found) {
        cout << "Student not found!" << endl;
    }
}

//function to delete student
void deleteStudent(Student s[], int& count) {
    int idToDelete = 0;

    cout << "Enter the ID of the student you want to delete: ";
    cin >> idToDelete;

    bool found = false;
    for (int i = 0; i < count; i++) {
        if (s[i].id == idToDelete) {
            found = true;
            s[i] = s[count - 1]; // Replace with last record
            count--;
            cout << "Student deleted successfully!" << endl;
            break;
        }
    }
    if (!found) {
        cout << "Student not found!" << endl;
    }
}

//function to create teacher information
void createTeacher(Teacher t[], int& count) {

    cout << "Enter Teacher Name: ";
    cin >> t[count].name;

    cout << "Enter Teacher ID: ";
    cin >> t[count].id;

    cout << "Enter Teacher Course: ";
    cin >> t[count].course;

    cout << "Enter Teacher Section: ";
    cin >> t[count].section;

    cout << "Enter Teacher Batch: ";
    cin >> t[count].batch;

    count++;
}

//function to display teacher information
void displayTeacher(Teacher t[], int count) {

    for (int i = 0; i < count; i++) {
        cout << "Name: " << t[i].name << endl;
        cout << "ID: " << t[i].id << endl;
        cout << "Course: " << t[i].course << endl;
        cout << "Section: " << t[i].section << endl;
        cout << "Batch: " << t[i].batch << endl;
    }
}

//function to enter course information
void enterCourse(Course c[], int& count) {

    cout << "Enter Course: ";
    cin >> c[count].course;
    cout << "Enter ID: ";
    cin >> c[count].id;
    cout << "Enter Batch: ";
    cin >> c[count].batch;

    count++;
}


void displayCourse(Course c[], int count) {

    for (int i = 0; i < count; i++) {
        cout << "Course: " << c[i].course << endl;
        cout << "ID: " << c[i].id << endl;
        cout << "Batch: " << c[i].batch << endl;
    }
}

void displayAndStore(Student s[], Teacher t[], Course c[], int count) {
    ofstream outFile("student_records.txt"); // Open file for writing

    for (int i = 0; i < count; i++) {
        outFile << s[i].name << "," << s[i].id << "," << s[i].course << "," << s[i].section << "," << s[i].batch << "\n"; // Write student record to file
    }

    for (int i = 0; i < count; i++) {
        outFile << t[i].name << "," << t[i].id << "," << t[i].course << "," << t[i].section << "," << t[i].batch << "\n"; // Write teacher record to file
    }

    for (int i = 0; i < count; i++) {
        outFile << c[i].course << "," << c[i].id << "," << c[i].batch << "\n"; // Write course record to file
    }

    outFile.close(); // Close file after writing

    // Display success message
    cout << "Student, teacher, and course information saved to file." << endl;
}

//function to exit
void exitProgram() {
    cout << "Exiting........." << endl;
}

int main() {
    const int MAX_STUDENTS = 100; // Maximum number of allowed student records
    const int MAX_TEACHERS = 10; // Maximum number of allowed teacher records
    const int MAX_COURSES = 10; // Maximum number of allowed course records

    int choice = 0;
	int count = 0;

    Student students[MAX_STUDENTS];
    Teacher teachers[MAX_TEACHERS];
    Course courses[MAX_COURSES];

    while (choice != 11) {
        cout << "\t\t\t\t\t\t\t\t\t\t|*************************************|" << endl;
        cout << "\t\t\t\t\t\t\t\t\t\t|         Group Member Name           |" << endl;
        cout << "\t\t\t\t\t\t\t\t\t\t|1. Alpha Tesfaye RDCS-121-21A        |" << endl;
        cout << "\t\t\t\t\t\t\t\t\t\t|2. Abenezer Mengistu RDCS-121-21A    |" << endl;
        cout << "\t\t\t\t\t\t\t\t\t\t|3. Betelhem Teshome RDCS-121-21A     |" << endl;
        cout << "\t\t\t\t\t\t\t\t\t\t|4. Feven Yirefu RDCS-121-21A         |" << endl;
        cout << "\t\t\t\t\t\t\t\t\t\t|5. Tibebesilasie Tilahun RDCS-121-21A|" << endl;
        cout << "\t\t\t\t\t\t\t\t\t\t|2. Sofoniyas Tesfu                   |" << endl;
        cout << "\t\t\t\t\t\t\t\t\t\t|*************************************|" << endl;
 
       
        cout << "|***************************|" << endl;
        cout << "| Student Management System |" << endl;
        cout << "|1. Create student          |" << endl;
        cout << "|2. Display students        |" << endl;
        cout << "|3. Search student          |" << endl;
        cout << "|4. Update student          |" << endl;
        cout << "|5. Delete student          |" << endl;
        cout << "|6. Create teacher          |" << endl;
        cout << "|7. Display teachers        |" << endl;
        cout << "|8. Enter course information|" << endl;
        cout << "|9. Display courses         |" << endl;
        cout << "|10. Save to file           |" << endl;
        cout << "|11. Exit                   |" << endl;
        cout << "|***************************|" << endl;

       
        cout << "Enter option: " << endl;
        cin >> choice;
        
        switch (choice) {
        case 1:
            createStudent(students, count);
            break;
        case 2:
            displayStudent(students, count);
            break;
        case 3:
            searchStudent(students, count);
            break;
        case 4:
            updateStudent(students, count);
            break;
        case 5:
            deleteStudent(students, count);
            break;
        case 6:
            createTeacher(teachers, count);
            break;
        case 7:
            displayTeacher(teachers, count);
            break;
        case 8:
            enterCourse(courses, count);
            break;
        case 9:
            displayCourse(courses, count);
            break;
        case 10:
            displayAndStore(students, teachers, courses, count);
            break;
        case 11:
            exitProgram();
            break;
   return 0;
 }
  }
}