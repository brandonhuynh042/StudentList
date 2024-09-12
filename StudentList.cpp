#include <iostream>
#include <cstring>
#include <vector>
#include <iterator>
#include <iomanip>

using namespace std;

/* This program stores a list of students that can be edited.
 * Brandon Huynh, last edited 9/12/2024 */

// Defining student struct
struct Student {
  char firstName[20];
  char lastName[20];
  int studentID;
  float studentGPA;
};
// forwarding functions
void addStudent(vector<Student*> &studentList);
void printStudent(vector<Student*> studentList);
void deleteStudent(vector<Student*> &studentList, int input);

int main() {
  // Initialiing list of student
  vector<Student*> studentList;
  bool quit = false;
  char input[7];
  // Main sequence
  while (quit == false) {
    // Take in user input, show commands
    cout << "You can: \'ADD\' \'PRINT\' \'DELETE\' \'QUIT\'" << endl;
    cin >> input;
    // See what they entered...
    if (strcmp(input, "ADD") == 0) {
      addStudent(studentList);             // go to proccess of adding student
    }
    else if (strcmp(input, "PRINT") == 0) {
      printStudent(studentList);           // go to process of printing student list
    }
    else if (strcmp(input, "DELETE") == 0) {
      // Get the ID that wants to be deleted
      cout << "What is the ID of the student you'd like to delete?" << endl;
      int deleteInput;
      cin >> deleteInput;
      deleteStudent(studentList, deleteInput); // go to process of deleting that student (if possible)
    }
    else if (strcmp(input, "QUIT") == 0) {
      cout << "Quitting." << endl;
      quit = true;
    }
    else {
      cout << "Please enter a valid input!";
    }
  }
  return 0;
}

// Adding a student
void addStudent(vector<Student*> &studentList) {
  Student* newStudent = new Student;                     // create student pointer for the new student 
  // Read in the different pieces of information, add it to the new student
  cout << "What is the student's first name?" << endl;
  cin >> newStudent->firstName;                         
  cout << "What is the student's last name?" << endl;
  cin >> newStudent->lastName;
  cout << "What is the student's ID?" << endl;
  cin >> newStudent->studentID;
  cout << "What is the student's GPA?" << endl;
  cin >> newStudent->studentGPA;
  // Add this new student to the end of the list
  studentList.push_back(newStudent);
}

/* Iterator part used from: https://www.geeksforgeeks.org/different-ways-to-print-elements-of-vector/#5-print-vector-using-iterators
 * The iterator is used to traverse through the vector and print the data of each student */
void printStudent(vector<Student*> studentList) {
  for (vector<Student*>::iterator it = studentList.begin();
       it != studentList.end(); ++it) {
    cout << (*it)->firstName << " " << (*it)->lastName << ", "
	 << (*it)->studentID << ", " << fixed << setprecision(2)
	 << (*it)->studentGPA << endl;
  }
}

// Deleting a student
void deleteStudent(vector<Student*> &studentList, int input) {
 for (vector<Student*>::iterator it = studentList.begin();
       it != studentList.end(); ++it) {
   // Check if the id of the student is the same as the want that wants to be deleted
    if ((*it)->studentID == input) {
      // If so, delete the student & the pointer to the student.
      delete *it;
      studentList.erase(it);
      return;
    }
  }
 // This will show if the wanted student isn't found...
  cout << "That person doesn't exist..." << endl;
}












