#ifndef Pizza_hpp
#define Pizza_hpp

#include <iostream>
#include <memory>


template<typename T, typename... Args>
std::unique_ptr<T> make_unique(Args&&... args) {
    return std::unique_ptr<T>(new T(std::forward<Args>(args)...));
}


class Pizza
{
    //Four memeber functions
public:
    Pizza();
    Pizza(const Pizza&);
    Pizza& operator=(const Pizza&);
    ~Pizza();
    
public:
    void setDough(const std::string& dough)
    {
        m_dough = dough;
    }
    
    void setSauce(const std::string& sauce)
    {
        m_sauce = sauce;
    }
    
    void setTopping(const std::string& topping)
    {
        m_topping = topping;
    }
    
    void open() const
    {
        std::cout << "Pizza with " << m_dough << "dough, " << m_sauce << " sauce and " << m_topping << " topping. Mmm" << std::endl;
    }
    
private:
    std::string m_dough;
    std::string m_sauce;
    std::string m_topping;
};

class PizzaBuilder
{
public:
    PizzaBuilder();
    PizzaBuilder(const PizzaBuilder&);
    PizzaBuilder& operator=(const PizzaBuilder&);
    virtual ~PizzaBuilder();
    
    Pizza *getPizza()
    {
        return m_pizza.get();
    }
    
    void createNewPizzaProduct()
    {
        m_pizza = make_unique<Pizza>();
    }
    
    virtual void buildDough() = 0;
    virtual void buildSauce() = 0;
    virtual void buildTopping() = 0;
    
protected:
    std::unique_ptr<Pizza> m_pizza;
};

class HawaiiPizzaBuilder : public PizzaBuilder
{
public:
    HawaiiPizzaBuilder();
    HawaiiPizzaBuilder(const HawaiiPizzaBuilder&);
    HawaiiPizzaBuilder& operator=(const HawaiiPizzaBuilder&);
    virtual ~HawaiiPizzaBuilder();
    
public:
    void buildDough()
    {
        m_pizza->setDough("cross");
    }
    
    void buildSauce()
    {
        m_pizza->setSauce("mild");
    }
    
    void buildTopping()
    {
        m_pizza->setTopping("ham+pineapple");
    }
};

class SpicyPizzaBuilder : public PizzaBuilder
{
public:
    SpicyPizzaBuilder();
    SpicyPizzaBuilder(const SpicyPizzaBuilder&);
    SpicyPizzaBuilder& operator=(const SpicyPizzaBuilder&);
    ~SpicyPizzaBuilder();
    
public:
    void buildDough()
    {
        m_pizza->setDough("pan baked");
    }
    
    void buildSauce()
    {
        m_pizza->setSauce("hot");
    }
    
    void buildTopping()
    {
        m_pizza->setTopping("pepperoni+salami");
    }
};

class Cook
{
public:
    Cook();
    Cook(const Cook&);
    Cook& operator=(const Cook&);
    ~Cook();
    
public:
    void openPizza()
    {
        m_pizzaBuilder->getPizza()->open();
    }
    
    void makePizza(PizzaBuilder *pb)
    {
        m_pizzaBuilder = pb;
        m_pizzaBuilder->createNewPizzaProduct();
        m_pizzaBuilder->buildDough();
        m_pizzaBuilder->buildSauce();
        m_pizzaBuilder->buildTopping();
    }
    
private:
    PizzaBuilder *m_pizzaBuilder;
};













#endif /* Pizza_hpp */
