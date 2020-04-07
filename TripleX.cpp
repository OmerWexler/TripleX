#include <iostream>
#include <ctime>

using namespace std;

bool playWithDifficulty(int Difficulty) {
    // Initiate game.
    int Code[3] = {};
    int CurrentCodeMember;
    int Guess[3] = {};
    
    int CodeMultiplication = 1;
    int CodeSum = 0;

    int GuessMultiplication = 1;
    int GuessSum = 0;

    // Greet user.
    cout << "Welcome to level " << Difficulty << ".\n";
    cout << "In order to break the Code you need to insert 3 numbers between " << Difficulty << "-" << Difficulty * 2 - 1 << " (including).\n";

    // Generate code.
    for (int i = 0; i < 3; i++) {
        CurrentCodeMember = rand() % Difficulty + Difficulty;

        Code[i] = CurrentCodeMember;
        CodeMultiplication *= CurrentCodeMember;
        CodeSum += CurrentCodeMember;
    }

    // Request guess.
    cout << "The Multiplication of the 3 numbers is " << CodeMultiplication << "\n";
    cout << "The sum of the 3 numbers is " << CodeSum << "\n\n";
    cout << "Have you figured out the Code yet (INSERT IT NOW - seperated by spaces) - ";
    
    // Take guess in.
    for (int i = 0; i < 3; i++) {
        cin >> Guess[i];

        GuessMultiplication *= Guess[i];
        GuessSum += Guess[i];
    }

    cout << "\n\n\n";
    // Finish game.
    return GuessMultiplication == CodeMultiplication && GuessSum == CodeSum;
}

int main() {
    int Difficulty = 1;
    int MaxDifficulty = 0;
    bool bUserWon = true;

    cout << "Insert max Difficulty: ";
    cin >> MaxDifficulty;

    // Reset RNG
    srand(time(NULL));

    while (Difficulty <= MaxDifficulty) {
        bUserWon = playWithDifficulty(Difficulty);

        if (bUserWon) {
            ++Difficulty;
        }

        cin.clear();
        cin.ignore();
    }

    cout << "Well done, you have beaten the game!" << endl;
    return 0;
}