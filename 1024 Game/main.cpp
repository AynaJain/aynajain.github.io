//  prog5_1024.cpp
//     Text version of the game 1024, a variant of 2048 available online at:
//        http://gabrielecirulli.github.io/2048/
//     Object of game is to combine number tiles with the same value, accumulating
//     points as the game progresses, to try and create the tile with the value 1024.
//     Each move consists of sliding pieces to the left, up, right or down.
/*  Running program looks like:
 
     Ayna Jain
     UIC CS 141, Spring 2019
     Welcome to 1024.
     This program is based off of Gabriele Cirulli's game online at
     bit.ly/great2048
 
     For each move enter a direction as a letter key, as follows:
         W
       A S D
     where A=left,W=up, D=right and S=down.
 
     After a move, when two identical valued tiles come together they
     join to become a new single tile with the value of the sum of the
     two originals. This value gets added to the score.  On each move
     one new randomly chosen value of 2 or 4 is placed in a random open
     square.  User input of x exits the game.
 
     Game ends when you reach 1024.
 
     Score: 0
	 .     4     .     .

	 .     .     .     .

	 .     .     4     .

	 .     .     .     .
 
     1. Your move: a
 
     Score: 0
	 4     .     .     .

	 .     .     .     .

	 4     .     .     .

	 .     .     2     .
 
     2. Your move: a
     .
     .
     .
*/

#include <iostream>     // For cin, cout, endl
#include <iomanip>      // used for setting output field size using setw
#include <cstdlib>      // For rand()
#include <cmath>        // For adding math library functions
using namespace std;    // So we don't need std:: in front of every cin, cout, and endl

const int MaxBoardSize = 12;          // Max number of squares per side
const int MaxTileStartValue = 1024;   // Max tile value to start out on a 4x4 board


//--------------------------------------------------------------------
// Display Instructions
void displayInstructions()
{
    cout << "Welcome to 1024. \n"
         << "  \n"
         << "For each move enter a direction as a letter key, as follows: \n"
		 << "    W    \n"
		 << "  A S D  \n"
		 << "where A=left,W=up, D=right and S=down. \n"
		 << "  \n"
		 << "After a move, when two identical valued tiles come together they    \n"
		 << "join to become a new single tile with the value of the sum of the   \n"
		 << "two originals. This value gets added to the score.  On each move    \n"
		 << "one new randomly chosen value of 2 or 4 is placed in a random open  \n"
		 << "square.  User input of x exits the game.                            \n"
		 << "  \n";
}//end displayInstructions()


//--------------------------------------------------------------------
// Place a randomly selected 2 or 4 into a random open square on
// the board.
void placeRandomPiece( int board[], int squaresPerSide)
{
    // Randomly choose a piece to be placed (2 or 4)
    int pieceToPlace = 2;
    if( rand()%2 == 1) {
        pieceToPlace = 4;
    }
    
    // Find an unoccupied square that currently has a 0
    int index;
    do {
        index = rand() % (squaresPerSide*squaresPerSide);
    }while( board[ index] != 0);
    
    // board at position index is blank, so place piece there
    board[ index] = pieceToPlace;
}//end placeRandomPiece()

void displayBoard(int board[], int squaresPerSide, int score){              // function for displaying th board of the game 1024.
    cout << "Score: " << score << endl;                                     //displaying the score everytime you ask the usk for another move.
    int k=0;
    for(int index=0;index<squaresPerSide;index++){
        cout<<setw(9);
        for(k;k<squaresPerSide*squaresPerSide;k++){ 
            if((k+1)%squaresPerSide==0){
                    if(board[k]==0){
                        cout<<".";                  
                    }
                    if(board[k]!=0){
                        cout<<board[k];
                    }
                    cout<<endl<<endl;
                    k++;
                    break;
            }
            if((k+1)%squaresPerSide!=0){
                    if(board[k]==0){
                        cout<<"."<<setw(6);
                    }
                    if(board[k]!=0){
                        cout<<board[k]<<setw(6);
                    }
            }             
        }
    }
}

void shiftLeft(int board[], int squaresPerSide){    //Function to move board pieces to the left side
    for(int index=0; index<squaresPerSide*squaresPerSide; index++){
            if(index % squaresPerSide != 0 && board[index] != 0){
                int temporaryvariable = index;
                while(board[temporaryvariable-1]==0 && temporaryvariable % squaresPerSide!=0){
                        board[temporaryvariable-1] = board[temporaryvariable];
                        board[temporaryvariable] = 0;
                        temporaryvariable--; 
            }
        }
    }
}

