#include <iostream>
#include <cstdlib>
using namespace std ;

//game stuff
int gamestate;

//player cards
int Card1;
int Card2;
int CardSum;

//houses cards

int HCard1;
int HCard2;
int HCardSum;



int main(){
    gamestate = 0;
    std::cout << "hello welcome to black jack" << std::endl;

    //game state chosing 
    if(gamestate == 0){
    std::cout << "play black jack:1" << std::endl;
    std::cout << "close program:2" << std::endl;
    std::cout << "choose an option:";
    cin >> gamestate;
    }
    
    //playing
    if (gamestate == 1) {
        srand(time(0));
        Card1 = rand() % 13 + 1;
        Card2 = rand() % 13 + 1;

        HCard1 = rand() % 13 + 1;
        HCard2 = rand() % 13 + 1;

        std::cout <<"Your cards:" << Card1 << "and " << Card2 << endl;
        std::cout <<"House's cards:" << HCard1 << "and " << HCard2 << endl;

        CardSum = Card1 + Card2;
        HCardSum = HCard1 + HCard2;

        if(CardSum > HCardSum ){
            std::cout <<"YOU WIN!:)" << endl;
            std::cout <<"Your score:" << CardSum <<"house score:" << HCardSum  << endl;
        }

        if(CardSum < HCardSum ){
            std::cout <<"You Lose :(" << endl;
            std::cout <<"Your score:" << CardSum <<"house score:" << HCardSum  << endl;
        }
        
    }
    

    //take a guess 
    if (gamestate == 2){
        std::cout <<"exiting";
        return 0;
    }

    return 4;
}

