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
// To reduce std:: calls
using namespace std;
// Needed for Card and Hand class info
#include "Card.h"
#include "Hand.h"

// This function compares two hands and determines which hand holds the higher card
void compareHands(Hand firstHand, Hand secondHand){
    // Create arrays of the values (ranks) of the two hands
    array<int, 5> handOneVals = firstHand.getCardVals();
    array<int, 5> handTwoVals = secondHand.getCardVals();

    // Loop through the values
    for(unsigned int i = 0; i < handOneVals.size(); i++){
        // Since its sorted, if hand one is bigger, print that out
        if (handOneVals[i] > handTwoVals[i]){
            firstHand.printHand();
            cout << "ranks higher than ";
            secondHand.printHand();
            cout << endl;
            return;
        } //end if
        
        // If hand two is bigger, print that out
        else if (handOneVals[i] < handTwoVals[i]){
            secondHand.printHand();
            cout << "ranks higher than ";
            firstHand.printHand();
            cout << endl;
            return;
        } //end else if

        // Otherwise, they are the same
        else{
            continue;
        }
    } //end for

    // So then print out that they are equal in value
    firstHand.printHand();
    cout << "and ";
    secondHand.printHand();
    cout << "are of equal rank " << endl;
    return;

} //end compareHands

// Function to evaluate Straight Flush test cases
void evaluateStraightFlush(){
    
    // Hand One
    Card handOne_cardOne("10", "C");
    Card handOne_cardTwo("9", "C");
    Card handOne_cardThree("8", "C");
    Card handOne_cardFour("7", "C");    
    Card handOne_cardFive("6", "C");

    // Hand Two
    Card handTwo_cardOne("8", "H");
    Card handTwo_cardTwo("7", "H");
    Card handTwo_cardThree("6", "H");
    Card handTwo_cardFour("5", "H");    
    Card handTwo_cardFive("4", "H");

    // Hand Three
    Card handThree_cardOne("6", "S");
    Card handThree_cardTwo("5", "S");
    Card handThree_cardThree("4", "S");
    Card handThree_cardFour("3", "S");    
    Card handThree_cardFive("2", "S");        

    // Hand Four
    Card handFour_cardOne("7", "D");
    Card handFour_cardTwo("6", "D");
    Card handFour_cardThree("5", "D");
    Card handFour_cardFour("4", "D");    
    Card handFour_cardFive("3", "D");

    // Hand Five
    Card handFive_cardOne("7", "S");
    Card handFive_cardTwo("6", "S");
    Card handFive_cardThree("5", "S");
    Card handFive_cardFour("4", "S");    
    Card handFive_cardFive("3", "S");

    // Create arrays of the cards
    array<Card, 5> handOneCards{handOne_cardOne, handOne_cardTwo, 
                           handOne_cardThree, handOne_cardFour,
                           handOne_cardFive};

    array<Card, 5> handTwoCards{handTwo_cardOne, handTwo_cardTwo, 
                           handTwo_cardThree, handTwo_cardFour,
                           handTwo_cardFive};

    array<Card, 5> handThreeCards{handThree_cardOne, handThree_cardTwo, 
                           handThree_cardThree, handThree_cardFour,
                           handThree_cardFive};

    array<Card, 5> handFourCards{handFour_cardOne, handFour_cardTwo, 
                           handFour_cardThree, handFour_cardFour,
                           handFour_cardFive};

    array<Card, 5> handFiveCards{handFive_cardOne, handFive_cardTwo, 
                           handFive_cardThree, handFive_cardFour,
                           handFive_cardFive};

    // Create hand objects
    Hand handOne(handOneCards);
    Hand handTwo(handTwoCards);
    Hand handThree(handThreeCards);
    Hand handFour(handFourCards);
    Hand handFive(handFiveCards);


    // Comparison one
    if(handOne.getStraightFlush() == 1 && handTwo.getStraightFlush() == 1){
        compareHands(handOne, handTwo);
    }else{
        cout << "ERROR - Both hands are not straight flushes. Quitting" << endl;
        EXIT_FAILURE;
    }

    // Comparison two
    if(handOne.getStraightFlush() == 1 && handTwo.getStraightFlush() == 1){
        compareHands(handTwo, handThree);
    }else{
        cout << "ERROR - Both hands are not straight flushes. Quitting" << endl;
        EXIT_FAILURE;
    }

    // Comparison three
    if(handOne.getStraightFlush() == 1 && handTwo.getStraightFlush() == 1){
        compareHands(handFour, handFive);
    }else{
        cout << "ERROR - Both hands are not straight flushes. Quitting" << endl;
        EXIT_FAILURE;
    }        
   
} //end evaluateStraightFlush

