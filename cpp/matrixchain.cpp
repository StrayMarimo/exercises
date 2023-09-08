/*
 <----------------------------------------------------------------------->
 This program accepts a sequence of matrices with different dimensions,
 implements matrix chain multiplication by dynamic programming approach
 to determine
 algorithm in multiplying matrices
<------------------------------------------------------------------------>
 */

#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <climits>
#include <string>
#include <iomanip>

using namespace std;

// aliases
#define ll long long
#define Matrix vector<vector<ll>>
#define Address pair<size_t, size_t>
#define AuxTables pair<Matrix, Matrix>
#define Arr vector<size_t>

// global variables
size_t CHAIN_SIZE = 6;
vector<Matrix> matrix_chain(CHAIN_SIZE);
string parens = "";

// <------------------ function prototypes ------------------------------>
bool promptUser();
Arr getDimensions();
Matrix setMatrixValues(Address, bool);
void displayMatrix(Matrix);
AuxTables matrixChainOrder(Arr);
Matrix matrixChainMultiply(Arr);
Matrix matrixMultiply(Matrix, Matrix);
void optimalParens(Matrix, Address);
int toInt(char num);
void displayDivider();
// <--------------------------------------------------------------------->

// <------------------------- Driver ------------------------------------>
int main()
{
    Arr dimensions; // hold the dimensions of the matrix chain

    // used to generate different random numbers per run
    srand(time(NULL));

    // Prompt the user to enter custom dimensions or use default values
    bool custom_input = promptUser();

    // If the user entered custom dimensions, get the dimensions
    // and resize the matrix_chain vector to hold the matrices
    if (custom_input)
    {
        dimensions = getDimensions();
        CHAIN_SIZE = dimensions.size() - 1;
        matrix_chain.resize(CHAIN_SIZE);
    }
    else
    {
        // If the user didn't enter custom dimensions, use default values
        dimensions = {2, 3, 4, 3, 2, 5, 3};
    }

    // Loop through the matrix chain and set values for each matrix
    for (size_t i = 0; i < CHAIN_SIZE; i++)
    {
        // If the user entered custom dimensions, prompt the user to enter
        // values for the current matrix
        if (custom_input)
            cout << "Enter values for Matrix " << i + 1 << "("
                 << dimensions[i] << "x" << dimensions[i + 1] << ") :" << endl;

        // Create an object to hold the dimensions of the current matrix
        Address dimension(dimensions[i], dimensions[i + 1]);

        // Set values for current matrix and store it to the matrix chain
        matrix_chain[i] = setMatrixValues(dimension, custom_input);

        // Print the current matrix
        cout << "Matrix " << i + 1 << ": " << endl;
        displayMatrix(matrix_chain[i]);
        displayDivider();
    }
    // Calculate the optimal order to multiply the matrices
    // and print the result
    AuxTables mc = matrixChainOrder(dimensions);
    ll optimal = mc.first[1][CHAIN_SIZE];
    cout << "The minimum number of scalar multiplications needed to ";
    cout << "multiply the chain of matrices is: " << optimal << endl;
    // Get the parenthisiaztion of the optimal order of multiplying the
    // matrix chain as a string and print it
    optimalParens(mc.second, make_pair(1, CHAIN_SIZE));
    cout << "The optimal parenthesization is: " << parens << endl;

    // multiply the matrices in order
    Matrix C = matrixChainMultiply(dimensions);
    displayDivider();

    // print the resultant matrix
    cout << "The product of the matrix chain is: " << endl;
    displayMatrix(C);
}
// <--------------------- Custom Functions ------------------------------>
/**
 * Calculates the optimal order to multiply the matrices in the
 * given matrix chain
 * @param dimensions: An Arr object representing the dimensions
 *         of the matrix chain
 * @return A pair of matrices representing the minimum number of scalar
 *         multiplications needed to multiply the chain of matrices and
 *         the optimal parenthesization of the matrix chain
 */
AuxTables matrixChainOrder(Arr dimensions)
{
    // Create two matrices initialized to 0
    Matrix m(CHAIN_SIZE + 1, vector<ll>(CHAIN_SIZE + 1, 0));
    Matrix s(CHAIN_SIZE + 1, vector<ll>(CHAIN_SIZE + 1, 0));

    // Loop through the matrix chain and calculate the minimum number
    // of scalar multiplications needed to multiply each subchain
    for (size_t chain_len = 1; chain_len < CHAIN_SIZE; chain_len++)
    {
        for (size_t i = 1; i < CHAIN_SIZE - chain_len + 1; i++)
        {
            int j = i + chain_len;
            m[i][j] = INT_MAX;
            for (int k = i; k <= j - 1; k++)
            {
                ll q = m[i][k] + m[k + 1][j] + dimensions[i - 1] * 
                    dimensions[k] * dimensions[j];
                if (q < m[i][j])
                {
                    m[i][j] = q;
                    s[i][j] = k;
                }
            }
        }
    }

    // create object to hold the result and return it
    AuxTables mc(m, s);
    return mc;
}

