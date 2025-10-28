#include <iostream>
#include <random>
#include <ctime>
#include <thread>
#include <chrono>
#include <windows.h>
#include <algorithm>
#include <stdlib.h>

using namespace std;

void sleepfor(int milliseconds){
   this_thread::sleep_for(chrono::milliseconds(milliseconds));
}

int number;
int balance;
string color;

int main(){
    // Spacing for better readability
    cout << "----------------------------------" << endl;
    cout << "      RUSSIAN ROULETTE GAME      " << endl;
    cout << endl;

    // Create random number generators
    random_device rd1;
    mt19937 gen1(rd1());
    uniform_int_distribution<> dis1(1, 36);

    random_device rd2;
    mt19937 gen2(rd2());
    uniform_int_distribution<> dis2(1, 36);

    // Simple, safe replay loop
    while (true) {
        // Losuj nowy numer dla każdej rundy
        number = dis1(gen1);
        
        // Selecting colors based on the random number
        if(number < 17){
            color = "RED";
        }
        else if(number < 34){
            color = "BLACK";
        }
        else{
            color = "GREEN";
        }

        // Player system - tylko za pierwszym razem
        if (balance == 0) {
            cout << "Hello Player! Welcome to Russian Roulette!" << endl;
            cout << "Enter how much balance you want to have: ";
            cin >> balance;
            if(balance == 0) {
                cout << "Lmao" << endl;
                exit(0);
            }
            cout << "Your balance is: " << balance << endl;
        }

        cout << "-----------------------------------" << endl;
        cout << "Let's start the game!" << endl;

        // Betting system
        cout << "Place your bet amount: ";
        int betamount;
        do {
            cin >> betamount;
            if(betamount > balance) {
                cout << "You cannot bet more than your balance. Please enter a valid bet amount: ";
            }
        } while(betamount > balance);
        
        cout << "You have placed a bet of: " << betamount << endl;
        
        cout << "Choose a color to bet on (Red/Black/Green): ";
        string playercolor;
        cin >> playercolor;
        transform(playercolor.begin(), playercolor.end(), playercolor.begin(), ::toupper);
        cout << "You have chosen to bet on: " << playercolor << endl;
        
        cout << "-----------------------------------" << endl;
        cout << "Press any key to continue and release the roulette" << endl;
        system("pause>nul");

        // Roulette animation
        cout << "The roulette is spinning..." << endl;
        for(int i = 0; i < 7; i++) {
            int RouleteChamberNum = dis2(gen2);
            if(RouleteChamberNum < 17) {
                sleepfor(500);
                cout << "Red " << RouleteChamberNum << endl;
            }
            else if(RouleteChamberNum < 34) {
                sleepfor(500);
                cout << "Black " << RouleteChamberNum << endl;
            }
            else {
                sleepfor(500);
                cout << "Green " << RouleteChamberNum << endl;
            }
        }
        
        sleepfor(1000);
        cout << "and finally the ball lands on..." << endl;
        sleepfor(2000);
        cout << "-----------------------------------" << endl;
        cout << endl;
        cout << "| " << color << " " << number << " |" << endl;
        cout << endl;
        cout << "-----------------------------------" << endl;

        // Determine the outcome of the bet
        if(playercolor == color) {
            cout << "BIG WINNNER!!!" << endl;
            if(color == "GREEN") {
                int winAmount = betamount * 14;
                balance += winAmount;
                cout << "JACKPOOOOT!! " << winAmount << "!" << endl;
            } else {
                balance += betamount;
                cout << "You won " << betamount << "!" << endl;
            }
            cout << "Your new balance is: " << balance << endl;
        }
        else {
            cout << "You lost the bet :(" << endl;
            balance -= betamount;
            cout << "Your new balance is: " << balance << endl;
        }

        // Game over check
        if(balance == 0) {
            cout << "You have run out of balance. Game over!" << endl;
            exit(0);
        }

        cout << "----------------------------------" << endl;
        cout << "Do you want to play again? (y/n): ";
        char playagain;
        cin >> playagain;

        if(playagain == 'n') {
            cout << "Thank you for playing! Goodbye!" << endl;
            break;
        }
    }

    return 0;
}