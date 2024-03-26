#include "StandHeader.h"
#include "CaseMatrix.h"

int fMatrix() 
{
	Matrix Matrix_test1, Matrix_test2;
	cout << "Enter the dimensions of the two matrices. .(string, column) Example: 10 10 :";
	cin >> Matrix_test1;
	cout << endl;
	cin >> Matrix_test2;
	cout << endl;

	if (Matrix_test1.getSize() > 0 && Matrix_test2.getSize() > 0) {
		
		cout << "Matrix one: " << endl << Matrix_test1 << endl;
		cout << "Matrix two: " << endl << Matrix_test2 << endl;

		// +
		cout << "Adding two matrices:" << endl;
		Matrix MatrixAdding = Matrix_test1 + Matrix_test2;
		cout <<"Result: " << MatrixAdding << endl;

		// -
		cout << "Subtracting matrices: " << endl;
		Matrix SubMatrix = Matrix_test1 + Matrix_test2;
		cout << "Result: " << SubMatrix << endl;

		// *
		cout << "Multiply the matrices: " << endl;
		Matrix MultiMatrix = Matrix_test1 * Matrix_test2;
		cout << "Result: " << MultiMatrix << endl;

		// +=
		cout << "Adding the second matrix to the first: " << endl;
		Matrix_test1 += Matrix_test2;
		cout << "Result: " << Matrix_test1 << endl;

		// -=
		cout << "Subtract the second matrix from the first one: " << endl;
		Matrix_test1 -= Matrix_test2;
		cout << "Result: " << Matrix_test1 << endl;

		// *=
		cout << "Multiply the first matrix by the second: " << endl;
		Matrix_test1 *= Matrix_test2;
		cout << "Result: " << Matrix_test1 << endl;
	}

	return 0;
}