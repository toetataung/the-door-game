#include <cstdlib>
#include <ctime>
#include <iostream>
using namespace std;

int userInput;
int password;
int levelBlock =10;
int life = 4;
int level = 1;
void levelUp();
void welcome();
void welcome2();
void gameOver();

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
    cout << "The Door V.1 (By Toe Tat Aung)";
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
    }
}

int main()
{
    passwordMaker();
    welcome();
    for (int a= life; a>=1;) {
        cout << "\n\n";
        cin >> userInput;
        check();
        a = life;
    }
}
