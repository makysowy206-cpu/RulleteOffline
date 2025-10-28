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
   this_thread::sleep_for(chrono::milliseconds(milliseconds));  // Sleep function to pause execution for a specified time 
}


    


int number;
int balance;
string color;


int main(){
        // Spacing for better readability
cout<< "----------------------------------"<< endl;
cout<< "      RUSSIAN ROULETTE GAME      "<< endl;
cout<< endl;


// Create a random number generator
random_device rd1;
mt19937 gen1(rd1());
uniform_int_distribution<> dis1(1, 36);
number = dis1(gen1);

random_device rd2;
    mt19937 gen2(rd2());
    uniform_int_distribution<> dis2(1, 36);
    

// Selecting colors based on the random number
if(number <17){
    color = "RED";
}
else if(number < 34){
    color = "BLACK";
}
else{
    color = "GREEN";
}

//cout<<" "<< number << endl;
// Player system

cout<<"Hello Player! Welcome to Russian Roulette!"<<endl;
cout<< "enter how much balance you want to have: ";
cin>> balance;
if(balance ==0)
{
cout<< "Lmao" << endl;
exit(0);
}
cout<< "do you want to confirm[y/n]: ";
char confirm;
cin>> confirm;
if(confirm == 'n'){
    cout<< "enter how much balance you want to have: ";  //balance confirmation  
    cin>> balance;
    if(balance == 0){
        cout<< "Exiting the game..." << endl;
        
        for(int i=5; i>0; i--){
            cout<< i << "..." << endl;      // Countdown before exit
            sleepfor(1000);
        }
        cout<< "Goodbye!" << endl;
        return 0;
    }
}
cout<< "Your balance is: " << balance << endl;
cout<<"-----------------------------------"<< endl;
cout<<"let's start the game!"<< endl;

cout<< "place your bet amount: ";
int betamount;
do{
    cin>>betamount;
    if(betamount > balance){
        cout<< "You cannot bet more than your balance. Please enter a valid bet amount: ";
    }
}while(betamount > balance);
cout<< "You have placed a bet of: " << betamount << endl;
cout<< "Choose a color to bet on (Red/Black/Green): ";
string playercolor;
cin>> playercolor;
cout<< "You have chosen to bet on: " << playercolor << endl;
cout<<" do you want to confirm[y/n]: ";
char confirmcolor;
cin>> confirmcolor;
if(confirmcolor == 'n'){
    cout<< "Choose a color to bet on (Red/Black/Green): ";  //color confirmation  
    cin>> playercolor;
}
transform(playercolor.begin(), playercolor.end(), playercolor.begin(), ::toupper); // Convert to uppercase for consistency
cout<<"You have chosen to bet on: " << playercolor << endl;
cout<<"-----------------------------------"<< endl;
cout<<"press any key to continue and release the roulett"<< endl;
system("pause>nul");

cout<<"The roulette is spinning..."<< endl;
for(int i=0;i<7;i++){
    int RouleteChamberNum =dis2(gen2);
    if(RouleteChamberNum <17){
        sleepfor(500);
        cout<< "Red " << RouleteChamberNum << endl;
        
    }
    else if(RouleteChamberNum <34){
        sleepfor(500);
        cout<< "Black " << RouleteChamberNum << endl;
    }
    else{
        sleepfor(500);
        cout<< "Green " << RouleteChamberNum << endl;
    }
}
sleepfor(1000);
cout<<"and finally the ball lands on..."<< endl;
sleepfor(2000);
cout<<"-----------------------------------"<< endl;
cout<<endl;
cout<<"|" <<color << " " << number <<"|" << endl;
cout<<endl;
cout<<"-----------------------------------"<< endl;


// Determine the outcome of the bet
if((playercolor == color)){
    cout<<"BIG WINNNER!!!"<< endl;
    if(color == "RED"){
        balance += betamount;
        cout<< "You won " << betamount << "!" << endl;
        cout<< "Your new balance is: " << balance << endl;
    }
    else if(color == "BLACK"){
        balance += betamount;
        cout<< "You won " << betamount << "!" << endl;
        cout<< "Your new balance is: " << balance << endl;
    }
    else{
        balance += betamount * 14;
        cout<< "JACKPOOOOT!! " << betamount * 14 << "!" << endl;
        cout<< "Your new balance is: " << balance << endl;
    }
}
else{
    cout<<"You lost the bet :("<< endl;
    balance -= betamount;
    cout<< "Your new balance is: " << balance << endl;
    if(balance ==0){
        if(balance == 0){
    cout << "You have run out of balance. Game over!" << endl;
    cout << "Computer will shutdown in 3 seconds..." << endl;
    
    for(int i = 3; i > 0; i--){
        cout << i << "..." << endl;
        sleepfor(1000);
    }
    
    // Wyłączenie komputera
    system("shutdown /s /t 1");
    // Lub dla Linux: system("shutdown -h now");
    
    exit(0);
}
    }
    
}

cout<< "----------------------------------"<< endl;

// Simple, safe replay loop that avoids mismatched braces or stray characters
while (true) {
    cout<< "do you want to play again? (y/n): ";
    char playagain;
    cin>> playagain;

    if (playagain == 'n') {
        cout<< "Thank you for playing! Goodbye!" << endl;
        break;
    }

    if (balance <= 0) {
        cout<< "You have run out of balance. Game over!" << endl;
        break;
    }

    // Ask for a new bet for the next round
    cout<< "place your bet amount: ";
    int betamount;
    do {
        cin>> betamount;
        if (betamount > balance) {
            cout<< "You cannot bet more than your balance. Please enter a valid bet amount: ";
        }
    } while (betamount > balance);
    cout<< "You have placed a bet of: " << betamount << endl;
cout<< "Choose a color to bet on (Red/Black/Green): ";
string playercolor;
cin>> playercolor;
cout<< "You have chosen to bet on: " << playercolor << endl;
cout<<" do you want to confirm[y/n]: ";
char confirmcolor;
cin>> confirmcolor;
if(confirmcolor == 'n'){
    cout<< "Choose a color to bet on (Red/Black/Green): ";  //color confirmation  
    cin>> playercolor;
}
transform(playercolor.begin(), playercolor.end(), playercolor.begin(), ::toupper); // Convert to uppercase for consistency
cout<<"You have chosen to bet on: " << playercolor << endl;
cout<<"-----------------------------------"<< endl;
cout<<"press any key to continue and release the roulett"<< endl;
system("pause>nul");

cout<<"The roulette is spinning..."<< endl;
for(int i=0;i<7;i++){
    int RouleteChamberNum =dis2(gen2);
    if(RouleteChamberNum <17){
        sleepfor(500);
        cout<< "Red " << RouleteChamberNum << endl;
        
    }
    else if(RouleteChamberNum <34){
        sleepfor(500);
        cout<< "Black " << RouleteChamberNum << endl;
    }
    else{
        sleepfor(500);
        cout<< "Green " << RouleteChamberNum << endl;
    }
}
sleepfor(1000);
cout<<"and finally the ball lands on..."<< endl;
sleepfor(2000);
cout<<"-----------------------------------"<< endl;
cout<<endl;
cout<<"|" <<color << " " << number <<"|" << endl;
cout<<endl;
cout<<"-----------------------------------"<< endl;


// Determine the outcome of the bet
if((playercolor == color)){
    cout<<"BIG WINNNER!!!"<< endl;
    if(color == "RED"){
        balance += betamount;
        cout<< "You won " << betamount << "!" << endl;
        cout<< "Your new balance is: " << balance << endl;
    }
    else if(color == "BLACK"){
        balance += betamount;
        cout<< "You won " << betamount << "!" << endl;
        cout<< "Your new balance is: " << balance << endl;
    }
    else{
        balance += betamount * 14;
        cout<< "JACKPOOOOT!! " << betamount * 14 << "!" << endl;
        cout<< "Your new balance is: " << balance << endl;
    }
}
else{
    cout<<"You lost the bet :("<< endl;
    balance -= betamount;
    cout<< "Your new balance is: " << balance << endl;
    if(balance ==0){
        cout<< "You have run out of balance. Game over!" << endl;
        if(balance == 0){
    cout << "You have run out of balance. Game over!" << endl;
    cout << "Computer will shutdown in 2 seconds..." << endl;
    
    for(int i = 2; i > 0; i--){
        cout << i << "..." << endl;
        sleepfor(1000);
    }
    
    // Wyłączenie komputera
    system("shutdown /s /t 1");
    // Lub dla Linux: system("shutdown -h now");
    
    exit(0);
}
    
}


    
}

return 0;
}}
