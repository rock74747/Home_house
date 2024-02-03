#include <iostream>
#include <string>

class Human {
protected:
    std::string name;
    int age;
public:
    Human() {
        name = "noname";
        age = 0;
    }

    Human(std::string name, int age) {
        this->name = name;
        this->age = age;
    }
    Human(const Human& other) {
        this->name = other.name;
        this->age = other.age;
    }


    void setName(std::string name) {
        this->name = name;
    }
    std::string getName() {
        return this->name;
    }  
    void setAge(int age) {
        this->age = age;
    }
    int  getAge() {
        return this->age;
    }
    

    void printhuman() {
        std::cout << name << age << "лет" << '\n';
        std::cout << std::endl;
    }


     ~Human() {}
};
   

class Flat : public Human {
protected:
    int flat_number;
    int size_; // кол-во человек в квартире
    Human* obj;
public:
    Flat() : Human() {
        flat_number = 0;
        int size_ = 0;
        
    } 
    
    
     
    Flat(int flat_number, int size_, Human* obj) : Human(name, age) {
        this->flat_number = flat_number;
        this->size_ = size_;
        this->obj = new Human [size_] {};
      
    }

   void printFlat() {
         std::cout << "Квартира " << flat_number << '\n';
         std::cout << "Проживает " << size_ <<  "человек" << '\n';
         std::cout << std::endl;
         }
         
    
    ~Flat() {delete[] obj;}
};
 
   

int main()
{
    setlocale(LC_ALL, "Russian");
    Human obj1 ("Петров В.В.", 25);
    Human obj2("Петрова С.В.", 22);
   
 
    Human* obj[] = {&obj1, &obj2};

    Flat flat1 (1, 2, obj[2]);
    flat1.printFlat();
    obj1.printhuman();
    obj2.printhuman();
   
    return 0;
}