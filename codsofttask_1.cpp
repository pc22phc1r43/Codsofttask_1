#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    // Seed the random number generator with the current time
    srand(static_cast<unsigned>(time(nullptr)));

    // Generate a random number between 1 and 100
    int randomNumber = rand() % 100 + 1;
    
    int userGuess;
    
   cout << "Welcome to the Number Guessing Game!" << endl;

    while (true) {
        cout << "Guess the number (between 1 and 100): ";
        cin >> userGuess;

        if (userGuess < 1 || userGuess > 100) {
            cout << "Please enter a number between 1 and 100." <<endl;
        } else if (userGuess < randomNumber) {
            cout << "Too low. Try again." << endl;
        } else if (userGuess > randomNumber) {
            cout << "Too high. Try again." <<endl;
        } else {
            cout << "Congratulations! You guessed the number." << endl;
            break; // Exit the loop when the correct number is guessed
        }
    }

    return 0;
}
