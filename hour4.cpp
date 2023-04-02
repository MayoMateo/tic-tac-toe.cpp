#include <iostream>
#include <ctime>

void drawboard(char *pspaces);
void getuserchoice(char *pspaces);
void getcomputerchoice(char *pspaces);
bool checkwinner(char *pspaces);
bool tiechecker(char *pspaces);


int main (){

    std::cout << "****************************************************" << '\n';
    std::cout << "                   Tic Tac Toe                    " << '\n';
    std::cout << "| 1 | 2 | 3 |" << '\n';
    std::cout << "------------" << '\n';
    std::cout << "| 4 | 5 | 6 |" << '\n';
    std::cout << "------------" << '\n';
    std::cout << "| 7 | 8 | 9 |" << '\n';

    char spaces[9] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
    
    bool gamecontinue = true;

    while (tiechecker(spaces) && checkwinner(spaces)){
        
        if(tiechecker(spaces) && checkwinner(spaces)){
            getuserchoice(spaces);

        }
        
        
        if (tiechecker(spaces) && checkwinner(spaces)) {
            getcomputerchoice(spaces); 

        }
        
        drawboard(spaces);

        if(!(tiechecker(spaces)) && checkwinner(spaces)){
            std::cout<< "Its a tie!" << '\n';
        }


    }

}

/*
 | 1 | 2 | 3 |
 -------------
 | 4 | 5 | 6 |
 -------------
 | 7 | 8 | 9 |
 game board
*/

void drawboard(char *pspaces){
    

    std::cout << "| " << pspaces[0] << " | " << pspaces[1] << " | " << pspaces[2] << " |" << '\n';
    std::cout << "------------" << '\n';
    std::cout << "| " << pspaces[3] << " | " << pspaces[4] << " | " << pspaces[5] << " |" << '\n';
    std::cout << "------------" << '\n';
    std::cout << "| " << pspaces[6] << " | " << pspaces[7] << " | " << pspaces[8] << " |" << '\n';
    
 
}

void getuserchoice(char *pspaces){
    int input;
    
    while (true){
        std::cout << "Enter a number 1-9 to place an X (computer will be O)" << '\n';
        std::cin >> input;
        input = input - 1;
        if(pspaces[input] == ' '){
            pspaces[input] = 'X';
            break;
        }
        else {
            std::cout << "please enter an empty spot" << '\n';
        }
    }

}

void getcomputerchoice(char *pspaces){
    srand(time(NULL));
    int N = 9;
    while (true){
        int Random = rand() % N;
        if(pspaces[Random] == ' '){
            pspaces[Random] = 'O';
            break;
        }
    }


}

bool checkwinner(char *pspaces){

    if((pspaces[0] != ' ') && (pspaces[0] == pspaces[1]) && (pspaces[0] == pspaces[2])){
        if(pspaces[0] == 'X'){
            std::cout << "you win" << '\n';
            return false;
        }
        else{
            std::cout << "you loose" << '\n';
            return false;
        }
    }
    else if((pspaces[3] != ' ') && (pspaces[3] == pspaces[4]) && (pspaces[3] == pspaces[5])){
        if(pspaces[3] == 'X'){
            std::cout << "you win" << '\n';
            return false;
        }
        else{
            std::cout << "you loose" << '\n';
            return false;
        }
    }
    else if((pspaces[6] != ' ') && (pspaces[6] == pspaces[7]) && (pspaces[6] == pspaces[8])){
        if(pspaces[6] == 'X'){
            std::cout << "you win" << '\n';
            return false;
        }
        else{
            std::cout << "you loose" << '\n';
            return false;
        }
    }
    else if((pspaces[0] != ' ') && (pspaces[0] == pspaces[3]) && (pspaces[0] == pspaces[6])){
        if(pspaces[0] == 'X'){
            std::cout << "you win" << '\n';
            return false;
        }
        else{
            std::cout << "you loose" << '\n';
            return false;
        }
    }
    else if((pspaces[1] != ' ') && (pspaces[1] == pspaces[4]) && (pspaces[1] == pspaces[7])){
        if(pspaces[1] == 'X'){
            std::cout << "you win" << '\n';
            return false;
        }
        else{
            std::cout << "you loose" << '\n';
            return false;
        }
    }
    else if((pspaces[2] != ' ') && (pspaces[2] == pspaces[5]) && (pspaces[2] == pspaces[8])){
        if(pspaces[2] == 'X'){
            std::cout << "you win" << '\n';
            return false;
        }
        else{
            std::cout << "you loose" << '\n';
            return false;
        }
    }
    else if((pspaces[0] != ' ') && (pspaces[0] == pspaces[4]) && (pspaces[0] == pspaces[8])){
        if(pspaces[0] == 'X'){
            std::cout << "you win" << '\n';
            return false;
        }
        else{
            std::cout << "you loose" << '\n';
            return false;
        }
    }
    else if((pspaces[2] != ' ') && (pspaces[2] == pspaces[4]) && (pspaces[2] == pspaces[6])){
        if(pspaces[2] == 'X'){
            std::cout << "you win" << '\n';
            return false;
        }
        else{
            std::cout << "you loose" << '\n';
            return false;
        }
    }
    else {
        return true;
    }
    
}

bool tiechecker(char *pspaces){
    
    int xo = 0;
    int whitespace = 0;

    for (int i = 0; i < sizeof(pspaces)/sizeof(char); i++){
        
        if (pspaces[i] != ' '){
            xo = xo + 1;
        }
        else{
            whitespace = whitespace + i;
        }
    }
    if(xo == 8){
        return false;
        
    }
    else{
        return true;
    }
    
}