void evaluateFOAK(){ 

    // Hand One
    Card handOne_cardOne("K", "S");
    Card handOne_cardTwo("K", "H");
    Card handOne_cardThree("K", "C");
    Card handOne_cardFour("K", "D");    
    Card handOne_cardFive("3", "H");

    // Hand Two
    Card handTwo_cardOne("7", "H");
    Card handTwo_cardTwo("7", "D");
    Card handTwo_cardThree("7", "S");
    Card handTwo_cardFour("7", "C");    
    Card handTwo_cardFive("Q", "H");

    // Hand Three
    Card handThree_cardOne("7", "H");
    Card handThree_cardTwo("7", "D");
    Card handThree_cardThree("7", "S");
    Card handThree_cardFour("7", "C");    
    Card handThree_cardFive("10", "H");        

    // Hand Four
    Card handFour_cardOne("4", "C");
    Card handFour_cardTwo("4", "S");
    Card handFour_cardThree("4", "D");
    Card handFour_cardFour("4", "H");    
    Card handFour_cardFive("9", "C");

    // Hand Five
    Card handFive_cardOne("4", "C");
    Card handFive_cardTwo("4", "S");
    Card handFive_cardThree("4", "D");
    Card handFive_cardFour("4", "H");    
    Card handFive_cardFive("9", "D");

    // Create arrays of the cards
    array<Card, 5> handOneCards{handOne_cardOne, handOne_cardTwo, 
                           handOne_cardThree, handOne_cardFour,
                           handOne_cardFive};

    array<Card, 5> handTwoCards{handTwo_cardOne, handTwo_cardTwo, 
                           handTwo_cardThree, handTwo_cardFour,
                           handTwo_cardFive};

    array<Card, 5> handThreeCards{handThree_cardOne, handThree_cardTwo, 
                           handThree_cardThree, handThree_cardFour,
                           handThree_cardFive};

    array<Card, 5> handFourCards{handFour_cardOne, handFour_cardTwo, 
                           handFour_cardThree, handFour_cardFour,
                           handFour_cardFive};

    array<Card, 5> handFiveCards{handFive_cardOne, handFive_cardTwo, 
                           handFive_cardThree, handFive_cardFour,
                           handFive_cardFive};

    // Create hand objects
    Hand handOne(handOneCards);
    Hand handTwo(handTwoCards);
    Hand handThree(handThreeCards);
    Hand handFour(handFourCards);
    Hand handFive(handFiveCards);


    // Comparison one
    if(handOne.getFOAK() != 0 && handTwo.getFOAK() != 0){
        compareHands(handOne, handTwo);
    }else{
        cout << "ERROR - Both hands are not four of a kind. Quitting" << endl;
        EXIT_FAILURE;
    } //end else

    // Comparison two
    if(handTwo.getFOAK() != 0  && handThree.getFOAK() != 0 ){
        compareHands(handTwo, handThree);
    }else{
        cout << "ERROR - Both hands are not four of a kind. Quitting" << endl;
        EXIT_FAILURE;
    } //end else

    // Comparison three
    if(handFour.getFOAK() != 0  && handFive.getFOAK() != 0 ){
        compareHands(handFour, handFive);
    }else{
        cout << "ERROR - Both hands are not four of a kind. Quitting" << endl;
        EXIT_FAILURE;
    }//end else        
   
} //end evaluateFOAK

void compareFH(Hand handOne, Hand handTwo){
    // Comparison one
    if(handOne.getFullHouse() == true && handTwo.getFullHouse() == true){
        // Determine the values for the three of a kind and pairs for each hand
        int handOneThree;
        int handTwoThree;
        int handOnePair;
        int handTwoPair;

        // Get those values
        handOneThree = handOne.getTOAK();
        handOnePair = handOne.getPair();
        handTwoThree = handTwo.getTOAK();
        handTwoPair = handTwo.getPair();

        // If hand one's three of a kind is bigger, it wins
        if(handOneThree > handTwoThree){
            handOne.printHand();
            cout << "ranks higher than ";
            handTwo.printHand();
            cout << endl;        
        } //end if

        // If hand two's three of a kind is bigger, it wins
        else if (handTwoThree > handOneThree){
            handTwo.printHand();
            cout << "ranks higher than ";
            handOne.printHand();
            cout << endl;
        }//endif

        // Otherwise, they are equal
        else{
            //Now check the pairs
            // If hand one's pair is bigger, it wins
            if(handOnePair > handTwoPair){
                handOne.printHand();
                cout << "ranks higher than ";
                handTwo.printHand();
                cout << endl;              
            } //end if

            // If hand two's pair is bigger, it wins
            else if(handTwoPair > handOnePair){
                handTwo.printHand();
                cout << "ranks higher than ";
                handOne.printHand();
                cout << endl;
            } //end if

            // Otherwise, the hands are equal
            else{
                // So then print out that they are equal in value
                handOne.printHand();
                cout << "and ";
                handTwo.printHand();
                cout << "are of equal rank " << endl;             
            } //end else
        } //end parent else

    // Hands weren't straight flushes
    }else{
        cout << "ERROR - Both hands are not full houses. Quitting" << endl;
        EXIT_FAILURE;
    }    
}

void evaluateFH(){

    // Hand One
    Card handOne_cardOne("8", "S");
    Card handOne_cardTwo("8", "D");
    Card handOne_cardThree("8", "H");
    Card handOne_cardFour("7", "D");    
    Card handOne_cardFive("7", "C");

    // Hand Two
    Card handTwo_cardOne("4", "D");
    Card handTwo_cardTwo("4", "S");
    Card handTwo_cardThree("4", "C");
    Card handTwo_cardFour("9", "D");    
    Card handTwo_cardFive("9", "C");

    // Hand Three
    Card handThree_cardOne("4", "D");
    Card handThree_cardTwo("4", "S");
    Card handThree_cardThree("4", "C");
    Card handThree_cardFour("5", "C");    
    Card handThree_cardFive("5", "D");    

    // Hand Four
    Card handFour_cardOne("K", "C");
    Card handFour_cardTwo("K", "S");
    Card handFour_cardThree("K", "D");
    Card handFour_cardFour("J", "S");    
    Card handFour_cardFive("J", "C");

    // Hand Five
    Card handFive_cardOne("K", "C");
    Card handFive_cardTwo("K", "H");
    Card handFive_cardThree("K", "D");
    Card handFive_cardFour("J", "C");    
    Card handFive_cardFive("J", "J");

    // Create arrays of the cards
    array<Card, 5> handOneCards{handOne_cardOne, handOne_cardTwo, 
                           handOne_cardThree, handOne_cardFour,
                           handOne_cardFive};

    array<Card, 5> handTwoCards{handTwo_cardOne, handTwo_cardTwo, 
                           handTwo_cardThree, handTwo_cardFour,
                           handTwo_cardFive};

    array<Card, 5> handThreeCards{handThree_cardOne, handThree_cardTwo, 
                           handThree_cardThree, handThree_cardFour,
                           handThree_cardFive};

    array<Card, 5> handFourCards{handFour_cardOne, handFour_cardTwo, 
                           handFour_cardThree, handFour_cardFour,
                           handFour_cardFive};

    array<Card, 5> handFiveCards{handFive_cardOne, handFive_cardTwo, 
                           handFive_cardThree, handFive_cardFour,
                           handFive_cardFive};

    // Create Hand objects
    Hand handOne(handOneCards);
    Hand handTwo(handTwoCards);
    Hand handThree(handThreeCards);
    Hand handFour(handFourCards);
    Hand handFive(handFiveCards);


    compareFH(handOne, handTwo);
    compareFH(handTwo, handThree);
    compareFH(handFour, handFive);
   
}//end evaluateFH

