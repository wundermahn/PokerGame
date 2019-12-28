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
// Needed for vectors
#include <vector>
// Needed for random
#include <random>
// To reduce std:: calls
using namespace std;
// Needed for Card
#include "Card.h"


// Create a class for a Player
class Deck
{
    // constructor for a player
    public:
    explicit Deck(){

        buildDeck();

    } //end constructor

    // Create a destructor
    virtual ~Deck(){ };

    // Build the deck
    void buildDeck(){
        // Empty the deck
        this->cards.empty();

        // Add in Clubs
        for(unsigned int i = 2; i <= 10; i++){
            Card curr(to_string(i), "C");
                this->cards.push_back(curr);
        }

        // Add in Diamonds
        for(unsigned int i = 2; i <= 10; i++){
            Card curr(to_string(i), "D");
                this->cards.push_back(curr);
        }

        // Add in Hearts
        for(unsigned int i = 2; i <= 10; i++){
            Card curr(to_string(i), "H");
                this->cards.push_back(curr);
        }

        // Add in Spades
        for(unsigned int i = 2; i <= 10; i++){
            Card curr(to_string(i), "S");
                this->cards.push_back(curr);
        }

        // Create some arrays to quickly add the rest of the cards
        array<string, 4> suits = {"C", "H", "S", "D"};
        array<string, 4> vals = {"J", "K", "Q", "A"};

        // Loop through and finish building the deck
        for (unsigned int i = 0; i < suits.size(); i++){
            for(unsigned int j = 0; j < vals.size(); j++){
                Card curr(vals[j], suits[i]);
                this->cards.push_back(curr);
            } //end inner loop
        } //end outer loop
    }

    // Inspired by: https://codereview.stackexchange.com/questions/39001/fisher-yates-modern-shuffle-algorithm
    // Perform Fisher-Yates Shuffle
    void shuffleDeck(vector<Card> &cards){        
        // Create random
        random_device random;
        // Use mersenne twister engine
        mt19937 mersenne_twister(random());
        // Create distribution
        uniform_int_distribution<uint8_t> distribution;
        // Loop through and shuffle the cards
        for (auto i = cards.size() - 1; i > 0; i--){
            distribution.param(uniform_int_distribution<uint8_t>::param_type(0, i));
            // Actually perform the shuffle
            swap(cards[i], cards[distribution(mersenne_twister)]);
        } //end for
    } //end shuffleDeck

    // Return the deck of cards
    vector<Card> getDeck(){
        // Return it
        return this->cards;
    }

    // Keep the member data in a protected scope
    protected:
    vector<Card> cards;

}; 