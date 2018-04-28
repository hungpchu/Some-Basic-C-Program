#include <iostream>
#include<vector>
using namespace std;



// function to check for valid column and row through the vector of integer containing valid row and
bool valid(double row, double column, vector<int> num ){

    // set valid to be false
    bool  valid = false;

    int i ;

        // if the value of row = the value in the vector number
        // set the valid = true
        for (i = 0; i < num.size(); i++) {

            if (num[i] == row) {

                valid = true;

            }

        }

        // if the value of column = the value in the vector number
        // set the valid = false
        // since according to Prim, column should be different from the set of number in vector number
        for (i = 0; i < num.size(); i++) {

            if ( num[i] == column ) {

                valid = false;

            }
        }

    return valid;

}

// function to return the value of minium spanning tree
double minimumST( vector< vector<double> > adjacencyMatrix ){

    int row, column, edges = 1, size = adjacencyMatrix.size(), overlapRow, overlapColumn;
    vector<int> num;
    int minSize = 0;
    int min;


    // stop finding the value of minimum spanning tree
    // when edges = to size, which equals to the number of nodes
    while(edges < size) {

        // initialize the value of min to be INT_MAX
        min = INT8_MAX;


        for (row = 0; row < adjacencyMatrix.size(); row++) {

            for (column = 0; column <adjacencyMatrix.size(); column++) {

                // if edge = 1 then no need to validate this min
                // since we need the row and column from this node to put in the vector number
                if ( edges == 1) {

                    // no accept the value = 0 for min
                    if ( adjacencyMatrix[row][column] < min && adjacencyMatrix[row][column] != 0) {

                    min = adjacencyMatrix[row][column];
                    overlapColumn = column;
                    overlapRow = row;

                }

            }

                    // if edge >= 2 then we need to validate this min
                    // with the Prim's condition that row can be the value in the set of number
                    // but column must be different from that set of number
                else if ( edges >= 2 ){

                    // if already have one edges for the minimum spanning tree
                    // then the next edge must qualify the Prim's rule
                    // no accept the value = 0 for min
                    if (adjacencyMatrix[row][column] < min && valid(row,column,num) && adjacencyMatrix[row][column] != 0 ) {

                        min = adjacencyMatrix[row][column];
                        overlapColumn = column;
                        overlapRow = row;

                    }

                }

            }

        }

        // add the value of valid row and column into the vector number
        // which will be used to monitor upcoming column and row for the validation
        num.push_back(overlapColumn);
        num.push_back(overlapRow);

        // add the valid min to the minSize, which is the value of minimum spanning tree
        minSize = minSize + min;

        // increase the edges whenever find the min
        edges++;

    }

   // return the value of minimum spanning tree
    return minSize;
}

int main() {

    vector<vector<double>> adjacencyMatrix;


    int row, column, edges = 1, overlapRow, overlapColumn;
    int minSize = 0;
    int min, tempMin = 0;
    int nonOverLap;
    vector<int> num;



    int size;

    cout << "Enter Matrix size = ";
    cin >> size;


    vector<vector<double>> matrix;
    for (int i = 0; i < size; ++i) {
        //Create a vector
        vector<double> row;
        for (int j = 0; j < size; ++j) {
            double value;
            cin >> value;
            row.push_back(value);
        }
        //Push the row in matrix
        matrix.push_back(row);
    }




/*

    for (row = 0; row < matrix.size(); row++) {
        for (column = 0; column < matrix.size(); column++) {
            if (matrix[row][column] == 0) {
                matrix[row][column] = INT8_MAX;
            }
        }

    }




    while (edges < size) {

        min = INT8_MAX;
        for (row = 0; row < matrix.size(); row++) {
            for (column = 0; column < matrix.size(); column++) {

                  if ( edges == 1) {

                      if (matrix[row][column] < min ) {
                          min = matrix[row][column];
                          //cout << "min = " << min << endl;
                          overlapColumn = column;
                          overlapRow = row;

                      }
                  }

                else if (edges >= 2){
                      if (matrix[row][column] < min && valid(row,column,num) ) {
                          min = matrix[row][column];
                         // cout << "min = " << min << endl;
                          overlapColumn = column;
                          overlapRow = row;

                      }

                }

                }

                }

              num.push_back(overlapColumn);
             num.push_back(overlapRow);
                //cout << "overlapROw = " << overlapRow << endl;
               // cout << "overlapCOl = " << overlapColumn << endl;

            printf("%d edges (%d,%d) =%d\n", edges++, overlapRow, overlapColumn, min);

           // cout << "min1 = " << min << endl;
          //  cout << "edge = " << edges << endl;


            // cong vao tim min
            minSize = minSize + min;


            // tranh lap
            matrix[overlapRow][overlapColumn] = matrix[overlapColumn][overlapRow] = INT8_MAX;






        }

*/

        cout << "minSize: " << minimumST(matrix) << endl;









 }