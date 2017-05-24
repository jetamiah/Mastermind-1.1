//
//  main.cpp
//  Mastermind
//
//  Created by Jet on 4/4/17.
//  Copyright © 2017 Jet. All rights reserved.
//

#include <iostream>
#include <time.h>
#include <string>
using namespace std;


int main(int argc, const char * argv[]) {
    // Guess done , Duplicate done, Compare done
    
   srand(static_cast<unsigned int>(time(NULL)));
    

    
    int duplicateSelect;
    int colorSelect;
    int guessSelect;
    int playerSelect;
    int i;
    int j;
    int k = 0;
    int whitePeg;
    int ComwhitePeg;
    int ComredPeg;
    int redPeg;
    int pegSelect;
    string userGuess[10];
    string userPick[10];
    string ComPeg[10];
    bool isRed[10];
    bool isWhite[10];
    bool hasColor;
    

    
    
    // number of pegs = for loop during guessing and ComSelect
    // string solution[pick] array cin pick
    
    

     string color[10] = {"gray" , "purple", "pink", "white", "black", "brown", "green", "orange", "red", "yellow" };
    
    cout << "This is Mastermind" << endl;
    
    cout << "How many Colors do you want? (Up to 10): ";
    
    cin >> colorSelect;
    
    
    cout << "How many pegs? (Up to 10 pegs): ";
    
    cin >> pegSelect;
    
    
    
    
   
    
    cout << "How many guesses you want?(Infinite amount): ";
    
    cin >> guessSelect;

    
    cout << "Do you want duplicates? (1 for yes) (0 for no):  ";
    
    
    cin >> duplicateSelect;
 
    
     //Computer or User guessing?
    
    cout << "If you want computer to guess?  (1 for yes) (0 for no): ";
    cin >> playerSelect;
    
    
    cout << "These are the colors for the game: ";
    

    for(i=0; i<colorSelect; i++){
        
        
        cout << color[i] << " ";
        
        
        
    }
    
    cout << endl;
    
    
    if(playerSelect == 1){
        
        cout << "Select your colors" << endl;
        
       
        for(int i = 0; i < pegSelect; i++){
            
            cout << "Pick " << i+1 << ": ";
            
            cin >> userPick[i];
            
            
            
        }

     
        
        
        cout << "Computer is guessing..." << endl;
        
        cout << "Computer Guessed: ";
        
        
        for(int k=0; k<guessSelect; k++){
         
            if(duplicateSelect ==1){
        
            for(int i=0; i<pegSelect; i++){
            int r = rand() % colorSelect;
            string TEMP = color[i];
            color[i] = color[r];
            color[r] = TEMP;
            cout << color[i] << " ";
            }
                
            }else{
                
                for(int i=pegSelect - 1; i>0; i--){
                    int r = rand() % (i+1);
                    string TEMP = color[r];
                    color[r] = color[i];
                    color[i] = TEMP;
                    
                    cout << color[i] << " ";

                
                
                
                
            }
                
            
            
            }
            
            
            
            
            
            
            cout << endl << "Number of White Pegs: ";
            
            cin >> ComwhitePeg;
            
            cout << "Number of Red Pegs: ";
            
            cin >> ComredPeg;
            
            if(ComredPeg == pegSelect){
                cout << "Computer Guessed the right combination you lose!" << endl;
                exit(0);
            }

            
            
        }
        
        
        
        cout << "Computer did not guess the right combination and YOU WIN" << endl;
        exit(0);
        
        
        
    
    }else{
        
        
        
        
        
        if(duplicateSelect==1){
    
            
           // cout << "Computer selected: ";
            for(int i=0; i<pegSelect; i++){
                int r = rand() % colorSelect;
                string TEMP = color[i];
                color[i] = color[r];
                color[r] = TEMP;
                
               // cout << color[i] << " ";
                
                ComPeg[k]  = color[i];
                k++;
                
                
            }
                }else{
                    
                   // cout << "Computer selected: ";
                    for(int i=pegSelect - 1; i>-1; i--){
                        int r = rand() % (i+1);
                        string TEMP = color[r];
                        color[r] = color[i];
                        color[i] = TEMP;
                        
                      //  cout << color[i] << " ";
                        
                
                         ComPeg[k]  = color[i];
                        k++;
                    
                    }
            
        
            
        
        }
        cout << endl;
        
  
        
        //Guess = for loop counter
        //compareWhite with boolean arrays
        
        
        
        cout << "Time to guess! " << endl;
        for(j=0; j<guessSelect; j++){
            redPeg = 0;
            whitePeg = 0;
        for(int i=0; i<pegSelect; i++){
        hasColor = false;
        isRed[i] = false;
        isWhite[k] = false;
        
  
        cout << "Guess " << i+1 << ": ";
        cin >> userGuess[i];
            
        
                if(userGuess[i] == ComPeg[i]){
                isRed[i] = true;
                redPeg++;
                }
            
            if(redPeg==pegSelect){
                cout << "You guessed the right combination you win!" << endl;
                exit(0);
            }
            
                    for(int i=0; i < pegSelect; i++){
                         if(isRed[i] == false){
                            for(k=0; k<pegSelect; k++){
                                
                    if(isRed[k] == false){
                           if(i!=k)
                            if(userGuess[i] == ComPeg[k])
                               if(isWhite[k] == false)
                                hasColor = true;
                                j = k;
                            }
                        }
                        }
                    if (hasColor == true){
                        isWhite[j] = true;
                        hasColor = false;
                        whitePeg++;
                    }
                    }
        }
            
            
            cout << "Red pegs: " << redPeg << endl;
            cout << "White pegs: " << whitePeg << endl;
            
            
            
        }
    
        
        
        cout << "You didn't guess the right combination. You lose!" << endl;
        
        
        
    }
    
    
    
    
    
    
    
    
    return 0;
    
    
    
}

