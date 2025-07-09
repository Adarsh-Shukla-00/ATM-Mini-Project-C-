#include <iostream>
#include <string>

using namespace std;

class Atm {
private:
    long int account_no;
    string name;
    int pin;
    double balance;
    string mobile;

public:
    void setData(long int account_no_a, string name_a, int pin_a, double balance_a, string mobile_a) {
        account_no = account_no_a;
        name = name_a;
        pin = pin_a;
        balance = balance_a;
        mobile = mobile_a;
    }

    long int getAccountNo() {
        return account_no;
    }

    string getName() {
        return name;
    }

    int getPin() {
        return pin;
    }

    double getBalance() {
        return balance;
    }

    string getMobileNo() {
        return mobile;
    }

    void setMobile(string old_mob, string new_mob) {
        if (old_mob == mobile) {
            mobile = new_mob;
            cout << "Successfully Updated Mobile No" << endl;
        } else {
            cout << "Incorrect Old Mobile No" << endl;
        }
        system("pause"); // or use cin.get() if preferred
    }

    void cashWithdraw(int amount_a) {
        if (amount_a > 0 && amount_a < balance) {
            balance -= amount_a;
            cout << "Please collect your cash" << endl;
            cout << "Your current balance is: " << balance << endl;
        } else {
            cout << "Invalid input or insufficient balance" << endl;
        }
        system("pause"); // or use cin.get()
    }
};

int main() {
    int choice = 0, enterPin;
    long int enterAccountNo;
    Atm user1;

    user1.setData(101, "Adarsh", 1234, 35000.0, "9876543210");

    do {
        system("cls");
        cout << "******* Welcome to the ATM ********\n";
        cout << "Enter Account Number: ";
        cin >> enterAccountNo;
        cout << "Enter PIN: ";
        cin >> enterPin;

        if (enterAccountNo == user1.getAccountNo() && enterPin == user1.getPin()) {
            do {
                int amount = 0;
                string oldMobile, newMobile;

                system("cls");
                cout << "\n****** ATM Menu ******";
                cout << "\n1. Check Balance";
                cout << "\n2. Cash Withdraw";
                cout << "\n3. Show User Details";
                cout << "\n4. Update Mobile Number";
                cout << "\n5. Exit\n";
                cout << "Enter your choice: ";
                cin >> choice;

                switch (choice) {
                case 1:
                    cout << "Your balance is: " << user1.getBalance() << endl;
                    system("pause");
                    break;
                case 2:
                    cout << "Enter amount to withdraw: ";
                    cin >> amount;
                    user1.cashWithdraw(amount);
                    break;
                case 3:
                    cout << "\nUser Details:\n";
                    cout << "Account No: " << user1.getAccountNo() << endl;
                    cout << "Name: " << user1.getName() << endl;
                    cout << "Mobile No: " << user1.getMobileNo() << endl;
                    cout << "Balance: " << user1.getBalance() << endl;
                    system("pause");
                    break;
                case 4:
                    cout << "Enter old mobile number: ";
                    cin >> oldMobile;
                    cout << "Enter new mobile number: ";
                    cin >> newMobile;
                    user1.setMobile(oldMobile, newMobile);
                    break;
                case 5:
                    exit(0);
                default:
                    cout << "Please enter a valid choice" << endl;
                    system("pause");
                }

            } while (true);
        } else {
            cout << "Invalid account number or PIN" << endl;
            system("pause");
        }

    } while (true);

    return 0;
}
