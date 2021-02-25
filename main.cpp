#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <cstdlib>
#include <sstream>
#include <vector>

using namespace std;

string studentList[100], studentLogList[100], bookLogList[100];
string bookList[100] = {"English", "Math", "Science", "Technology", "Entrepreneurship", "Programming"};

int bookListSize, studentListSize, studentLogListSize, bookLogListSize;
char mainInputNumber, libraryInputNumber, studentInputNumber;
string studentUpdateNumber, studentDeleteNumber, borrowBookNumber, borrowStudentNumber, returnBookNumber, returnLogNumber;
string bookUpdateNumber, bookDeleteNumber;

void display_books();
void display_student_list();
void display_logs();
int getSizeOfArray(string arr[]);
void library();
void student();

/* Main Function */
int main()
{
        cout << "\n\n";
        while(mainInputNumber != '3'){
        libraryInputNumber = '0';
        studentInputNumber = '0';
        cout <<"\n\n\t\t\tWelcome to Student Library\n";
        cout <<"\n\n\t\t\tInstruction:\n \t\t\tAdd a student first in the Student Record.\n";
        cout <<"\t\t\tIf you already have a student in student record you can access the library.\n";
        cout <<"\n\n\t\t\tMain Menu: \n";
        cout <<"\t\t\t(1) Student Record\n";
        cout <<"\t\t\t(2) Library \n";
        cout <<"\t\t\t(3) Exit\n\n";
        cout <<"\t\t\tPress: ";
        mainInputNumber = getch();
        cout <<"\t\t\t\n\n";

        if(mainInputNumber == '1'){
            system("cls");
            student();
        }
        else if(mainInputNumber == '2'){
            system("cls");
            studentListSize = getSizeOfArray(studentList);
            if(studentListSize <= 0){
                system("cls");
                cout << "\n\nNotice: Please add student in the student record first";
            }
            else{
                library();
            }
        }
        else if(mainInputNumber == '3'){
            system("cls");
            cout << "\n\n";
            cout <<"\t\t\t\nThankyou for using Student Library Program!\n\n";
        }
        else{
            system("cls");
            cout <<"\t\t\t\nInvalid Key\n";
        }

    };

    return 0;
}
/* End of Main Function */


// Student Function
void student(){

    cout << "\n\n";
    while(studentInputNumber != '5'){
        cout <<"\t\t\tStudent Record\n\n";
        cout <<"\t\t\t(1) Add Student\n";
        cout <<"\t\t\t(2) Update Student\n";
        cout <<"\t\t\t(3) Remove Student\n";
        cout <<"\t\t\t(4) List of Students Name\n";
        cout <<"\t\t\t(5) Back\n";
        cout <<"\t\t\t(6) Exit\n\n";

        cout <<"\t\t\tPress: ";
        studentInputNumber = getch();
        cout <<"\t\t\t\n\n";


        // Adding Student
        if(studentInputNumber == '1'){
            system("cls");
            string studentName;

            studentListSize = getSizeOfArray(studentList);
            cout << "\t\t\t\n\nEnter Student Name: ";
            getline(cin, studentList[studentListSize]);
            system("cls");
            cout << "\t\t\t\n\n\nNotice: Student successfully added to student list\n\n\n";
            studentListSize = getSizeOfArray(studentList);
        }

        // Updating Student
        else if(studentInputNumber == '2'){
                system("cls");
                string inputUpdateNumber;
                studentListSize = getSizeOfArray(studentList);
                if(studentListSize <= 0){
                    cout << "\n\nNotice: Student Record is empty!\n\n";
                }
                else{
                    cout << "\t\t\t\n\nUpdating Student\n\n";
                    studentUpdateNumber = 1;
                    display_student_list();
                    cout << "\t\t\t\n\nEnter Student Number: ";
                    getline(cin, inputUpdateNumber);

                    stringstream studentNumber(inputUpdateNumber);
                    int studentUpdateNumber;
                    studentNumber >> studentUpdateNumber;

                    string studentName;

                    if(studentUpdateNumber <= 0 || studentUpdateNumber > studentListSize){
                        system("cls");
                        cout << "\n\nNotice: Invalid Key\n\n";
                    }
                    else{
                        cout << "\t\t\t\n\nEnter new name: ";
                        getline(cin, studentName);
                        studentList[studentUpdateNumber - 1] = studentName;
                        system("cls");
                    }
                }
        }

        // Deleting Student
        else if(studentInputNumber == '3'){
            system("cls");
            string inputDeleteNumber;
            studentDeleteNumber = 1;
            studentListSize = getSizeOfArray(studentList);

            if(studentListSize <= 0){
                cout << "\n\nNotice: Student Record is empty!\n\n";
            }
            else{
                cout << "Deleting Student Record\n\n";
                display_student_list();
                cout << "Enter Student Number: ";
                getline(cin, inputDeleteNumber);

                stringstream studentNumber(inputDeleteNumber);
                int studentDeleteNumber;
                studentNumber >> studentDeleteNumber;

                if(studentDeleteNumber <= 0 || studentDeleteNumber > studentListSize){
                        system("cls");
                        cout << "\n\nNotice: Invalid Key\n\n";
                }
                else{
                    int arrSize = sizeof(studentList)/sizeof(studentList[0]);
                    for (int i = studentDeleteNumber; i < arrSize; ++i){
                        studentList[i - 1] = studentList[i];
                    }
                    system("cls");
                    cout << "Notice: Student record successfully deleted!\n\n";
                }
            }
        }

        // Displaying Student
        else if(studentInputNumber == '4'){
            system("cls");
            studentListSize = getSizeOfArray(studentList);
            display_student_list();
        }

        // Return to main
        else if(studentInputNumber == '5'){
            system("cls");
            return;
        }

        // Terminate Program
        else if(studentInputNumber == '6'){
            system("cls");
            cout <<"\n\n";
            cout <<"\t\t\tThankyou for using Student Library Program!\n\n";
            exit(0);
        }

        // If user inputted invalid character
        else{
            system("cls");
            cout <<"\t\t\tWarning: Invalid Input\n\n";
        }
    };
}

