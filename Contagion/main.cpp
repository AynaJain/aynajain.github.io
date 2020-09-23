/* Prog2Contagion.cpp

   Program #2: Play the game of Contagion against another person
               This is a variation of Ataxx, a version of which can
               be played online at: http://www.classikgames.com/ataxx.html
   Class: CS 141
   Date: 1/27/2019
   Author: Ayna Jain

   Grading Rubric:
     55% Passes Codio run-time tests (some cases below are split into multiple tests)
          5 Handles both upper and lower case user input
          5 Handles making adjacent move for each player
         10 Handles making jump move for each player
          5 Handles pass move 
          2 Error message and retry when source position does not belong to player
          2 Error message and retry when destination position is not empty
          6 Error message and retry when destination is not one or two squares away
            in horizontal, vertical, or diagonal line
         15 Flips opponent pieces adjacent to move destination
          5 When board is filled correctly identifies winner and exits program

     45% Programming Style:
         10 Meaningful Identifier Names.
         10 Comments, header, and meaningful variable names
         10 Functional Decomposition 
         10 Appropriate data and control structures
          5 Code Layout
*/
#include <iostream>
#include <cstdlib>   // for exit() and abs()
using namespace std;

// The 25 board position variables may be global variables, but no other variables may be global.
char  p1, p2, p3, p4, p5,
      p6, p7, p8, p9,p10,
     p11,p12,p13,p14,p15,
     p16,p17,p18,p19,p20,
     p21,p22,p23,p24,p25;


//-----------------------------------------------------------------------------------------
// Display the game instructions
void displayInstructions()
{
    cout << " \n"
         << "Welcome to the 2-player game of Contagion, where the point of the game is    \n"
         << "to capture as much of the board as possible.  On each move you must enter \n"
         << "the row and column position of one of your current pieces (e.g. a1) and   \n"
         << "the row and column of an empty destination, which must be one or two      \n"
         << "squares away.  Moves can be made horizontally, vertically, or diagonally. \n"
         << " \n"
         << "If the destination is one square away, then an additional piece for you   \n"
         << "is placed in the destination square.  If the destination is two squares   \n"
         << "away (a jump move), then the original piece is moved to that destination. \n"
         << "jumping over a single square or any player's piece.                       \n"
         << " \n"
         << "After a piece has been moved, all opponent pieces adjacent to the         \n"
         << "destination are changed to match the piece of the user making the move.   \n"
         << "Player X moves first.     \n"
         << " \n"
         << "A valid first move, for instance, could be: a1 a2  which since it is just \n"
         << "one square away, would put an additional X on square a2.  Alternatively   \n"
         << "if the first move is:  a1 c3  then since it is two squares away, the piece\n"
         << "currently at a1 would be moved to destination c3.                         \n"
         << endl;
}


//-----------------------------------------------------------------------------------------
// Display the board, using the global board variables
// For reference here are the board row, col and board variable values:
//       1  2  3  4  5
//    ----------------
//  A |  1  2  3  4  5
//  B |  6  7  8  9 10
//  C | 11 12 13 14 15
//  D | 16 17 18 19 20
//  E | 21 22 23 24 25
    //
void displayBoard()
{
    cout << "    1   2   3   4   5  \n"
         << "  ---------------------\n"
         << "A | " <<  p1 << " | " <<  p2 << " | " <<  p3 << " | " <<  p4 << " | " <<  p5 << " | A \n"
         << "  |---|---|---|---|---| \n"
         << "B | " <<  p6 << " | " <<  p7 << " | " <<  p8 << " | " <<  p9 << " | " << p10 << " | B \n"
         << "  |---|---|---|---|---| \n"
         << "C | " << p11 << " | " << p12 << " | " << p13 << " | " << p14 << " | " << p15 << " | C \n"
         << "  |---|---|---|---|---| \n"
         << "D | " << p16 << " | " << p17 << " | " << p18 << " | " << p19 << " | " << p20 << " | D \n"
         << "  |---|---|---|---|---| \n"
         << "E | " << p21 << " | " << p22 << " | " << p23 << " | " << p24 << " | " << p25 << " | E \n"
         << "  ---------------------\n"
         << "    1   2   3   4   5  \n"
         << endl;
}

