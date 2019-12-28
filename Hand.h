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
// Include the card class
#include "Card.h"

// Create a class for a hand
class Hand
{
    public:
    // It's constructor expects an array of size 5 of type Card
    // 5 cards
    explicit Hand(array<Card, 5> cards) : cards(cards){
        // Convert the cards to int values
        convertHandtoInt();
        // Check the hand to see what types of poker you have
        // pair, three of a kind, etc.
        checkHand();
    } //end constructor

    // Default constructor
    // Added for Program 8
    Hand(){ };


    // Adds a card at a specified index to the hand
    // Added for Program 8
    void addCardToHand(Card &curr, int index){
        // Add a card object to the hand
        this->cards[index] = curr;
    }

    // Print out the hand
    void printHand(){
        // Loop through the cards in the hand
        for (unsigned i = 0; i < cards.size(); i++){
            // Print out their rank and suit as described in requirements
            cout << cards[i].getRank() << cards[i].getSuit() << " ";
        } //end for
    } //end printHand

    // Check to see if there is a flush in the hand
    bool isFlush(){
        // Loop through the cards in the hand
        for (unsigned i = 0; i < cards.size(); i++) {
            // If all the suits are not the same, return false
            if (cards[i].getSuit() != cards[0].getSuit()) {
                return false;
            } //end if
        } //end for
        // Otherwise, return true
        return true;
    } //end isFlush

    // Check to seeif there is a straight in the hand
    bool isStraight(){
        // Loop through the cards in the hand
        for (unsigned i = 0; i < tempArray.size() -1; i++){
            // Check to ensure next item in the array is one less than the current
            if (tempArray[i+1] == tempArray[i] - 1){
                // If it is, continue on
                continue;
            }else{
                // If it is not, its not a straight
                return false;
            } //end else
        } //end for

        // If you've gotten here, then there is a straight
        return true;    
    }//end isStraight

    // Check to see if there is a pair
    int isPair(){        
        // Loop through the hand and see if there is a pair
        for(unsigned int i = 0; i < tempArray.size(); i++){
            // If the current is equal to the next, that is a pair
            if (tempArray[i] == tempArray[i+1]){
                // Return the pair value
                return tempArray[i];
            } //end if
        } //end for
        // Otherwise there is no pair so return 0
        return 0;
    } //end isPair

    // Check to see if there are two pairs
    bool isTwoPair(){
        // Ensure you don't have three or four of a kind
        // And that you have at least one pair
        if((TOAK == true || FOAK == true) && onePair != 0){
            // If you don't then you don't have two pair
            return false;
        // Otherwise
        }else{
            // Create a count for the pairs
            int pairCount = 0;

            // Loop through the array
            for(unsigned int i = 0; i < tempArray.size(); i++){
                if(tempArray[i] == tempArray[i+1]){
                    // If you have a pair, increase the pair count
                    pairCount += 1;
                } //end if
            } //end for
            // If you have more than 1 pair, return true
            if(pairCount > 1){
                return true;
            // Otherwise, return false
            }else{
                return false;
            } //end if
        } //end else        
    } //end isPair    

    // Check to see if there is a full house
    bool isFullHouse(){
        // Ensure that you have at least three of a kind
        // and that you have a pair
        if(TOAK != 0 && onePair != 0){
            // If that's true, then you have a full house
            return true;
        // Otherwise
        }else{
            // You don't
            return false;
        } //end else
    } //end isFullHouse

    // Checks to see if there are three of a kind
    int isThreeOfAKind(){
        // Loop through the hand
        for(unsigned int i = 0; i < tempArray.size(); i++){
            // Since it is sorted, check the current card and the next two
            // to see if they are equal
            if (tempArray[i] == tempArray[i+1] && tempArray[i+1] == tempArray[i+2]){
                // If so, return the number
                return tempArray[i];
            } //end if
        }// end for

        // If not, return 0
        return 0;
    } //end isThreeOfAKind

    // Checks to see if there are four of a kind
    int isFourOfAKind(){
        // Loop through the hand
        for(unsigned int i = 0; i < tempArray.size(); i++){
            // Since it is sorted, check the first 4 cards and see if they match
            if (tempArray[i] == tempArray[i+1] && tempArray[i+1] == tempArray[i+2]
            && tempArray[i+2] == tempArray[i+3]){
                // If so return the number
                return tempArray[i];
            } //end if
        }//end for

        //If not, return 0
        return 0;
    }//end isFourOfAKind

    // Checks if thereis a straight flush
    bool isStraightFlush(){
        // If there is a straight and a flush
        if(Flush == true && Straight == true){
            // Return true
            return true;
        // Otherwise
        }else{
            // Return false
            return false;
        } //end else
    } //end isStraightFlush

