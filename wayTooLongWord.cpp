#include <iostream>
#include<vector>
using namespace std;


char uppercase(string word){

    char upper;
    for (int j = 0; j < word.length(); ++j) {
        if (isupper(word[j])) {
              upper = word[j];
            break;
        }
    }

    return upper;
}


int main() {

    int num;
    string word;
    int num1;

    cout << "Number of words: " << endl;

    cin >> num;

    if (num >= 1 && num <= 100) {
        vector<string> wordList;

        for (int i = 0; i < num; i++) {
            cin >> word;
            if (word.length() >= 1 && word.length() <= 100){
                wordList.push_back(word);
            }


            if (isupper(uppercase(word)) ) {

                wordList.erase(wordList.begin() + i);

            }

    }


        for (int in = 0; in < wordList.size(); in++) {




                int count = 0;
                if (wordList.at(in).length() > 10) {

                    int index = 0;
                    for (index = 1; index <= wordList.at(in).length() - 2; index++) {

                        count++;
                    }

                    wordList.at(in) =
                            wordList.at(in)[0] + to_string(count) + wordList.at(in)[wordList.at(in).length() - 1];

                }


                cout << wordList.at(in) << endl;

            }

        }





   // }

    else{
        cout << "Nigga please" << endl;
    }
}





