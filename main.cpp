//Last updated Dec 18, 2020
//Name: Survival Quest Mini Game
//Created by Brandon Macias

#include <iostream> 
using namespace std;

void Nothing(int playHealth){ 
    cout << "You have found no one/nothing..." << endl; 
        return; 
}

int Aid(int playHealth){ 
    cout << "You have found a health pack!" << endl; 
        if (playHealth == 100){ 
            cout << "Health already full, cant carry you continue walking..." << endl;  return playHealth; 
        } 
        cout << "Consuming..." << endl; 
        playHealth = playHealth + 20; 
        if(playHealth > 100){ 
            int difference = playHealth - 100; 
            playHealth = playHealth - difference; 
        } 
    return playHealth; 
}

int Enemy(int playHealth){ 
    string ans; 
    int enemyHealth = rand() % 100 + 1; 
    cout << "Enemy has been discovered" << endl; 
    cout << "What action will you take (attack or run?): "; cin >> ans; cout << endl;   
    if(ans == "run"){ 
        cout << "You have fled...\n"; 
        return playHealth; 
    } 
    cout << "approaching enemy..." << endl; 
    while(playHealth > 0 && enemyHealth > 0){ 
        cout << "Your Health: " << playHealth << "\tEnemy Health: " << enemyHealth << endl; 
        cout << endl; 
        int dam1 = rand() % 50; 
        int dam2 = rand() % 50; 
        cout << "You deal " << dam1 << " damage to enemy!" << endl;  
        enemyHealth = enemyHealth - dam1; 
        cout << "Enemy deals " << dam2 << " damage to you!" << endl;  
        playHealth = playHealth - dam2; 
    } 
  
    if(enemyHealth < 0 && playHealth > 0){ 
        cout << "Enemy has died, you continue on." << endl; 
        return playHealth; 
    } 
 //otherwise your probably return your health 
 return playHealth; 
}

int Death(int playHealth){ 
    string ans; 
    cout << "Are you sure? Last chance (yes/no): "; cin >> ans; 
    if(ans == "yes"){ 
        playHealth = 0; 
        cout << "Current health: " << playHealth << endl; 
        cout << "you have commited suicide..." << endl; 
        return playHealth; 
    } 
    else 
    { 
        cout << "you will continue...\n"; 
        return playHealth; 
    } 
} 

int main(){ 
    int health = 100; 
    int kills = 0; 
    int rounds = 0; 
    cout << "Welcome to game. Enjoy!" << endl;
    cout << "You begin walking..." << endl;  
    while (health > 0) 
    { 
        int choice; 
        cout << "\nWhat will you do?\n"; 
        cout << "Current Health: " << health << endl;  cout << "1. Continue walking.\n";  cout << "2. Search for health.\n";  cout << "3. Commit suicide.\n";  cout <<"Enter you answer: "; cin >> choice;  cout << endl; 
        int a = rand() % 2 + 1; 
        int b = rand() % 2 + 1; 
        switch (choice){ 
            case 1: 
            switch(a){ 
                case 1: 
                Nothing(health); break; 
                case 2: 
                health = Enemy(health);  break; 
                default: 
                health = Enemy(health);  break; 
            } 
            break; 
            case 2: 
            switch(b){ 
                case 1: 
                Nothing(health); break; 
                case 2: 
                health = Aid(health);  break; 
                default: 
                health = Aid(health);  break; 
            } 
            break; 
            case 3: 
            health = Death(health);  break; 
            default:
            cout << "Invalid choice, try again!" << endl;  break; 
        } 
        rounds++; 
    }  

    cout << "\n\nYou have died, Goodbye!\n";  
    cout << "Rounds survived: " << rounds << endl;  
    return 0; 
}
