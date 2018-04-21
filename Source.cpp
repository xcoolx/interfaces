#include <stdint.h>
#include <string>
#include <vector>

class Outputter
{
public:
    virtual void output ( std::string ) = 0;
};

class Logger
{
private:
    static Outputter* outputter;
    static Logger* logger;
    Logger ( );
    ~Logger ( );
public:
    static Logger* getLogger ( );
    static void addRecord ( std::string record );
};

void Logger::addRecord ( std::string record )
{
    outputter->output(record);
}

Logger * Logger::logger = nullptr;

Logger* Logger::getLogger ( )
{
    if (nullptr == logger)
    {
        logger = new Logger;
    }
    return logger;
}

namespace characterLimitation
{
    const uint32_t MAX_ABILITY_VALUE = 1000;
};

class Ability
{
private:
    uint32_t currentValue;
    const uint32_t limit;
public:
    explicit Ability ( uint32_t, const uint32_t );
    Ability ( ) = delete;
    void improve ( uint32_t );
    virtual uint32_t getValue ( );
};

class Capability
{
private:
    uint32_t currentValue;
    Ability *ability;
public:
    explicit Capability(Ability *);
    Capability() = delete;
    void update();
    void spend(uint32_t);
    uint32_t getValue();
};

Capability::Capability(Ability *_ability)
{
    if (nullptr == _ability)
    {
        Logger *log = Logger::getLogger();
        log->addRecord(" wrong initialization ");
        throw "critical issue";
    }
    else
    {
        ability = _ability;
    }
    //place to register observer to send event in case of currentValue == 0
};

void Capability::update()
{
    currentValue = ability->getValue();
}

void Capability::spend(uint32_t value)
{
    if (currentValue <= value)
    {
        currentValue = 0;
        //place for observer notification
    }
    else
    {
        currentValue -= value;
    }
}

uint32_t Capability::getValue()
{
    return currentValue;
}

Ability::Ability ( uint32_t value, const uint32_t _limit = characterLimitation::MAX_ABILITY_VALUE ) : currentValue ( value ), limit ( _limit )
{
    if (currentValue > limit/2)
    {
        Logger *log = Logger::getLogger ( );
        log->addRecord ( " wrong initialization " );

        currentValue = limit;
    }
};

void Ability::improve ( uint32_t value )
{
    currentValue += value;
    if (limit < currentValue)
    {
        currentValue = limit;
    }
}

uint32_t Ability::getValue( )
{
    return currentValue;
}



int main ( )
{
    return 0;
}
