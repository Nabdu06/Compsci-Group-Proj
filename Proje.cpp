// Proje.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iomanip>
#include <string>
#include <vector>
#include <iostream>
#include <Windows.h>
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
    int randomNum;
    srand(time(0));
    randomNum = rand() % 5;
    return randomNum;
}


class Hangman {
public:
    void play() {
        cout << "Hello! What is your name? ";
        getline(cin, userName);
        Player1.setName(userName);

        cout << "Well " << Player1.getName() << ", welcome to..." << endl;

        cout << "*************************** HANGMAN ***************************" << endl << endl;
        cout << "Please choose a difficulty (h = hard   e = easy): ";
        cin >> userChoice;

        if (userChoice == 'h') {
            cout << "Player has chosen hard mode" << endl;
            cout << "Since you are on hard mode, no prompt for you kid" << endl;
        }
        else if (userChoice == 'e') {
            cout << "Player has chosen easy mode" << endl;
            cout << endl;
            cout << "Computer is generating prompt..." << endl;
            numOneFive = randomNum();
            rightGuess = EasyGameWords[numOneFive];
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
                for (int i = 0; i < rightGuess.length(); i++) {
                    cout << "_ ";
                }
                cout << endl << endl;

                cout << "Enter your first letter choice: ";
                cin >> userChoice;
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
                else if(counter == 1){
                    cout << "You got " << counter << " letter!" << endl;
                   
                }
                else {
                    cout << "You got " << counter << " letters!" << endl;
                  
                }
                if (guessedWord == rightGuess) {
                    cout << "Congratulations!!! You guessed the word! It was: " << rightGuess << endl;
                    break;
                }
               
            }
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
            hook = "   ---------------\n   |             |\n   |             |\n   O             |\n  \\|             |\n                 |\n                 |\n                 |\n                 |\n                 |\n     =========================";
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
private:
    string userName;
    int wrongAnswers = 0;
    int numOneFive;
    Player Player1;
    char userChoice;
    int counter = 0;
    string hook = "   ---------------\n   |             |\n   |             |\n                 |\n                 |\n                 |\n                 |\n                 |\n                 |\n                 |\n     =========================";
    string rightGuess;
    string guessedWord;
    string EasyGamePrompts[5] = { "another way to say charisma", "a perfect city", "free", "sad", "mental issue" };
    string EasyGameWords[5] = { "rizz", "utopia", "available", "down", "syndrome" };
};

int main()
{
    Hangman Game;
    Game.play();
}


