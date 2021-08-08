#include <iostream>
#include <regex> //libreria para manejo de expresiones
using namespace std;

int main()
{
    regex patron("alex");

    string textos[] = 
    {
        "alex",
        "joel",
        "suazo"
    };

    for(string var : textos)
    {
        if(regex_match(var, patron))
            cout<<var;
        else 
            cout<<"\n";
    }

    return 0;
}
