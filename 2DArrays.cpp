#include<iostream>
using namespace std;

int main()
{
    int a[100][100];
    int r,c; //rows = r, columns = c
    cin >> r >> c; //

    for(int i =0; i< r; i++){
        for(int j =0; j < c ;j++) {
            cin >> a[i][j];
        }
    }
    //printing (row)
    cout <<"Print by row:" << endl;
    for(int i =0; i < r; i++) {
        for(int j =0; j <c; j++) { //same algorithm as populating, only using "cout" instead of "cin"
            cout <<a[i][j] << " ";
        }
        cout <<endl; // used to move onto the next row of the matrix
    }
    //printing (column)
    cout<< "Printing by column" << endl;
    for(int i = 0; i < c; i++) { // opposite of printing by row
        for(int j = 0; j < r; j++) {
            cout << a[j][i] << " ";
        }
        cout <<endl;
    }

}
/* when looking at traversal of a matrix there are two ways that the matrix can be
printed:
 1) By row
 2) By column

**Example**

    Matrix A: (for the purpose of this example "[]" references the encapsulated element of the
               index, not an array)

            (0)(1)(2)
         (0)[a][b][c]
         (1)[d][e][f]

    Print by Row (order):  a,b,c,d,e,f
    Print by column (order): a,d,b,e,c,f
*/
