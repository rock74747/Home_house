#include <iostream>
#include <string>


class Human {
private:
    std::string name;
    int age;
    
public:
    
    Human(std::string name = "noname", int age = 0) {
        this->name = name;
        this->age = age;
    }
    
    void printhuman() {
        std::cout << this-> name << std::endl; 
        std::cout << this->age << " лет" << std::endl;
    }
    Human (const Human& ob) {
    this->name = ob.name;
    this->age = ob.age;
    }
   ~ Human () {}
};



class Flat {
    friend class Human;
private:
    int flat_number;
    int size_; // кол-во человек в квартире 
    Human* ob;
public:

    Flat() : flat_number  (0), size_(0), ob (nullptr) {}

    Flat( int flat_number, int size_,  Human& obj) {
    ob = new Human;
    this->ob = &obj;
    this->size_ = size_;
    this->flat_number = flat_number;
    }
        
   
    
   void printFlat() {
         std::cout << "Квартира " << this->flat_number << '\n';
         std::cout << "Проживает " << this->size_ <<  " человек(а)" << '\n';
         for (int i = 0; i < size_; i++) {
             this->ob[i].printhuman(); 
             std::cout << '\n';
         }
   }
   
   Flat (const Flat& obj) {
       this->ob = obj.ob;
       this->ob = new Human;
       this->size_ = obj.size_;
   }
    ~Flat() {
       std:: cout << this << std::endl; delete[] ob;
   }
   
};
 
class House
{
  private:
    Flat* ob;
    int sized_; // кол-во  квартир 
    int number_hous; // номер дома
public:
    House() : number_hous (0), sized_(0), ob(nullptr) {};
    
    House(int number_hous, int sized_, Flat& o) {
    this->number_hous= number_hous;
    this->sized_ = sized_;
    this->ob = &o;
    }
    House(const House& obj) {
        this->ob = obj.ob;
    }
    
    void printhouse() {
        std::cout << "Номер дома: " << this->number_hous << '\n';
        std::cout << "Количество квартир: " << this->sized_  << '\n';
        for (int i = 0; i < sized_; i++) {
            this->ob[i].printFlat();
        }
    }
    ~House() {
        std::cout << this << std::endl; 
        delete[] ob;
    }
};


int main()
{
    setlocale(LC_ALL, "Russian");
     
  
    Human* arr1 = new Human [2];
    Flat flat1 (1, 2, *arr1);
    arr1[0] = { "Петров В.В.", 25 }; 
    arr1[1] = { "Петрова С.В.", 22 };
   
    
     Human* arr2 = new Human[3];
     Flat flat2(2, 3, *arr2); 
     arr2[0] = { "Семенов В.В.", 15 };
     arr2[1] = { "Семенов С.В.", 29 };
     arr2[2] = { "Иванов Л.В.", 74 };
     
     Flat* arr = new Flat[2];
     House house (55,2, *arr);
     arr[0] = { flat1 };
     arr[1] = { flat2 };
     
     house.printhouse();
     
     delete[] arr1;
     delete[] arr2;
     delete[] arr;
     arr = nullptr;
   
  
    return 0;
}