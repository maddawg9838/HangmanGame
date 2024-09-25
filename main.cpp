#include <iostream>
#include <string>

using namespace std;

// Function Prototypes
void game();
void message();
bool selectWord(string &theWord);


int main() {
    bool playAgain = true;
    while (playAgain) {
        game();
        cout << "Would you like to play againe? (Yes/No): ";
        string response;
        cin >> response;
        playAgain = (response == "Yes");
    }
    return 0;
}

// Function contains the selection of the word and the guessing
void game() {
    string theWord;
    if (!selectWord(theWord)) {
        cout << "Word selection failed." << endl;
        return;
    }
    
    int strikes = 0;
    int maxStrikes = 5;
    int matchCount = 0;
    string guessedLetters;
    
    // Display the word with spaces between the underscores
    cout << "Guess the word: ";
    for (size_t i = 0; i < theWord.length(); i++) {
        cout << "_ ";
    }
    cout << endl;
    
    // Game loop
    while (strikes < maxStrikes && matchCount < theWord.length()) {
        char guess;
        cout << "Please guess a letter: ";
        cin >> guess;
        guess = tolower(guess); // convert guess to lowercase
        
        // Check if the guessed letter is in the word
        bool found = false;
        for (size_t i = 0; i < theWord.length(); i++) {
            if (tolower(theWord[i]) == guess) {
                found = true;
                matchCount++;
            }
        }
        
        // Update guessed letters
        guessedLetters += guess;
        
        if (!found) {
            strikes++;
            cout << "Strike " << strikes << " out of " << maxStrikes << endl;
        }
        
        // Display current state of the guessed word
        for (char c : theWord) {
            if (guessedLetters.find(tolower(c)) != string::npos) {
                cout << c << ' ';
            } else {
                cout << '_' << ' ';
            }
        }
        
        cout << endl;
        
        // Check for win condition
        if (matchCount == theWord.length()) {
            message();
            return;
        }
    }
    
    cout << "You've run out of attempts. The word was: " << theWord << endl;
}

// Function to select the word to guess
bool selectWord (string &theWord) {
    cout << "Enter the word to guess: ";
    cin >> theWord;
    return !theWord.empty();
}

// Function that congratulates the player 
void message()
{
    cout << "Congrats on guessing the correct word!";
    return;
}
