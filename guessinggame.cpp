#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    srand(time(0));
    int number_to_guess = rand() % 100 + 1;
    int user_guess = 0;

    cout << "Welcome to the Guess the Number game!" << endl;
    cout << "I have selected a number between 1 and 100." << endl;

    while (user_guess != number_to_guess) {
        cout << "Enter your guess: ";
        cin >> user_guess;

        if (user_guess > number_to_guess) {
            cout << "Your guess is too high. Try again." << endl;
        } else if (user_guess < number_to_guess) {
            cout << "Your guess is too low. Try again." << endl;
        } else {
            cout << "Congratulations! You guessed the correct number!" << endl;
        }
    }

    return 0;
}
