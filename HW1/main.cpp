#include <iostream>

#include <fstream>

#include <vector>

#include <string>

#include <iomanip>




using namespace std;

const int maxCourseAmt = 99;




struct Course

{
    string course = "";
    int credit = 0;
    int score = 0;
    int grade = 0;

};




struct Student

{

    int ID = 0;
    string name = "";
    vector<Course> arrCourse;

};




int isInArray(vector<Student> arr, int target)

{

    for (int i = 0; i < arr.size(); i++)
        if (arr.at(i).ID == target)
            return i;

    return -1;

}



double getCourseGPA(Course course)

{

    if (course.score >= 90) {

        return 4.0;

    } else if (course.score >= 80) {
        
        return 3.0;

    } else if (course.score >= 70) {
        
        return 2.0;

    } else if (course.score >= 60) {

        return 1.0;

    } else {
        
        return 0.0;

    }

}



double getGPA(vector<Course> stuCourse)

{

    double points = 0;
    int credit = 0;

    for (int i = 0; i < stuCourse.size(); i++) {

        points += (1.0 * getCourseGPA(stuCourse.at(i)) * stuCourse.at(i).credit);
        
    }


    for (int i = 0; i < stuCourse.size(); i++) {

        credit += stuCourse.at(i).credit;

    }

    return (points/credit);

}




int main()

{

    fstream inputFile;
    string fileName = "StudentRecords.txt";
    string token;

    vector<Student> arrStu;
    inputFile.open(fileName, ios::in);

    if (inputFile.is_open())
    {
        int index = 0;
        int ID = 0;
        string name;
        string courseName;
        int credit;
        int score;

        while (!inputFile.eof())
        {
            inputFile >> ID;
            inputFile >> name;
            inputFile >> courseName;
            inputFile >> credit;
            inputFile >> score;

            Course stuCourse;
            stuCourse.course = courseName;
            stuCourse.credit = credit;
            stuCourse.score = score;

            // cout << ID << " " << name << " " << courseName << " " << credit << " " << score << endl;

            int ii = isInArray(arrStu, ID);

            if (ii == -1) // The student record does not exist
            {
                Student student;
                student.ID = ID;
                student.name = name;
                student.arrCourse.push_back(stuCourse);
                arrStu.push_back(student);
                index++;
            }
            else /// The student exists
            {
                /// Add course and score to the existing student record

                arrStu.at(ii).arrCourse.push_back(stuCourse);
            }

            stuCourse.course = "";
            stuCourse.credit = 0;
            stuCourse.score = 0;
        }

        inputFile.close();

    }
    else
        cout << "File cannot be opened.";


    
    
    for (int i = 0; i < arrStu.size(); i++) {

        Student stu = arrStu.at(i);

        cout << stu.ID << " " << stu.name << endl << endl;
        cout << "=========" << endl << endl;

        for (int ii = 0; ii < stu.arrCourse.size(); ii++) {

            cout << stu.arrCourse.at(ii).course << " " << stu.arrCourse.at(ii).credit << " " << stu.arrCourse.at(ii).score << " " << getCourseGPA(stu.arrCourse.at(ii)) << endl;

        }

        cout << endl << endl << "======================" << endl << endl;
        cout << "GPA " << setprecision(3) << getGPA(stu.arrCourse) << endl << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl << endl << endl << endl << endl;
         
    }


    return 0;

}