/**
 * Determines the optimal parenthesization of the matrix chain and
 * stores it to a static string
 * @param s: A Matrix representing the optimal splitting points
 *      of the matrix chain
 * @param ad: A pair of size_t representing the address of the cuurent
 *      subchain to parenthesize
 * @return A string representing the optimal parenthesization of the
 *      matrix chain
 */
void optimalParens(Matrix s, Address ad)
{

    // If the subchain is a single matrix,
    // add it to the parenthesization string
    if (ad.first == ad.second)
        parens += "A" + to_string(ad.first);
    else
    {
        // If the subchain is not a single matrix,
        // recursively parenthesize its two subchains
        parens += "(";
        optimalParens(s, make_pair(ad.first, s[ad.first][ad.second]));
        optimalParens(s, make_pair(s[ad.first][ad.second] + 1, ad.second));
        parens += ")";
    }
}

/**
 * Multiplies the matrix chain in order
 * @param dimensions: An array of size_t representing the dimensions of
 *         the matrix chain
 * @return Matrix: the resultant matrix which is the product of all
 *          the matrices in the chain
 */
Matrix matrixChainMultiply(Arr dimensions)
{
    // holds the products of two matrices in the chain
    vector<Matrix> products(CHAIN_SIZE - 1);
    size_t bCtr = 0; // holds address in products to add a product

    // This function will iterate until there are no more matrix left
    // to multiply in the parenthesization
    while (parens.length() > 0)
    {
        // loop through the parenthisization string
        for (int i = 0; i < parens.length(); i++)
        {
            /* if the current character is a digit and the next character
            is an alpha, it means that it is safe to multiply
            the adjacent matrices.

            For example, in the parenthisization, ((A1A2)(((A3A4)A5)A6))
            this function first multiplies A1 and A2, then push the
            result to products. Then proceed to traverse the string and
            find adjacent matrices to multiply
            */
            if (isdigit(parens[i]) && isalpha(parens[i + 1]))
            {

                /* If the cuurent matrix has an A prefix, then get the
                matrix from the chain_order, otherwise, get the matrix
                from the products vector. The number specifies the position
                of the matrix in the vector
                */
                Matrix A = (parens[i - 1] == 'A')
                               ? matrix_chain[toInt(parens[i])]
                               : products[toInt(parens[i])];
                Matrix B = (parens[i + 1] == 'A')
                               ? matrix_chain[toInt(parens[i + 2])]
                               : products[toInt(parens[i + 2])];

                cout << "Current Parenthesization: " << parens << endl;

                // Print the matrices to be multiplied and multiply it
                cout << "Multiplying " << parens[i - 1] << parens[i]
                     << " and " << parens[i + 1]
                     << parens[i + 2] << ":" << endl;

                cout << "Matrix " << parens[i - 1]
                     << parens[i] << ":" << endl;
                displayMatrix(A);
                cout << "Matrix " << parens[i + 1]
                     << parens[i + 2] << ":" << endl;
                displayMatrix(B);
                cout << endl;

                Matrix product = matrixMultiply(A, B);
                products[bCtr] = product;
                bCtr++;
                cout << "The product C" << bCtr << " is: " << endl;
                displayMatrix(product);

                displayDivider();

                // if length is 6, it means it is the last set
                // to be multiplied, so clear the parens variable to
                // break the loop
                if (parens.length() == 6)
                    parens = "";
                // otherwise replace the string with the address of
                // the product in products vector
                // For example, in the parenthisization,
                // ((A1A2)(((A3A4)A5)A6)), after mulriplying A1 and A2
                // the parens string will be replaced with
                // (C1(((A3A4)A5)A6))
                else
                    parens.replace(i - 2, 6, "C" + to_string(bCtr));
            }
        }
    }

    // the product of the whole chain will be stored
    // in the last element of products variable
    return products[products.size() - 1];
}

/**
 * Multiplies two matrices
 * @param A: A Matrix representing the first matrix
 * @param B: A Matrix representing the second matrix
 * @return A Matrix representing the product of the two matrices
 */
