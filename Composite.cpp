//
//  Composite.hpp
//  COns
//
//  Created by zhTian on 16/4/16.
//  Copyright © 2016年 zhTian. All rights reserved.
//

#ifndef Composite_hpp
#define Composite_hpp

#include <iostream>
#include <vector>
#include <memory>
#include <algorithm>

class Graghic
{
public:
    Graghic(){}
    Graghic(const Graghic&){}
    Graghic& operator=(const Graghic&) = delete;
    virtual ~Graghic(){}
    
public:
    virtual void print() const = 0;
};

class Ellipse : public Graghic
{
public:
    Ellipse(){}
    Ellipse(const Ellipse&){}
    Ellipse& operator=(const Ellipse&) = delete;
    virtual ~Ellipse(){}
    
public:
    void print() const
    {
        std::cout << "Ellipse." << std::endl;
    }
};

class CompositeGraghic : public Graghic
{
public:
    CompositeGraghic(){}
    CompositeGraghic(const CompositeGraghic&){}
    CompositeGraghic& operator=(const CompositeGraghic&) = delete;
    virtual ~CompositeGraghic(){}
    
public:
    void print() const
    {
        for_each(m_graphicList.begin(), m_graphicList.end(), [](Graghic *a){
            a->print();
        });
    }
    
    void add(Graghic *g)
    {
        m_graphicList.push_back(g);
    }
    
private:
    std::vector<Graghic*> m_graphicList;
};












#endif /* Composite_hpp */
