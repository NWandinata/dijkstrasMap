//Makenzie Johnson and Nicholas Wadinata
//cs 302
//3-25-23

#include<iostream>
#include<fstream>
#include<cstdlib>
#include<vector>

using namespace std;

int main(){
    ofstream fout;
    vector<char> letters = {'f', 'g', 'G', 'h', 'm', 'r'}; //store letters in here

    //convert numbers to char to get the letter, insert into vector before moving on. if that number is already in the vector, try again
    //In ascii: for upper case = 65 - 90 | for lower case = 97 - 122

    fout.open("1000_numbers.txt");
    srand(time(0)); //only generated positive numbers, starting at 0

    //change the amount of numbers/letters generated for each section

    //I manually change the index numbers, 10, 20, etc.

    fout << "6" << endl;
    fout << "f 3" << endl;
    fout << "g 1" << endl;
    fout << "G 2" << endl;
    fout << "h 4" << endl;
    fout << "m 7" << endl;
    fout << "r 5" << endl;
    fout << "1000 1000" << endl;

    for(int i = 0; i < 1000; i++){
        for(int j = 0; j < 1000; j++){
            int data = rand() % letters.size();
            fout << letters[data] << " ";    
        }
        fout << endl;
    }

    fout << "0 0" << endl;
    fout << rand() % 1000 << " " << rand() % 1000;

    fout.close();
}
