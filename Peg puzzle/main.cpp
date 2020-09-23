/* pegJump.cpp

   Author: Ayna Jain and Jay Patel 
   Program:  3, Peg Jump
   CS 141, Spring 2019
 
*/
 
#include <iostream>
#include <cctype>     // For toupper()

using namespace std;

char move;
const int PegsInRow = 11; // 11 X 11 grid, means 11pegs per row stays constant throughout. 

//char board[121];

void displayInstructions()
{
    cout << endl
         << "Welcome to the peg jump puzzle. The board starts out with a \n"
         << "single blank position, represented by the '*'.  To make a \n"
         << "move, select the letter of a peg.  A peg must be able to \n"
         << "jump over an adjacent peg into a blank position for a move \n"
         << "to be valid.  The jumped peg is then removed from the board. \n"
         << "The game is over when there are no valid moves left. At any \n"
         << "point enter '-' to exit, or '+' for instructions. \n"
         << endl;
}

// display the main board as desired.
void displayboard(char board[]){
  
      for(int i=0; i<121; i++){
      if(i%11==0){               // mod 11 because the each row has 11 pieces.
        cout <<endl;
        }
      else {
        cout << board[i] <<" ";
        }
     }
    cout<<endl;
  
}
// find the index of a character in the array.
int findIndex(char var, char board[]){
	 
	for( int i = 0; i < 121; i++) {
        if( var == board[ i]) {
        	return( i); // return the index.
        }
    }
	return -1; // if not found. 

} 

// look for the possible moves, according to the conditions provided.
int possibleMoves(int pegIndex, char board[], int destinations[]) { 
	
	//Local variable declared (and assigned ), for use in the function.

	int numMoves = 0;
	int var = 0;
	int adjacentToPeg;
	int destination;
	char adjacentPieces[]= {-11,-1,1,11};
	char destinationPieces[] = {-22,-2,2,22};
	
	for( int i=0; i<4; i++) {
		
		adjacentToPeg = pegIndex + adjacentPieces[ i];       // iterates over the loop checking all four possible sides.
    destination   = pegIndex + destinationPieces[ i];
        
		if( (board[ adjacentToPeg] != '*' ) && ( board[ destination] == '*' ) ) {
         
            destinations[ var++] = destination;
            numMoves++;  // incrementing the moves number.
		}
	}

	return numMoves;
}

// code for multiple moves, the user's choice of destination if there are multiple destinations possible.
void userChoiceDest ( int destinations[], int source, char board[] ) {
    int userDestChoice;          
    int possibleDest = 0;

    
    for( int i = 0+PegsInRow; i < (121 - PegsInRow); i++) {
       
       if( board[i] == ' ') {
            cout << "  ";  
       }
       else if( (i == destinations[ 0]) ||
                (i == destinations[ 1]) ||
                (i == destinations[ 2]) ||
                (i == destinations[ 3])
              ) {
            
            possibleDest++;
            cout << possibleDest << " "; 
       }
      
       else if( i == source) {
            cout << '+' << " "; 
       }
       else {
            cout << '*' << " ";
       }
        if( ((i+1) % PegsInRow) == 0) {
            cout << endl;
        }
    }
    
    //prompt for the user to choose one of the multiple possible moves.

    cout << "There is more than one possible move.  Which move do you want? ";
    cin >> userDestChoice;
    destinations[0] = destinations[ userDestChoice - 1];
}

// the move function that uses the data from the above functions about the possibke moves, and the 
int maketheMove( char move, char board[])
{
    int destinations[] = {0,0,0,0};
    int movesPossible = 0;    
    int adjacentToPeg = 0;
    int pegIndex; // index of the move

    pegIndex = findIndex( move, board);

    if( !(isalnum( move)) ||
        (pegIndex == -1) ||
        ( (isdigit( move - '0')) && ((move < '1') || (move > '0'+ 6 ))  )
      ) {
        return false;
    }
  
    movesPossible = possibleMoves( pegIndex, board, destinations);
    
    if( movesPossible > 1 )  {
        userChoiceDest( destinations, pegIndex, board );
    }
    else if( movesPossible == 0 )  {
        return false;
    }
    adjacentToPeg = (pegIndex + destinations[ 0]) / 2;
    
    
    board[ destinations[ 0]] = board[ pegIndex];
    board[ adjacentToPeg] = board[ pegIndex] = '*';
    
    return true; 
}


int checkIfDone( char board[] )  {
    
  int destinations[ 4];
 
    for( int i = 0 + PegsInRow; i < (121 - PegsInRow); i++) {
       if( (board[i] != ' ') && (board[i] != '*') ) {
            if( possibleMoves( i, board, destinations) > 0) {
                return true;
            }
       }
    }//
    
    return false;    //
}

//-------------------------------------------------------------------------------------
int main()
{
  
  //Variable declarations
    int SrNum =1; // initialized to 1 becuase there in no 0 numbered move. 
    char move;
    int counter = 0;
    int i= 0;
  
  //Declaring four variables, for storing the locations of possible moves.
    char Loc_var1;
    char Loc_var2;
    char Loc_var3;
    char Loc_var4;
  
    char board[] = {
            ' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',
            ' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',
            ' ',' ',' ',' ','A','B','C',' ',' ',' ',' ',
            ' ',' ',' ',' ','D','E','F',' ',' ',' ',' ',
            ' ',' ','G','H','I','J','K','L','M',' ',' ',
            ' ',' ','N','O','P','*','Q','R','S',' ',' ',
            ' ',' ','T','U','V','W','X','Y','Z',' ',' ',
            ' ',' ',' ',' ','1','2','3',' ',' ',' ',' ',
            ' ',' ',' ',' ','4','5','6',' ',' ',' ',' ',
            ' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',
            ' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '
          };
          	
  
    // Prompt for and get move
    cout << "Welcome to the peg jump puzzle! \n"
         << "Enter '-' to exit, or '+' for instructions. "
         << endl;
    
     displayboard(board);

 //     Main loop to play the game
  do {
		cout<< SrNum << ". Enter the peg to move: ";
    cin >> move;
    move = toupper(move);
        
        
    	if(move == '+'){
        	displayInstructions();
      }
   
    	else if(move == '-'){
        cout<< " \nExiting...\n" << endl;
        	break;
      }
      
      if(  maketheMove(move, board) == false){
        if(SrNum == 1){
          continue;
        }
          cout << "*** Invalid move, please retry. *** " << endl;
          continue;
      }
    
    
    SrNum++;
    displayboard(board);
      
  } while(checkIfDone(board));
      
    
             
    
  
  // Check for the number of pegs remaining.
      for(int i=0; i<121; i++){
      
      if( (isupper(board[i])) || (isdigit(board[i])) ) {
           counter += 1;
        }
      } // end for loop.
  
  
  // Display appropriate message depending on number of remaining pegs
      
      if(counter == 1 ) {
        cout << counter << " pieces remaining. Excellent! \n";  
      }
      else if(counter == 2 ) {
        cout << counter << " pieces remaining. Good! \n";
        
      }
      else if(counter == 3 ){
        cout << counter << " pieces remaining. Ok. \n";
        
      }
      else if(counter == 4){
        cout << counter << " pieces remaining. Needs Improvement. \n";
        
      }
      else if(counter >= 5){
        cout << counter << " pieces remaining. Ouch! \n";
      }
    cout << endl;
    return 0;
 
    
} //end main()