void evaluateFlush(){ 

    // Hand One
    Card handOne_cardOne("K", "D");
    Card handOne_cardTwo("J", "D");
    Card handOne_cardThree("9", "D");
    Card handOne_cardFour("6", "D");    
    Card handOne_cardFive("4", "D");

    // Hand Two
    Card handTwo_cardOne("Q", "C");
    Card handTwo_cardTwo("J", "C");
    Card handTwo_cardThree("7", "C");
    Card handTwo_cardFour("6", "C");    
    Card handTwo_cardFive("5", "C");

    // Hand Three
    Card handThree_cardOne("J", "H");
    Card handThree_cardTwo("10", "H");
    Card handThree_cardThree("9", "H");
    Card handThree_cardFour("4", "H");    
    Card handThree_cardFive("2", "H");        

    // Hand Four
    Card handFour_cardOne("J", "S");
    Card handFour_cardTwo("10", "S");
    Card handFour_cardThree("8", "S");
    Card handFour_cardFour("6", "S");    
    Card handFour_cardFive("3", "S");

    // Hand Five
    Card handFive_cardOne("J", "H");
    Card handFive_cardTwo("10", "H");
    Card handFive_cardThree("8", "H");
    Card handFive_cardFour("4", "H");    
    Card handFive_cardFive("3", "H");

    // Hand Six
    Card handSix_cardOne("J", "C");
    Card handSix_cardTwo("10", "C");
    Card handSix_cardThree("8", "C");
    Card handSix_cardFour("4", "C");    
    Card handSix_cardFive("2", "C");   

    // Hand Seven
    Card handSeven_cardOne("10", "D");
    Card handSeven_cardTwo("8", "D");
    Card handSeven_cardThree("7", "D");
    Card handSeven_cardFour("6", "D");    
    Card handSeven_cardFive("5", "D");

    // Hand Eight
    Card handEight_cardOne("10", "S");
    Card handEight_cardTwo("8", "S");
    Card handEight_cardThree("7", "S");
    Card handEight_cardFour("6", "S");    
    Card handEight_cardFive("5", "S");

    // Create arrays of the cards
    array<Card, 5> handOneCards{handOne_cardOne, handOne_cardTwo, 
                           handOne_cardThree, handOne_cardFour,
                           handOne_cardFive};

    array<Card, 5> handTwoCards{handTwo_cardOne, handTwo_cardTwo, 
                           handTwo_cardThree, handTwo_cardFour,
                           handTwo_cardFive};

    array<Card, 5> handThreeCards{handThree_cardOne, handThree_cardTwo, 
                           handThree_cardThree, handThree_cardFour,
                           handThree_cardFive};

    array<Card, 5> handFourCards{handFour_cardOne, handFour_cardTwo, 
                           handFour_cardThree, handFour_cardFour,
                           handFour_cardFive};

    array<Card, 5> handFiveCards{handFive_cardOne, handFive_cardTwo, 
                           handFive_cardThree, handFive_cardFour,
                           handFive_cardFive};

    array<Card, 5> handSixCards{handSix_cardOne, handSix_cardTwo, 
                           handSix_cardThree, handSix_cardFour,
                           handSix_cardFive};

    array<Card, 5> handSevenCards{handSeven_cardOne, handSeven_cardTwo, 
                           handSeven_cardThree, handSeven_cardFour,
                           handSeven_cardFive};

    array<Card, 5> handEightCards{handEight_cardOne, handEight_cardTwo, 
                           handEight_cardThree, handEight_cardFour,
                           handEight_cardFive};                                                                                     

    // Create hand objects
    Hand handOne(handOneCards);
    Hand handTwo(handTwoCards);
    Hand handThree(handThreeCards);
    Hand handFour(handFourCards);
    Hand handFive(handFiveCards);
    Hand handSix(handSixCards);
    Hand handSeven(handSevenCards);
    Hand handEight(handEightCards);

    // Comparison one
    if(handOne.getFlush() != 0 && handTwo.getFlush() != 0){
        compareHands(handOne, handTwo);
    }else{
        cout << "ERROR - Both Hands are not flushes. Quitting" << endl;
        EXIT_FAILURE;
    } //end else

    // Comparison two
    if(handTwo.getFlush() != 0  && handThree.getFlush() != 0 ){
        compareHands(handTwo, handThree);
    }else{
        cout << "ERROR - Both Hands are not flushes. Quitting" << endl;
        EXIT_FAILURE;
    } //end else

    // Comparison three
    if(handThree.getFlush() != 0  && handFour.getFlush() != 0 ){
        compareHands(handThree, handFour);
    }else{
        cout << "ERROR - Both Hands are not flushes. Quitting" << endl;
        EXIT_FAILURE;
    }//end else

    // Comparison four
    if(handFour.getFlush() != 0  && handFive.getFlush() != 0 ){
        compareHands(handFour, handFive);
    }else{
        cout << "ERROR - Both Hands are not flushes. Quitting" << endl;
        EXIT_FAILURE;
    }//end else   

    // Comparison five
    if(handFive.getFlush() != 0  && handSix.getFlush() != 0 ){
        compareHands(handFive, handSix);
    }else{
        cout << "ERROR - Both Hands are not flushes. Quitting" << endl;
        EXIT_FAILURE;
    }//end else   

    // Comparison six
    if(handSeven.getFlush() != 0  && handEight.getFlush() != 0 ){
        compareHands(handSeven, handEight);
    }else{
        cout << "ERROR - Both Hands are not flushes. Quitting" << endl;
        EXIT_FAILURE;
    }//end else      
   
} //end evaluateFlush

