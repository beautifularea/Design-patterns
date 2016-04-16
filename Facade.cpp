//
//  Facade.hpp
//  COns
//
//  Created by zhTian on 16/4/16.
//  Copyright © 2016年 zhTian. All rights reserved.
//

#ifndef Facade_hpp
#define Facade_hpp

#include <iostream>

class Alarm
{
public:
    Alarm(){}
    Alarm(const Alarm&){}
    Alarm& operator=(const Alarm&) = delete;
    virtual ~Alarm(){}
    
public:
    void alarmOn()
    {
        std::cout << "Alarm is on." << std::endl;
    }
    
    void alarmOff()
    {
        std::cout << "Alarm is Off." << std::endl;
    }
};

class Ac
{
public:
    Ac(){}
    Ac(const Ac&){}
    Ac& operator=(const Ac&) = delete;
    virtual ~Ac(){}
    
public:
    void AcOn()
    {
        std::cout << "Ac is On." << std::endl;
    }
    
    void AcOff()
    {
        std::cout << "Ac is Off." << std::endl;
    }
};

class Tv
{
public:
    Tv(){}
    Tv(const Tv&){}
    Tv& operator=(const Tv&) = delete;
    virtual ~Tv(){}
    
public:
    void TvOn()
    {
        std::cout << "Tv is On." << std::endl;
    }
    
    void TvOff()
    {
        std::cout << "Tv is Off." << std::endl;
    }
};

class HouseFacade
{
public:
    HouseFacade(){}
    HouseFacade(const HouseFacade&){}
    HouseFacade& operator=(const HouseFacade&) = delete;
    virtual ~HouseFacade(){}
    
public:
    void gotowork()
    {
        alarm.alarmOn();
        tv.TvOff();
        ac.AcOff();
    }
    
    void comeHome()
    {
        alarm.alarmOff();
        tv.TvOn();
        ac.AcOn();
    }
    
private:
    Alarm alarm;
    Ac ac;
    Tv tv;
};


#endif /* Facade_hpp */
