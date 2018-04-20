#include <stdint.h>

namespace characterLimitation
{
    const uint32_t MAX_TRAIT_VALUE = 1000;
};

class Trait
{
private:
    uint32_t currentValue;
    const uint32_t limit;
public:
    Trait ( uint32_t, const uint32_t limit );
    void increase ( uint32_t );
    uint32_t getValue ( );
};


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

class GraphContent
{
    void interface(void);
private:
};

class GraphAlgorithm
{
public:
};



int main ( )
{
    return 0;
}
