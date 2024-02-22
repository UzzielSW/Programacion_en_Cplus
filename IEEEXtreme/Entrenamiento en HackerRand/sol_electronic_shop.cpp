/*electronic shop
    este programa sobre dado un presupuesto $, y dos listas. una de keysboars y otra de drives(usb). comprar
    el mas caro de ambos con el presupuesto dado. 

    ejemlo dado las listas:
    key = {40,50,60};
    usb = {5,8,12};
    int b = 60; y el presupuesto

    podriamos tener:

    40 + 12 = 52
    40 + 8 = 48
    50 + 5 = 55
    50 + 8 = 58

    donde el mejor seria: 50 + 8 
*/
#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

template<typename T>
vector<T> select_T(const vector<T>& inVec, function<bool(const T&)> predicate)
{
  vector<T> result;
  copy_if(inVec.begin(), inVec.end(), back_inserter(result), predicate);
  return result;
}

int main()
{
    vector<int> mVec = {1,4,7,8,9,0};
    vector<int> key = {40,50,60};
    vector<int> usb = {5,8,12};
    int b = 60;

// filter out values > 5
vector<int> gtFive = select_T<int>(mVec, [](auto a) {return (a > 5); });

// or > target
int target = 9;
vector<int> gt = select_T<int>(mVec, [target](auto a) {return (a > target); });

//key
vector<int> fkey = select_T<int>(key, [b](auto a) {return (a < b); });
vector<int> fusb = select_T<int>(usb, [b](auto a) {return (a < b); });

//ordenar k > && U <
sort(fkey.begin(), fkey.end(), greater<int>()); //descendiente
sort(fusb.begin(), fusb.end());//ascendiente

//argoritmo
int max = -1;
for(int i = 0, j = 0; i < fkey.size(); i++){
    for(; j < fusb.size(); j++){
        if(fkey[i]+fusb[j] > b) break; //This prevents j from incrementing
        if(fkey[i]+fusb[j] > max)
            max = fkey[i]+fusb[j];
    }
}

//imprimir
  cout<<"fkeys: ";
    for (size_t i = 0; i < fkey.size(); i++) {
        cout << fkey[i] << " ";
    }
    cout<<endl;
  
  cout<<"fusb: ";
    for (size_t i = 0; i < fusb.size(); i++) {
        cout << fusb[i] << " ";
    }
    cout<<endl;

  cout<<"max:"<<max;
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

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
