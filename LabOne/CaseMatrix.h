#include "StandHeader.h"
using namespace std;

class Matrix
{
private:
	
	int m_rows, m_cols;
	vector <vector <int>> array_Matrix; // vector <vector <int>> - двумерный вектор 

public:

	Matrix(); // Создание пустых переменных
	Matrix(int rows, int cols);
	Matrix(vector <vector <int>> arrayMatrix);

	friend Matrix& operator+	(const Matrix& arrayA,		const Matrix& arrayB);
	friend Matrix& operator+=	(Matrix& arrayA,			const Matrix& arrayB);
	friend Matrix& operator-	(const Matrix& arrayA,		const Matrix& arrayB);
	friend Matrix& operator-=	(Matrix& arrayA,			const Matrix& arrayB);
	friend Matrix& operator*	(const Matrix& arrayA,		const Matrix& arrayB);
	friend Matrix& operator*=	(Matrix& arrayA,			const Matrix& arrayB);
	
	unsigned getSize();


	friend ostream& operator<<	(std::ostream& stringOut, const Matrix& arrayM);
	friend istream& operator>>	(std::istream& stringIn, Matrix& arrayM);
};

Matrix::Matrix() {
	m_rows = m_cols = 0;
}
Matrix::Matrix(int rows, int cols) {
	
	m_cols = cols;
	m_rows = rows;
	array_Matrix = *new vector <vector <int>>(m_rows, vector <int>(m_cols,0)); // резервирование памяти под массив

}
Matrix::Matrix(vector <vector <int>>  arrayMatrix) {

	array_Matrix = arrayMatrix;
	m_rows = array_Matrix.size();
	
	if (m_rows > 0){
		m_cols = array_Matrix[0].size();
	}
	else{
		m_cols = 0;
	}
}

/* Мат. Функции */
// в параметре: const = знач, после выхода функции массивы не изменяются
Matrix &operator+(const Matrix& arrayA, const Matrix& arrayB) { 

	Matrix* arrayR = new Matrix(arrayA.m_rows, arrayA.m_rows);
	for (int i = 0; i < arrayA.m_rows; i++)
	{
		for (int j = 0; j < arrayA.m_cols; j++) {
			arrayR->array_Matrix[i][j] = arrayA.array_Matrix[i][j] + arrayB.array_Matrix[i][j];
		}
	}
	return *arrayR;

}
Matrix &operator-(const Matrix& arrayA, const Matrix& arrayB) {
	
	Matrix* arrayR = new Matrix(arrayA.m_rows, arrayA.m_rows);
	for (int i = 0; i < arrayA.m_rows; i++)
	{
		for (int j = 0; j < arrayA.m_cols; j++) {
			arrayR->array_Matrix[i][j] = arrayA.array_Matrix[i][j] - arrayB.array_Matrix[i][j];
		}
	}

	return *arrayR;

}
Matrix &operator*(const Matrix& arrayA, const Matrix& arrayB) {
	
	Matrix* arrayR = new Matrix(arrayA.m_rows, arrayA.m_rows);
	for (int i = 0; i < arrayA.m_rows; i++)
	{
		for (int j = 0; j < arrayA.m_cols; j++) {
			arrayR->array_Matrix[i][j] = arrayA.array_Matrix[i][j] * arrayB.array_Matrix[i][j];
		}
	}

	return *arrayR;

}

/* Функции присваивания */
Matrix& operator+=(Matrix& arrayA, const Matrix& arrayB) {
	
	//Matrix* arrayR = new Matrix(arrayA.m_rows, arrayA.m_rows);
	for (int i = 0; i < arrayA.m_rows; i++)
	{
		for (int j = 0; j < arrayA.m_cols; j++) {
			arrayA.array_Matrix[i][j] += arrayB.array_Matrix[i][j];
		}
	}

	return arrayA;
}
Matrix& operator-=(Matrix& arrayA, const Matrix& arrayB) {
	
	for (int i = 0; i < arrayA.m_rows; i++)
	{
		for (int j = 0; j < arrayA.m_cols; j++) {
			arrayA.array_Matrix[i][j] -= arrayB.array_Matrix[i][j];
		}
	}

	return arrayA;
}
Matrix& operator*=(Matrix& arrayA, const Matrix& arrayB) {
	for (int i = 0; i < arrayA.m_rows; i++)
	{
		for (int j = 0; j < arrayA.m_cols; j++) {
			arrayA.array_Matrix[i][j] *= arrayB.array_Matrix[i][j];
		}
	}

	return arrayA;
}

/* Функции ввода и вывода */
ostream& operator<<(ostream& stringOut, const Matrix& arrayM) {
	
	for (int i = 0; i < arrayM.m_rows; i++)
	{
		for (int j = 0; j < arrayM.m_cols; j++)
		{
			stringOut << arrayM.array_Matrix[i][j] << "; ";
		}
		stringOut << endl;
	}
	stringOut << "Size in: string - "<< arrayM.m_rows<< "; column - "<< arrayM.m_cols << endl;
}
istream& operator>>(istream& stringIn, Matrix& arrayM) {

	stringIn >> arrayM.m_rows;
	stringIn >> arrayM.m_cols;

	arrayM.array_Matrix = *new vector <vector <int>>(arrayM.m_rows, vector <int>(arrayM.m_cols, 0)); // резервирование памяти под массив
	
	for (int i = 0; i < arrayM.m_rows; i++) {
		for (int j = 0; j < arrayM.m_cols; j++)
		{
			stringIn >> arrayM.array_Matrix[i][j];
		}
	}

	return stringIn;
}


/* Служебные функции */

unsigned Matrix::getSize() {
	return array_Matrix.size();
}