void shiftDown(int board[], int squaresPerSide){   //Function to move board pieces to Down side.
    for(int index= (squaresPerSide*squaresPerSide - squaresPerSide - 1); index >=0 ; index--){
           if(board[index] !=0){
               int temporaryvariable = index;
               while(board[temporaryvariable+squaresPerSide]== 0 && temporaryvariable < (squaresPerSide*squaresPerSide - squaresPerSide)){
                       board[temporaryvariable + squaresPerSide] = board[temporaryvariable];
                       board[temporaryvariable] = 0;
                       temporaryvariable = temporaryvariable + squaresPerSide;
           }
       } 
    }
}

void shiftRight(int board[], int squaresPerSide){  //Functions to move board pieces to Right side of the board.
    for(int index= (squaresPerSide*squaresPerSide - 1); index>=0; index--){
            if((index+1) % squaresPerSide != 0 && board[index] != 0){
                int temporaryvariable = index;
                while(board[temporaryvariable+1]==0 && (temporaryvariable+1) % squaresPerSide!=0){
                        board[temporaryvariable+1] = board[temporaryvariable];
                        board[temporaryvariable] = 0;
                        temporaryvariable++; 
            }
        } 
    }
}

void shiftUp(int board[], int squaresPerSide){    //Functions to move board pieces to upward of the board.
    for(int index=squaresPerSide; index < squaresPerSide*squaresPerSide; index++){
           if(board[index] !=0){
               int temporaryvariable = index;
               while(board[temporaryvariable-squaresPerSide]== 0 && temporaryvariable >= squaresPerSide ){
                       board[temporaryvariable - squaresPerSide] = board[temporaryvariable];
                       board[temporaryvariable] = 0;
                       temporaryvariable = temporaryvariable - squaresPerSide;
           }
       }
    }
}