void evaluateStraight(){
    // Hand One
    Card handOne_cardOne("J", "H");
    Card handOne_cardTwo("10", "H");
    Card handOne_cardThree("9", "C");
    Card handOne_cardFour("8", "S");    
    Card handOne_cardFive("7", "H");

    // Hand Two
    Card handTwo_cardOne("10", "S");
    Card handTwo_cardTwo("9", "S");
    Card handTwo_cardThree("8", "C");
    Card handTwo_cardFour("7", "H");    
    Card handTwo_cardFive("6", "S");

    // Hand Three
    Card handThree_cardOne("6", "C");
    Card handThree_cardTwo("5", "S");
    Card handThree_cardThree("4", "H");
    Card handThree_cardFour("3", "S");    
    Card handThree_cardFive("2", "D");        

    // Hand Four
    Card handFour_cardOne("9", "C");
    Card handFour_cardTwo("8", "C");
    Card handFour_cardThree("7", "C");
    Card handFour_cardFour("6", "D");    
    Card handFour_cardFive("5", "D");

    // Hand Five
    Card handFive_cardOne("9", "S");
    Card handFive_cardTwo("8", "S");
    Card handFive_cardThree("7", "S");
    Card handFive_cardFour("6", "H");    
    Card handFive_cardFive("5", "H");

    // Create arrays of the cards
    array<Card, 5> handOneCards{handOne_cardOne, handOne_cardTwo, 
                           handOne_cardThree, handOne_cardFour,
                           handOne_cardFive};

    array<Card, 5> handTwoCards{handTwo_cardOne, handTwo_cardTwo, 
                           handTwo_cardThree, handTwo_cardFour,
                           handTwo_cardFive};

    array<Card, 5> handThreeCards{handThree_cardOne, handThree_cardTwo, 
                           handThree_cardThree, handThree_cardFour,
                           handThree_cardFive};

    array<Card, 5> handFourCards{handFour_cardOne, handFour_cardTwo, 
                           handFour_cardThree, handFour_cardFour,
                           handFour_cardFive};

    array<Card, 5> handFiveCards{handFive_cardOne, handFive_cardTwo, 
                           handFive_cardThree, handFive_cardFour,
                           handFive_cardFive};

    // Create hand objects
    Hand handOne(handOneCards);
    Hand handTwo(handTwoCards);
    Hand handThree(handThreeCards);
    Hand handFour(handFourCards);
    Hand handFive(handFiveCards);

    // Comparison one
    if(handOne.getStraight() != 0 && handTwo.getStraight() != 0){
        compareHands(handOne, handTwo);
    }else{
        cout << "ERROR - Both hands are straights. Quitting" << endl;
        EXIT_FAILURE;
    } //end else

    // Comparison two
    if(handTwo.getStraight() != 0  && handThree.getStraight() != 0 ){
        compareHands(handTwo, handThree);
    }else{
        cout << "ERROR - Both hands are not straights. Quitting" << endl;
        EXIT_FAILURE;
    } //end else

    // Comparison three
    if(handFour.getStraight() != 0  && handFive.getStraight() != 0 ){
        compareHands(handFour, handFive);
    }else{
        cout << "ERROR - Both hands are not straights. Quitting" << endl;
        EXIT_FAILURE;
    }//end else        
   
} //end evaluateStraight

