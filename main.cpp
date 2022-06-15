#include <iostream>
#include "Transportations.h"

int main() {
    Transportations c("THEHELL", 0);
    const char separator    = ' ';

    int choice = 0;
    while(1)
    {
        cout<<"1. Add vehicle" << endl;
        cout<<"2. Remove vehicle" << endl;
        cout << "3. Search information " << endl;
        cout << "4. Update information"<<endl;
        cout << "5. Display information"<<endl;
        cout << "0. Exit" << endl;
        cout << "Enter your choice:"; cin >> choice;
        if(choice==1) {
            cout << "Enter number of students in class " << c.getRouteName() << endl;
            long id;
            string name, type, producer;
            double speed;
            cout << "ID: "; cin >> id;
            cout << "Name: ";
            cin.ignore(256, '\n'); getline(cin, name);
            cout << "Type: "; cin >> type;
            cout << "Speed: "; cin >> speed;
            cout << "Producer: "; cin >> producer;
            Vehicle s(id,type, name, speed, producer);
            c.add(s);
            cout << c.size() <<endl;

        }else if(choice == 2){
            long id;
            cout << "ID: "; cin >> id;
            c.remove(id);
        }else if(choice == 3){
            cout << "Enter number of students in class " << c.getRouteName() << endl;
            long id;
            cout << "ID: "; cin >> id;
            Node* node = c.findVehicle(id);
            if(node)
            {
                cout << left << setw(6) << setfill(separator)
                     << left << setw(10) << setfill(separator) << "ID"
                     << left << setw(25) << setfill(separator) << "NAME"
                        << left << setw(25) << setfill(separator) << "TYPE"
                     << left << setw(20) << setfill(separator) << "Speed"
                     << left << setw(25) << setfill(separator) << "Producer"
                     <<endl;
                cout << left << setw(6) << setfill(separator)
                     << left << setw(10) << setfill(separator) << node->getData().getId()
                     << left << setw(25) << setfill(separator) << node->getData().getName()
                     << left << setw(25) << setfill(separator) << node->getData().getType()
                     << left << setw(20) << setfill(separator) << node->getData().getSpeed()
                     << left << setw(25) << setfill(separator) << node->getData().getProducer()<<endl;
            }
        }else if(choice == 4){
            long oldId;
            Vehicle oldStd,newStd;
            cout<<"Enter id of vehicle in class whose you wanna update information" <<endl;
            cin >> oldId;
                cout<<"Enter new information of vehicle  whose you wanna update information" <<endl;
                long id;
                string name,type, producer;
                double speed;
                cout << "ID: "; cin >> id;
                cout << "Name: ";
                cin.ignore(256, '\n'); getline(cin, name);
                cout << "Type: ";cin >>type;
                cout << "Speed: "; cin >> speed;
                cout << "Producer: "; cin >> producer;
                Vehicle s(id, type,name,  speed, producer);

            c.updateVehicleInfo(oldId, s);

        }else if(choice == 5){
            c.displayAllVehicle();

        }else if(choice == 6){

        }
        else if(choice ==0){
            break;
        }
    }
    return 0;
}
