#include<iostream>
using namespace std;

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

//use of a function to print the matrix, same algorithm as below
void print(int a[][2], int r , int c) {
cout <<"Print by row:" << endl;
    for(int i =0; i < r; i++) {
        for(int j =0; j <c; j++) { //same algorithm as populating, only using "cout" instead of "cin"
            cout <<a[i][j] << " ";
        }
        cout <<endl; // used to move onto the next row of the matrix

}
}



int main()
{
    int a[][2] = {{1,2},
                    {3,4}
                    };
    print(a,2,2);
    /*
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
*/
}
/*Following the examples above I was confused to why the input of rows was optional
but the number of columns was mandatory for the matrix to be passed as a function
parameter. The following will be a roughly high level analysis to how matrix is stored in
computer memory and explain my previous query.

So given a matrix, lets call it Matrix B. Matrix B has the dimensions of B[5],[5]
                              [00],[01],[02],[03],[04]
                              [05],[06],[07],[08],[09]
                              [10],[11],[12],[13],[14]
                              [15],[16],[17],[18],[19]
                              [20],[21],[22],[23],[24]

    Say user A inputs the dimensions of rows = 3, columns = 2. From Matrix B only the
    following will be used: (rest will be default 0)
                                     [00],[01],
                                     [05],[06],
                                     [10],[11],

However this is it not how the matrix is stored. The compiler will take the array and store it
in the form of a 1 dimensional array, this can be done in two different ways:
    1) Row major
    2) Column major

    **Row Major**
    With Matrix B being a 5x5 matrix, this presents 25 elements. This will be a 1D
    array:
                [0] -> [24] (represents an array from element 0 to 24)
    This represents 25 continuous blocks of memory from element[0] to [24].
    In this block of memory the way in which it is stored is it will store row by row:
                        1 ->   [00],[01],[02],[03],[04]
                        2 ->   [05],[06],[07],[08],[09]
                        3 ->   [10],[11],[12],[13],[14]
                        4 ->   [15],[16],[17],[18],[19]
                        5 ->   [20],[21],[22],[23],[24]

            Example of the array:   [00],[01],[02],[03],[04],...,[20],[21],[22],[23],[24]

    **Column major**
    The size of the array will be the same:
                [0] -> [24] (represents an array from element 0 to 24)
    The functionality of this is identical to the method above only instead of incrementing
    through rows, it will increment through the columns.

                              (1)  (2)  (3)  (4)  (5)
                              [00],[01],[02],[03],[04]
                              [05],[06],[07],[08],[09]
                              [10],[11],[12],[13],[14]
                              [15],[16],[17],[18],[19]
                              [20],[21],[22],[23],[24]

            Example of the array:  [00],[05],[10],[15],[20],...,[04],[09],[14],[15],[24]

Row major however dominates as column major is rarely used.



Looking deeper into Row major:

                    Matrix C:

                              (0) (1) (2) (3) (4)
                          (0) [-],[-],[-],[-],[-]
                          (1) [-],[-],[-],[-],[-]
                          (2) [-],[-],[x],[-],[-]
                          (3) [-],[-],[-],[-],[-]
                          (4) [-],[-],[-],[-],[-]

    As an example, if I were trying to locate the position of 'x' it would be C[2][2] with the index
    being (2,2).

    Looking at matrix C, for each traversal there has to be a number of rows and columns
    that are skipped, this can be calculated through:
                (  X*no.ofRows) + (no. of columns skipped ).
    So in my case (2*5)+2 = 12.

    This above operation is the conversion of matrices index to an index along a 1D plane
    of memory. The integer that is returned is the index of where the value is stored.
    So 'x' is at the 13th cell, however it is at index 12.


                            [00],[01],[02],[03],[04],...[x],...,[20],[21],[22],[23],[24]
                                                *index 12 on the 1D array*

    A general way to calculate the index is: (Row major)
                        X[i][j] = i * c + j     (R = rows, C = columns)

    Looking at the above formula, it is clear that R is not present in this formula
    this is why C is mandatory to initialise an array.


