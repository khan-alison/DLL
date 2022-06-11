#include <iostream>
#include "Class.h"

int main() {
    Class c("ICE2019A", 0);
    const char separator    = ' ';

    int choice = 0;
    while(1)
    {

        cout<<"1. Add student" << endl;
        cout<<"2. Remove student" << endl;
        cout << "3. Search information " << endl;
        cout << "4. Update information"<<endl;
        cout << "5. Display information"<<endl;
        cout << "0. Exit" << endl;
        cout << "Enter your choice:"; cin >> choice;
        if(choice==1) {
            cout<<"Enter number of students in class " << c.getClassName()<<endl;
            long id;
            string name, y;
            double gpa;
            cout << "ID: "; cin >> id;
            cout << "Name: ";
            cin.ignore(256, '\n'); getline(cin, name);
            cout << "GPA: "; cin >> gpa;
            cout << "Year: "; cin >> y;
            Student s(id, name, gpa, y);

            c.add(s);
            cout << c.size() <<endl;

        }else if(choice == 2){
            long id;
            cout << "ID: "; cin >> id;
            c.remove(id);
        }else if(choice == 3){
            cout<<"Enter number of students in class " << c.getClassName()<<endl;
            long id;
            cout << "ID: "; cin >> id;
            Node* node = c.findStudent(id);
            if(node)
            {
                cout << left << setw(6) << setfill(separator)
                     << left << setw(10) << setfill(separator) << "ID"
                     << left << setw(25) << setfill(separator) << "NAME"
                     << left << setw(5) << setfill(separator) << "GPA"
                     << left << setw(5) << setfill(separator) << "Year"
                     << left << setw(10) << setfill(separator) << "Scholarship"
                     <<endl;
                cout << left << setw(6) << setfill(separator)
                     << left << setw(10) << setfill(separator) << node->getData().getId()
                     << left << setw(25) << setfill(separator) << node->getData().getName()
                     << left << setw(5) << setfill(separator) << node->getData().getGPA()
                     << left << setw(5) << setfill(separator) << node->getData().getYear()
                     << left << setw(10) << setfill(separator) << node->getData().getScholarship() <<endl;
            }
        }else if(choice == 4){
            long oldId;
            Student oldStd,newStd;
            cout<<"Enter id of students in class whose you wanna update information" <<endl;
            cin >> oldId;
                cout<<"Enter new information of students  whose you wanna update information" <<endl;
                long id;

                string name, y;
                double gpa;
                cout << "ID: "; cin >> id;
                cout << "Name: ";
                cin.ignore(256, '\n'); getline(cin, name);
                cout << "GPA: "; cin >> gpa;
                cout << "Year: "; cin >> y;
                Student s(id, name, gpa, y);

                c.updateStudent(oldId,s);

        }else if(choice == 5){
            c.displayAllStudent();

        }else if(choice == 5){
//            Node node = c.getFirst();
//            c.insertionSort(node);

        }
        else if(choice ==0){
            break;
        }
    }
    return 0;
    //s
}
