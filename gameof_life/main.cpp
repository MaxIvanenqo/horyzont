#include "class/game.cpp"
#include <vector>
#include <utility>

int main(int argc, const char** argv) {
    std::vector<std::pair<int,int>> V;
    V.emplace_back(std::make_pair(31,14));
    V.emplace_back(std::make_pair(27,48));
    V.emplace_back(std::make_pair(12,32));
    V.emplace_back(std::make_pair(41,15));
    V.emplace_back(std::make_pair(20,9));
    V.emplace_back(std::make_pair(49,12));
    Game game(V);
    game.check();

    return 0;
}