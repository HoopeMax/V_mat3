#include<iostream>
#include<math.h>

void Metod_Gays(int m, int n, float** matrix);//Метод Гаусса
void InputMat(int n, int m, float** matrix);//Вывод матриц 

int main()
{
	setlocale(LC_ALL, "rus");
    int i, j, n, m;
    //создаем массив
    std::cout << "Количество уравнений: ";
    std::cin >> n;
    std::cout << "Количество переменных: ";
    std::cin >> m;
    int mA = m;
    m += 1;//Добавляем под вектор столбец
    
    float** matrix = new float* [n];
    for (i = 0; i < n; i++)
        matrix[i] = new float[m];

    //Матрица А
    float** matrixA = new float* [n];
    for (i = 0; i < n; i++)
        matrixA[i] = new float[mA];

    //инициализируем
    std::cout << std::endl << "Введите  АХ=В: " << std::endl;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            std::cin >> matrix[i][j];
        }
    }
    std::cout << std::endl;

    //Матрица А
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < mA; j++)
        {
            matrixA[i][j] = matrix[i][j];
        }
    }

    //выводим массив АХ=В
    std::cout << "Матрица АХ=В: " << std::endl;
    InputMat(n, m, matrix);
 
    //выводим массив А
    std::cout << "Матрица А : " << std::endl;
    InputMat(n, mA, matrixA);

    Metod_Gays(m, n, matrix);

    delete[] matrix;
    delete[] matrixA;
    system("pause");

	return 0;
}

void Metod_Gays(int m, int n, float** matrix)
{
    //Метод Гаусса
    //Прямой ход, приведение к верхнетреугольному виду
    float  tmp;
    int k, i, j;
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
}

void InputMat(int n, int m, float** matrix)
{
    std::cout << std::endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            std::cout << matrix[i][j] << " ";
        std::cout << std::endl;
    }
    std::cout << std::endl;
}