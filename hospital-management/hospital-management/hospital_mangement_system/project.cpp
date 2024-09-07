#include<bits/stdc++.h>
using namespace std;

int pid = 1;
int did = 1;

class Patient {
public:
    string name;
    string gender;
    int age;
    int ID;
    Patient(string n, int a, string g) {
        ID = pid++;
        name = n;
        age = a;
        gender = g;
    }
};

class Doctor {
public:
    string name;
    string gender;
    int age;
    int ID;
    Doctor(string n, int a, string g) {
        ID = did++;
        name = n;
        age = a;
        gender = g;
    }
};

class Appointment {
public:
    int patientID;
    int doctorID;
    string Date;

    Appointment(int p, int d, string date) {
        Date = date;
        patientID = p;
        doctorID = d;
    }
};

vector<Patient> allPatients;
vector<Doctor> allDoctors;
vector<Appointment> allAppointments;

bool isPatientPresent(int id){
    bool ans = false;
    for(int i = 0;i<allPatients.size();i++){
        if (allPatients[i].ID == id)
        {
            ans = true;
        }
        
    }


    return ans;
}

bool isDoctorPresent(int id){
    bool ans = false;
    for(int i = 0;i<allDoctors.size();i++){
        if (allDoctors[i].ID == id)
        {
            ans = true;
        }
        
    }


    return ans;
}

void addPatient() {
    string n, g;
    int a;
    cout << "Give the Patient name: ";
    cin.ignore();
    getline(cin, n);
    cout << "Give the Patient age: ";
    cin >> a;
    cout << "Give the Patient gender: ";
    cin.ignore();
    getline(cin, g);

    Patient temp(n, a, g);
    allPatients.push_back(temp);
}

void addDoctor() {
    string n, g;
    int a;
    cout << "Give the Doctor name: ";
    cin.ignore();
    getline(cin, n);
    cout << "Give the Doctor age: ";
    cin >> a;
    cout << "Give the Doctor gender: ";
    cin.ignore();
    getline(cin, g);

    Doctor temp(n, a, g);
    allDoctors.push_back(temp);
}

void scheduleAppointments() {
    int patientID;
    int doctorID;
    string Date;

    cout << "Give the Patient ID: ";
    cin >> patientID;
    cout << "Give the Doctor ID: ";
    cin >> doctorID;
    cout << "Give the Date in DD-MM-YYYY: ";
    cin.ignore();
    getline(cin, Date);


    if (isPatientPresent(patientID) == false || isDoctorPresent(doctorID) == false)
    {
        cout<<"Invalid Patient ID or Doctor ID"<<endl;
        cout<<"Appointment schedule uncessfull"<<endl;

        return ;
    }
    
    Appointment temp(patientID, doctorID, Date);
    allAppointments.push_back(temp);
}

void viewPatients() {
    for (int i = 0; i < allPatients.size(); i++) {
        cout << "Patient Name: " << allPatients[i].name << endl;
    }
    cout << endl;
}

void viewDoctors() {
    for (int i = 0; i < allDoctors.size(); i++) {
        cout << "Doctor Name: " << allDoctors[i].name << endl;
    }
    cout << endl;
}

void viewAppointments() {
    for (int i = 0; i < allAppointments.size(); i++) {
        cout << "Patient ID: " << allAppointments[i].patientID << " has appointment with Doctor ID: " << allAppointments[i].doctorID
             << " on DATE " << allAppointments[i].Date << endl;
    }
    cout << endl;
}

int main() {
    int choice;
 
    do {
        cout << "1. Add Patient" << endl;
        cout << "2. Add Doctor" << endl;
        cout << "3. Schedule Appointment" << endl;
        cout << "4. View Patients" << endl;
        cout << "5. View Doctors" << endl;
        cout << "6. View Appointments" << endl;
        cout << "0. Exit" << endl;
        cout << "Give your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addPatient();
                break;
            case 2:
                addDoctor();
                break;
            case 3:
                scheduleAppointments();
                break;
            case 4:
                viewPatients();
                break;
            case 5:
                viewDoctors();
                break;
            case 6:
                viewAppointments();
                break;
            case 0:
                continue;
                break;
            default:
                cout << "Invalid Choice" << endl;
                cout << endl;
        }
    } while (choice != 0);

   
}
