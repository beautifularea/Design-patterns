//
//  Bridge.hpp
//  COns
//
//  Created by zhTian on 16/4/16.
//  Copyright © 2016年 zhTian. All rights reserved.
//

#ifndef Bridge_hpp
#define Bridge_hpp

#include <iostream>

class DrawAPI
{
public:
    DrawAPI(){}
    DrawAPI(const DrawAPI&){}
    DrawAPI& operator=(const DrawAPI&) = delete;
    virtual ~DrawAPI(){}
    
public:
    virtual void draw_circle(double, double, double) = 0;
};

class DrawAPI_1 : public DrawAPI
{
public:
    DrawAPI_1(){}
    DrawAPI_1(const DrawAPI_1&){}
    DrawAPI_1& operator=(const DrawAPI_1&) = delete;
    virtual ~DrawAPI_1(){}
    
public:
    void draw_circle(double x, double y, double z)
    {
        std::cout << "api_1 draw : x = " << x << " y = " << y << " z = " << z << std::endl;
    }
};

class DrawAPI_2 : public DrawAPI
{
public:
    DrawAPI_2(){}
    DrawAPI_2(const DrawAPI_2&){}
    DrawAPI_2& operator=(const DrawAPI_2&) = delete;
    virtual ~DrawAPI_2(){}
    
public:
    void draw_circle(double x, double y, double z)
    {
        std::cout << "api_2 draw : x = " << x << " y = " << y << " z = " << z << std::endl;
    }
};

class Shape
{
public:
    Shape(){}
    Shape(const Shape&){}
    Shape& operator=(const Shape&) = delete;
    virtual ~Shape(){}
    
public:
    virtual void draw() = 0;
    virtual void resizeByPercentage(double) = 0;
};

class CircleShape : public Shape
{
public:
    CircleShape(){}
    CircleShape(const CircleShape&){}
    CircleShape& operator=(const CircleShape&) = delete;
    virtual ~CircleShape(){}
    
public:
    CircleShape(double x, double y, double z, DrawAPI *api) : m_x(x), m_y(y), m_z(z),m_drawingAPI(api){}
    
public:
    void resizeByPercentage(double pct)
    {
        m_z *= pct;
    }
    
    void draw()
    {
        m_drawingAPI->draw_circle(m_x, m_y, m_z);
    }
    
private:
    double m_x, m_y, m_z;
    DrawAPI *m_drawingAPI;
};

#endif /* Bridge_hpp */
