// Needed to ensure this is only compiled once
#pragma once
// Needed for print function like cout
#include <iostream>
// Needed for standard array
#include <array>
// Needed for string operations
#include <string>
// Needed for sorting
#include <algorithm>
// Needed for sorting
#include <functional>
// To reduce std:: calls
using namespace std;

// Create a class for a card
class Card
{
    // Takes in a rank and a suit to create it
    public:
    explicit Card(string rank, string suit){
        // Set the rank and suit to the passed in values
        this->rank = rank;
        this->suit = suit;
    } //end constructor

    // Blank constructor
    Card(){ };

    // Destructor
    virtual ~Card() { };

    // Get the rank
    string getRank(){
        return rank;
    }//end getRank

    // Get the suit
    string getSuit(){
        return suit;
    }//end getSuit

    // Keep the rank and suit in a protected scope
    protected:
    string rank;
    string suit;

}; 