    // Create a function to return values of the two pairs of the hand
    array<int, 2> getTwoPairValues(){
        // Declare an array to return
        array<int, 2> twoPairValues;
        // Set the first pair to 0, which it will stay it if there isn't a pair
        int firstPairNum = 0;
        // Set the second pair to 0, which it will at if there isn't a second pair
        int secondPairNum = 0;
        // If there are two pair
        if(getTwoPair() == true){
            // Loop through the array
            for(unsigned int i = 0; i < tempArray.size(); i++){
                // If there is a pair
                if(tempArray[i] == tempArray[i+1]){
                    // and the first pair variable hasn't been filled yet
                    if(firstPairNum == 0){
                        // Grab the value of the first pair
                        firstPairNum = tempArray[i];
                        // Fill the array with the values
                        twoPairValues[0] = tempArray[i];
                        //cout << " Iteration " << i << " the first pair was set." << endl;
                        continue;
                    } //endif

                    // If there is a pair and the first pair variable has been filled
                    else if(firstPairNum != 0 && secondPairNum == 0){
                        // Grab the value of the second pair
                        secondPairNum = tempArray[i];
                        twoPairValues[1] = tempArray[i];
                        //cout << " Iteration " << i << " the second pair was set." << endl;
                        continue;
                    } //end else if

                    // Otherwise, you may have 3 of a kind and shouldn't be here
                    else{
                        cout << " Error in hand logic. ";
                        EXIT_FAILURE;
                    } //end else                    
                } //end if
            } //end for                    
        // Error check in the event this function gets called when there aren't two pair
        }else{
            cout << " Not two pair. Cannot grab their values. ";
            EXIT_FAILURE;
        } //end else
        
        // Return the array
        return twoPairValues;

    }//return the array

    // Returns the highest card
    int getMax(){
        return tempArray[0];
    } //end getMax

    // Returns the lowest card
    int getMin(){
        return tempArray[4];
    }//end getMin

    // Returns if the hand has a flush or not
    bool getFlush(){
        return Flush;
    } //end getFlush

    // Returns if the hand has a straight or not
    bool getStraight(){
        return Straight;
    }//end getStraight

    // Returns if there is a straight flush or not
    bool getStraightFlush(){
        return StraightFlush;
    }//end getStraightFlush

    // Returns if there is a pair or not
    int getPair(){
        return onePair;
    } //end getPair

    // Returns if there are two pairs or not
    bool getTwoPair(){
        return twoPair;
    }//end getTwoPair

    // Returns if there are three of a kind or not
    int getTOAK(){
        return TOAK;
    }//end getTOAK

    // Returns if there are four of a kind or not
    int getFOAK(){
        return FOAK;
    }//end getFOAK

    // Returns if there is a full house
    bool getFullHouse(){
        return FullHouse;
    }//end getFullHouse

    // Create a function to return the numeric value of the ranks
    array<int, 5> getCardVals(){
        return tempArray;
    }//return the array

    // Function to determine status of the hand
    void checkHand(){
        // Set the values
        Flush = isFlush();
        Straight = isStraight();
        StraightFlush = isStraightFlush();
        onePair = isPair();
        twoPair = isTwoPair();
        TOAK = isThreeOfAKind();
        FOAK = isFourOfAKind();
        FullHouse = isFullHouse();
    }//end checkHand

    // Added for proj 8
    /**
     * This function checks to see what "type" of hand the object is
     * It then updates a score. This will be used for hand comparison
     * @return int 
     */
    int highHand(){
        convertHandtoInt();
        checkHand();
        // Rank the hands according to:
        // https://www.cardplayer.com/rules-of-poker/hand-rankings
        if(StraightFlush){
            return 8;
        }else if (FOAK){
            return 7;
        }else if (FullHouse){
            return 6;
        }else if (Flush){
            return 5;
        }else if (Straight){
            return 4;
        }else if (TOAK){
            return 3;
        } else if (twoPair){
            return 2;
        } else if (onePair){
            return 1;
        }else{
            return 0;
        } //end if else
    } //end highHand        

    // Convert the hand to a temp array of ints
    // to determine their true values
    void convertHandtoInt(){    
        string::size_type sz;

        // Loop through the cards
        for (unsigned i = 0; i < cards.size(); i++){
            // If its a Jack, assume its worth 11
            if (cards[i].getRank() == ("J")){
                tempArray[i] = 11;
            }// end jack check
            
            //If its a Queen, assume its worth 12
            else if (cards[i].getRank() == ("Q")){
                tempArray[i] = 12;
            } //end queen check

            // If its a King, assume its worth 13
            else if (cards[i].getRank() == ("K")){
                tempArray[i] = 13;
            } //end king check

            //If its an Ace, assume its high and worth 14
            else if (cards[i].getRank() == ("A")){
                tempArray[i] = 14;
            } //end ace check
            
            // Otherwise, convert the string to an int
            else{
                try{
                    tempArray[i] = stoi(cards[i].getRank(), &sz);
                }catch(...){
                    //Nothing
                }
                
            } //end else
        } //end for

    //https://stackoverflow.com/questions/4008253/how-to-sort-c-array-in-asc-and-desc-mode
    //https://stackoverflow.com/questions/28491584/c-sort-error-no-instance-of-overloaded-function
    
    // Sort the array
    sort(tempArray.begin(), tempArray.end(), greater<int>());

    } //end convertHandtoInt

    // Declare protected member data
    protected:
    array<Card, 5> cards;
    array<int, 5> tempArray;
    bool Flush;
    bool Straight;
    bool StraightFlush;
    int onePair;
    bool twoPair;
    int TOAK;
    int FOAK; 
    bool FullHouse;    
};
