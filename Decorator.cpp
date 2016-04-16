//
//  Decorator.hpp
//  COns
//
//  Created by zhTian on 16/4/16.
//  Copyright © 2016年 zhTian. All rights reserved.
//

#ifndef Decorator_hpp
#define Decorator_hpp

#include <iostream>

class Car
{
public:
    Car()
    {
        m_name = "Unknown car";
    }
    
    Car(const Car&){}
    Car& operator=(const Car&) = delete;
    virtual ~Car()
    {
        std::cout << "~Car()" << std::endl;
    }
    
public:
    virtual std::string getDescription()
    {
        return m_name;
    }
    
    virtual double getCost() = 0;
    
protected:
    std::string m_name;
};

//Concrete Car
class CarModell : public Car
{
public:
    CarModell()
    {
        m_name = "CarModell";
    }
    
    CarModell(const CarModell&){}
    CarModell& operator=(const CarModell&) = delete;
    
    ~CarModell()
    {
        std::cout << "~CarModell()" << std::endl;
    }
    
public:
    double getCost()
    {
        return 310000.23;
    }
};

//Decorator
class Decorator : public Car
{
public:
    Decorator(){}
    Decorator(const Decorator&){}
    Decorator& operator=(const Decorator&) = delete;
    virtual ~Decorator()
    {
        std::cout << "~Decorator()" << std::endl;
    }
    
public:
    virtual std::string getDescription() = 0;
    virtual double getCost() = 0;
};

class Navigation : public Decorator
{
public:
    Navigation(){}
    Navigation(const Navigation&){}
    Navigation& operator=(const Navigation&) = delete;
    virtual ~Navigation()
    {
        std::cout << "~Navigation()" << std::endl;
    }
    
public:
    Navigation(Car *b) : m_b(b){}
    
public:
    std::string getDescription()
    {
        return m_b->getDescription() + ", Navigaton.";
    }
    
    double getCost()
    {
        return 200.3 + m_b->getCost();
    }
    
private:
    Car *m_b;
};

class PremiumSoundSystem : public Decorator
{
public:
    PremiumSoundSystem(){}
    PremiumSoundSystem(const PremiumSoundSystem&){}
    PremiumSoundSystem& operator=(const PremiumSoundSystem&) = delete;
    virtual ~PremiumSoundSystem()
    {
        std::cout << "~PremiumSoundSystem()" << std::endl;
    }
    
public:
    PremiumSoundSystem(Car *b) : m_b(b){}
    
public:
    std::string getDescription()
    {
        return m_b->getDescription() + ", PremiumSoundSystem.";
    }
    
    double getCost()
    {
        return 11.34 + m_b->getCost();
    }
    
private:
    Car *m_b;
};

class ManualTransmission : public Decorator
{
public:
    ManualTransmission(){}
    ManualTransmission(const ManualTransmission&){}
    ManualTransmission& operator=(const ManualTransmission&) = delete;
    virtual ~ManualTransmission()
    {
        std::cout << "~ManualTransmission()" << std::endl;
    }
    
public:
    ManualTransmission(Car *b) : m_b(b){}
    
public:
    std::string getDescription()
    {
        return m_b->getDescription() + ", ManualTransmission";
    }
    
    double getCost()
    {
        return 14.45 + m_b->getCost();
    }
    
private:
    Car *m_b;
};

class CarDecoratorExample
{
public:
    void excute()
    {
        Car *b = new CarModell();
        
        std::cout << "base model of " << b->getDescription() << " , and cost is " << b->getCost() << std::endl;
        
        //let's add some features.
        b = new Navigation(b);
        
        //set cout precision to output double type value.
        std::cout.precision(10);
        
        std::cout << b->getDescription() << " will cost you " << b->getCost() << std::endl;
        
        b = new PremiumSoundSystem(b);
        std::cout << b->getDescription() << " will cost you " << b->getCost() << std::endl;

        b = new ManualTransmission(b);
        std::cout << b->getDescription() << " will cost you " << b->getCost() << std::endl;
        
    }
};


#endif /* Decorator_hpp */