/* Library Function */
void library()
{
    cout << "\n\n";
    while(libraryInputNumber != '8'){
        cout <<"\t\t\tLibrary\n\n";
        cout <<"\t\t\t(1) Borrow Book\n";
        cout <<"\t\t\t(2) Return Book\n";
        cout <<"\t\t\t(3) Logs of Borrowed Books\n";
        cout <<"\t\t\t(4) List of Available Books\n";
        cout <<"\t\t\t(5) Add New Book\n";
        cout <<"\t\t\t(6) Update Book\n";
        cout <<"\t\t\t(7) Remove Book\n";
        cout <<"\t\t\t(8) Back\n";
        cout <<"\t\t\t(9) Exit\n\n";

        cout <<"\t\t\tPress: ";
        libraryInputNumber = getch();
        cout <<"\t\t\t\n\n";

        // Borrowing Book
        if(libraryInputNumber == '1'){
            system("cls");

            studentLogListSize = getSizeOfArray(studentLogList);
            bookLogListSize = getSizeOfArray(bookLogList);
            bookListSize = getSizeOfArray(bookList);
            studentListSize = getSizeOfArray(studentList);

            display_books();
            cout << "\t\t\t\n\nEnter book number: ";
            getline(cin, borrowBookNumber);

            stringstream inputBorrowBookNumber(borrowBookNumber);
            int bookBorrowNumber;
            inputBorrowBookNumber >> bookBorrowNumber;

            if(bookBorrowNumber <= 0 || bookBorrowNumber > bookListSize){
                        system("cls");
                        cout << "\n\nNotice: Invalid Key\n\n";
            }
            else{
                if(studentListSize <= 0){
                    display_student_list();
                }
                else{
                    display_student_list();
                    cout <<"\t\t\t\n\nEnter student number: ";
                    getline(cin, borrowStudentNumber);

                    // Converting String to Int
                    stringstream inputBorrowStudentNumber(borrowStudentNumber);
                    int studentBorrowNumber;
                    inputBorrowStudentNumber >> studentBorrowNumber;

                    if(studentBorrowNumber <= 0 || studentBorrowNumber > studentListSize){
                                system("cls");
                                cout << "\n\nNotice: Invalid Key\n\n";
                    }
                    else{
                        // Inserting to array log lists
                        studentLogList[studentLogListSize] = studentList[studentBorrowNumber - 1];
                        bookLogList[bookLogListSize] = bookList[bookBorrowNumber - 1];

                        // Deleting a book to book records
                        int arrSize = sizeof(bookList)/sizeof(bookList[0]);
                        for (int i = bookBorrowNumber; i < arrSize; ++i){
                            bookList[i - 1] = bookList[i];
                        }

                        system("cls");
                        cout << "\t\t\t\n\n\nNotice: Successfully borrowed a book\n\n\n";
                    }
                }


            }

        }

        // Return Book
        else if(libraryInputNumber == '2'){
            display_logs();
            if(bookLogListSize <= 0){

            }
            else{
                cout << "\t\t\t\n\nEnter Log Number: ";
                getline(cin, returnLogNumber);
                // Converting string to int
                stringstream inputReturnLogNumber(returnLogNumber);
                int intReturnLogNumber;
                inputReturnLogNumber >> intReturnLogNumber;

                if(intReturnLogNumber <= 0 || intReturnLogNumber > bookLogListSize){
                    system("cls");
                    cout << "\n\nNotice: Invalid Key\n\n";
                }
                else{
                    // Returning book to book shelf
                    bookListSize = getSizeOfArray(bookList);
                    bookList[bookListSize] = bookLogList[intReturnLogNumber - 1];

                    int arrSize = sizeof(bookLogList)/sizeof(bookLogList[0]);

                    // Deleting Logs
                    for (int i = intReturnLogNumber; i < arrSize; ++i){
                        studentLogList[i - 1] = studentLogList[i];
                        bookLogList[i - 1] = bookLogList[i];
                    }

                    // Updating Size of Arrays
                    bookLogListSize = getSizeOfArray(bookLogList);
                    studentLogListSize = getSizeOfArray(studentLogList);

                    cout << "Notice: Successfully returned a book!\n\n";
                }
            }

        }

        // Log Book
        else if(libraryInputNumber == '3'){
            display_logs();
        }

        // List of Available Books
        else if(libraryInputNumber == '4'){

            system("cls");

            // Getting Size
            studentLogListSize = getSizeOfArray(studentLogList);
            bookLogListSize = getSizeOfArray(bookLogList);

            display_books();
        }

        // Adding Book
        else if(libraryInputNumber == '5'){
            system("cls");

            bookListSize = getSizeOfArray(bookList);
            cout << "\t\t\t\n\nEnter Book Name: ";
            getline (cin, bookList[bookListSize]) ;
            system("cls");
            cout << "\t\t\t\n\n\nNotice: Book successfully added to book list\n\n\n";
            bookListSize = getSizeOfArray(bookList);
        }

        // Updating Books
        else if(libraryInputNumber == '6'){
                system("cls");
                string inputUpdateNumber;
                bookListSize = getSizeOfArray(bookList);
                if(bookListSize <= 0){
                    cout << "\n\nNotice: Book Record is empty!\n\n";
                }
                else{
                    cout << "\t\t\t\n\nUpdating Book\n\n";
                    bookUpdateNumber = 1;
                    display_books();
                    cout << "\t\t\t\n\nEnter Book Number: ";
                    getline(cin, inputUpdateNumber);

                    stringstream bookNumber(inputUpdateNumber);
                    int bookUpdateNumber;
                    bookNumber >> bookUpdateNumber;

                    string bookName;

                    if(bookUpdateNumber <= 0 || bookUpdateNumber > bookListSize){
                        system("cls");
                        cout << "\n\nNotice: Invalid Key\n\n";
                    }
                    else{
                        cout << "\t\t\t\n\nEnter new book name: ";
                        getline(cin, bookName);
                        bookList[bookUpdateNumber - 1] = bookName;
                        system("cls");
                    }
                }
        }

        // Deleting Book
        else if(libraryInputNumber == '7'){
            system("cls");
            string inputDeleteNumber;
            bookDeleteNumber = 1;
            bookListSize = getSizeOfArray(bookList);

            if(bookListSize <= 0){
                cout << "\n\nNotice: Book Record is empty!\n\n";
            }
            else{
                cout << "Deleting Book Record\n\n";
                display_books();
                cout << "Enter Book Number: ";
                getline(cin, inputDeleteNumber);

                stringstream bookNumber(inputDeleteNumber);
                int bookDeleteNumber;
                bookNumber >> bookDeleteNumber;

                if(bookDeleteNumber <= 0 || bookDeleteNumber > bookListSize){
                        system("cls");
                        cout << "\n\nNotice: Invalid Key\n\n";
                }
                else{
                    int arrSize = sizeof(bookList)/sizeof(bookList[0]);
                    for (int i = bookDeleteNumber; i < arrSize; ++i){
                        bookList[i - 1] = bookList[i];
                    }
                    system("cls");
                    cout << "Notice: Book record successfully deleted!\n\n";
                }
            }
        }

        //
        else if(libraryInputNumber == '8'){
            system("cls");
            return;
        }
        else if(libraryInputNumber == '9'){
            system("cls");
            cout << "\n\n";
            cout <<"\t\t\tThankyou for using Student Library Program!\n\n";
            exit(0);
        }
        else{
            system("cls");
            cout <<"\t\t\tWarning: Invalid Input\n\n";
        }

    };

}
/* End of Library Function */

