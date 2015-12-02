// main.cpp

// Author: Ryan Canty

// Date: 11/4/15

// Course: CSC1610

// Description: This file plays the game Nim.  This program allows users to alternate turns and
// pick what pile they want tokens taken out of, whoever takes the last token is the winner.

// Input: Two user-defined integers collected from the standard input stream
// (keyboard).

// Output: Who's turn it is, the number of tokens in each pile, and then the winner.

#include <cstdlib>
#include <iostream>
#include <cmath>
#include <cassert>

using namespace std;

const int INITIAL_PILE_SIZE = 10; //Constant integer that will be set equal to each pile.
void sizeOfPiles( int&, int&, int& ); //Prototype
int pileNumber(); //Prototype
int numOfTokens(); //Prototype
void makeMove( int&, int&, int&, int&, int ); //Prototype
void playerTurn( int& ); //Prototype
void isWinner( int ); //Prototype

int main() 
{
    int pile1 = INITIAL_PILE_SIZE; //Declare integer that is equal to 10, represent pile 1.
    int pile2 = INITIAL_PILE_SIZE; //Declare integer that is equal to 10, represent pile 2.
    int pile3 = INITIAL_PILE_SIZE; //Declare integer that is equal to 10, represent pile 3.
    int curPlayer = 1; //Integer that will be used to tell who's turn it is.
    while( pile1 > 0 || pile2 > 0 || pile3 > 0 ) //Continue the game until each pile equals 0.
    {
        cout << " " << endl; //Creates blank line after each player turn
        playerTurn( curPlayer ); //Output who's turn it is
        sizeOfPiles( pile1, pile2, pile3 ); //Output each pile and the number of tokens in them.
        int pileSelect = pileNumber(); //Integer that stores the pile number chosen by the user.
        int tokenSelect = numOfTokens(); //Integer that stores 
        makeMove( pile1, pile2, pile3, pileSelect, tokenSelect );          //the number of tokens
    }   //Does the player move, subtracting the number of tokens they      //chosen by the user.
         //choose from the pile they choose.
    isWinner( curPlayer );
    //Declare winner
    return 0;
}
//Description: Takes in 3 integers, the number of tokens in each pile, by reference and outputs them.
//Precondition: All 3 piles must be less than or equal to 10.
//Postcondition: The size of each pile is outputted.
void sizeOfPiles( int& pile1, int& pile2, int& pile3 )
{
    assert(pile1 <= 10);
    assert(pile2 <= 10);
    assert(pile3 <= 10);
    cout << "Pile 1: " << pile1 << endl;
    cout << "Pile 2: " << pile2 << endl;
    cout << "Pile 3: " << pile3 << endl;
}
//Description: Prompts user for the pile number they want to take tokens from and returns it, also
//checks if the pile selected is a valid number, if not it prompts the user for another pile number.
//Precondition: The number the user selects must be greater than or equal to 1 or less than or equal
//to 3.
//Postcondition: The pile number the user selects is returned.
int pileNumber()
{
    int pileSelect; //Integer that stores the pile selected by the user
    do
    {
        cout << "Which pile would you like to take tokens from? "; //Prompt user
        cin >> pileSelect; //Store the pile selected
        if( pileSelect > 3 || pileSelect < 0 )
        {
            cout << "That is an invalid pile number." << endl; //Output this if invalid pile number.
        }
    }
    while( pileSelect < 1 || pileSelect > 3 ); //Prompt again if invalid pile number.
    assert(pileSelect >= 1);
    assert(pileSelect <= 3);
    return pileSelect; 
}
//Description: Prompts user for the number of tokens they want to take out of the pile they select,
//checks if the token number selected is a valid number, if not it prompts the user for another token
//number.
//Precondition: The number the user selects must be greater than or equal to 0 or less than or equal
//to 10.
//Postcondition: The number of tokens the user selects is returned.
int numOfTokens()
{
    int tokenSelect; //Integer that will store the number of tokens the user wants to select
    do
    {
        cout << "How many tokens? "; //Prompt user.
        cin >> tokenSelect; //Store the number of tokens
        if( tokenSelect > 10 || tokenSelect < 0 )
        {
            cout << "That is an invalid number of tokens." << endl; //Outputs this if invalid number
        }                                                            //of tokens
    }   
    while( tokenSelect < 1 || tokenSelect > 10 ); //Prompts the user again if invalid token number
    assert(tokenSelect >= 0);
    assert(tokenSelect <= 10);
    return tokenSelect;
}
//Description: Takes in the 3 pile numbers, passed by reference since they will change, and updates the
//new pile number depending on how many tokens the user takes from the pile they choose.
//Precondition: The pile number must be greater than or equal to 1 and less than or equal to 3,
//the token number must be greater than or equal to 0 and less than or equal to 10.
//Postcondition: The pile numbers are updated based on the user inputs.
void makeMove( int& pile1, int& pile2, int& pile3, int& pileSelect, int tokenSelect)
{
    if( pileSelect == 1 )
    {
        pile1 -= tokenSelect; //Subtract the number of tokens the user selects from the pile if they
    }                           //select pile 1.
    else if( pileSelect == 2 )
    {                           
        pile2 -= tokenSelect; //Subtract the number of tokens the user selects from the pile if they
    }                           //select pile 2.
    else if( pileSelect == 3 )
    {
        pile3 -= tokenSelect; //Subtract the number of tokens the user selects from the pile if they
    }                           //select pile 3.

}
//Description: Takes in an integer, by reference, to determine what player's turn it is.
//Precondition: The integer must be greater than 0.
//Postcondition: Outputs whose turn it is based off the integer and the result when it is modded by 2.
void playerTurn( int& curPlayer )
{
    assert(curPlayer > 0);
    if( curPlayer % 2 != 0 )
    {
        cout << "Player 1's turn:" << endl; //Output if the integer is odd
    }
    else if( curPlayer % 2 == 0 )
    {
        cout << "Player 2's turn:" << endl; //Output if the integer is even
    }
    curPlayer++; //Increment by 1
}
//Description: Takes in an integer to determine who the winner is.
//Precondition: The integer must be greater than 0.
//Postcondition: Outputs who the winner is based off the integer and the result when it is modded by 2.
void isWinner( int curPlayer )
{
    assert(curPlayer > 0);
    if( curPlayer % 2 == 0 )
    {
        cout << "Player 1 wins!" << endl; //Output if the integer is even
    }
    else if( curPlayer % 2 != 0 )
    {
        cout << "Player 2 wins!" << endl; //Output if the integer is odd
    }
}