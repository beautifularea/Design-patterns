//
//  Proxy.hpp
//  COns
//
//  Created by zhTian on 16/5/5.
//  Copyright © 2016年 zhTian. All rights reserved.
//

#ifndef Proxy_hpp
#define Proxy_hpp

#include <iostream>

class ICar {
public:
    virtual void DriveCar() = 0;
};

class Car : public ICar {
public:
    Car(int driver_age, ICar* pCar) : _pImpl(pCar), _driver_age(driver_age) {}
    
    void DriveCar() {
        if (_driver_age >= 16)
            _pImpl->DriveCar();
    }
    
private:
    ICar* _pImpl;
    int _driver_age;
};

#endif /* Proxy_hpp */
