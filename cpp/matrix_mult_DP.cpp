/*
 <----------------------------------------------------------------------->
 This program accepts performs matrix multiplication of 2 nxn matrices
 This uses dynamic programming approach that makes use of standard DAC
 algorithm in multiplying matrices
<------------------------------------------------------------------------>
 */

#include <iostream>
#include <vector>
#include <iomanip>
#include <map>
using namespace std;

// aliases
#define mat vector<vector<int>>
#define input pair<pair<mat, mat>, int>

// map for memoization
map<input, mat> memo;

// stores the submatrix and its current address on original matrix
struct Matrix{
    mat matrix;
    int row = 0;
    int col = 0;
};


// <------------------ function prototypes ------------------------------>
void inputMatrix(mat &A, int n, bool isEven);
void displayMatrix(mat C, bool isEven);
void sumMatrix(mat A, mat B, mat &C, int row, int col);
mat SMMR(Matrix A, Matrix B, int n);
mat truncateKey(Matrix matrix, int n);
// <--------------------------------------------------------------------->



// <------------------------- Driver ------------------------------------>
int main(){
    int n = 0;
    bool isEven = 1;
    Matrix A, B, C;
    
    do {
        // input dimension of matrices
        cout << "Enter size of square matrix: ";
        cin >> n;
        if (n < 1) cout << "Invalid input. Try Again" << endl;
    } while (n < 1);
    

    /*
     * if n is not divisible by 2, create an n+1 by n+1 matrix.
     * Since algo only works if n is divisible by 2,
     * adding 1 to n will make it divisible by 2.
     * then fill the extra cells with zeroes later on.
     */
    if (n % 2 != 0 && n > 2) {
        n++;
        isEven = 0;
    }
    
    // prompt message
    cout << "Input should be space separated or newline separated, example input for 2by2 matrix: " << endl;
    cout << "1 2 \n";
    cout << "3 4 \n";
    cout << "The matrix above can also be inputted as follows" << endl;
    cout << "1 2 3 4\n";
    
    // input matrices to be multiplied
    cout << "Enter Matrix A: \n";
    inputMatrix(A.matrix, n, isEven);
    cout << "Enter Matrix B: \n";
    inputMatrix(B.matrix, n, isEven);

    // call the recursive function and store resultant matrix to C
    C.matrix = SMMR(A, B, n);
    
    // display resultant matrix
    // (without filled zeroes if n is not divisible by 2)
    displayMatrix(C.matrix, isEven);
    
    return 0;
}

// <------------------ function definitions ------------------------------>


/*
 *  function that partitions nxn matrix into n/2 by n/2 matrix if n != 1
 *  if n = 1, then perform a scalar multiplication
 *  overall, this function is called 8^⌈n/2⌉ times
 *  @params:
 *   A - 2d vector input matrix
 *   B - 2d vector input matrix
 *   rowA and colA - integers indicating indices of matrix A
 *           to be multiplied when base case is reached
 *   rowB and colB - integers indicating indices of matrix B
 *           to be multiplied when base case is reached
 */

mat SMMR(Matrix A, Matrix B, int n) {
    
    /*
     * the key for the memo map consists of:
     *   - values of the submatrix A,
     *   - values of the submatrix B
     *   - current size of the submatrix
     * since this algo does not create new submatrices and
     * only manipulates the indices, the truncateKey
     * function is needed to determine the
     * exact values of submatrices A and B.
     */
    input key = make_pair(make_pair(truncateKey(A, n), truncateKey(B, n)), n);
    // if the submatrix was solved previously,
    // then get the stored value for the result of multiplying these matrices
    if (memo.find(key) != memo.end()) return memo[key];
    
    // declare resultant matrix
    mat c(n,vector<int> (n, 0));
    Matrix C;
    C.matrix = c;

    if (n == 1) {
        C.matrix[0][0] = A.matrix[A.row][A.col] * B.matrix[B.row][B.col];
        return C.matrix;
    }
     // partition A, B, and C
    int newSize = n / 2;
    for (int i = 0; i < 4; i++) {
        Matrix A1 = A, A2 = A, B1 = B, B2 = B;
        switch (i) {
            case 0: // C[0][0] = A[0][0] * B[0][0] + A[0][1] * B[1][0]
                A2.col += newSize;
                B2.row += newSize;
                break;
            case 1: // C[0][1] = A[0][0] * B[0][1] + A[0][1] * B[1][1]
                B1.col += newSize;
                A2.col += newSize;
                B2.col += newSize;
                B2.row += newSize;
                C.col = newSize;
                break;
            case 2: // C[1][0] = A[1][0] * B[0][0] + A[1][1] * B[1][0]
                A1.row += newSize;
                A2.row += newSize;
                A2.col += newSize;
                B2.row += newSize;
                C.row = newSize;
                C.col = 0;
                break;
            case 3: // C[1][1] = (A[1][0] * B[0][1]) + A[1][1] * B[1][1]
                A1.row += newSize;
                B1.col += newSize;
                A2.row += newSize;
                A2.col += newSize;
                B2.row += newSize;
                B2.col += newSize;
                C.row = newSize;
                C.col = newSize;
                break;
        }
        // adding the products
        sumMatrix(SMMR(A1, B1, newSize), SMMR(A2, B2, newSize), C.matrix, C.row, C.col);
            
    }
    // store the resultant matrix to this subproblem that may be used later on
    memo[key] = C.matrix;
   
    return memo[key];
}

/*
 * function to add the products of submatrices
 * overall, this function is called 4^⌈n/2⌉ times
 * @params:
 *   A - 2d vector input matrix
 *   B - 2d vector input matrix
 *   C - 2d vector reaultant matrix passed by reference
 *   rowC and colC - indices to indicate where
 *      to store the sum in resultant matrix
 */

void sumMatrix(mat A, mat B, mat &C, int row, int col) {
    int n = A[0].size();
    // this nested loop iterates ⌈n/2⌉ times
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            C[i + row][j + col] = A[i][j] + B[i][j];
        }
    }

}


/*
 * function to input a matrix
 * @params:
 *   A - 2d vector passed by reference
 *   isPower2 - boolean that indicates if n is divisible by 2
 */

void inputMatrix(mat &A, int n, bool isEven) {
   
    for (int i = 0; i < n; i++) {
        vector<int> temp;
        for (int j = 0; j < n; j++) {
            // if isPower2 is false, fill the last column and row with zeroes
            int num = 0;
            if ((!isEven && j < 3 && i < 3) || isEven)
                cin >> num;
            temp.push_back(num);
        }
        A.push_back(temp);
    }
}


/*
 * function to display a matrix
 * @params:
 *   A - 2d vector passed by reference
 *   isPower2 - boolean that indicates if n is divisible by 2
 */

void displayMatrix(mat C, bool isEven) {
    int n = isEven? C.size() : C.size() - 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << left << setw(10) <<  C[i][j] << " ";
        }
        cout << endl;
    }
}

/*
 * function to get values of a submatrix from the original matrix
 * @params:
 *   matrix - a struct which is the original matrix
 *   n - size of submatrix
 * @return:
 *  a 2d vector with suze nbyn
 */
mat truncateKey(Matrix matrix, int n) {
    mat res;
    for (int i = 0; i < n; i++) {
         vector<int> temp;
        for (int j = 0; j < n; j++) {
           temp.push_back(matrix.matrix[matrix.row + i][matrix.col + j]);
        }
        res.push_back(temp);
    }
    return res;
}
