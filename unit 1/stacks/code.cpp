#include<iostream> //header file lib
#include<string> //string lib 
#include<math> //math library
using namespace std; // lets us use names for objects and variables from std lib


int main() {
    // cout << "Hello world\n"; // output operator
    // std::cout << "HELLO WORLD" << "\n\n"; // can be used when namespace not declared.
    // cout <<"\t" << "this is a \"test\"" << "\\" ;
    /*multi line
    comment*/
    // variable types - int,double,char,string,bool.

    // int var;
    // var = 50;
    // cout << "\n" << var;

    // int var1 = 30;
    // double dob = 6.5;
    // float flt = 6.5;
    // char lett = 'C';
    // string word = "bitch";
    // bool func = "true";

    // int sum = var + var1;
    // cout <<"\n" "the sum is " << sum <<"\n";


    // const int wtf = 69;
    // // constant variable is givena value that cannot be changed

    // // input function - cin
    // int x;
    // cout << "enter a number:";
    // cin >> x;
    // cout << "\n" << "your number is: " <<x;


    // simple calculator for two nuumbers
    // int a,b;
    // cout << "\n" << "enter a number:";
    // cin >> a;
    // cout << "\n" << "enter another number:";
    // cin >> b;
    // int sm = a+b;
    // int diff = a-b;
    // int mul = a*b;

    // cout << diff;
    // cout << mul;
    // cout << sum;


    string len = "QWERTYUIOPASDFGHJKLZXCVBNM";
    cout <<"\n" << "size of the string is:" << len.size();
    cout <<"\n" << "length of the string is:" << len.length();
    //mystring.length will alo give out length of string.
    cout << len.at(3); //prints index 3 in the string

    string name ;
    cout << "type your name:" ;
    getline (cin, name); //usefuul to get a line of text
    cout << "\n" << "your name is" << name;

    string mystring = "BENCHORI";
    cout << mystring[4];

    cout << max(7,8) <<"\n";
    cout << min(7,8) <<"\n";

    cout<< sqrt(64) <<"\n" << round(3.6) << "\n" << log(2);


    //arrays

    string cars[] = {"volvo","merc","mazda","tesla","tata"};
    for(int k =0;k<5;k++) {
        cout << k. << cars[k] << "\n";
    }
    //or
    //for-each loop can be used

    int numb[] = {1,2,3,4,5};
    for(int h = numb){
        cout << h << "\n";

    }
    cout << sizeof(numb); //size like memory occupied
    int arrlen = sizeof(numb)/sizeof(int);
    cout << arrlen;



    return 0;
}