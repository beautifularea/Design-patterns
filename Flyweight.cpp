//
//  Flyweight.hpp
//  COns
//
//  Created by zhTian on 16/4/16.
//  Copyright © 2016年 zhTian. All rights reserved.
//

#ifndef Flyweight_hpp
#define Flyweight_hpp

#include <iostream>
#include <vector>

#define NUMBER_OF_SAME_TYPE_CHARS 3;

class FlyweightCharacter;

class FlyweightCharacterAbstractBuilder
{
public:
    FlyweightCharacterAbstractBuilder(){}
    FlyweightCharacterAbstractBuilder(const FlyweightCharacterAbstractBuilder&){}
    FlyweightCharacterAbstractBuilder& operator=(const FlyweightCharacterAbstractBuilder&) = delete;
    virtual ~FlyweightCharacterAbstractBuilder(){}
    
public:
    static void setFontsAndNames();
    static FlyweightCharacter createFlyweightCharacter(unsigned short fontSizeIndex,
                                                       unsigned short fontNameIndex,
                                                       unsigned short positionInStream);
    
public:
    static std::vector<float> s_fontSizes;
    static std::vector<std::string> s_fontNames;
};

std::vector<float> fontSizes(3);
std::vector<std::string> fontNames(3);

void FlyweightCharacterAbstractBuilder::setFontsAndNames() {
    fontSizes[0] = 1.0; fontSizes[1] = 1.5; fontSizes[2] = 2.0;
    fontNames[0] = "first_font"; fontNames[1] = "second_font"; fontNames[2] = "third_font";
}

class FlyweightCharacter
{
    unsigned short fontSizeIndex; // index instead of actual font size
    unsigned short fontNameIndex; // index instead of font name
    unsigned positionInStream;
public:
    FlyweightCharacter(unsigned short fontSizeIndex,
                       unsigned short fontNameIndex,
                       unsigned short positionInStream):
    fontSizeIndex(fontSizeIndex),
    fontNameIndex(fontNameIndex),
    positionInStream(positionInStream) {}
    
    void print() {
        std::cout << "Font Size: " <<
        ::fontSizes[fontSizeIndex] <<
        ", font Name: " <<
        ::fontNames[fontNameIndex] <<
        ", character stream position: " <<
        positionInStream <<
        std::endl;
    }
    
    ~FlyweightCharacter() {}
};

FlyweightCharacter createFlyweightCharacter(unsigned short fontSizeIndex,
                                            unsigned short fontNameIndex,
                                            unsigned short positionInStream) {
    FlyweightCharacter fc(fontSizeIndex, fontNameIndex, positionInStream);
    return fc;
}

class FlyweightDemo
{
public:
    void excute()
    {
        std::vector<FlyweightCharacter> chars;
        
        FlyweightCharacterAbstractBuilder::setFontsAndNames();
        
        unsigned short limit = NUMBER_OF_SAME_TYPE_CHARS;
        for (unsigned short i = 0; i < limit; i++) {
            chars.push_back(FlyweightCharacterAbstractBuilder::createFlyweightCharacter(0, 0, i));
            chars.push_back(FlyweightCharacterAbstractBuilder::createFlyweightCharacter(1, 1, i + 1                                                                                                                                    * limit));
            
            chars.push_back(FlyweightCharacterAbstractBuilder::createFlyweightCharacter(2, 2, i + 2
                                                                                        * limit));
        }
    }
};

#endif /* Flyweight_hpp */
