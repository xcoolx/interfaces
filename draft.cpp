#include <stdint.h>

class Vehicle
{
private:
    uint32_t speed;
};

class Character
{
public:
    virtual void increaseMaxEnergy ( uint32_t ) = 0;
    virtual void decreaseEnergy ( uint32_t ) = 0;
private:
    int32_t cash;
    uint32_t happiness;
    uint32_t energy;
    uint32_t maxEnergy;
    Vehicle *vehicle;
};