// function that display student list or the array list
void display_student_list(){
    system("cls");
    if(studentListSize <= 0){
        cout << "\n\nNotice: Student Record is empty!\n\n";
    }
    else{
        cout << "\t\t\tList of Students: \n";
        for (int i = 0; i < studentListSize; ++i) {
            cout << "\t\t\t" <<  i+1 << ". " << studentList[i] << "\n";
        }
        cout << "\n";
    }

}

void display_books(){
    system("cls");
    bookListSize = getSizeOfArray(bookList);
    if(bookListSize <= 0){
        cout << "\n\nNotice: Books shelf is empty!\n\n";
    }
    else{
        cout << "\t\t\tList of Books Available: \n";
        for (int i = 0; i < bookListSize; ++i) {
            cout << "\t\t\t" <<  i+1 << ". " << bookList[i] << "\n";
        }
        cout << "\n";
    }

}

void display_logs(){
    system("cls");
    bookLogListSize = getSizeOfArray(bookLogList);
    if(bookLogListSize <= 0){
        cout << "\n\n\nNotice: Book Logs is empty! \n\n\n";
    }
    else{
        cout << "\t\t\tList of Books Borrowed: \n\n";
        for (int i=0; i < bookLogListSize; ++i){
            cout << "\t\t\t" << i+1 << ". Student Name: " << studentLogList[i] << " - Borrowed Book: " << bookLogList[i] << "\n\n";
        }
    }
}


// function that get the size of array
int getSizeOfArray(string arr[])
{
    int count=0;
    for(int i=0;i<100;i++)
    {
        if(arr[i]!="")
            count++;
    }

    return count;
}



