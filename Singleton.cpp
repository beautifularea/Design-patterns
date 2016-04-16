class S
{
public:
    static S *getInstance()
    {
        static S  *instance = new S(); // Guaranteed to be destroyed.
        // Instantiated on first use.
        return instance;
    }
private:
    S() {};                   // Constructor? (the {} brackets) are needed here.
    
    // C++ 03
    // ========
    // Dont forget to declare these two. You want to make sure they
    // are unacceptable otherwise you may accidentally get copies of
    // your singleton appearing.
//    S(S const&);              // Don't Implement
//    void operator=(S const&); // Don't implement
    
    // C++ 11
    // =======
    // We can use the better technique of deleting the methods
    // we don't want.
public:
    S(S const&)               = delete;
    void operator=(S const&)  = delete;
    
    // Note: Scott Meyers mentions in his Effective Modern
    //       C++ book, that deleted functions should generally
    //       be public as it results in better error messages
    //       due to the compilers behavior to check accessibility
    //       before deleted status
    
    void test();
};


//Another Example:
class StringSingleton
{
public:
    std::string getString() const
    {
        return mString;
    }
    
    void setString(const std::string& newStr)
    {
        mString = newStr;
    }
    
public:
    static StringSingleton& instance()
    {
        static StringSingleton *instance = new StringSingleton;
        return *instance;
    }
    
private:
    StringSingleton(){}
    StringSingleton(const StringSingleton&);
    const StringSingleton& operator=(const StringSingleton&);
    ~StringSingleton(){}
    
private:
    std::string mString;
};



