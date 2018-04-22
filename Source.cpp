#include <stdint.h>
#include <string>
#include <vector>
#include <iostream>

//*********** TODO:
//*********** 1. implement error handling

//*********** GLOBAL VALUES

namespace characterLimitation
{
    const uint32_t MAX_ABILITY_VALUE = 1000;
};


//*********** OUTPUTTER
//*********** todo:
class Outputter
{
public:
    virtual void output ( const std::string& ) = 0;
};

class consoleOutput : public Outputter
{
    void output( const std::string& );
};

void consoleOutput::output(const std::string& log)
{
    std::cout << log << std::endl;
}
//*********** OUTPUTTER_END


//*********** LOGGER
//*********** todo:
//*********** 1. Logger should have filename, line, and some parameters
class Logger
{
private:
    static Outputter* loggerOutputter;
    static Logger* singlton_logger;
    Logger ();
    ~Logger ();
public:
    static void setOutputter(Outputter*);
    static const Logger* getLogger ( );
    static void addRecord ( const std::string& record );
};

Logger::Logger()
{
}

Logger::~Logger()
{
}

void Logger::setOutputter(Outputter* _outputter)
{
    loggerOutputter = _outputter;
}

void Logger::addRecord (const std::string& record)
{
    if (nullptr == loggerOutputter)
    {
        throw "critical issue";
    }
    else
    {
        loggerOutputter->output(record);
    }
}

Logger * Logger::singlton_logger = nullptr;
Outputter * Logger::loggerOutputter = nullptr;

const Logger* Logger::getLogger ( )
{
    if (nullptr == singlton_logger)
    {
        singlton_logger = new Logger;
    }
    return singlton_logger;
}
//*********** LOGGER_END

//*********** ABILITY
class Ability
{
private:
    uint32_t currentValue;
    const uint32_t limit;
public:
    explicit Ability ( const uint32_t, const uint32_t );
    Ability ( ) = delete;
    void improve ( const uint32_t );
    uint32_t getValue ( )const;
};

Ability::Ability ( uint32_t value, const uint32_t _limit = characterLimitation::MAX_ABILITY_VALUE ) : currentValue ( value ), limit ( _limit )
{
    if (currentValue > limit/2)
    {
        Logger::getLogger()->addRecord ( " wrong initialization " );

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

uint32_t Ability::getValue( )const
{
    return currentValue;
}
//*********** ABILITY_END

//*********** CAPABILITY
//*********** todo:
//*********** 1. place to register observer to send event in case of currentValue == 0
//*********** 2. place for observer notification

class Capability
{
private:
    uint32_t currentValue;
    const Ability& ability;
public:
    explicit Capability(const Ability&);
    Capability() = delete;
    void update();
    void spend(const uint32_t);
    uint32_t getValue()const;
};

Capability::Capability(const Ability& _ability):ability(_ability)
{
    //place to register observer to send event in case of currentValue == 0
};

void Capability::update()
{
    currentValue = ability.getValue();
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

uint32_t Capability::getValue()const
{
    return currentValue;
}
//*********** CAPABILITY_END
int main ( )
{
    return 0;
}
