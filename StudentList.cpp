#include <iostream>
#include <cstring>
#include <vector>
#include <iterator>
#include <iomanip>

using namespace std;

struct Student {
  char firstName[20];
  char lastName[20];
  int studentID;
  float studentGPA;
};

void addStudent(vector<Student*> &studentList);
void printStudent(vector<Student*> studentList);
void deleteStudent(vector<Student*> &studentList, int input);

int main() {
  vector<Student*> studentList;
  bool quit = false;
  char input[6];
  while (quit == false) {
    cout << "You can: \'ADD\' \'PRINT\' \'DELETE\' \'QUIT\'" << endl;
    cin >> input;
    if (strcmp(input, "ADD") == 0) {
      addStudent(studentList);
    }
    else if (strcmp(input, "PRINT") == 0) {
      printStudent(studentList);
    }
    else if (strcmp(input, "DELETE") == 0) {
      cout << "What is the ID of the student you'd like to delete?" << endl;
      int deleteInput;
      cin >> deleteInput;
      deleteStudent(studentList, deleteInput);
    }
    else if (strcmp(input, "QUIT") == 0) {
      cout << "Quitting." << endl;
      quit = true;
    }
  }
  return 0;
}

void addStudent(vector<Student*> &studentList) {
  Student* newStudent = new Student;
  cout << "What is the student's first name?" << endl;
  cin >> newStudent->firstName;
  cout << "What is the student's last name?" << endl;
  cin >> newStudent->lastName;
  cout << "What is the student's ID?" << endl;
  cin >> newStudent->studentID;
  cout << "What is the student's GPA?" << endl;
  cin >> newStudent->studentGPA;
  studentList.push_back(newStudent);
}

// source this later https://www.geeksforgeeks.org/different-ways-to-print-elements-of-vector/#5-print-vector-using-iterators
void printStudent(vector<Student*> studentList) {
  for (vector<Student*>::iterator it = studentList.begin();
       it != studentList.end(); ++it) {
    cout << (*it)->firstName << " " << (*it)->lastName << ", "
	 << (*it)->studentID << ", " << fixed << setprecision(2)
	 << (*it)->studentGPA << endl;
  }
}

void deleteStudent(vector<Student*> &studentList, int input) {
  
 for (vector<Student*>::iterator it = studentList.begin();
       it != studentList.end(); ++it) {
    if ((*it)->studentID == input) {
      cout << "deleting " << input << endl;
      delete *it;
      studentList.erase(it);
      return;
    }
  }
  cout << "That person doesn't exist..." << endl;
}












