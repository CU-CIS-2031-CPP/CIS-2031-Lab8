#include <iostream>
#include <string>
using std::cout;
using std::string;
using std::endl;

//Create a struct type named Monster
struct Monster {
    string name;
    int attack;
    int hitpoints;
};

//Create an array of five monsters
Monster monsters[5] = {
    Monster{"Godzilla", 5, 162}, //These values are in the same order as in the struct!
    Monster{"Mothra", 10, 37},
    Monster{"Babadook", 3, 101},
    Monster{"Frankenstein", 2, 23},
    Monster{"ProfessorBill", 1, 3}
};

// This function takes a monster and prints it's name and hitpoints
// to the console, and prints "DEAD" if it has negative HP
void printMonsterStats(Monster m){
    cout << m.name << " hp:" << m.hitpoints;
    if ( m.hitpoints <= 0 )
        cout << " DEAD";
    cout << endl;
}

//Fight two monsters!
//Takes references to each monster, so the variables
//in the calling function are changed.
void fight(Monster &m1, Monster &m2){
    cout << m1.name << " Fights " << m2.name << "!" << endl;
    int round = 0;
    while ( m1.hitpoints > 0 && m2.hitpoints > 0 ){
        round++;
        m1.hitpoints = m1.hitpoints - m2.attack;
        m2.hitpoints = m2.hitpoints - m1.attack;
    }
    if ( m1.hitpoints > 0 && m2.hitpoints < 0 ){
        cout << m1.name << " wins in " << round << " rounds!" << endl;
    } else if ( m1.hitpoints < 0 && m2.hitpoints > 0 ){
        cout << m2.name << " wins in " << round << " rounds!" << endl;
    } else {
        cout << "It's a tie!" << endl;
    }
}

int main(){

    //Loop through all monsters to choose the first
    //opponent for each fight
    for ( int i = 0; i < 5; i++){
        //This local variable contains the opponent for each fight:
        Monster a = monsters[i];

        //Loop through all the monsters to choose
        //the second opponent for each fight.
        for ( int j = 0; j < 5; j++ ){
            //This local variable contains the second opponent for each fight:
            Monster b = monsters[j];

            //Only fight if they are two different monsters.
            if ( i != j ){
                //Dont beat a dead horse
                if ( a.hitpoints > 0 && b.hitpoints > 0){
                    fight(a,b);
                }
            }
        }
    }

    //Print out the final results
    cout << endl << "=== Final Results ===" << endl;
    for ( Monster m : monsters ){
        printMonsterStats(m);
    }
    cout << endl;

    return 0;
}