int Convert1(char row, char column){
	 int currentpos = 0;  //for current position
	 currentpos = (row-'A')*5;
	 currentpos = currentpos + (column -'0');
	 return currentpos;
} // end of convert1 function

void Convert2(int currentpos, char &currentRow, char &input1){
     currentRow = (currentpos-1) / 5 + 'A';
     input1 = ((currentpos-1) % 5) + '1';
} // end of convert2 function


char getValueAt( char pos, char col){
    char valueAtPiece = ' ';  
    int value= Convert1(pos, col);
    // Retrieve the character stored at that particular piece index
    switch( value) {
        case  1: valueAtPiece =  p1; break;
        case  2: valueAtPiece =  p2; break;
        case  3: valueAtPiece =  p3; break;
        case  4: valueAtPiece =  p4; break;
        case  5: valueAtPiece =  p5; break;
        case  6: valueAtPiece =  p6; break;
        case  7: valueAtPiece =  p7; break;
        case  8: valueAtPiece =  p8; break;
        case  9: valueAtPiece =  p9; break;
        case  10: valueAtPiece =  p10; break;
        case  11: valueAtPiece =  p11; break;
        case  12: valueAtPiece =  p12; break;
        case  13: valueAtPiece =  p13; break;
        case  14: valueAtPiece =  p14; break;
        case  15: valueAtPiece =  p15; break;
        case  16: valueAtPiece =  p16; break;
        case  17: valueAtPiece =  p17; break;
        case  18: valueAtPiece =  p18; break;
        case  19: valueAtPiece =  p19; break;
        case  20: valueAtPiece =  p20; break;
        case  21: valueAtPiece =  p21; break;
        case  22: valueAtPiece =  p22; break;
        case  23: valueAtPiece =  p23; break;
        case  24: valueAtPiece =  p24; break;
        case  25: valueAtPiece =  p25; break;
//         default: cout<<endl<<"***Invalid Source"<<endl;
     } //end of switch case
  return valueAtPiece;
} // end of getValueAt function

void setValueAt( char row1, char col1, char newValue){ 
    // Retrieve the character stored at that particular piece index
    int convertvalue = Convert1(row1, col1);
    switch( convertvalue) {
        case  1:  p1 = newValue; break;
        case  2:  p2 = newValue; break;
        case  3:  p3 = newValue; break;
        case  4:  p4 = newValue; break;
        case  5:  p5 = newValue; break; 
		case  6:  p6 = newValue; break;
		case  7:  p7 = newValue; break;
		case  8:  p8 = newValue; break;
		case  9:  p9 = newValue; break;
		case  10:  p10 = newValue; break;
		case  11:  p11 = newValue; break;
		case  12:  p12 = newValue; break;
		case  13:  p13 = newValue; break;
		case  14:  p14 = newValue; break;
		case  15:  p15 = newValue; break;
		case  16:  p16 = newValue; break;
		case  17:  p17 = newValue; break;
		case  18:  p18 = newValue; break;
		case  19:  p19 = newValue; break;
		case  20:  p20 = newValue; break; 
		case  21:  p21 = newValue; break;
		case  22:  p22 = newValue; break;
		case  23:  p23 = newValue; break;
		case  24:  p24 = newValue; break;
		case  25:  p25 = newValue; break;
//         default:  cout<<endl<<"***Invalid Destination"<<endl;
    } // swtich case
} // end of setValueAt function

int Counting(){ 
      int counting = 0; 
      int number1;
      int number2;
      for(number1=65; number1<=69; number1++){
          for(number2=1; number2<=5; number2++){
             if(getValueAt(number1,number2)=='X')
                 counting += 1;
          }
      } // end of first for loop
      for(number1=65; number1<=69; number1++){
          for(number2=1; number2<=5; number2++){
             if(getValueAt(number1,number2)=='O')
                 counting -= 1;
          }
      } // end of second for loop
      return counting;    
 } // end of counting function


