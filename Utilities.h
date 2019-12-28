// Only compile once
#pragma once
// Include all classes and other header file (utilities) needed for this assignment
// All of these were created / written by me for Project 8 - Poker 2
#include "TestingLogic.h"
#include "Card.h"
#include "Deck.h"
#include "Hand.h"
#include "Player.h"

int compareHighest(Hand firstHand, Hand bestHand){
    // Create arrays of the values (ranks) of the two hands
    array<int, 5> firstHandVals = firstHand.getCardVals();
    array<int, 5> bestHandVals = bestHand.getCardVals();

    // Loop through the values
    for(unsigned int i = 0; i < firstHandVals.size(); i++){
        // Since its sorted, if hand one is bigger, print that out
        if (firstHandVals[i] > bestHandVals[i]){
            // If the current hand is better, return 1
            return 1;
        } //end if
        
        // If hand two is bigger, print that out
        else if (firstHandVals[i] < bestHandVals[i]){
            // if the best hand is better, return 2
            return 2;
        } //end else if

        // Otherwise, they are the same
        else{
            continue;
        }
    } //end for

    // Otherwise, they are completely equal, so return 3
    return 3;
 
}//end compareHighest

// This function compares two hands and determines which hand holds the higher card
int compareTheHands(Hand &firstHand, Hand &bestHand){

    int firstHigh = firstHand.highHand();
    int bestHigh = bestHand.highHand();

    if (firstHigh == bestHigh){
        switch (firstHigh)
        {
            // Straight Flush
            case 8: 
                return compareHighest(firstHand, bestHand);
                break;

            // FOAK
            case 7:
                return compareHighest(firstHand, bestHand);
                break;

            // FullHouse
            case 6:
            {
                int firstHandThree;
                int bestHandThree;
                int firstHandPair;
                int bestHandPair;

                // Get those values
                firstHandThree = firstHand.getTOAK();
                firstHandPair = firstHand.getPair();
                bestHandThree = bestHand.getTOAK();
                bestHandPair = bestHand.getPair();

                // If hand one's three of a kind is bigger, it wins
                if(firstHandThree > bestHandThree){
                    return 1;
                } //end if

                // If hand two's three of a kind is bigger, it wins
                else if (bestHandThree > firstHandThree){
                    return 2;
                }//endif

                // Otherwise, they are equal
                else{
                    //Now check the pairs
                    // If hand one's pair is bigger, it wins
                    if(firstHandPair > bestHandPair){
                        return 1;
                    } //end if

                    // If hand two's pair is bigger, it wins
                    else if(bestHandPair > firstHandPair){
                        return 2;
                    } //end if

                    // Otherwise, the hands are equal
                    else{
                        return 3;
                    } //end parent else
                } //endother else
            } //end case
            break;

            // Flush
            case 5:
                return compareHighest(firstHand, bestHand);
                break;

            // Straight
            case 4:
                return compareHighest(firstHand, bestHand);
                break;
            // TOAK
            case 3:
            {    
                // If so, initialize and assign some data
                int firstHandThree = firstHand.getTOAK();
                int bestHandThree = bestHand.getTOAK();
                // These variables are for the high and low cards
                // that are NOT part of the three of a kind
                int firstHandHigh;
                int firstHandLow;
                int bestHandHigh;
                int bestHandLow;
                array<int, 5> firstHandVals = firstHand.getCardVals();
                array<int, 5> bestHandVals = bestHand.getCardVals();

                // The first and second cards that are not in the three of a kind
                int firstHandFirst = 0;
                int firstHandSecond = 0;
                for (unsigned int i = 0; i < firstHandVals.size(); i++){
                    // cout << "Comparing: " << firstHandVals[i] << " and " << firstHandThree << endl;            
                    if (firstHandVals[i] != firstHandThree){
                        firstHandFirst = firstHandVals[i];
                        break;
                    } //end if
                } //end for

                for (unsigned int i = 0; i < firstHandVals.size(); i++){
                    if(firstHandVals[i] != firstHandThree && firstHandVals[i] != firstHandFirst){
                        firstHandSecond = firstHandVals[i];
                        break;
                    } //end if
                } //end for

                // The first and second cards that are not in the three of a kind
                int bestHandFirst = 0;
                int bestHandSecond = 0;
                for (unsigned int i = 0; i < bestHandVals.size(); i++){
                    if (bestHandVals[i] != bestHandThree){
                        bestHandFirst = bestHandVals[i];
                        break;
                    } //end if
                } //end for

                for (unsigned int i = 0; i < bestHandVals.size(); i++){
                    if(bestHandVals[i] != bestHandThree && bestHandVals[i] != bestHandFirst){
                        bestHandSecond = bestHandVals[i];
                    } //end if
                } //end for

                // Check if hand One's three of a kind is higher than bestHand
                // If so, alert the user
                if(firstHandThree > bestHandThree){
                    return 1;
                } // end if
                
                // If not, check if hand Two's Three of a kind is higher
                // than hand One's. If so, alert the user
                else if(bestHandThree > firstHandThree){
                    return 2;
                } //end else if

                // Otherwise, they are equal, so check their next highest card
                else{
                    if(max(firstHandFirst, firstHandSecond) > max(bestHandFirst, bestHandSecond)){
                        return 1;
                    } //end if

                    else if(max(firstHandFirst, firstHandSecond) < max(bestHandFirst, bestHandSecond)){
                        return 2;
                    } //end else if

                    // At this point, the three of a kind next highest are equal, so check the last card
                    else{                
                        // If the first hand is higher
                        if(min(firstHandFirst, firstHandSecond) > min(bestHandFirst, bestHandSecond)){
                            return 1;
                        } //end if

                        // If the second hand is higher
                        else if(min(firstHandFirst, firstHandSecond) < min(bestHandFirst, bestHandSecond)){
                            return 2;
                        } //end else if

                        // Otherwise they are equal
                        else{
                            return 3;
                        } //end else
                    } //end else
                } //end else
            } // switch
            break;

            // twoPair
            case 2:
            {                
                // Create a 2-item array of the two pair values
                array<int, 2> firstHandPairs = firstHand.getTwoPairValues();
                array<int, 2> bestHandPairs = bestHand.getTwoPairValues();
                
                // Get the values of the ranks of the cards in the two hands
                array<int, 5> firstHandVals = firstHand.getCardVals();
                array<int, 5> bestHandVals = bestHand.getCardVals();

                // Create the high and low of the pairs for each hand
                int firstHandPairHigh = max(firstHandPairs[0], firstHandPairs[1]);
                int firstHandPairLow = min(firstHandPairs[0], firstHandPairs[1]);
                int bestHandPairHigh = max(bestHandPairs[0], bestHandPairs[1]);
                int bestHandPairLow = min(bestHandPairs[0], bestHandPairs[1]);

                // Create ints to hold the value of each hand that isn't one of the pairs
                int firstHandNotPairVal;
                int bestHandNotPairVal;

                // Loop through the hands and figure out which value isn't a pair
                for(unsigned int i = 0; i < firstHandVals.size(); i++){
                    if(firstHandVals[i] != firstHandPairHigh && firstHandVals[i] != firstHandPairLow){
                        firstHandNotPairVal = firstHandVals[i];
                    } //end if

                    if(bestHandVals[i] != bestHandPairHigh && bestHandVals[i] != bestHandPairLow){
                        bestHandNotPairVal = bestHandVals[i];
                    }//end if
                } //end for 

                // Compare the high of the two pairs
                if(firstHandPairHigh > bestHandPairHigh){
                    return 1;
                } //end if

                else if(firstHandPairHigh < bestHandPairHigh){
                    return 2;
                } //end else if

                // If the highs are equal, compare the lows
                else{
                    if(firstHandPairLow > bestHandPairLow){
                        return 1;
                    } //end if

                    else if(firstHandPairLow < bestHandPairLow) {
                        return 2;
                    } //end else if

                    // If both pairs are equal, compare the last card
                    else{
                        if(firstHandNotPairVal > bestHandNotPairVal){
                            return 1;
                        } // end if

                        else if(firstHandNotPairVal < bestHandNotPairVal){
                            return 2;
                        } //end else if

                        // Otherwise, everything is equal
                        else{
                            return 3;
                        } //end else
                    } //end else
                }//end else  
            } // end case
            break;

            // onePair
            case 1:
            {
                // Get the pair values                
                int firstHandPairVal = firstHand.getPair();
                int bestHandPairVal = bestHand.getPair();
                // Create arrays of the rank values of the cards
                array<int, 5> firstHandVals = firstHand.getCardVals();
                array<int, 5> bestHandVals = bestHand.getCardVals();
                // Create vectors for the remaining values of the hands
                vector<int> firstHandRemainingVals;
                vector<int> bestHandRemainingVals;

                // Loop through the hands, and fill the remaining values for each
                for(unsigned int i = 0; i < firstHandVals.size(); i++){
                    if (firstHandVals[i] != firstHandPairVal){
                        firstHandRemainingVals.push_back(firstHandVals[i]);
                    } //end if
                    if (bestHandVals[i] != bestHandPairVal){
                        bestHandRemainingVals.push_back(bestHandVals[i]);
                    } //end if
                } //end for
                
                // Sort the remaining values
                sort(firstHandRemainingVals.begin(), firstHandRemainingVals.end(), greater<int>());
                sort(bestHandRemainingVals.begin(), bestHandRemainingVals.end(), greater<int>());

                // Compare the pairs of each hand
                if(firstHandPairVal > bestHandPairVal){
                    return 1;
                } //end if

                else if(firstHandPairVal < bestHandPairVal){
                    return 2;
                } //end if

                // If the pairs are equal
                else{
                    // Create a bool to determine if all values are equal
                    bool isEqual = true;
                    // Loop through the remaining values
                    for (unsigned int i = 0; i < firstHandRemainingVals.size(); i++){
                        // If hand one is bigger, it wins
                        if (firstHandRemainingVals[i] > bestHandRemainingVals[i]){
                            isEqual = false;
                            return 1;
                            break;                   
                        } // end

                        // If hand two is bigger, it wins
                        else if(firstHandRemainingVals[i] < bestHandRemainingVals[i]){
                            isEqual = false;
                            return 2;
                            break;
                        } //end else if

                        // If they are equal, continue
                        else{
                            continue;
                        } //end else
                    } //end the loop

                    // If both hands are equal, alert
                    if(isEqual == true){
                        return 3;
                    } //end if
                } //end else              
            } // end switch    
            break;

            default:
                return compareHighest(firstHand, bestHand);
        } //end switch
    }else{
        return compareHighest(firstHand, bestHand);
    } //end else
} //end function

// This function checks to ensure players are still in the game
void checkPlayers(vector<Player> &players){
    // Loop through the players
    for(unsigned int i = 0; i < players.size(); i++){
        // Make sure they have a balance above 0
        if(players[i].getBalance() <= 0){
            cout << players[i].getName() << " is eliminated. " << endl;
            // If they don't, remove them from the list
            players.erase(players.begin() + i);
        } //end
    } //end for
} //end checkPlayers