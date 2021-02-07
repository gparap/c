// Classes.cpp
// Created by gparap

#include <iostream>

using namespace std;

class MyClass {
public:
    int x, y, z;
    MyClass(){
        x = y = z = 0;
    }
    MyClass(int x, int y, int z) {
        cout << "Constructor.." << endl;
        this->x = x;
        this->y = y;
        this->z = z;
    }
    ~MyClass() {
        cout << "Destructor.." << endl;
    }
    void printValues() {
        cout << "x: " << x << endl;
        cout << "y: " << y << endl;
        cout << "z: " << z << endl;
    }
};
void MyClassFunction() {
    MyClass myClass(2, 2, 2);
    std::cout << "x=" << myClass.x << " y=" << myClass.y << " z=" << myClass.z << std::endl;
}
class MyClassChild : public MyClass {
public:
    int a = 0;
    void printValue() {
        cout << "a: " << a << endl;
    }
};

struct MyStruct {
    int var1 = 5, var2 = 5;
    void addOne(int var1, int var2) {
        this->var1++;
        this->var2++;
    }
    void addOne(const MyStruct& myStruct) {
        this->var1 = myStruct.var1 + 1;
        this->var2 += myStruct.var2;
    }
    void printVars() {
        std::cout << "var1 = " << var1 << std::endl;
        std::cout << "var2 = " << var2;
    }
};

class MyStatic {
public:
    static int x, y;
    void consoleLog() {
        cout << "x: " << x << ", y: " << y << endl;
    }
};
int MyStatic::x;
int MyStatic::y;

void MyStaticFunction() {
    static int counter = 0;
    counter++;
    cout << "counter: " << counter << endl;
}

class Log {
public:
    enum LogLevel {
		VERBOSE = 0,
        TRACE = 1,
        INFO = 2,
        WARNING = 3,
        ERROR = 4
    };
    void log(const char *logMessage) {
        if (logLevel == ERROR) {
            cout << "   ERROR: " << logMessage << endl;
            std::cout << "----------------------\n";
        } else if (logLevel == WARNING) {
            cout << " WARNING: " << logMessage << endl;
            cout << "   ERROR: " << logMessage << endl;
            std::cout << "----------------------\n";
        } else if (logLevel == INFO) {
            cout << "    INFO: " << logMessage << endl;
            cout << " WARNING: " << logMessage << endl;
            cout << "   ERROR: " << logMessage << endl;
            std::cout << "----------------------\n";
        } else if (logLevel == TRACE) {
            cout << "   TRACE: " << logMessage << endl;
            cout << "    INFO: " << logMessage << endl;
            cout << " WARNING: " << logMessage << endl;
            cout << "   ERROR: " << logMessage << endl;
            std::cout << "----------------------\n";
        } else {
			cout << " VERBOSE: " << logMessage << endl;
            cout << "   TRACE: " << logMessage << endl;
            cout << "    INFO: " << logMessage << endl;
            cout << " WARNING: " << logMessage << endl;
            cout << "   ERROR: " << logMessage << endl;
            std::cout << "----------------------\n";
        }
    }
    void SetLogLevel(LogLevel logLevel) {
        this->logLevel = logLevel;
    }
private:
    LogLevel logLevel = VERBOSE;
};

class MyPureVirtual {
public:
    virtual void Print() = 0;
};
class MyVirtualBase : public MyPureVirtual {
public:
    virtual string GetType() {
        return "Base";
    }
    void Print() override {
        cout << "MyVirtualBase" << endl;
    }
};
class MyVirtualChild : public MyVirtualBase, public MyPureVirtual {
private:
    string type;
public:
    MyVirtualChild(const string &type){
        this->type = type;
    }
    string GetType() override {
        return type;
    }
    void Print() override {
        cout << "MyVirtualChild" << endl;
    }
};
void MyVirtualFunction(MyVirtualBase *base) {
    cout << base->GetType() << endl;
}
void MyPureVirtualFunction(MyPureVirtual *instance) {
    instance->Print();
}

int main()
{
    std::cout << "\nClass\n";
    MyClassFunction();
    MyClassChild myClassChild;
    myClassChild.x = 5;
    myClassChild.y = 5;
    myClassChild.z = 5;
    myClassChild.printValues();
    myClassChild.printValue();

    std::cout << "\nStruct\n";
    MyStruct myStruct0; 
    myStruct0.var1 = 10; 
    myStruct0.var2 = 10;

    MyStruct myStruct;
    myStruct.addOne(10,10);
    myStruct.addOne(myStruct0);
    myStruct.printVars();

    // log information based on logging levels
    Log logInstance;
    std::cout << "Log\n";
    std::cout << "---\n";
    logInstance.log("Testing Log...");
    logInstance.SetLogLevel(Log::VERBOSE);
    logInstance.log("Testing Log...");
    logInstance.SetLogLevel(Log::WARNING);
    logInstance.log("Testing Log...");
    logInstance.SetLogLevel(Log::ERROR);
    logInstance.log("Testing Log...");

    std::cout << "\nStatic variables\n";
    MyStatic myStatic1;
    myStatic1.x = 0;
    myStatic1.y = 0;
    MyStatic myStatic2;
    MyStatic::x = 5;
    MyStatic::y = 5;
    myStatic1.consoleLog();
    myStatic2.consoleLog();

    std::cout << "\nStatic function\n";
    for (int i = 0; i < 9; i++) {
        MyStaticFunction();
    }

    std::cout << "\nVirtual\n";
    std::cout << "------\n";
    MyVirtualBase *base = new MyVirtualBase();
    MyVirtualChild *child = new MyVirtualChild("Child");
    MyVirtualFunction(base);
    MyVirtualFunction(child);
    MyPureVirtualFunction(base);
    MyPureVirtualFunction(child);

    std::cout << "\nArray\n";
    int array[10];
    array[0] = 0;
    cout << array[0] << endl;
    cout << array << endl;

    std::cin.get();
    std::cin.get();
}