//-----------------------------------------------------------------------------------------
int main() {
    // Set initial values for the global board variables to all be blank
    p1=p2=p3=p4=p5=p6=p7=p8=p9=p10=p11=p12=p13=p14=p15=p16=p17=p18=p19=p20=p21=p22=p23=p24=p25= ' ';
    // Set corner starting positions
    p1=p25= 'X';
    p5=p21= 'O';
 
    // Variables to store user input for current row and column, and destination row and column
    char currentRow;
    char destinationRow;
    char input1;
    char input2;
    char val = ' ';
    int Countervariable = 1;
    int Score;
    // ...
    
    cout << "Welcome to the 2-player game of Contagion. \n"
         << endl;


// Main loop to play game
   while( true) {
    
      // Display board and handle first character of user input
        displayBoard();
        if(Countervariable % 2 != 0){
          cout <<Countervariable<< ". Enter 'i' for instructions, 'x' to exit, or move for X: ";
        }
        if(Countervariable %2 == 0){
          cout << Countervariable << ". Enter 'i' for instructions, 'x' to exit, or move for O: ";
        }
        cin >> currentRow;
        currentRow = toupper(currentRow);
        if(currentRow == 'P')
        {
          Countervariable += 1;
          continue;
        }
        // Check to see if user input was 'i' for instructions or 'x' to exit
        if( currentRow == 'I') {
            displayInstructions();
            continue;       // Loop back up to retry move
        }
        else if( currentRow == 'X') {
            displayBoard();
         
            break;  // Break out of enclosing loop, to exit the game.
        }
        else {
            cin >> input1 >> destinationRow >> input2;
            destinationRow = toupper(destinationRow);
            val = getValueAt(currentRow,input1);
            //For jump moves.
            if((Countervariable %2 !=0 && val != 'X') || (Countervariable %2==0 && val != 'O'))
            {
              cout <<endl<< "*** Invalid move.  Current piece must belong to you. Please retry."<<endl;
              Countervariable -= 1;
            }
            else if(getValueAt(destinationRow,input2)!=' '){
              cout<<endl<<"*** Invalid move.  Destination must be empty. Please retry."<<endl;
              Countervariable -= 1;
            }
            else if(abs(currentRow-destinationRow)<=2 && abs(input1-input2)<=2){
            //for adjacent vertical move single move
                if(abs(currentRow-destinationRow)==1 && (input1==input2)){
                  setValueAt(destinationRow,input2,val);
                }
                else if(abs(currentRow-destinationRow)==2 && (input1==input2)){
                  setValueAt(destinationRow,input2,val);
                  setValueAt(currentRow,input1,' ');
                }
                else if(currentRow==destinationRow && abs(input1-input2)==1){
                  setValueAt(destinationRow,input2,val);
                }
                else if(currentRow==destinationRow && abs(input1-input2)==2){
                  setValueAt(destinationRow,input2,val);
                  setValueAt(currentRow,input1,' ');
                }
                else if(abs(currentRow-destinationRow)==2 && abs(input1-input2)==2){
                  setValueAt(destinationRow,input2,val);
                  setValueAt(currentRow,input1,' ');
                }
                else if(abs(currentRow-destinationRow)==1 && abs(input1-input2)==1){
                  setValueAt(destinationRow,input2,val);
                }
                else{
                  cout <<endl<<"*** Invalid move.  A move must be one or two squares away. Please retry."<<endl;
                  Countervariable -= 1;
                }
          }
          else{ 
              cout <<endl<<"*** Invalid move.  A move must be one or two squares away. Please retry."<<endl;
              Countervariable -= 1;
            }
        }
      Countervariable+=1;
    } //end while
     Score = Counting();
     if(Score==0)
       cout<<"Tie game."<<endl;
     if(Score>0)
       cout<<"X Wins!"<<endl;
     if(Score<0){
       cout<<"O Wins!"<<endl;}
     cout << "Exiting program... \n"
                 << endl;
     return 0;
  } // end main
