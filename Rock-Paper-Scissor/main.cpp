/* ------------------------------------------------
   prog1RockPaperScissors.cpp
 
   Program #1: Play the game of Paper / Rock / Scissors against the computer.
   Class: CS 141
   Author: Ayna Jain
*/
#include <iostream>    // For cin and cout
#include <cstdlib>     // For rand()
using namespace std;
//-----------------------------------------------------------------------------------------
int main()
{
    // Display Instructions
    cout << "CS 141 Program #1: Rock/Paper/Scissors\n"
         << endl
         << "Welcome to the game of Rock/Paper/Scissors where you play against\n"
         << "the computer.  On each move the computer will choose R, P, or S, then\n"
         << "the user will be prompted for their choice, and then the score will\n"
         << "be updated.  P beats R, R beats S, and S beats P. The score starts\n"
         << "at 0.  Add one if the person wins, subtract one if the computer wins.\n"
         << "The game ends if the score reaches -5 or + 5.\n"
         << "User input of 'x' or 'X' causes the game to exit.\n"
         << endl
         << "Here we go!\n"
         << endl;
    
    int computerChoiceVersion;
    cout << "Select how the computer chooses its move:\n"
         << "1. Always choose Rock\n"
         << "2. Random guess\n"
         << "3. Random guess with graphical score\n"
         << "Enter your choice: ";
    cin >> computerChoiceVersion;
    cout << endl;
  
    char CompChoice = ' ';
    int TieScore = 0;
    int Score = 0;
    char userIn;
    cout << endl;
    int SrNo = 0;
    
    if(computerChoiceVersion == 1){     //if statement for Computer version when choice is always R//
// *** Arvan: Follow the DRY (“Don’t Repeat Yourself) principle.
// *** Arvan: Use of one while loop would have been enough
      while(Score > -5 || Score < 5){
        SrNo += 1;
        CompChoice = 'R';               //Computer Choice for first case when choice is always R//
        cout << SrNo <<". Your move:";
        cin >> userIn;                  //User input//
        userIn = toupper(userIn);       //converting every user Input to Capital letter to satisfy the condition// 
        if(CompChoice==userIn){        
          TieScore = 0;
          cout << "\n   Computer chose R" << endl;
          cout << "   Tie. Score:" << TieScore << endl;
        }
        if(userIn =='P'&&CompChoice == 'R'){
          Score += 1;
          cout << "\n   Computer chose R" << endl; 
          cout << "   User's point. Score: " << Score << endl;
        }
        if(userIn == 'S'&&CompChoice == 'R'){
          Score -= 1;
          cout << "\n   Computer chose R" << endl; 
          cout << "   Computer's point. Score: "<< Score << endl;
        }
        if(userIn == 'X'){                    // If statement for exiting program //
            cout << "\n Exiting program..." << endl;
            if(Score==0)
              cout << "Tie game!" << endl;
            else if(Score>0)
              cout << "User won" << endl;
            else
              cout << "Computer won" << endl;
            cout << endl;
       
            cout << "Ending program..." << endl;
          exit(0);
         }
         if(Score==5 || Score==-5){               // if statement for Checking the max or min score to be 5 or -5 and displaying the winner//
            cout << endl;
            if(Score>0)
              cout << "User wins!" << endl;
            else if(Score<0)
              cout << "Computer wins!" << endl;
            else
              cout << "Tie game!" << endl;
            cout << endl;
       
            cout << "Ending program..." << endl;
             exit(0);
        }
        cout << endl;
     }
    }
    if(computerChoiceVersion == 2){               // if statement for Random choice second choice//
// *** Arvan: Follow the DRY (“Don’t Repeat Yourself) principle.
// *** Arvan: Use of one while loop would have been enough
       while(Score > -5 || Score < 5){              //while loop starts//
      SrNo += 1;
      cout << SrNo <<". Your move:";              //user input//
      cin >> userIn;
      userIn = toupper(userIn);                   //converting user input to 
      int CompNum = rand() % 3;                   //generating random numbers using rand() function//
      if(CompNum == 0){
        char CompChoice = 'R';                    //assigning computer choice to R when random guess is 0//
        if(userIn == CompChoice){
          TieScore -= 1;
          cout << "\n   Computer chose R" << endl;         
          cout << "   Tie. Score:" << TieScore << endl;
        }
        else if(userIn =='P'&&CompChoice == 'R'){
          Score += 1;
          cout << "\n   Computer chose R" << endl;
          cout << "   User's point. Score: " << Score << endl;
        }
        else if(userIn == 'S'&&CompChoice == 'R'){
          Score -= 1;
          cout << "\n   Computer chose R" << endl;
          cout << "   Computer's point. Score: "<< Score << endl;
        }
      }
      else if(CompNum == 1){                     //assigning computer choice with P when random guess is 1//
        char CompChoice = 'P';
        if(userIn == CompChoice){
          TieScore -= 1;
          cout << "\n   Computer chose P" << endl;
          cout << "   Tie. Score:" << TieScore << endl;
        }
        else if(userIn =='R'&&CompChoice == 'P'){
          Score -= 1;
          cout << "\n   Computer chose P" << endl;
          cout << "   Computer's point. Score: "<< Score << endl;
        }
        else if(userIn == 'S'&&CompChoice == 'P'){
          Score += 1;
          cout << "\n   Computer chose P" << endl;
          cout << "   User's point. Score: " << Score << endl;
        }
      }
      else if(CompNum == 2){                     //assigning computer choice with S when random guess is 2//
        char CompChoice = 'S';
        if(userIn == CompChoice){
          TieScore -= 1;
          cout << "\n   Computer chose S" << endl;
          cout << "   Tie. Score:" << TieScore << endl;
        }
        else if(userIn =='R'&&CompChoice == 'S'){
          Score += 1;
          cout << "\n   Computer chose S" << endl;
          cout << "   User's point. Score: " << Score << endl;
        }
        else if(userIn == 'P'&&CompChoice == 'S'){
          Score -= 1;
          cout << "\n   Computer chose S" << endl;
          cout << "   Computer's point. Score: "<< Score << endl;
        }
      }
       if(userIn == 'X'){                       //condition for exiting program//
            cout << "\n Exiting program..." << endl;
            if(Score==0)
              cout << "Tie game!" << endl;
            else if(Score>0)
              cout << "User won" << endl;
            else
              cout << "Computer won" << endl;
            cout << endl;
       
            cout << "Ending program..." << endl;
          exit(0);
         
          }
         if(Score==5 || Score==-5){
            cout << endl;
            if(Score>0)
              cout << "User wins!" << endl;
            else if(Score<0)
              cout << "Computer wins!" << endl;
            else
              cout << "Tie game!" << endl;
            cout << endl;
       
            cout << "Ending program..." << endl;
             exit(0);
        }
        cout << endl;
     }                                                //end of while loop// 
    } 
    if(computerChoiceVersion == 3){                   // if statement for Random choice second choice for graphing the score//
// *** Arvan: Follow the DRY (“Don’t Repeat Yourself) principle.
// *** Arvan: Use of one while loop would have been enough
       while(Score > -5 || Score < 5){                  // while loop starts//
      SrNo += 1;
      cout << endl << SrNo <<". Your move:";
      cin >> userIn;                                  // user Input//
      userIn = toupper(userIn);                       //converting to uppercase to satisfy the conditions//
      int CompNum = rand() % 3;                       // generating random numbers//
      if(CompNum == 0){ 
        char CompChoice = 'R';                        //assigning computer choice to R when random number generated is 0//
        if(userIn == CompChoice){
          TieScore -= 1;
          cout << "\n   Computer chose R" << endl;         
          cout << "   Tie Score" << endl;
        }
        else if(userIn =='P'&&CompChoice == 'R'){
          Score += 1;
          cout << "\n   Computer chose R" << endl;
          cout << "   User's point. " << endl;
        }
        else if(userIn == 'S'&&CompChoice == 'R'){
          Score -= 1;
          cout << "\n   Computer chose R" << endl;
          cout << "   Computer's point. " << endl;
        }
      }
      else if(CompNum == 1){                          //assigning computer choice to P when random number generated is 1//
        char CompChoice = 'P';
        if(userIn == CompChoice){
          TieScore -= 1;
          cout << "\n   Computer chose P" << endl;
          cout << "   Tie. Score:" << endl;
        }
        else if(userIn =='R'&&CompChoice == 'P'){
          Score -= 1;
          cout << "\n   Computer chose P" << endl;
          cout << "   Computer's point. " << endl;
        }
        else if(userIn == 'S'&&CompChoice == 'P'){
          Score += 1;
          cout << "\n   Computer chose P" << endl;
          cout << "   User's point. " << endl;
        }
      }
      else if(CompNum == 2){
        char CompChoice = 'S';                      //assigning computer choice to S when random number generated is 2//
        if(userIn == CompChoice){
          TieScore -= 1;
          cout << "\n   Computer chose S" << endl;
          cout << "   Tie Score " << endl;
        }
        else if(userIn =='R'&&CompChoice == 'S'){
          Score += 1;
          cout << "\n   Computer chose S" << endl;
          cout << "   User's point. " << endl;
        }
        else if(userIn == 'P'&&CompChoice == 'S'){
          Score -= 1;
          cout << "\n   Computer chose S" << endl;
          cout << "   Computer's point. "<< endl;
        }
      }
       if(userIn == 'X'){
            cout << "\n Exiting program..." << endl;
            if(Score==0)
              cout << "Tie game!" << endl;
            else if(Score>0)
              cout << "User wins!" << endl;
            else
              cout << "Computer wins!" << endl;
            cout << endl;
       
            cout << "Ending program..." << endl;
          exit(0);
         }
       cout <<"    -5 -4 -3 -2 -1  0  1  2  3  4  5" << endl;
          cout <<"  ----------------------------------" << endl;
          cout <<"  ";
          for(int i=0;i<Score+5;i++){                          //for loop for graphing the score//
            cout <<"..."; 
          }                                                   
          cout <<"..^" << endl;                                //end of for loop//
       if(Score==5 || Score==-5){
            cout << endl;
            if(Score>0)
              cout << "User wins!" << endl;
            else if(Score<0)
              cout << "Computer wins!" << endl;
            else
              cout << "Tie game!" << endl;
            cout << endl;
       
            cout << "Ending program..." << endl;
             exit(0);
        }
        cout << endl; 
     }                                                        //end of while loop//   
    } 
    cout << "Ending program..." << endl;
    return 0;   // Keep C++ happy
}//end main()