void compareTOAK(Hand handOne, Hand handTwo){
// Check to ensure both hands are three of a kind
    if(handOne.getTOAK() != 0 && handTwo.getTOAK() != 0){
        // If so, initialize and assign some data
        int handOneThree = handOne.getTOAK();
        int handTwoThree = handTwo.getTOAK();
        // These variables are for the high and low cards
        // that are NOT part of the three of a kind
        int handOneHigh;
        int handOneLow;
        int handTwoHigh;
        int handTwoLow;
        array<int, 5> handOneVals = handOne.getCardVals();
        array<int, 5> handTwoVals = handTwo.getCardVals();

        // The first and second cards that are not in the three of a kind
        int handOneFirst = 0;
        int handOneSecond = 0;
        for (unsigned int i = 0; i < handOneVals.size(); i++){
            // cout << "Comparing: " << handOneVals[i] << " and " << handOneThree << endl;            
            if (handOneVals[i] != handOneThree){
                handOneFirst = handOneVals[i];
                break;
            } //end if
        } //end for

        for (unsigned int i = 0; i < handOneVals.size(); i++){
            if(handOneVals[i] != handOneThree && handOneVals[i] != handOneFirst){
                handOneSecond = handOneVals[i];
                break;
            } //end if
        } //end for

        // The first and second cards that are not in the three of a kind
        int handTwoFirst = 0;
        int handTwoSecond = 0;
        for (unsigned int i = 0; i < handTwoVals.size(); i++){
            if (handTwoVals[i] != handTwoThree){
                handTwoFirst = handTwoVals[i];
                break;
            } //end if
        } //end for

        for (unsigned int i = 0; i < handTwoVals.size(); i++){
            if(handTwoVals[i] != handTwoThree && handTwoVals[i] != handTwoFirst){
                handTwoSecond = handTwoVals[i];
            } //end if
        } //end for

        // Check if hand One's three of a kind is higher than handTwo
        // If so, alert the user
        if(handOneThree > handTwoThree){
            handOne.printHand();
            cout << "ranks higher than ";
            handTwo.printHand();
            cout << endl; 
        } // end if
        
        // If not, check if hand Two's Three of a kind is higher
        // than hand One's. If so, alert the user
        else if(handTwoThree > handOneThree){
            handOne.printHand();
            cout << "ranks higher than ";
            handTwo.printHand();
            cout << endl;            
        } //end else if

        // Otherwise, they are equal, so check their next highest card
        else{
            if(max(handOneFirst, handOneSecond) > max(handTwoFirst, handTwoSecond)){
                handOne.printHand();
                cout << "ranks higher than ";
                handTwo.printHand();
                cout << endl;                
            } //end if

            else if(max(handOneFirst, handOneSecond) < max(handTwoFirst, handTwoSecond)){
                handOne.printHand();
                cout << "ranks higher than ";
                handTwo.printHand();
                cout << endl;                    
            } //end else if

            // At this point, the three of a kind next highest are equal, so check the last card
            else{                
                // If the first hand is higher
                if(min(handOneFirst, handOneSecond) > min(handTwoFirst, handTwoSecond)){
                    handOne.printHand();
                    cout << "ranks higher than ";
                    handTwo.printHand();
                    cout << endl;                
                } //end if

                // If the second hand is higher
                else if(min(handOneFirst, handOneSecond) < min(handTwoFirst, handTwoSecond)){
                    handOne.printHand();
                    cout << "ranks higher than ";
                    handTwo.printHand();
                    cout << endl;                    
                } //end else if

                // Otherwise they are equal
                else{
                    handOne.printHand();
                    cout << "and ";
                    handTwo.printHand();
                    cout << "are of equal rank ";
                    cout << endl;                     
                } //end else
            } //end else
        } //end else
    // They both weren't TOAK
    }else{
        cout << "ERROR - Both hands are not TOAK. Quitting" << endl;
        EXIT_FAILURE;        
    } //end else

} //end compareTOAK

// This function evaluates the testing cases for Three Of A Kind
void evaluateTOAK(){

    // Hand One
    Card handOne_cardOne("6", "H");
    Card handOne_cardTwo("6", "D");
    Card handOne_cardThree("6", "S");
    Card handOne_cardFour("Q", "C");    
    Card handOne_cardFive("4", "S");

    // Hand Two
    Card handTwo_cardOne("3", "D");
    Card handTwo_cardTwo("3", "C");
    Card handTwo_cardThree("3", "C");
    Card handTwo_cardFour("K", "S");    
    Card handTwo_cardFive("2", "S");

    // Hand Three
    Card handThree_cardOne("3", "D");
    Card handThree_cardTwo("3", "S");
    Card handThree_cardThree("3", "C");
    Card handThree_cardFour("J", "C");    
    Card handThree_cardFive("7", "H");        

    // Hand Four
    Card handFour_cardOne("3", "H");
    Card handFour_cardTwo("3", "S");
    Card handFour_cardThree("3", "C");
    Card handFour_cardFour("J", "S");    
    Card handFour_cardFive("5", "D");

    // Hand Five
    Card handFive_cardOne("9", "S");
    Card handFive_cardTwo("9", "H");
    Card handFive_cardThree("9", "D");
    Card handFive_cardFour("10", "D");    
    Card handFive_cardFive("8", "H");

    // Hand Six
    Card handSix_cardOne("9", "S");
    Card handSix_cardTwo("9", "H");
    Card handSix_cardThree("9", "D");
    Card handSix_cardFour("10", "D");    
    Card handSix_cardFive("8", "D");

    // Create arrays of the cards
    array<Card, 5> handOneCards{handOne_cardOne, handOne_cardTwo, 
                           handOne_cardThree, handOne_cardFour,
                           handOne_cardFive};

    array<Card, 5> handTwoCards{handTwo_cardOne, handTwo_cardTwo, 
                           handTwo_cardThree, handTwo_cardFour,
                           handTwo_cardFive};

    array<Card, 5> handThreeCards{handThree_cardOne, handThree_cardTwo, 
                           handThree_cardThree, handThree_cardFour,
                           handThree_cardFive};

    array<Card, 5> handFourCards{handFour_cardOne, handFour_cardTwo, 
                           handFour_cardThree, handFour_cardFour,
                           handFour_cardFive};

    array<Card, 5> handFiveCards{handFive_cardOne, handFive_cardTwo, 
                           handFive_cardThree, handFive_cardFour,
                           handFive_cardFive};

    array<Card, 5> handSixCards{handSix_cardOne, handSix_cardTwo, 
                           handSix_cardThree, handSix_cardFour,
                           handSix_cardFive};
    // Create hand objects
    Hand handOne(handOneCards);
    Hand handTwo(handTwoCards);
    Hand handThree(handThreeCards);
    Hand handFour(handFourCards);
    Hand handFive(handFiveCards);
    Hand handSix(handSixCards);

    // Compare the hands
    compareTOAK(handOne, handTwo);
    compareTOAK(handTwo, handThree);
    compareTOAK(handThree, handFour);
    compareTOAK(handFive, handSix);
} //end evaluateTOAK

