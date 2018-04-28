#include <iostream>
using namespace std;

int main() {

    string word = "hungmetlamroi";

    for (int i = 0; i < word.size()/2; i++){
        swap(word.at(i),word.at(word.size() - i - 1));

    }


    cout<<"string = "<<word<<endl;
    //cout << "Hello, World!" << endl;
    return 0;
}