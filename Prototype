#ifndef Record_hpp
#define Record_hpp

#include <iostream>
#include <unordered_map>
#include <memory>
#include <string>

enum RecordType {
    CAR,
    BIKE,
    PERSON
};

template<typename T, typename... Args>
std::unique_ptr<T> make_unique(Args&&... args) {
    return std::unique_ptr<T>(new T(std::forward<Args>(args)...));
}

class Record
{
public:
    Record();
    Record(const Record&);
    Record& operator=(const Record&);
    virtual ~Record();
    
public:
    virtual void print() = 0;
    virtual std::unique_ptr<Record> clone() = 0;
};

class CarRecord : public Record
{
public:
    CarRecord();
    CarRecord(std::string carName, int ID) : m_carName(carName), m_ID(ID){}
    CarRecord(const CarRecord&);
    CarRecord& operator=(const CarRecord&);
    virtual ~CarRecord();
    
public:
    void print()
    {
        std::cout << "CarRecord: " << std::endl ;
        std::cout << m_carName << std::endl;
        std::cout << m_ID << std::endl;
    }
    
    std::unique_ptr<Record> clone()
    {
        return make_unique<CarRecord>(*this);
    }

private:
    std::string m_carName;
    int m_ID;
};

class BikeRecord : public Record
{
public:
    BikeRecord();
    BikeRecord(const BikeRecord&);
    BikeRecord& operator=(const BikeRecord&);
    virtual ~BikeRecord();
    
public:
    BikeRecord(std::string bikeName, int ID) : m_bikeName(bikeName), m_ID(ID){}
    
    void print()
    {
        std::cout << "Bike Record " << std::endl;
        std::cout << "Name = " << m_bikeName << std::endl;
        std::cout << "Number = " << m_ID << std::endl;
    }
    
    std::unique_ptr<Record> clone()
    {
        return make_unique<BikeRecord>(*this);
    }
    
private:
    std::string m_bikeName;
    int m_ID;
};

class PersonRecord : public Record
{
public:
    PersonRecord();
    PersonRecord(const PersonRecord&);
    PersonRecord& operator=(const PersonRecord&);
    ~PersonRecord();
    
public:
    PersonRecord(std::string personName, int age) : m_personName(personName) , m_age(age){}
    
    void print()
    {
        std::cout << "Person Record" << std::endl;
        std::cout << "Name = " << m_personName << std::endl;
        std::cout << "Age = " << m_age << std::endl;
    }
    
    std::unique_ptr<Record> clone()
    {
        return make_unique<PersonRecord>(*this);
    }
    
private:
    std::string m_personName;
    int m_age;
};



class RecordFactory
{
public:
    RecordFactory()
    {
        std::unique_ptr<CarRecord> carR = make_unique<CarRecord>("Ferrari", 5050);
        std::unique_ptr<BikeRecord> bikeR = make_unique<BikeRecord>("Yamaha", 2525);
        std::unique_ptr<PersonRecord> pR = make_unique<PersonRecord>("Tom", 25);
        
        m_records[CAR] = carR;
        m_records[BIKE] = bikeR;
        m_records[PERSON] = pR;
    }
    
    RecordFactory(const RecordFactory&);
    RecordFactory& operator=(const RecordFactory&);
    virtual ~RecordFactory();
    
public:
    std::unique_ptr<Record> createRecord(RecordType recordType)
    {
        return m_records[recordType]->clone();
    }
    
private:
    std::unordered_map<RecordType, std::unique_ptr<Record>> m_records;
};
























#endif /* Record_hpp */
