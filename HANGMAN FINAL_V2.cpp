// Proje.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iomanip>
#include <string>
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;


class Player {
public:
    string getName() {
        return name;
    }
    void setName(string userInput) {
        name = userInput;
        return;
    }
private:
    string name;
};

int randomNum() {
    srand(time(0));
    return static_cast<unsigned int>(rand() % 5);
}


class Hangman {
public:
    void play() {
        Player Player1;
        cout << "Hello! What is your name? ";
        getline(cin, userName);
        Player1.setName(userName);

        cout << "Well " << Player1.getName() << ", welcome to..." << endl;

        cout << "*************************** HANGMAN ***************************" << endl << endl;
        cout << "Please choose a difficulty (h = hard   e = easy): ";
        cin >> difficulty;


        if (difficulty == "h") {
            cout << "Player has chosen hard mode" << endl;
            cout << "Since you are on hard mode, no prompt for you kid" << endl;
            numOneFive = randomNum();
            rightGuess = HardGameWords[numOneFive];
            guessedWord = string(rightGuess.length(), '_');    // Creates a whole new string where each character is the _ character for each letter of the correct word
            while (wrongAnswers <= 6) {
                if (wrongAnswers == 6) {
                    checkSwitchHook();
                    cout << hook << endl << endl;
                    cout << "See what you did! You fail!" << endl;
                    break;
                }

                
                checkSwitchHook();
                cout << hook << endl << endl;

                cout << "        ";
                placeHolderWord();
                cout << endl << endl;


                cout << "Enter your first letter choice (in lowercase please): ";
                cin >> userChoice;
                if (!isalpha(userChoice)) {
                    cout << "Please enter a valid input, This counts as a wrong guess. DONT DO IT AGAIN!" << endl;
                }
                userChoice = tolower(userChoice);

                counter = 0;
                for (int i = 0; i < HardGameWords[numOneFive].length(); i++) {
                    if (userChoice == rightGuess[i]) {
                        counter++;
                        guessedWord[i] = rightGuess[i];
                    }
                }
                cout << endl;
                if (counter == 0) {
                    wrongAnswers++;
                }

                if (guessedWord == rightGuess) {
                    cout << "Hey you did it! You figured it out! The word was:  " << rightGuess << endl;
                    break;
                }


            }
        }
        else if (difficulty == "e") {
            cout << "Player has chosen easy mode" << endl;
            cout << endl;
            cout << "Computer is generating prompt..." << endl;
            numOneFive = randomNum();
            rightGuess = EasyGameWords[numOneFive];
            guessedWord = string(rightGuess.length(), '_');    // Creates a whole new string where each character is the _ character for each letter of the correct word
            while (wrongAnswers <= 6) {
                if (wrongAnswers == 6) {
                    checkSwitchHook();
                    cout << hook << endl << endl;
                    cout << "See what you did! You fail!" << endl;
                    break;
                }

                cout << "prompt is: ";
                cout << EasyGamePrompts[numOneFive] << endl << endl;
                checkSwitchHook();
                cout << hook << endl << endl;

                cout << "        ";
                placeHolderWord();
                cout << endl << endl;


                cout << "Enter your first letter choice (in lowercase please): ";
                cin >> userChoice;
                if (!isalpha(userChoice)) {
                    cout << "Please enter a valid input, This counts as a wrong guess. DONT DO IT AGAIN!" << endl;
                }
                userChoice = tolower(userChoice);

                counter = 0;
                for (int i = 0; i < EasyGameWords[numOneFive].length(); i++) {
                    if (userChoice == rightGuess[i]) {
                        counter++;
                        guessedWord[i] = rightGuess[i];
                    }
                }
                cout << endl;
                if (counter == 0) {
                    wrongAnswers++;
                }

                if (guessedWord == rightGuess) {
                    cout << "Hey you did it! You figured it out! The word was:  " << rightGuess << endl;
                    break;
                }


            }
        }
        else {
            cout << "Not a valid difficulty, STOP TRYING TO CHEAT OR HACK THE GAME PLEASE!" << endl;
        }



    }

    void checkSwitchHook() {
        if (wrongAnswers == 0) {
            hook = "   ---------------\n   |             |\n   |             |\n                 |\n                 |\n                 |\n                 |\n                 |\n                 |\n                 |\n     =========================";
        }
        if (wrongAnswers == 1) {
            hook = "   ---------------\n   |             |\n   |             |\n   O             |\n                 |\n                 |\n                 |\n                 |\n                 |\n                 |\n     =========================";
        }
        if (wrongAnswers == 2) {
            hook = "   ---------------\n   |             |\n   |             |\n   O             |\n   |             |\n                 |\n                 |\n                 |\n                 |\n                 |\n     =========================";
        }
        if (wrongAnswers == 3) {
            hook = "   ---------------\n   |             |\n   |             |\n   O             |\n  \\|             |\n                 |\n                 |\n                 |\n                 |\n                 |\n     =========================";           // This checks how many wrong answers they have and prints out the hook it corresponds to
        }
        if (wrongAnswers == 4) {
            hook = "   ---------------\n   |             |\n   |             |\n   O             |\n  \\|/            |\n                 |\n                 |\n                 |\n                 |\n                 |\n     =========================";
        }
        if (wrongAnswers == 5) {
            hook = "   ---------------\n   |             |\n   |             |\n   O             |\n  \\|/            |\n  /              |\n                 |\n                 |\n                 |\n                 |\n     =========================";
        }
        if (wrongAnswers == 6) {
            hook = "   ---------------\n   |             |\n   |             |\n   O             |\n  \\|/            |\n  / \\            |\n                 |\n                 |\n                 |\n                 |\n     =========================";
        }
    }

    void placeHolderWord() {
        for (char c : guessedWord) {                // So this prints out each character of the string guessWord which at first is just _ _ _ _ for as many letters are in the rightGuess string
            cout << c << ' ';
        }
        return;
    }
private:
    string userName;
    int wrongAnswers = 0;
    int numOneFive;
    Player Player1;
    string difficulty;
    char userChoice;
    int counter = 0;
    string hook = "   ---------------\n   |             |\n   |             |\n                 |\n                 |\n                 |\n                 |\n                 |\n                 |\n                 |\n     =========================";             // All the vars (we hate global variables so we threw them all into one big class)
    string rightGuess;
    string guessedWord;
    string EasyGamePrompts[5] = { "another way to say charisma", "an idealistic city or place", "im free", "slightly down or sad", "a condition characterized by a set of symptoms" };
    string EasyGameWords[5] = { "charm", "utopia", "available", "melancholy", "syndrome" };
    string HardGameWords[5] = { "antidisestablishmentarianism", "supercalifragilisticexpialidocious", "hippopotomonstrosesquippedaliophobia", "pneumonoultramicroscopicsilicovolcanoconiosis", "incomprehensibilities" };
};

int main()
{
    Hangman Game;
    Game.play();            // yep... this is our main (kinda underwhelming)

}