// This function compares two two pair hands
void compareTwoPair(Hand handOne, Hand handTwo){
    // First, ensure that both pairs are two hands
    if(handOne.getTwoPair() == true && handTwo.getTwoPair() == true){
        // Create a 2-item array of the two pair values
        array<int, 2> handOnePairs = handOne.getTwoPairValues();
        array<int, 2> handTwoPairs = handTwo.getTwoPairValues();
        
        // Get the values of the ranks of the cards in the two hands
        array<int, 5> handOneVals = handOne.getCardVals();
        array<int, 5> handTwoVals = handTwo.getCardVals();

        // Create the high and low of the pairs for each hand
        int handOnePairHigh = max(handOnePairs[0], handOnePairs[1]);
        int handOnePairLow = min(handOnePairs[0], handOnePairs[1]);
        int handTwoPairHigh = max(handTwoPairs[0], handTwoPairs[1]);
        int handTwoPairLow = min(handTwoPairs[0], handTwoPairs[1]);

        // Create ints to hold the value of each hand that isn't one of the pairs
        int handOneNotPairVal;
        int handTwoNotPairVal;

        // Loop through the hands and figure out which value isn't a pair
        for(unsigned int i = 0; i < handOneVals.size(); i++){
            if(handOneVals[i] != handOnePairHigh && handOneVals[i] != handOnePairLow){
                handOneNotPairVal = handOneVals[i];
            } //end if

            if(handTwoVals[i] != handTwoPairHigh && handTwoVals[i] != handTwoPairLow){
                handTwoNotPairVal = handTwoVals[i];
            }//end if
        } //end for 

        // Compare the high of the two pairs
        if(handOnePairHigh > handTwoPairHigh){
            handOne.printHand();
            cout << "ranks higher than ";
            handTwo.printHand();            
            cout << endl;              
        } //end if

        else if(handOnePairHigh < handTwoPairHigh){
            handTwo.printHand();
            cout << "ranks higher than ";
            handOne.printHand();
            cout << endl;               
        } //end else if

        // If the highs are equal, compare the lows
        else{
            if(handOnePairLow > handTwoPairLow){
                handOne.printHand();
                cout << "ranks higher than ";
                handTwo.printHand();
                cout << endl;                   
            } //end if

            else if(handOnePairLow < handTwoPairLow) {
                handTwo.printHand();
                cout << "ranks higher than ";
                handOne.printHand();
                cout << endl;   
            } //end else if

            // If both pairs are equal, compare the last card
            else{
                if(handOneNotPairVal > handTwoNotPairVal){
                    handOne.printHand();
                    cout << "ranks higher than ";
                    handTwo.printHand();
                    cout << endl;                        
                } // end if

                else if(handOneNotPairVal < handTwoNotPairVal){
                    handTwo.printHand();
                    cout << "ranks higher than ";
                    handOne.printHand();
                    cout << endl;                       
                } //end else if

                // Otherwise, everything is equal
                else{
                    handOne.printHand();
                    cout << "and ";
                    handTwo.printHand();
                    cout << "are of equal rank ";
                    cout << endl;  
                } //end else
            } //end else
        }//end else  
    }else{
        cout << "ERROR - Both hands are not two pairs. Quitting" << endl;
        EXIT_FAILURE;        
    } //end else
}

// This function evaluates the two pair hands
void evaluateTwoPair(){
    // Hand One
    Card handOne_cardOne("10", "D");
    Card handOne_cardTwo("10", "S");
    Card handOne_cardThree("2", "S");
    Card handOne_cardFour("2", "C");    
    Card handOne_cardFive("K", "C");

    // Hand Two
    Card handTwo_cardOne("5", "C");
    Card handTwo_cardTwo("5", "S");
    Card handTwo_cardThree("4", "D");
    Card handTwo_cardFour("4", "H");    
    Card handTwo_cardFive("10", "H");

    // Hand Three
    Card handThree_cardOne("5", "C");
    Card handThree_cardTwo("5", "S");
    Card handThree_cardThree("3", "C");
    Card handThree_cardFour("3", "D");    
    Card handThree_cardFive("Q", "S");        

    // Hand Four
    Card handFour_cardOne("5", "C");
    Card handFour_cardTwo("5", "S");
    Card handFour_cardThree("3", "C");
    Card handFour_cardFour("3", "D");    
    Card handFour_cardFive("J", "S");

    // Hand Five
    Card handFive_cardOne("K", "D");
    Card handFive_cardTwo("K", "S");
    Card handFive_cardThree("7", "D");
    Card handFive_cardFour("7", "H");    
    Card handFive_cardFive("8", "H");

    // Hand Six
    Card handSix_cardOne("K", "C");
    Card handSix_cardTwo("K", "S");
    Card handSix_cardThree("7", "C");
    Card handSix_cardFour("7", "H");    
    Card handSix_cardFive("8", "C"); 

    // Create arrays of the cards
    array<Card, 5> handOneCards{handOne_cardOne, handOne_cardTwo, 
                           handOne_cardThree, handOne_cardFour,
                           handOne_cardFive};

    array<Card, 5> handTwoCards{handTwo_cardOne, handTwo_cardTwo, 
                           handTwo_cardThree, handTwo_cardFour,
                           handTwo_cardFive};

    array<Card, 5> handThreeCards{handThree_cardOne, handThree_cardTwo, 
                           handThree_cardThree, handThree_cardFour,
                           handThree_cardFive};

    array<Card, 5> handFourCards{handFour_cardOne, handFour_cardTwo, 
                           handFour_cardThree, handFour_cardFour,
                           handFour_cardFive};

    array<Card, 5> handFiveCards{handFive_cardOne, handFive_cardTwo, 
                           handFive_cardThree, handFive_cardFour,
                           handFive_cardFive};

    array<Card, 5> handSixCards{handSix_cardOne, handSix_cardTwo, 
                           handSix_cardThree, handSix_cardFour,
                           handSix_cardFive};
                        
    // Create hand objects
    Hand handOne(handOneCards);
    Hand handTwo(handTwoCards);
    Hand handThree(handThreeCards);
    Hand handFour(handFourCards);
    Hand handFive(handFiveCards);
    Hand handSix(handSixCards);

    // Compare the hands
    compareTwoPair(handOne, handTwo);
    compareTwoPair(handTwo, handThree);
    compareTwoPair(handThree, handFour);
    compareTwoPair(handFive, handSix);
}// end evaluateTwoPair

