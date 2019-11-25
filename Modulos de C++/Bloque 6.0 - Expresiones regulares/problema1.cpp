#include <regex> //libreria para manejo de expresiones
#include <iostream>
#include <string.h>
#include <stdio.h>
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

    getchar();
    return 0;
}