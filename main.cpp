#include <iomanip>
#include <string>
#include <vector>
#include <cstdlib>
#include <iostream>

using namespace std;
class Hangman {
    public:
        void addHead();
        void addBody();
        void addArmR();
        void addArmL();
        void addLegR();
        void addLegL();
    private:
      
};

class Player {
    public:
        void setLives(int userInput);
        int getLives();
        void setName(string userInput);
    private:
        int lives;
        string name;
};

void Player::setLives(int userInput) {
    lives = userInput;
    return;
}

int Player::getLives() {
    return lives;
}


int main()
{
    srand(static_cast<unsigned>(time(0)));
    char userChoice;
    string gamePrompt = { "a red fruit", "a orange fruit", "a purple fruit" };
    vector<string>gameStrings = { "apple", "orange", "grapes" };
    int min = 0, max = gameStrings.size();
    int compChoice = min + rand() % gameStrings.size();
    cout << compChoice << endl;

    cout << "******Welcome to HANGMAN******" << endl;
    cout << "***Please choose gamemode e = easy, h = hard: ";
    cin >> userChoice;
    if (userChoice == 'h') // hardMode
    {
        cout << "Player has choosen hard mode" << endl;
        cout << endl;
        cout << "Computer is generating prompt..." << endl;
        cout << "prompt is: ";
    }
    else if (userChoice == 'e') //easyMode
    {
        cout << "Player has choosen easy mode" << endl;
        cout << endl;
        cout << "Computer is generating prompt..." << endl;
        cout << "prompt is: ";
        cout << gamePrompt[compChoice] << endl;
        for(char ch : gameStrings[compChoice])
        {

        }
        
    }
    do{
    if (userChoice != 'e' || userChoice != 'h') {
        cout << "Invalid Option, please choose e or h. " << endl;
}
    while (userChoice != 'e' || userChoice != 'h');
return userChoice;
    
}