//---------------------------------------------------------------------------------------
int main()
{
    int score = 0;
    int squaresPerSide = 4;        // User will enter this value.  Set default to 4
    int board[ MaxBoardSize * MaxBoardSize];          // space for largest possible board
    int previousBoard[ MaxBoardSize * MaxBoardSize];  // space for copy of board, used to see
                                                      //    if a move changed the board.
    int maxTileValue = MaxTileStartValue;  // 1024 for 4x4 board, 2048 for 5x5, 4096 for 6x6, etc.
    char userInput = ' ';                  // handles user input.
    int move = 1;                          // user move counter.
    int sign = 0;                          //variable to recide when to call random value function.
    int indicator;                         //takes index from the user input value in case it places a new value.
    int toatalEndScore =0;                 //variable to check the end of game has reached.
    int defaultSize = 4;                   //this variable is used to determine the maximum tile value of the board.
    int customSize = 4;                    //used to input th new size of the user Input.
    int number;                            //takes the new value which is to be placed in the function.
    int max=0;                             //it stores the value of number of empty spaces in the board.
    int baseExponent=10;
    
    
    displayInstructions();
    cout<<"Game ends when you reach 1024."<<endl<<endl;
    // Get the board size, create and initialize the board, and set the max tile value depending on board size
    board[squaresPerSide*squaresPerSide];
    for(int i=0;i<squaresPerSide*squaresPerSide;i++){
        board[i]=0;
    }
    placeRandomPiece(board, squaresPerSide);
    placeRandomPiece(board, squaresPerSide);
    // ..
    // Infinite loop to run program until user selects exit, board is full, or max tile value is reached
    while( true)
    {
        // Display the text-based board
        displayBoard( board, squaresPerSide, score);
        
        // Make a copy of the board.  After we then attempt a move, the copy will be used to
        // verify that the board changed, which only then allows randomly placing an additional
        // piece on the board and updating the move number.
        previousBoard[squaresPerSide*squaresPerSide];
        for(int index=0;index<squaresPerSide*squaresPerSide;index++){
            previousBoard[index]=board[index];
        }
        // ...      
        // Prompt for and handle user input
        cout << move << ". Your move: "<<endl;
        if(max == squaresPerSide*squaresPerSide){
            cout <<endl<< "No more available moves.  Game is over."<<endl;
            displayBoard( board, squaresPerSide, score);
            break;
        }
        cin >> userInput;
        switch (userInput) {
            case 'x':
                    cout << "Thanks for playing. Exiting program... \n";  //Chcking if the user Inputs 'x' then it would end the program
                    exit(0);
                    break;
            case 'a':
                 shiftLeft(board, squaresPerSide);                        //Checking if the user Inputs 'a' then it will make the left move through shift left function
                    for(int index=0;index<squaresPerSide*squaresPerSide;index++){  //this for loop makes the move and calcualtes the score of the game // *** Abhinav: Use consistent indent
                        if(board[index]!=0){
                                if((index+1)%squaresPerSide!=0 && board[index]==board[index+1]){
                                        board[index]=board[index]+board[index+1];
                                        board[index+1]=0;
                                        score=score+board[index];
                                }
                            
                         }
                    }
                shiftLeft(board, squaresPerSide);
                break;    
            case 'd':
                shiftRight(board, squaresPerSide);                       //Checking if the user Inputs 'd' then it will make the right move through shiftright function.
                    for(int index= (squaresPerSide*squaresPerSide - 1); index>=0; index--){  //this for loop makes the move and calcualtes the score of the game. // *** Abhinav: Use consistent indent
                            if(board[index] != 0){
                                  if(index%squaresPerSide!=0 && board[index]==board[index-1]){
                                          board[index]=board[index]+board[index-1];
                                          board[index-1]=0;
                                          score=score+board[index];
                                  }
                                }
                            } 
                shiftRight(board, squaresPerSide);    
                break;
            case 'w':
                shiftUp(board, squaresPerSide);                          //Checking if the user Inputs 'W' then it will make the UP move through shiftup function.
                    for(int index=0; index< squaresPerSide*squaresPerSide; index++){  //this for loop makes the move and calcualtes the score of the game. // *** Abhinav: Use consistent indent
                            if(board[index] != 0){
                                if(board[index] == board[index+squaresPerSide]){
                                    board[index] = board[index] + board[index+squaresPerSide];
                                    board[index+squaresPerSide] = 0;
                                    score = score + board[index];
                                }
                            }
                    }
                shiftUp(board, squaresPerSide); 
                break;
            case 's':
                shiftDown(board, squaresPerSide);                       //Checking if the user Inputs 's' then it will make the down move through shiftdown function.
                    for(int index= (squaresPerSide*squaresPerSide -1); index >= 0; index--){  //this for loop makes the move and calcualtes the score of the game.
                           if(board[index] != 0){
                               if(board[index] == board[index-squaresPerSide]){
                                   board[index] = board[index] + board[index-squaresPerSide];
                                   board[index - squaresPerSide] = 0; 
                                   score = score + board[index];
                               }
                           }
                       }
                shiftDown(board, squaresPerSide);   
                break;
            case 'p':                                                  //This case is placing a number in a particular position in the board
                cin>>indicator>>number;
                if(indicator<squaresPerSide*squaresPerSide){
                        board[indicator] = number;
                        sign=1;
                }
                break;
            case 'r':                                                  //This case is used to reset the board of nay size taking from minimum of 4 to maximum of 12.
                    cout<<endl<<"Resetting board"<<endl<<"Enter the size board you want, between 4 and 12: ";
                    cin>>customSize;
                    squaresPerSide = customSize;
                    cout<<endl<<"Game ends when you reach "<<pow(2,(baseExponent + abs(defaultSize-customSize)))<<"."<<endl;
                    for(int i=0; i<squaresPerSide*squaresPerSide; i++){
                        board[i] = 0;
                    }
                    placeRandomPiece(board, squaresPerSide);
                    placeRandomPiece(board, squaresPerSide);
                    sign = 1;
                    move = 1;
                    score = 0;
              break;
			      //...
            default:                                                 //If nothing matches th userinput to the cases then it gives a default case whoch shows invalid input
                    cout << "Invalid input, please retry.";
                    continue;
                    break;
            
        }//end switch( userInput)
        
        // If the move resulted in pieces changing position, then it was a valid move
        // so place a new random piece (2 or 4) in a random open square and update the move number.
        int commonvariable=0;
        for(int index=0;index<squaresPerSide*squaresPerSide;index++){
                if(board[index]==previousBoard[index]){
                    commonvariable=commonvariable+1;
                }           
        }
        if(commonvariable!=squaresPerSide*squaresPerSide && sign==0){
                placeRandomPiece(board,squaresPerSide);
                move++;
        }
        sign=0;
        // ...
        max=0;
        if(toatalEndScore == 1){
                cout<<endl<<"Congratulations!  You made it to "<<"1024"<<" !!!"<<endl;
                displayBoard( board, squaresPerSide, score);
                break;
        }
        for(int index=0; index<squaresPerSide*squaresPerSide; index++){
                if(board[index] != 0){
                      max=max+1;  
                }
                if(board[index]>=pow(2,(baseExponent + abs(defaultSize-squaresPerSide))) ){
                        toatalEndScore = 1;
                }
        }      
        // See if we're done.  If so, display the final board and break.
        // ...
        //system("clear");   // Clear the screen in UNIX / Codio.  Should be "cls" on windows.
                             //     May not work in default Mac Xcode configuration, or some other environments.
    }//end while( true)
    return 0;
}//end main()