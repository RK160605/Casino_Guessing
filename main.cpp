#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

// Color codes
#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define BOLD    "\033[1m"

class Player {
public:
    string username;
    string password;
    int balance;

    Player() : balance(1000) {}

    void createAccount() {
        cout << CYAN << "Enter username: " << RESET;
        cin >> username;
        cout << CYAN << "Enter password: " << RESET;
        cin >> password;
        balance = 1000;

        ofstream out("players.txt", ios::app);
        out << username << " " << password << " " << balance << endl;
        out.close();

        cout << GREEN << "✅ Account created successfully!\n" << RESET;
    }

    bool login() {
        cout << CYAN << "Enter username: " << RESET;
        cin >> username;
        cout << CYAN << "Enter password: " << RESET;
        cin >> password;

        ifstream in("players.txt");
        string user, pass;
        int bal;
        while (in >> user >> pass >> bal) {
            if (user == username && pass == password) {
                balance = bal;
                in.close();
                cout << GREEN << "🔓 Login successful!\n" << RESET;
                return true;
            }
        }
        in.close();
        cout << RED << "❌ Invalid username or password.\n" << RESET;
        return false;
    }

    void updateBalance() {
        ifstream in("players.txt");
        ofstream temp("temp.txt");
        string user, pass;
        int bal;

        while (in >> user >> pass >> bal) {
            if (user == username) {
                temp << user << " " << pass << " " << balance << endl;
            } else {
                temp << user << " " << pass << " " << bal << endl;
            }
        }

        in.close();
        temp.close();
        remove("players.txt");
        rename("temp.txt", "players.txt");
    }

void playGame() {
    char choice;

    do {
        if (balance <= 0) {
            cout << RED << "❌ You don't have enough balance to play.\n" << RESET;
            cout << YELLOW << "💰 Please recharge your account to continue.\n" << RESET;
            return;  // Exit playGame()
        }

        int guess, bet;
        int number = rand() % 10 + 1;

        cout << YELLOW << "Current balance: " << balance << endl << RESET;
        cout << CYAN << "Enter your guess (1 to 10): " << RESET;
        cin >> guess;
        cout << CYAN << "Enter your bet amount: " << RESET;
        cin >> bet;

        if (bet > balance) {
            cout << RED << "❌ You don't have enough balance for this bet!\n" << RESET;
        } else if (guess == number) {
            cout << GREEN << "🎉 Congratulations! You guessed the correct number.\n" << RESET;
            balance += bet;
        } else {
            cout << RED << "😢 Wrong guess. The number was " << number << ".\n" << RESET;
            balance -= bet;
        }

        updateBalance();

        if (balance <= 0) {
            cout << RED << "\n❌ Your balance is now 0. You can no longer play.\n" << RESET;
            cout << CYAN << "Would you like to recharge your account? (y/n): " << RESET;
            char rechargeChoice;
            cin >> rechargeChoice;

            if (rechargeChoice == 'y' || rechargeChoice == 'Y') {
                int addAmount;
                cout << CYAN << "Enter amount to add to your balance: " << RESET;
                cin >> addAmount;
                balance += addAmount;
                updateBalance();
                cout << GREEN << "✅ Recharge successful! Your new balance is " << balance << "\n" << RESET;
            } else {
                cout << RED << "👋 Exiting game due to insufficient balance.\n" << RESET;
                return;
            }
        }

        cout << CYAN << "\nDo you want to play again? (y/n): " << RESET;
        cin >> choice;
    } while (choice == 'y' || choice == 'Y');
}

};

int main() {
    srand(time(0));
    Player p;
    int option;

    do {
        cout << BOLD << BLUE << "\n=== 🎰 Casino Guessing Game ===\n" << RESET;
        cout << YELLOW << "1. Create Account\n";
        cout << "2. Login\n";
        cout << "3. Exit\n" << RESET;
        cout << CYAN << "Choose an option: " << RESET;
        cin >> option;

        switch (option) {
            case 1:
                p.createAccount();
                break;
            case 2:
                if (p.login()) {
                    p.playGame();
                }
                break;
            case 3:
                cout << GREEN << "👋 Exiting the game. Goodbye!\n" << RESET;
                break;
            default:
                cout << RED << "❌ Invalid option!\n" << RESET;
        }
    } while (option != 3);

    return 0;
}


