#include <iostream>
#include <cstdlib>
#include <ctime>
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

//game state chosing 
void Selectr(){
    std::cout << "Play Black Jack: 1" << std::endl;
    std::cout << "Close program: 2" << std::endl;
    std::cout << "Choose an option:";
    cin >> gamestate;
}


int main(){
    gamestate = 0;
    std::cout << "hello welcome to black jack" << std::endl;

    Selectr();    
    
    //playing
    while (gamestate == 1) {
        std::cout << endl;
        srand(time(0));
        Card1 = rand() % 13 + 1;
        Card2 = rand() % 13 + 1;

        HCard1 = rand() % 13 + 1;
        HCard2 = rand() % 13 + 1;

        std::cout <<"Your cards:" << Card1 << " and " << Card2 << endl;
        std::cout <<"House's cards:" << HCard1 << " and " << HCard2 << endl;

        CardSum = Card1 + Card2;
        HCardSum = HCard1 + HCard2;

        if(CardSum > HCardSum ){
            std::cout <<"YOU WIN!:)" << endl;
            std::cout <<"Your score: " << CardSum <<" house score: " << HCardSum  << endl;
        }

        if(CardSum < HCardSum ){
            std::cout <<"You Lose :(" << endl;
            std::cout <<"Your score: " << CardSum <<" house score: " << HCardSum  << endl;
        }
        
         if(CardSum == HCardSum ){
            std::cout <<"You Draw :p" << endl;
            std::cout <<"Your score: " << CardSum <<" house score: " << HCardSum  << endl;
        }

        std::cout << endl;
        Selectr();
    }
    

    //take a guess 
    if (gamestate == 2){
        std::cout <<"exiting";
        return 0;
    }

    return 4;
}