// This function compares two pairs of hands of one pair
void compareOnePair(Hand handOne, Hand handTwo){
    // Ensure both hands are one pair
    if(handOne.getPair() != 0 && handTwo.getPair() != 0){
        // Get the pair value
        int handOnePairVal = handOne.getPair();
        int handTwoPairVal = handTwo.getPair();
        // Create arrays of the rank values of the cards
        array<int, 5> handOneVals = handOne.getCardVals();
        array<int, 5> handTwoVals = handTwo.getCardVals();
        // Create vectors for the remaining values of the hands
        vector<int> handOneRemainingVals;
        vector<int> handTwoRemainingVals;

        // Loop through the hands, and fill the remaining values for each
        for(unsigned int i = 0; i < handOneVals.size(); i++){
            if (handOneVals[i] != handOnePairVal){
                handOneRemainingVals.push_back(handOneVals[i]);
            } //end if
            if (handTwoVals[i] != handTwoPairVal){
                handTwoRemainingVals.push_back(handTwoVals[i]);
            } //end if
        } //end for
        
        // Sort the remaining values
        sort(handOneRemainingVals.begin(), handOneRemainingVals.end(), greater<int>());
        sort(handTwoRemainingVals.begin(), handTwoRemainingVals.end(), greater<int>());

        // Compare the pairs of each hand
        if(handOnePairVal > handTwoPairVal){
            handOne.printHand();
            cout << "ranks higher than ";
            handTwo.printHand();            
            cout << endl;              
        } //end if

        else if(handOnePairVal < handTwoPairVal){
            handTwo.printHand();
            cout << "ranks higher than ";
            handOne.printHand();            
            cout << endl;  
        } //end if

        // If the pairs are equal
        else{
            // Create a bool to determine if all values are equal
            int isEqual = true;
            // Loop through the remaining values
            for (unsigned int i = 0; i < handOneRemainingVals.size(); i++){
                // If hand one is bigger, it wins
                if (handOneRemainingVals[i] > handTwoRemainingVals[i]){
                    isEqual = false;
                    handOne.printHand();
                    cout << "ranks higher than ";
                    handTwo.printHand();            
                    cout << endl;
                    break;                   
                } // end

                // If hand two is bigger, it wins
                else if(handOneRemainingVals[i] < handTwoRemainingVals[i]){
                    isEqual = false;
                    handTwo.printHand();
                    cout << "ranks higher than ";
                    handOne.printHand();            
                    cout << endl;                  
                    break;
                } //end else if

                // If they are equal, continue
                else{
                    continue;
                } //end else
            } //end the loop

            // If both hands are equal, alert
            if(isEqual == true){
                handOne.printHand();
                cout << "and ";
                handTwo.printHand();
                cout << "are of equal rank ";
                cout << endl;  
            } //end if
        } //end else
    }else{
        cout << "ERROR - Both hands are not two pairs. Quitting" << endl;
        EXIT_FAILURE;  
    } //end else
}//end compareOnePair

void evaluateOnePair(){
    // Hand One
    Card handOne_cardOne("9", "C");
    Card handOne_cardTwo("9", "D");
    Card handOne_cardThree("Q", "S");
    Card handOne_cardFour("J", "H");    
    Card handOne_cardFive("5", "H");

    // Hand Two
    Card handTwo_cardOne("6", "D");
    Card handTwo_cardTwo("6", "H");
    Card handTwo_cardThree("K", "S");
    Card handTwo_cardFour("7", "H");    
    Card handTwo_cardFive("4", "C");

    // Hand Three
    Card handThree_cardOne("6", "D");
    Card handThree_cardTwo("6", "H");
    Card handThree_cardThree("Q", "H");
    Card handThree_cardFour("J", "S");    
    Card handThree_cardFive("2", "C");        

    // Hand Four
    Card handFour_cardOne("6", "D");
    Card handFour_cardTwo("6", "H");
    Card handFour_cardThree("Q", "S");
    Card handFour_cardFour("8", "C");    
    Card handFour_cardFive("7", "D");

    // Hand Five
    Card handFive_cardOne("6", "D");
    Card handFive_cardTwo("6", "H");
    Card handFive_cardThree("Q", "D");
    Card handFive_cardFour("8", "H");    
    Card handFive_cardFive("3", "S");

    // Hand Six
    Card handSix_cardOne("8", "S");
    Card handSix_cardTwo("8", "D");
    Card handSix_cardThree("10", "H");
    Card handSix_cardFour("6", "C");    
    Card handSix_cardFive("5", "S");

    // Hand Seven
    Card handSeven_cardOne("8", "H");
    Card handSeven_cardTwo("8", "C");
    Card handSeven_cardThree("10", "C");
    Card handSeven_cardFour("6", "S");    
    Card handSeven_cardFive("5", "C");    

    // Create arrays of the cards
    array<Card, 5> handOneCards{handOne_cardOne, handOne_cardTwo, 
                           handOne_cardThree, handOne_cardFour,
                           handOne_cardFive};

    array<Card, 5> handTwoCards{handTwo_cardOne, handTwo_cardTwo, 
                           handTwo_cardThree, handTwo_cardFour,
                           handTwo_cardFive};

    array<Card, 5> handThreeCards{handThree_cardOne, handThree_cardTwo, 
                           handThree_cardThree, handThree_cardFour,
                           handThree_cardFive};

    array<Card, 5> handFourCards{handFour_cardOne, handFour_cardTwo, 
                           handFour_cardThree, handFour_cardFour,
                           handFour_cardFive};

    array<Card, 5> handFiveCards{handFive_cardOne, handFive_cardTwo, 
                           handFive_cardThree, handFive_cardFour,
                           handFive_cardFive};

    array<Card, 5> handSixCards{handSix_cardOne, handSix_cardTwo, 
                           handSix_cardThree, handSix_cardFour,
                           handSix_cardFive};

    array<Card, 5> handSevenCards{handSeven_cardOne, handSeven_cardTwo, 
                           handSeven_cardThree, handSeven_cardFour,
                           handSeven_cardFive};                           
    
    // Create hand objects
    Hand handOne(handOneCards);
    Hand handTwo(handTwoCards);
    Hand handThree(handThreeCards);
    Hand handFour(handFourCards);
    Hand handFive(handFiveCards);
    Hand handSix(handSixCards);
    Hand handSeven(handSevenCards);

    compareOnePair(handOne, handTwo);
    compareOnePair(handTwo, handThree);
    compareOnePair(handThree, handFour);
    compareOnePair(handFour, handFive);
    compareOnePair(handSix, handSeven); 
} //end evaluateOnePair

