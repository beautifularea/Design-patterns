//
//  Adapter.hpp
//  COns
//
//  Created by zhTian on 16/4/16.
//  Copyright © 2016年 zhTian. All rights reserved.
//

#ifndef Adapter_hpp
#define Adapter_hpp

#include <iostream>

class Muslim
{
public:
    Muslim(){};
    Muslim(const Muslim&);
    Muslim& operator=(const Muslim&);
    virtual ~Muslim() = default;
    
public:
    virtual void performMuslimRitual() const = 0;
};

class MuslimFemale : public Muslim
{
public:
    MuslimFemale(){};
    MuslimFemale(const MuslimFemale&);
    MuslimFemale& operator=(const MuslimFemale&);
    virtual ~MuslimFemale(){};
    
public:
    virtual void performMuslimRitual() const
    {
        std::cout << "Muslim girl performs Muslim ritual." << std::endl;
    }
};

class Hindu
{
public:
    Hindu(){};
    Hindu(const Hindu&);
    Hindu& operator=(const Hindu&);
    virtual ~Hindu() = default;
    
public:
    virtual void performsHinduRitual() const = 0;
};

class HinduFemale : public Hindu
{
public:
    HinduFemale(){};
    HinduFemale(const HinduFemale&);
    HinduFemale& operator=(const HinduFemale&);
    virtual ~HinduFemale(){};
    
public:
    virtual void performsHinduRitual() const
    {
        std::cout << "Hindu girl performs Hindu ritual." << std::endl;
    }
};

class MuslimRitual
{
public:
    MuslimRitual(){};
    MuslimRitual(const MuslimRitual&);
    MuslimRitual& operator=(const MuslimRitual&);
    virtual ~MuslimRitual(){};
    
public:
    void carrayOutRitual(Muslim *muslim)
    {
        std::cout << "On with the muslim rituals." << std::endl;
        muslim->performMuslimRitual();
    }
};

//Adapter
class MuslimAdapter : public Muslim
{
public:
    MuslimAdapter();
    MuslimAdapter(const MuslimAdapter&);
    MuslimAdapter& operator=(const MuslimAdapter&);
    virtual ~MuslimAdapter(){};
    
public:
    MuslimAdapter(Hindu *h) : m_hindu(h){}
    
public:
    virtual void performMuslimRitual() const
    {
        m_hindu->performsHinduRitual();
    }
    
private:
    Hindu *m_hindu;
};

#endif /* Adapter_hpp */
