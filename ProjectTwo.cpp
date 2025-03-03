
// Author: Maggie Dixon
// CS-300 Project 2

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

class Course {
public:
    string courseId;
    string courseTitle;
    vector<string> preRequisites;
};

// Function to load courses from a file into a vector
void loadVector(const string& textFile, vector<Course>& courses) {
    ifstream file(textFile);
    
    if (file.is_open()) {
        Course tempCourse;
        
        while (file >> tempCourse.courseId >> tempCourse.courseTitle) {
            string preRequisite;
            tempCourse.preRequisites.clear();

            while (file >> preRequisite && preRequisite != "-1") {
                tempCourse.preRequisites.push_back(preRequisite);
            }
            
            courses.push_back(tempCourse);
        }
        
        file.close();
        cout << "Courses have been imported." << endl;
    } else {
        cout << "File not found." << endl;
    }
}

// Function to print the list of courses
void printCourseList(const vector<Course>& courses) {
    for (const Course& course : courses) {
        cout << course.courseId << ", " << course.courseTitle << endl;
    }
}

// Function to print course details
void printCourseInformation(const vector<Course>& courses, const string& courseNumber) {
    bool found = false;
    
    for (const Course& course : courses) {
        if (course.courseId == courseNumber) {
            found = true;
            cout << course.courseId << ": " << course.courseTitle << endl;

            if (!course.preRequisites.empty()) {
                cout << "Prerequisites: ";
                for (const string& preReq : course.preRequisites) {
                    cout << preReq << " ";
                }
                cout << endl;
            } else {
                cout << "Prerequisites: None listed." << endl;
            }
            break;
        }
    }

    if (!found) {
        cout << "Course not found." << endl;
    }
}

int main() {
    vector<Course> courses;
    string textFile;
    int choice;

    while (true) {
        // Display menu options
        cout << "\nMenu:\n";
        cout << "1. Load Data Structure.\n";
        cout << "2. Print Course List.\n";
        cout << "3. Print Course.\n";
        cout << "9. Exit\n";
        cout << "What would you like to do? ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter filename: ";
                cin >> textFile;
                loadVector(textFile, courses);
                break;
            case 2:
                printCourseList(courses);
                break;
            case 3:
                string courseNumber;
                cout << "Enter course number: ";
                cin >> courseNumber;
                printCourseInformation(courses, courseNumber);
                break;
            case 9:
                cout << "Thank you for using the course planner!" << endl;
                return 0;
            default:
                cout << "Invalid choice. Please enter a valid option." << endl;
                break;
        }
    }
}
