#include <iostream>
#include <cmath>
#include <string>

using namespace std;

// Completed: 6-12-23
// Author: Maddawg9838

// Function Prototypes
void game();
void message();
void replay();

// Function Main explains the rules of the game
int main()
{
    cout << "Let’s Play a Game!" << endl;
    cout << "We are gonna play hangman" << endl;
    cout << "First we will have the first person choose a word and then the second person will guess" << endl
         << endl;
    game();
    replay();
    return (0);
}

// Function void game contains the selection of the word and guessing
void game()
{
    int wordSize = 0, count = 0, strikes = 0, matchCount = 0;
    char guess;
    bool win = false;
    
    // Allows the first partner to select a word and stores is into an array
    cout << "How long is the word you want your partner to guess?" << endl;
    cin >> wordSize;

    char theWord[wordSize];
    bool match[wordSize];
    
    for (int i = 0; i < wordSize; i++)
    {
        theWord[i] = 'a';
        match[i] = false;
    }

    cout << "What is the word you will make your opponent guess, letter by letter?" << endl;
    for (int i = 0; i < wordSize; i++)
    {
        cin >> theWord[i];
    }

    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    
    // Displays the amount of characters in the word
    for (int i = 0; i < wordSize; i++)
    {
        cout << "__ ";
    }
    
    // Loop for the partner to guess a letter unless they strike out or guess the word correctly
    do
    {
        bool good = false;
        
        cout << "Please guess a letter. Remember 5 Strikes You are Out!!" << endl;
        cin >> guess;

        for (int i = 0; i < wordSize; i++)
        {
            if (theWord[i] == guess)
            {
                if (match[i] == false)
                {
                    match[i] = true;
                    good = true;
                    matchCount++;
                }
            }
        }

        if (good == false)
        {
            strikes++;
            cout << "You now have " << strikes << " amount of strikes" << endl;
        }

        if (matchCount == wordSize)
        {
            win = true;
            message();
            return;
        }

        if (strikes == 5)
        {
            cout << "You have run out of attempts" << endl;
            return;
        }

        for (int i = 0; i < wordSize; i++)
        {
            if (match[i] == true)
            {
                cout << theWord[i] << " ";
            }
            else
            {
                cout << "___ ";
                ;
            }
        }

    } while (win == false);
    return;
}

// Function void message congradulates the person if they guess the word correctly 
void message()
{
    cout << "Congrats on guessing the correct word!";
    return;
}

// Function void replay allows the players to replay the entire program
void replay()
{
    string playAgain;
    
    cout << "Would y'all want to play again? Yes or No" << endl;
    cin >> playAgain;
    
    if (playAgain == "Yes")
    {
        main();
    }
    else if (playAgain == "No")
    {
        return();
    }
}


