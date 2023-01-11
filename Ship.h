
#ifndef SHIP
#define SHIP
#include <string>
#include <vector>
#include <iostream>

using namespace std;
namespace Ship
{
    class Ship;
}
class Ship::Ship
{
public:
    Ship();

private:
    int dimensione;
    int corazza;
};
#endif