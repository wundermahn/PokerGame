#pragma once
#include "Hand.h"
#include "Card.h"
#include <vector>
#include <array>
using namespace std;

// Create a class for a Player
class Player
{
    // constructor for a player
    public:
    virtual Player& operator= (const Player& p){
        assign(p);
        return *this;
    }

    explicit Player(string name){
        // Set the name
        this->name = name;
        // Set the starting balance to 100
        this->balance = 100;
    } //end constructor

    // Default constructor
    Player() { };
    
    virtual ~Player() = default;

    virtual void tradeCards(vector<Card> &deck){ };

    // Getter for the balance
    int getBalance(){
        return this->balance;
    } //end getBalance

    // Getter for the hand
    Hand getHand(){
        return this->playerHand;
    } //end getHand

    // Getter for the name
    string getName(){
        return this->name;
    } //end getName

    // Fill an empty hand
    void fillHand(vector<Card> &deck){
        // Loop through the deck, take the top 5 cards, put them in the hand
        for (unsigned int i = 0; i < 5; i++){
            Card curr = deck[i];
            playerHand.addCardToHand(curr, i);
            // Remove them from the deck
            // https://stackoverflow.com/questions/875103/how-do-i-erase-an-element-from-stdvector-by-index
            deck.erase(deck.begin() + i);
        } //end for

        // Convert the hand to ints, allows for sorting and comparisons
        playerHand.convertHandtoInt();

    } //end fillHand

    // Function to change your current balance
    void updateBalance(int n){
        // Change the balance
        this->balance += n;
    } //end updateBalance

    // This function places a bet
    void placeBet(int &ante, int &pool){
        // Change the current pool to reflect the ante
        pool += ante;
        // Update the player's balance
        updateBalance(-ante);
    }

    // Keep the member data in a protected scope
    protected:
    void assign(const Player& p){}
    int balance;
    Hand playerHand;
    string name;

}; //end class

// Subclass, inherited, for bot players
class botPlayer : public Player
{
    // Public member data
    public:
    // Constructor
    explicit botPlayer(string name){
        // Set the name
        this->name = name;
        // Set the balance
        this->balance = 100;
    }// end botPlayer

    // Creates a random number, 0 or 1
    // Used for "decision making"
    int decide(){
        // Return it
        return rand() % 2;
    } //end decide

    // This function trades cards
    virtual void tradeCards(vector<Card> &deck) override{
        // Create a variable to see if the bot wants to tradein cards
        int decision = decide();
        // If so
        if(decision == 1){
            // 1-4 trades, you cannot trade all 5 cards
            int trades = rand() % 3 + 1;
            // Announce that
            cout << "Decided to trade " << trades << " cards" << endl;
            // Loop through the trades
            for (unsigned int i = 0; i < trades; i++){ 
                // Switch the cards in the index location with the card on the top of the deck
                playerHand.addCardToHand(deck[i], i);
                // Remove those cards form the deck
                deck.erase(deck.begin() + i);
            } //end loop     
        // Otherwise, it does not want to trade cards
        }else{
            cout << "Decided not to trade cards" << endl;
        } //end if else
    } //end trade
}; //end class

// Subclass, inherited, for human players
class humanPlayer : public Player
{
    // Public member data
    public:
    // Constructor
    explicit humanPlayer(string name){
        // Set the name
        this->name = name;
        // Set the balance
        this->balance = 100;
    } //end humanPlayer

    // This function trades cards
    virtual void tradeCards(vector<Card> &deck) override{
        // Influenced from: https://stackoverflow.com/questions/13096719/read-input-numbers-separated-by-spaces
        // And https://stackoverflow.com/questions/5029840/convert-char-to-int-in-c-and-c
        // Create variables
        string input;
        vector<int> trades;
        int curr;
        // Input information from the human player
        cout << "Please enter the indices you want to switch cards for. If you don't want a switch, simply type x" << endl;
        // Capture the input
        cin >> input;

        // Loop through the input
        for(char& c : input){
            // If it is equal to x, exit the function
            if(c == 'x'){
                return;
            // Otherwise...
            }else{
                // Convert the character to an int
                curr = (int)c - 48;
                // Add it to the trades to make
                trades.push_back(curr);
            } //endif else
        } //end for loop
        
        // Loop through the trades
        for (unsigned int i = 0; i < trades.size(); i++){ 
            // Switch the cards in the index location with the card on the top of the deck
            playerHand.addCardToHand(deck[i], trades[i]);
            // Remove those cards form the deck
            deck.erase(deck.begin() + i);
        } //end loop
    } //end trade

}; //end class