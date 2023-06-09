#include <iostream>
#include <cmath>
#include <string>

using namespace std;

void game();
void message();

// Function Main
int main()
{
    cout << "Let’s Play a Game!" << endl;
    cout << "We are gonna play hangman" << endl;
    cout << "First we will have the first person choose a word and then the second person will guess" << endl
         << endl;
    game();
    return (0);
}

void game()
{
    int wordSize, count = 0, strikes = 0;
    char guess;
    bool win = false;

    cout << "How long is the word you want your partner to guess?" << endl;
    cin >> wordSize;

    char theWord[wordSize];
    bool match[wordSize];

    for (int i = 0; i < wordSize; i++)
    {
        theWord[i] = 'a';
        match[wordSize] = false;
    }

    cout << "What is the word you will make your opponent guess, letter by letter?" << endl;
    for (int i = 0; i < wordSize; i++)
    {
        cin >> theWord[i];
    }

    for (int i = 0; i < wordSize; i++)
    {
        cout << "__ ";
    }

    do
    {
        bool good = false;
        
        cout << "Please guess a letter. Remember 5 Strikes You are Out!!" << endl;
        cin >> guess;

        for (int i = 0; i < wordSize; i++)
        {
            if (theWord[i] == guess)
            {
                match[i] = true;
                count++;
                good = true;
            }
        }

        if (good == false)
        {
            strikes++;
            cout << "You now have " << strikes << " amount of strikes" << endl;
        }

        if (count == wordSize)
        {
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

void message()
{
    cout << "Congrats on guessing the correct word!";
    return;
}



