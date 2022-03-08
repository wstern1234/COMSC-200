/// Question: Taking the getQuotient() function as example, what may go wrong when using this template?
//  It might go wrong because getQuotient may receive strings and attempt to divide them, which breaks. 
//  As for the given template, it breaks because the prompt is incorrect, making the user guess x or y 
//  instead of 1 or 2.

#include <iostream>
#include <cmath>
#include <random>

using namespace std;




template <typename dType>
dType randomPick(dType var1, dType var2, dType var3) {

    random_device device;
    
    // mersenne twister; produces sequence of 32-bit integers, repeats after 2^19937 – 1 numbers generated
    mt19937 rng(device());
    uniform_int_distribution<mt19937::result_type> dist3(1,3); // distribution in range [1, 3]

    if (dist3(rng) == 1) {
        return var1;
    } else if (dist3(rng) == 2) {
        return var2;
    } else {
        return var3;
    }
    
    
}




template <typename dType>
dType getChoice(string str1, string str2, dType var1, dType var2) {

    cout << "Please pick " << str1 << " or " << str2 << ": ";

    dType input;
    cin >> input;

    while (!(input == var1 || input == var2)) {

        cout << "Incorrect input, please pick " << str1 << " or " << str2 << ": ";
        cin >> input;
        
    }

    return input;
    
}




template <typename dType>
double getQuotient(dType var1, dType var2) {

    return ((double)var1/var2);
    
}




int main() {
    
    cout << "Part 1" << endl;

    cout << randomPick('1','2','3') << endl;

    cout << randomPick (11,22,33) << endl;

    cout << randomPick (true, false, true) << endl;

    cout << randomPick ("Mac","PC","Others") << endl << endl;
    

 

    cout << "Part 2" << endl;

    // CAN'T DO LETTERS FOR LINE 88 & 90
    cout << getChoice("seven", "eleven", 7, 11) << endl;
    cout << getChoice("w", "s", 'w', 's') << endl << endl;
    cout << getChoice("x","y", 1, 2) << endl << endl;
    

 

    cout << "Part 3" << endl;

    cout << getQuotient(4.3, 2.2) << endl;
    cout << getQuotient(10, 2) << endl;
    cout << getQuotient(10, 4) << endl;


    


    return 0;
}