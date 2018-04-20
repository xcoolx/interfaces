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
    static std::vector<std::string> storage;
    static Logger* logger;
    Logger ( );
    ~Logger ( );
public:
    static Logger* getLogger ( );
    static void addRecord ( std::string record );
    static void output ( );
};

void Logger::addRecord ( std::string record )
{
    storage.push_back ( record );
}

Logger * Logger::logger = nullptr;

void Logger::output ( )
{
    std::vector<std::string>::iterator it;
    for (it = storage.begin ( ); it != storage.end ( ); it++)
    {
        outputter->output( *it );
    }
}

Logger* Logger::getLogger ( )
{
    if (nullptr == logger)
    {
        logger = new Logger;
    }
    return logger;
}

Logger::~Logger ( )
{
    if (nullptr != logger)
    {
        delete logger;
    }
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
    explicit Ability ( uint32_t, const uint32_t limit );
    Ability ( ) = delete;
    void improve ( uint32_t );
    uint32_t getValue ( );
};

class Capability
{
private:

};

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

uint32_t Ability::getValue ( )
{
    return currentValue;
}



int main ( )
{
    return 0;
}
