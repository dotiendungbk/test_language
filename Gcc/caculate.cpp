#include <iostream>
#include <vector>
#include <map>
#include <cstring>
class rectangle{
    private:
    float a;
    float b;
    public:
    rectangle(float width, float height);
    ~rectangle(){};
    float primeter();
    float area();
};
 //TODO:dkdkddlk
rectangle::rectangle(float width, float height):a(width),b(height){

}

float rectangle::primeter(){
    return (a+b)*2;
}
float rectangle::area(){
    return a*b;
}

int main(){
    std::string m;
    rectangle a(20,30);
    std::cout << "value of primeter: " << a.primeter() << std::endl;
}