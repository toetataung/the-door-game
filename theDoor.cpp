#include <cstdlib>
#include <ctime>
#include <iostream>
#include <fstream >
#include <string>
using namespace std;

int userInput;
int password;
int levelBlock =10;
int life = 4;
int level = 1;
string myName;
std::string myScore;
void levelUp();
void welcome();
void welcome2();
void gameOver();
void highScoreUpdate();

void passwordMaker() {
    srand(time(0));
    password = rand()% levelBlock + 1;
}


void check() {
    if (userInput>password) {
    life -= 1;
    cout << "\nYour Number is Greater Than Password. Your chances left : " <<life ;
    gameOver();	    
    } else if (userInput<password){
    life -= 1;
    cout << "\nYour Number is Lower Than Password. Your chances left : " <<life;
    gameOver();	    
    } else if (userInput==password){
    levelUp();
    }
}


void levelUp(){
    passwordMaker();
    levelBlock += 5;
    level += 1;
    life += 3;
    welcome2();

}

void welcome(){
    if (level==1) {
    cout << "The Door V.1 (C By Toe Tat Aung)";
    cout << "\n\nHigh Score Player : "<<myName<< "| Door No : " << myScore << "\n";
    cout << "\nAre u escape from me ? The Door had been locked";
    cout << "\nPassword is Between form 1 - 10, You have 4 chance";
    cout << "\nDo or Die? \n";
    cout << "\nEnter Your Number : ";
    }
}

void welcome2(){
    cout << "\nPassword is correct, Access Granted!";
    cout << "\n\nCongratulation !! You will get +3 chances";
    cout << "\n\nWelcome to the next Door No : " <<level;
    cout << "\nPassword is Between form 1 - "<<levelBlock ;
    cout << "\nYour Total Chance Left : " << life;
    cout << "\nEnter Your Number :  ";
}

void gameOver(){
    if (life == 0) {
        cout << "\n\nYou Had Been Killed at Door Number : " <<level<<"\n\n"<<"Password is "<< password;
        if (level>=std::stoi(myScore)){
        cout << "\n\nCongratulation !, You are highest Score player in game. So , We'll update Champion with You, \n\nPlease Enter Your Name :";
        highScoreUpdate();
    }
    	}
}

void highScoreUpdate(){
    string inputName;
    cin >> inputName;
	ofstream fout;
	fout.open("player.txt");
    fout<<inputName;
	fout.close();

	fout.open("score.txt");
    fout<<level;
	fout.close();
}

int main()
{
    ifstream MyReadFile("player.txt");
    getline (MyReadFile, myName);
    ifstream MyScoreFile("score.txt");
    getline (MyScoreFile, myScore);

    passwordMaker();

    welcome();
    for (int a= life; a>=1;) {
        cout << "\n\n";
        cin >> userInput;
        check();
        a = life;
    }
}
