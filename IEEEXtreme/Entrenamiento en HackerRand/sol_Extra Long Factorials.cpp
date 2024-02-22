#include <bits/stdc++.h>
using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'extraLongFactorials' function below.
 *
 * The function accepts INTEGER n as parameter.
 */

void extraLongFactorials(int n) {
    int a[200]; //array will have the capacity to store 200 digits.
    int i,j,temp,m,x;
    a[0]=1;  //initializes array with only 1 digit, the digit 1.
    m=1;    // initializes digit counter

    temp = 0; //Initializes carry variable to 0.
    for(i=1;i<=n;i++)
    {
        for(j=0;j<m;j++)
        {
            x = a[j] * i + temp; //x contains the digit by digit product
            a[j] = x%10; //Contains the digit to store in position j
            temp = x/10; //Contains the carry value that will be stored on later indexes
        }

        while(temp > 0) //while loop that will store the carry value on array.
        { 
            a[m] = temp%10;
            temp = temp/10;
            m++; // increments digit counter
        }
    }
    
    for(i=m-1;i>=0;i--) //printing answer
        printf("%d",a[i]);
}

int main()
{
    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    extraLongFactorials(n);

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}
