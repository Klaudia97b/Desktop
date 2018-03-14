#include <iostream>
#include <cmath>
#include <cstdlib>

int main()
{
    int userinput; int suma = 0;
    std::cout << "Podaj liczbe naturalna z przedzialu 0...1000" << std::endl;
    std::cin >> userinput;
    if( userinput <= 0 || userinput > 1000 )
    {
        std::cout << "0" << std::endl;
        return 0;
    }
   
    for( int i = 1; i < userinput + 1; i++ )
    {
        suma = suma + i;
}
    std::cout << suma << std::endl;
    
    system ("PAUSE");
    return 0;
}