Matrix matrixMultiply(Matrix A, Matrix B)
{

    // holds the product of the two matrices
    Matrix C(A.size(), vector<ll>(B[0].size(), 0));

    // compute the product using the naive method
    for (int i = 0; i < A.size(); i++)
        for (int j = 0; j < B[0].size(); j++)
            for (int k = 0; k < B.size(); k++)
                C[i][j] += A[i][k] * B[k][j];

    // return the resultant matrix
    return C;
}

/**
 * Prompts the user to choose between inputting a custom matrix chain or
 * generating a randomized input.If the user chooses a randomized input,
 * the dimensions of the matrices are predetermined.
 * @return true if the user chooses custom input,
 *          false if they choose ndomized input.
 */
bool promptUser()
{
    char answer = 'x';

    displayDivider();
    cout << "This program multiplies a sequence of matrices." << endl;
    displayDivider();

    // Loop until user enters a valid input
    do
    {
        cout << "Do you want to input a chain of matrices or ";
        cout << "generate a randomized input?" << endl;
        cout << "The randomized input has 6 matrices with ";
        cout << "the dimensions: " << endl;
        cout << "A1: (2 x 3)" << endl;
        cout << "A2: (3 x 4)" << endl;
        cout << "A3: (4 x 3)" << endl;
        cout << "A4: (3 x 2)" << endl;
        cout << "A5: (2 x 5)" << endl;
        cout << "A6: (5 x 3)" << endl;
        cout << "Enter y for custom input, n for random input with ";
        cout << "predetermined dimensions: ";

        cin >> answer;

        // Check user input
        if (answer == 'y')
            return true;
        else if (answer == 'n')
            return false;
        else
            cout << "Invalid input. Try again " << endl;
        displayDivider();

    } while (true);
}
/**
 * Prompts user to input the number of matrices and their dimensions
 *
 * @return Arr: An array of integers representing the dimensions of
 *      matrices to be multiplied
 */
Arr getDimensions()
{

    // The dimensions will be stored in a vector of size chain_size + 1
    // The dimensions of Matrix i is represented by
    // dimensions[i] and dimensions[i+1]
    size_t n = 0;

    do
    {
        cout << "Enter the number of matrices you want to multiply: ";
        cin >> n;
        if (n < 2 || n > 9)
            cout << "Invalid Input. Size should be greater than 1 ";
        cout << "and less than 10 " << endl;
        displayDivider();
    } while (n < 2 || n > 9);

    Arr dimensions(n + 1);

    for (size_t i = 0; i < n; i++)
    {
        size_t row, col;
        if (i == 0)
        {
            cout << "Enter the dimensions for first matrix: ";
            cin >> dimensions[0] >> dimensions[1];
        }
        else
        {
            cout << "Enter the column for Matrix " << i << ": ";
            cin >> dimensions[i + 1];
        }

        cout << "Matrix " << i + 1 << " is a " << dimensions[i] << " by ";
        cout << dimensions[i + 1] << " matrix." << endl;
        displayDivider();
    }

    return dimensions;
}
/**
 * Set the values of a matrix.
 * If the user opted for custom input, then ask for values
 * Otherwise, generate a random number between -50 and 50 inclusive
 * @param dimension: a pair of size_t representing the dimension of
 *          the matrix to be populated
 * @param custom_input: a boolean that represents if the user wants to
 *          customize input
 * @return Matrix: a 2d vector with populated values
 */
Matrix setMatrixValues(Address dimension, bool custom_input)
{
    // holds the matrix to be populated
    Matrix matrix(dimension.first, vector<ll>(dimension.second, 0));
    for (size_t i = 0; i < dimension.first; i++)
    {
        for (size_t j = 0; j < dimension.second; j++)
        {
            if (custom_input)
                cin >> matrix[i][j];
            else // generate random number between -50 and 50 inclusive
                matrix[i][j] = -50 + rand() % (101);
        }
    }
    return matrix;
}

/**
 * Displays the matrix
 *
 * @param matrix: Matrix to be displayed
 */
void displayMatrix(Matrix matrix)
{
    for (size_t i = 0; i < matrix.size(); i++)
    {
        for (size_t j = 0; j < matrix[0].size(); j++)
        {
            cout << right << setw(15) << matrix[i][j] << "\t";
        }
        cout << endl;
    }
}
/**
 * Converts a single digit character to an integer value.
 *
 * @param num a single digit character to be converted to an integer
 * @return the integer value corresponding to the input character,
 *          starting from 0
 */
int toInt(char num) { return stoi(to_string(num)) - 49; }

/**
 * displays a divider consisting of 100 dashes to visually separate
 * different parts of the program output.
 */
void displayDivider()
{
    for (size_t i = 0; i < 100; i++)
        cout << "-";
    cout << endl;
}