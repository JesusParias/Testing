/* 
 * File:   main.cpp
 * Author: Jesus Parias-Castillo
 * Purpose: 
 * Created on November 1, 2018, 11:24 AM
 */

#include <iostream>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <fstream>

using namespace std;

string getColor();
string getCard();
string getCard(int);

int main(int argc, char** argv) {

    srand(static_cast<unsigned int>(time(0)));
    
    for(int i =1; i<=10;i++){
    cout << getColor()<<endl;
    }
    /*
    int nHands=10;
    int nCards=5;
    int count=0;
    for (int hand=1; hand<=nHands;hand++){
        for(int cpHand=1; cpHand <= nCards; cpHand++){
            cout<< getCard(rand()%52+1)<< " ";
        }
        cout <<endl;
    }
     */
    string card1,card2,card3,card4,card5;
    int nHand=100;
    for(int hand=1;hand<=nHand;hand++){
        card1=getCard(rand()%52+1);
        do{
            card2=getCard(rand()%52+1);
        }while(card1==card2);
        do{
            card3=getCard(rand()%52+1);
        }while(card1==card3||card2==card3);
        do{
            card4=getCard(rand()%52+1);
        }while(card1==card4|card2==card4||card3==card4);
        do{
            card5=getCard(rand()%52+1);
        }while(card1==card5|card2==card5||card3==card5||card4==card5);
        cout << card1<<" "<<card2<<" "<<card3<<" "<<card4<<" "<<card5<<endl;
    }
    return 0;
}

string getColor(){
    //declare variables
    fstream in;
    string color;
    int nLines;
    //initialize variables
    in.open("color.dat");
    nLines = rand()%8+1;      //possible eight colors in the files;
    //look thru files to find random color
    for(int line =1; line <= nLines; line++){
        in>>color;
    } 
    //close file
    in.close();
    return color;
}
string getCard(){
    //declare variables
    fstream in;
    string card;
    int nLines;
    //initialize variables
    in.open("card.dat");
    nLines = rand()%52+1;      //possible eight colors in the files;
    //look thru files to find random color
    for(int line =1; line <= nLines; line++){
        in>>card;
    }
    //close file
    in.close();
    return card;
}
string getCard(int nLines){
    //declare variables
    fstream in;
    string card;
    //initialize variables
    in.open("card.dat");
    //look thru files to find random color
    for(int line =1; line <= nLines; line++){
        in>>card;
    }
    //close file
    in.close();
    return card;
}
