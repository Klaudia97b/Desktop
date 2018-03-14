#include <cstdlib>
#include <iostream>
#include <cmath>

using namespace std;

int main(int argc, char *argv[])
{
    int i, suma=0;
    for(i=10;i<=100;i++)
    {
                      suma=suma+i;
                      cout << "Nr " << i << " Suma: " << suma << "\n";
                      }
                      cout << "10+20...+100+ = " << suma << "\n\n";
            
    
    system("PAUSE");
    return EXIT_SUCCESS;
}