void evaluateHighCard(){
    // Hand One
    Card handOne_cardOne("K", "S");
    Card handOne_cardTwo("6", "C");
    Card handOne_cardThree("5", "H");
    Card handOne_cardFour("3", "D");    
    Card handOne_cardFive("2", "S");

    // Hand Two
    Card handTwo_cardOne("Q", "S");
    Card handTwo_cardTwo("J", "D");
    Card handTwo_cardThree("6","C");
    Card handTwo_cardFour("5", "H");    
    Card handTwo_cardFive("3", "C");

    // Hand Three
    Card handThree_cardOne("Q", "S");
    Card handThree_cardTwo("10", "D");
    Card handThree_cardThree("8", "C");
    Card handThree_cardFour("7", "D");    
    Card handThree_cardFive("4", "S");        

    // Hand Four
    Card handFour_cardOne("Q", "H");
    Card handFour_cardTwo("10", "H");
    Card handFour_cardThree("7", "S");
    Card handFour_cardFour("6", "H");    
    Card handFour_cardFive("4", "S");

    // Hand Five
    Card handFive_cardOne("Q", "C");
    Card handFive_cardTwo("10", "C");
    Card handFive_cardThree("7", "D");
    Card handFive_cardFour("5", "C");    
    Card handFive_cardFive("4", "D");

    // Hand Six
    Card handSix_cardOne("Q", "H");
    Card handSix_cardTwo("10", "D");
    Card handSix_cardThree("7", "D");
    Card handSix_cardFour("5", "S");    
    Card handSix_cardFive("2", "H");

    // Hand Seven
    Card handSeven_cardOne("10", "C");
    Card handSeven_cardTwo("8", "S");
    Card handSeven_cardThree("7", "S");
    Card handSeven_cardFour("6", "H");    
    Card handSeven_cardFive("4", "D");

    // Hand Eight
    Card handEight_cardOne("10", "D");
    Card handEight_cardTwo("8", "D");
    Card handEight_cardThree("7", "S");
    Card handEight_cardFour("6", "C");    
    Card handEight_cardFive("4", "C");          

    // Create arrays of the cards
    array<Card, 5> handOneCards{handOne_cardOne, handOne_cardTwo, 
                           handOne_cardThree, handOne_cardFour,
                           handOne_cardFive};

    array<Card, 5> handTwoCards{handTwo_cardOne, handTwo_cardTwo, 
                           handTwo_cardThree, handTwo_cardFour,
                           handTwo_cardFive};

    array<Card, 5> handThreeCards{handThree_cardOne, handThree_cardTwo, 
                           handThree_cardThree, handThree_cardFour,
                           handThree_cardFive};

    array<Card, 5> handFourCards{handFour_cardOne, handFour_cardTwo, 
                           handFour_cardThree, handFour_cardFour,
                           handFour_cardFive};

    array<Card, 5> handFiveCards{handFive_cardOne, handFive_cardTwo, 
                           handFive_cardThree, handFive_cardFour,
                           handFive_cardFive};

    array<Card, 5> handSixCards{handSix_cardOne, handSix_cardTwo, 
                           handSix_cardThree, handSix_cardFour,
                           handSix_cardFive};

    array<Card, 5> handSevenCards{handSeven_cardOne, handSeven_cardTwo, 
                           handSeven_cardThree, handSeven_cardFour,
                           handSeven_cardFive};    

    array<Card, 5> handEightCards{handEight_cardOne, handEight_cardTwo, 
                           handEight_cardThree, handEight_cardFour,
                           handEight_cardFive};        
    
    // Create hand objects
    Hand handOne(handOneCards);
    Hand handTwo(handTwoCards);
    Hand handThree(handThreeCards);
    Hand handFour(handFourCards);
    Hand handFive(handFiveCards);
    Hand handSix(handSixCards);
    Hand handSeven(handSevenCards);
    Hand handEight(handEightCards);

    // Compare the hands
    compareHands(handOne, handTwo);        
    compareHands(handTwo, handThree);
    compareHands(handThree, handFour);
    compareHands(handFour, handFive);
    compareHands(handFive, handSix);
    compareHands(handSeven, handEight);
}