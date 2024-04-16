#include "HeaderGameEngine.h"

using namespace std;

int main() {
   
    auto myGame = make_unique<GameEngine>();
    myGame->run();
    return 0;

}