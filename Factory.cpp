
#ifndef Computer_hpp
#define Computer_hpp

#include <iostream>

class Computer
{
public:
    Computer(){}
    Computer(const Computer&){}
    Computer& operator=(const Computer&);
    virtual ~Computer(){}
    
public:
    virtual void Run() = 0;
    virtual void Stop() = 0;
};

class Laptop: public Computer
{
public:
    Laptop();
    Laptop(const Laptop&);
    Laptop& operator=(const Laptop&);
    virtual ~Laptop();
    
public:
    virtual void Run()
    {
        mHibernating = false;
    }
    
    virtual void Stop()
    {
        mHibernating = true;
    }
    
private:
    bool mHibernating;
};

class Desktop : public Computer
{
public:
    Desktop();
    Desktop(const Desktop&);
    Desktop& operator=(const Desktop&);
    virtual ~Desktop();
    
public:
    virtual void Run()
    {
        mOn = true;
    }
    
    virtual void Stop()
    {
        mOn = false;
    }
    
private:
    bool mOn;
};

class ComputerFactory
{
public:
    ComputerFactory();
    ComputerFactory(const ComputerFactory&);
    ComputerFactory& operator=(const ComputerFactory&);
    virtual ~ComputerFactory();
    
public:
    static Computer *newComputer(const std::string& description)
    {
        if(description == "laptop")
        {
            return new Laptop();
        }
        
        if(description == "desktop")
        {
            return new Desktop();
        }
        
        return nullptr;
    }
};













#endif /* Computer_hpp */
