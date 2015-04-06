// Katie Quinn55
// Implementation for Pokemon Class

#include "Pokemon.h"
#include <iostream>
#include <stdlib.h> // srand, rand
#include <time.h>
#include <string>
#include <math.h> // sqrt
using namespace std;

// updated constructor
Pokemon::Pokemon(string myName, int myLevel){
  Name = myName;
  level = myLevel;
  
  //call to intialize EVs to 0
  initEVs();

  //set IVs
  setIVs();

  //set other dependent stats in species and type classes
}

string Pokemon::getType(){
  return type;
}

void Pokemon::setType(string myType){
  type = myType;
}

void Pokemon::setBaseA(int a){
  base_A = a;
  cout << "base a: " << base_A << endl; // for testing
}

void Pokemon::setBaseD(int d){
  base_D = d;
  cout << "base d: " << base_D << endl;
}


void Pokemon::setBaseSpec(int spec){
  base_Spec = spec;
  cout << "base spec: " << base_Spec << endl;
}

void Pokemon::setBaseSpeed(int s){
  base_Speed = s;
  cout << "base_Speed: " << base_Speed << endl;
}

void Pokemon::setBaseHP(int h){
  base_HP = h;
  cout << "base HP: " << base_HP << endl;
}

void Pokemon::initEVs(){

// EVs start at 0
  EV_A = 0;
  EV_D = 0;
  EV_Spec = 0;
  EV_Speed = 0;
  EV_HP = 0;
  cout << "EVS : " << EV_A << "," << EV_D << "," << EV_Spec << "," << EV_Speed << "," << EV_HP << endl;

}
void Pokemon::setIVs(){
// IVs are a random number between 0 and 15 except IV_HP
// initalize random seed
  srand( time(NULL) );

  IV_A = rand() % 16; // generate rand between 0 and 15
cout << "IV_A: " << IV_A << endl; //for testing
  IV_D = rand() % 16;
cout << "IV_D: " << IV_D << endl; //for testing
  IV_Spec = rand() % 16;
cout << "IV_Spec: " << IV_Spec << endl;
  IV_Speed = rand() % 16;
cout << "IV_Speed: " << IV_Speed << endl;

//set IV_HP
  setIV_HP();
}
void Pokemon::updateEV_A(int update){
//update experience
//Check to see theres a formula
  EV_A += update;
}

void Pokemon::updateEV_D(int update){
  EV_D += update;
}

void Pokemon::updateEV_Spec(int update){
  EV_Spec += update;
}

void Pokemon::updateEV_Speed(int update){
  EV_Speed += update;
}

void Pokemon::updateEV_HP(int update){
  EV_HP += update;
}
void Pokemon::setIV_HP(){
//set the IV_HP using the other IV values
// IV_HP takes the last binary digit from IV Attack, Defense, Speed, and 
// Special. Arranges it in that order
// need a function to convert decimal IVs to binary
// take last digit, set to IV_HP
// EDIT FUNCTION
  IV_HP = rand() % 16; // set as a random number for now
cout << "IV_HP: " << IV_HP << endl; //for testing remove later
}
void Pokemon::setAttack(){
//determines the attack stat of a pokemon
  attack =( (IV_A + base_A + ( sqrt(EV_A) / 8 ) * level )/50 ) + 5;
  cout << "The attack is : " << attack << endl;
}

void Pokemon::setDef(){
//determines the defense stat of a pokemon
  defense =( (IV_D + base_D + ( sqrt(EV_D) / 8 ) * level )/50 ) + 5;
  cout << "The defense is : " << defense << endl;
}


void Pokemon::set_spec_A(){
//determines the special attack of a pokemon
specAttack = ( (IV_Spec + base_Spec + ( sqrt(EV_Spec) / 8 ) * level )/50 ) + 5;
 cout << "The special attack is " << specAttack << endl;
}


void Pokemon::set_spec_D(){
//determines the special defense of a pokemon
specDefense =( (IV_Spec + base_Spec + ( sqrt(EV_Spec) / 8 ) * level )/50 ) + 5;
cout << "The special defense is " << specDefense << endl;
}


void Pokemon::setSpeed(){
//determines the speed of a pokemon
  speed =( (IV_Speed + base_Speed + ( sqrt(EV_Speed) / 8 ) * level )/50 ) + 5;
  cout << "The speed is " << speed << endl;
}


void Pokemon::setHP(){
//determines the HP initially of a pokemon 
//determines the maximum health effectively
  HP  = ( ((IV_HP + base_HP + ( sqrt(EV_HP) / 8 ) + 50 )* level )/50 ) + 10;
  cout << "The HP is: " <<HP << endl;
}
string Pokemon::getName(){
  return Name;
}
int Pokemon::getAttack(){
  return attack;
}

int Pokemon::getDefense(){
  return defense;
}

int Pokemon::getSpecA(){
  return specAttack;
}

int Pokemon::getSpecD(){
  return specDefense;
}

int Pokemon::getSpeed(){
  return speed;
}

int Pokemon::getLevel(){
  return level;
}

int Pokemon::getHP(){
  return HP;
}

int Pokemon::updateHP(int damage){
  HP-=damage;
  if(HP<0){
     cout << "Pokemon has fainted!"; 
     return 1;
  }
  else return 0;
}

void Pokemon::updateLevel(int update){
  level+=update;
  cout << "New level: " << level << endl;
// set the other dependant stats 
  setAttack();
  setDef();
  set_spec_A();
  set_spec_D();
  setSpeed();
}