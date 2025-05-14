#include <iostream> 

#include<cmath> 

using namespace std; 

 int main() 

{ 

    float pi=3.14, base, altura, area, lado, radio; 

    std::cout << "Calculemos el área de un triángulo\n" << std::endl; 

    std::cout << "Ingrese la medida de la base:" << std::endl; 

    std::cin >> base; 

    std::cout << "Ingrese la altura:" << std::endl; 

    std::cin >> altura; 

    area=base*altura/ 2; 

std::cout << "El área es: \n" <<area<< std::endl; 

     

   std::cout << "Calculemos el área de un cuadrado\n" << std::endl; 

    std::cout << "Ingrese la medida del lado:" << std::endl; 

    std::cin >>lado ; 

    area=lado*lado; 

    std::cout << "El área es: \n" <<area<< std::endl; 

     

    std::cout << "Calculemos el área de un circulo\n" << std::endl; 

    std::cout << "Ingrese la medida del radio: " << std::endl; 

    std::cin >> radio;  

    area= pi*pow (radio, 2);  

    std::cout << "El área es: " <<area<< std::endl; 

     return 0; 

} 
