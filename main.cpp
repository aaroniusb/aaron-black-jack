#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std ;

//game stuff
int gamestate;
int PlayAction;
int GameAction;

//player cards
int Card1;
int Card2;
int CardSum;
int CardDraws;
int CardDrawnLast;


//houses cards

int HCard1;
int HCard2;
int HCardSum;
int HCardDraws;
int HCardDrawnLast;

//game state chosing 
void Selectr(){
    std::cout << "Play Black Jack: 1" << std::endl;
    std::cout << "Close program: 2" << std::endl;
    std::cout << "Choose an option:";

    while (!(cin >> gamestate)) {
        cout << "Invalid input. Choose an option:";
        cin.clear(); 
        cin.ignore(255, '\n');
    }
}

//card drawing
void CardDraw(){
    srand(time(0));

    Card1 = rand() % 13 + 1;
    Card2 = rand() % 13 + 1;
    CardDraws = 0;

    HCard1 = rand() % 13 + 1;
    HCard2 = rand() % 13 + 1;

    std::cout <<"Your cards:" << Card1 << " and " << Card2 << endl;
    std::cout <<"House's cards:" << HCard1 << " and " << HCard2 << endl;
    
    if(Card1 > 10){
        Card1 = 10;
    }

    if(Card2 > 10){
        Card2 = 10;
    }

     if(HCard1 > 10){
        HCard1 = 10;
    }

    if(HCard2 > 10){
        HCard2 = 10;
    }

    CardSum = Card1 + Card2;

}

// calculations to see who wins
void WinCalc(){

    CardSum = Card1 + Card2 + CardDraws;
    HCardSum = HCard1 + HCard2 + HCardDraws; 

    if(CardSum > HCardSum && CardSum < 21){
        std::cout <<"YOU WIN!:)" << endl;
        std::cout <<"Your score: " << CardSum <<" House score: " << HCardSum  << endl;
    }

    if(CardSum < HCardSum || CardSum > 21){
        std::cout <<"You Lose :(" << endl;
        std::cout <<"Your score: " << CardSum <<" House score: " << HCardSum  << endl;
    }
        
    if(CardSum == HCardSum ){
        std::cout <<"You Draw :p" << endl;
        std::cout <<"Your score: " << CardSum <<" House score: " << HCardSum  << endl;
    }



}

// action to see your response to ur cards
void ActionSelect(){

    while (GameAction == 2)
    {
        std::cout << std::endl;
        std::cout << "stay:1" << std::endl;
        std::cout << "draw:2" << std::endl;
        std::cout << "Choose an option:";

        while (!(cin >> PlayAction)) {
            cout << "Invalid input. Choose an option:";
            cin.clear(); 
            cin.ignore(255, '\n');
        }

        //player staying
        if(PlayAction == 1){
            std::cout << "staying" << std::endl;
            GameAction = 1;
        }

        //player drawing
        if(PlayAction == 2){
            CardDrawnLast = rand() % 13 + 1;
            std::cout << "You drew a " << CardDrawnLast << std::endl;

        if(CardDrawnLast > 10){
            CardDrawnLast = 10;
        }

   
            CardDraws += CardDrawnLast;

        if(CardDraws + CardSum > 21){
            std::cout << "you've busted :(" << std::endl;
            GameAction = 1;
        }
    }

    }
}

int main(){
    gamestate = 0;
    GameAction = 0;
    std::cout << "Hello, Welcome to Aaron's Black Jack" << std::endl;
    std::cout << std::endl;


    Selectr();    
    
    //playing
    while (gamestate == 1) {
        std::cout << endl;

        CardDraw();

        if(HCardSum == 21){
           WinCalc(); 
        }


        if(HCardSum != 21){
            GameAction = 2;
            ActionSelect();
        }



        WinCalc();

        gamestate = 0;
        GameAction = 0;

        std::cout << endl;
        Selectr();
    }
    

    //take a guess 
    if (gamestate == 2){
        std::cout <<"exiting" << std::endl;
        return 0;
    }

    return 4;
}



