// Include iostream for cin and cout type operations
#include <iostream>
// Include random for random number generator or random seed
#include <random>
// Include vector data structure
#include <vector>
// Include ctime for time initializer in random seed generator
#include <ctime>

// Include all classes and other header file (utilities) needed for this assignment
// All of these were created / written by me for Project 8 - Poker 2
#include "Utilities.h"

// To reduce std:: calls
using namespace std;

// Main function
int main(){
    // Seed the random number generator
    srand(time(NULL));
    // Declare an anti
    int ante = 50;
    // Set the current pool of money
    int pool = 0;

    // Create a deck
    Deck myDeck;
    // Return the deck into a vector of cards
    vector<Card> theDeck = myDeck.getDeck();
    // Shuffle the deck
    myDeck.shuffleDeck(theDeck);

    /**
     * Create Poker Player objects and add them to a vector of players
     * Note -- this can vary 
     */
    Player playerOne("computer1", 1);
    Player playerTwo("computer2", 1);
    Player playerThree("computer3", 1);
    Player playerFour("computer4", 1);

    vector<Player> players;
    players.push_back(playerOne);
    players.push_back(playerTwo);
    players.push_back(playerThree);
    players.push_back(playerFour);
    // ******* End players creation

    // Check to make sure there are at least two players
    // and less than seven
    if(players.size() < 2 && players.size() <= 7){
        cout << "ERROR -- INVALID NUMBER OF PLAYERS" << endl;
        return 1;
    } //end if

    // Create an iterator to hold the round
    int iter = 1;
    // Create a blank hand to be the "best" hand for every round
    Hand (*a)();
    Hand best = Hand();
    // Create a Player pointer
    Player *bestPlayer;
    // Create a boolean flag used to tell if this is the first evaluation for a round
    bool flag = false;

    // While there is more than one player remaining
    while(players.size() > 1){
        // Pretty print some stuff for formatting and output purposes
        cout << " --------------------------- " << "\n" << endl;            
        cout << "ROUND " << iter << endl;
        cout << " --------------------------- " << "\n" << endl;     
        // End pretty print

        // If the deck isnt big enough to support the game
        if(theDeck.size() < players.size() * 9){
            // Refresh the deck
            myDeck.buildDeck();
            // Get a new deck of cards
            theDeck = myDeck.getDeck();
            // Shuffle the deck
            myDeck.shuffleDeck(theDeck);
        } //end if

        // Loop through the vector of players   
        for(unsigned int i = 0; i < players.size(); i++){
            // Announce who the player is and what type of player they are, as well as their current balance
            cout << "My name is: " << players[i].getName() << ", I am a " << players[i].getType() << " and my balance is: " << players[i].getBalance() << "\n" << endl;
            // Give them a new hand
            players[i].fillHand(theDeck);
            // Place their bet into the pool from their own balance
            players[i].placeBet(ante, pool); 

            // Print out the current hand for the player
            cout << "My current hand is: " << endl;
            players[i].getHand().printHand();
            cout << "\n" << endl;

            // Decide if they will trade cards, and then announce the new hand
            players[i].tradeCards(theDeck);
            cout << "My new hand is: " << endl;
            players[i].getHand().printHand();
            cout << "\n" << endl;

            // If this is the first player for the round, their hand automatically becomes
            // ...the "best" at first
            if(flag == false){
                // Set the best hand and best player (temporarily)
                best = players[i].getHand();
                bestPlayer = &players[i];
                // Change the flag
                flag = true;
                // Skip to the next player
                continue;
            } //end if

            // If the player's hand is ranked higher than the best hand
            if(players[i].getHand().highHand() > best.highHand()){
                // Announce it
                cout << players[i].getName() << " has the high hand. " << endl;

                players[i].getHand().printHand();
                cout << " beats " << endl;
                best.printHand();
                cout << "\n" << endl;

                // Set the player's hand as the best hand
                best = players[i].getHand();
                // Set the best player pointer to point to this player
                bestPlayer = &players[i];
            // Otherwise, if the best hand is better than the current player's
            }else if (players[i].getHand().highHand() < best.highHand()){
                // Announce it
                cout << players[i].getName() << " loses to the high hand. " << endl;

                best.printHand();
                cout << " beats " << endl;
                players[i].getHand().printHand();
                cout << "\n" << endl;

            // Otherwise, they have the same type of hand, so compare them
            }else{
                // Compare the hands
                // This is a modified compareTheHands function from the Hand class
                int result = compareHighest(players[i].getHand(), best);
                // If the player has the better hand
                if(result == 1){
                    // Announce it
                    cout << players[i].getName() << " has the high hand. " << endl;

                    // Do some pretty printing
                    players[i].getHand().printHand();
                    cout << " beats " << endl;
                    best.printHand();
                    cout << "\n" << endl;

                    // Set the player's hand as the best hand
                    best = players[i].getHand();
                    // Set the best player pointer to point to this player
                    bestPlayer = &players[i];
                // If the best hand is better than the players
                }else if (result == 2){
                    // Announce it
                    cout << players[i].getName() << " loses to the high hand. " << endl;

                    // Do some pretty printing
                    best.printHand();
                    cout << " beats " << endl;
                    players[i].getHand().printHand();
                    cout << "\n" << endl;

                    // Move on
                    continue;
                // If their hands are completely tied
                }else if (result == 3){
                    // Announce it
                    cout << "There was a tie" << endl;
                // Otherwise...
                }else{
                    // Just move on
                    continue;
                } //end if else
            } //end if else
        } //end for

        // Do some pretty printing
        cout << "\n" << endl;
        // Announce who won the round
        cout << " Winning Player this round is: " << bestPlayer->getName() << endl;
        // Award the best player by updating their balance
        bestPlayer->updateBalance(pool);
        // Check to see if anyone should be kicked from the table
        checkPlayers(players);
        // Reset the pool
        pool = 0;
        // Increase the round iterator
        iter += 1;
        // Reset the flag
        flag = false;
    } //end while

    // Announce who won the game by finding the last player in the players vector
    cout << players[0].getName() << " wins the game! " << endl;
    // End succesfully
    return 0;
} //end main