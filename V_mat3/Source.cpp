#include<iostream>
#include<math.h>

int main()
{
	setlocale(LC_ALL, "rus");
    int i, j, n, m;
    //создаем массив
    std::cout << "Number of equations: ";
    std::cin >> n;
    std::cout << "Number of variables: ";
    std::cin >> m;
    m += 1;
    float** matrix = new float* [n];
    for (i = 0; i < n; i++)
        matrix[i] = new float[m];

    //инициализируем

    for (i = 0; i < n; i++)

        for (j = 0; j < m; j++)
        {
            std::cout << " Element " << "[" << i + 1 << " , " << j + 1 << "]: ";

            std::cin >> matrix[i][j];
        }

    //выводим массив
    std::cout << "matrix: " << std::endl;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
            std::cout << matrix[i][j] << " ";
            std::cout << std::endl;
    }
    std::cout << std::endl;

    //Метод Гаусса
    //Прямой ход, приведение к верхнетреугольному виду
    float  tmp;
    int k;
    float* xx = new float[m];

    for (i = 0; i < n; i++)
    {
        tmp = matrix[i][i];
        for (j = n; j >= i; j--)
            matrix[i][j] /= tmp;
        for (j = i + 1; j < n; j++)
        {
            tmp = matrix[j][i];
            for (k = n; k >= i; k--)
                matrix[j][k] -= tmp * matrix[i][k];
        }
    }
    /*обратный ход*/
    xx[n - 1] = matrix[n - 1][n];
    for (i = n - 2; i >= 0; i--)
    {
        xx[i] = matrix[i][n];
        for (j = i + 1; j < n; j++) xx[i] -= matrix[i][j] * xx[j];
    }

    //Выводим решения
    for (i = 0; i < n; i++)
        std::cout << xx[i] << " ";
    std::cout << std::endl;

    delete[] matrix;
    system("pause");

	return 0;
}