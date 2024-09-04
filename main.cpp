#include <iostream>

char selectPlayerSelection();
char generateBotSelection();
int processWinner(char human, char bot);
void displayWinner(int decider);
void displayBothSelections(char human, char bot);

int main() {

    char human = selectPlayerSelection();
    char bot = generateBotSelection();
    int decider = processWinner(human, bot);
    displayWinner(decider);
    displayBothSelections(human, bot);

    return 0;

}

char selectPlayerSelection(){

    char selection;

    do{
        std::cout << "Please select one of the following.. " << "\n";
        std::cout << "####################################" << "\n";
        std::cout << "r (Rock)" << "\n";
        std::cout << "p (Paper)" << "\n";
        std::cout << "s (Scissors)" << "\n";
        std::cout << "####################################" << "\n";
        std::cout << "Selection : ";
        std::cin >> selection;

        return selection;

    } while (selection == 'r' && selection == 'p' || selection == 's');

}

char generateBotSelection(){

    srand(time(NULL));
    int num = rand() % 3 + 1;

    switch(num){
        case 1: return 'r'; break;
        case 2: return 'p'; break;
        case 3: return 's'; break;
    }

    return 0;

}

int processWinner(char human, char bot){

    if (human == bot){
        return 0;
    }
    else if (human == 'r' && bot == 's'){
        return 1;
    }
    else if (human == 'p' && bot == 'r'){
        return 1;
    }
    else if (human == 's' && bot == 'p'){
        return 1;
    }
    else{
        return 2;
    }

}

void displayWinner(int decider){

    switch(decider){
        case 0:
            std::cout << "The human and bot have tied!" << "\n";
            break;
        case 1:
            std::cout << "The human has defeated the bot!" << "\n";
            break;
        case 2:
            std::cout << "The bot has defeated the human!" << "\n";
            break;
    }

}

void displayBothSelections(char human, char bot){

    std::cout << "Human selection: " << human << "\n";
    std::cout << "Bot selection: " << bot << "\n";

}

