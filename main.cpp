#include <iostream>
#include <cstdlib>
using namespace std ;
int gamestate;
int card1;
int card2;
int cardsum;


int main(){
    std::cout << "hello welcome to black jack" << std::endl;
    std::cout << "start black jack:1" << std::endl;
    std::cout << "close program:2" << std::endl;
     std::cout << "choose an option:" << std:: endl;
     cin >> gamestate;
    
    
    if (gamestate = 1) {
        srand(time(0));
        card1 = rand() % 12;
        card2 = rand() % 12;

        std::cout <<"youre number is :" << card1 << "and " << card2 << endl;

    }

    if (gamestate = 2){

        return 0;
    }



    

    return 0;


}

