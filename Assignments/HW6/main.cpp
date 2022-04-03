#include <iostream>
#include <map>
#include <string>
#include <fstream>
#include <iomanip>

using namespace std;




string strip(string in) {
    string result;

    for (int i = 0; i < in.length(); i++)
        if (isalpha(in[i]))
            result += in[i];


    return result;
}




int main() {

    map<string, int> words;
    pair<map<string, int>::iterator, bool> it;
    string word;

    ifstream myfile;
    myfile.open("NotesBetweenTwoSisters.txt");
    if (myfile.is_open()) {

        while (!myfile.eof()) {

            myfile >> word;

            word = strip(word);

            it = words.insert( pair<string, int>(word, 1) );


            if (!it.second) {

                it.first->second++;
                
            }

        } // end while


        cout << "Word          |  Count" << endl;
        cout << "----          |  -----" << endl;
        for (it.first = words.begin(); it.first != words.end(); it.first++) {

            cout << left << setw(14) << it.first->first << '|' << right << setw(7) << it.first->second << endl;
            
        }

    }


	return 0;
}
