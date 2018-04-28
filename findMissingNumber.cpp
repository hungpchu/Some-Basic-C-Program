#include <iostream>
#include <vector>
using namespace std;


vector<int> sortedArray(vector<int> a) {

    int i;

    for ( i = 0; i < a.size(); i++) {

        for (int j = i + 1; j <= a.size() - 1; j++) {

            // if the element of array containing ending number of interval is bigger
            // then put it to the right os that array
            if (a.at(i) > a.at(j)) {

                // have the increasing order of the array with swap
                swap(a.at(i), a.at(j));


            }
        }
    }

   return a;

}

int main() {

    vector<int> unsortedNumber = {100, 10 ,1};
    vector<int> sortedNumber, numberMissingAndOverlap;
    int index , numberMissing;
    static int overlapNumber;

    sortedNumber = sortedArray(unsortedNumber);

    for (index = 0; index < sortedNumber.size(); index++) {

        cout << sortedNumber.at(index)<<" ";
    }
    cout<<endl;


    for (index = 0; index < sortedNumber.size() - 1; index++) {

        if (sortedNumber.at(index + 1) - sortedNumber.at(index) == 0 && overlapNumber != sortedNumber.at(index)){
            overlapNumber =  sortedNumber.at(index);
            numberMissingAndOverlap.push_back(overlapNumber);
        }

        if (sortedNumber.at(index + 1) - sortedNumber.at(index) > 1 ){

            numberMissing = sortedNumber.at(index) + 1;
            numberMissingAndOverlap.push_back(numberMissing);
            while (sortedNumber.at(index + 1) - numberMissing > 1){
                numberMissing++;
                numberMissingAndOverlap.push_back(numberMissing);
            }

        }
    }

    cout<<endl;

    for (index = 0; index < numberMissingAndOverlap.size(); index++) {

        cout << numberMissingAndOverlap.at(index)<<" ";
    }


}

