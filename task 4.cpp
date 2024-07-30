

#include <iostream>
#include <queue>
#include <vector>

class Patient {
public:
    int age;

    Patient(int age) : age(age) {}

    // Overloading the less-than operator for priority comparison
    bool operator<(const Patient& other) const {
        if (age >= 60 && other.age >= 60) return false;
        if (age >= 60) return false;
        if (other.age >= 60) return true;
        if (age > 50 && age <= 60 && other.age > 50 && other.age <= 60) return false;
        if (age > 50 && age <= 60) return false;
        if (other.age > 50 && other.age <= 60) return true;
        if (age > 40 && age <= 50 && other.age > 40 && other.age <= 50) return false;
        if (age > 40 && age <= 50) return false;
        if (other.age > 40 && other.age <= 50) return true;
        if (age > 30 && age <= 40 && other.age > 30 && other.age <= 40) return false;
        if (age > 30 && age <= 40) return false;
        if (other.age > 30 && other.age <= 40) return true;
        return age <= 30 && other.age > 30;
    }
};

class Hospital {
private:
    std::priority_queue<Patient> pq;

public:
    void addPatient(int age) {
        pq.push(Patient(age));
    }

    void deletePatient() {
        if (!pq.empty()) {
            pq.pop();
            std::cout << "Patients history deleted\n";
        } else {
            std::cout << "No patients to delete.\n";
        }
    }

    void displayPatients() {
        if (pq.empty()) {
            std::cout << "No patients to display.\n";
            return;
        }

        std::priority_queue<Patient> tempPQ = pq;
        std::cout << "The queue is:\n";

        while (!tempPQ.empty()) {
            Patient p = tempPQ.top();
            std::cout << p.age << "\n";
            tempPQ.pop();
        }
    }
};

int main() {
    Hospital hospital;
    int choice;

    std::cout << "Welcome to patient's information system\n";

    while (true) {
        std::cout << "Enter your choice:\n";
        std::cout << "1. Insert\n";
        std::cout << "2. Delete\n";
        std::cout << "3. Display\n";
        std::cout << "4. Exit\n";
        std::cout << "Choice: ";
        std::cin >> choice;

        if (choice == 1) {
            int age;
            std::cout << "Input the age value to be added in the queue: ";
            std::cin >> age;
            hospital.addPatient(age);
        } else if (choice == 2) {
            hospital.deletePatient();
        } else if (choice == 3) {
            std::cout << "The queue is:\n";
            hospital.displayPatients();
        } else if (choice == 4) {
            break;
        } else {
            std::cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}
