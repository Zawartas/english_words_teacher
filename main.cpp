#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstdlib> //exit() i rand()
#include <ctime> //time()

using namespace std;

int random_number(int maks){
    return rand()%maks;
}

int main(){

srand(time(0));

    ifstream input;
    vector<string> polish, english;
    string pl, eng;

input.open("text.txt");
    if (!input.is_open()){
        cout << "Can't load the file with data.\n";
        exit(EXIT_FAILURE);}

while (input >> pl >> eng){
    polish.push_back(pl);
    english.push_back(eng);
}

input.close();

for (unsigned int i = 0; i < 10; i++){
    int x = random_number(polish.size());
        while (pl != english[x]){
            cout << polish[x] << " = ";
            cin >> pl;
    }
        polish.erase(polish.begin()+x);
        english.erase(english.begin()+x);
}
    return 0;
}
