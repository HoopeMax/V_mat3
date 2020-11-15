#include<iostream>
#include<math.h>
//Метод Гаусса
void Metod_Gays(int m, int n, float** matrix);
//Вывод матриц
void OutputMat(int n, int m, float** matrix); 
//Умножение матриц
void MatrixMul(int n, int m, float** matA, float** matA2, float** newmatA);
//Создание AX=B и A^3X=B
void MatAB(int n, int mA, float* matB, int mAB, float** matA, float** matAB);
//Ввод вектора В и У
void InputVek(int n, float* vek);
// У(т)*А^3*У
void Resul(int n, float* vekY, float** newmatA3);

int main()
{
	setlocale(LC_ALL, "rus");
    int i, j, n, mAB;
    //создаем массив
    std::cout << "Количество уравнений: ";
    std::cin >> n;
    std::cout << "Количество переменных: ";
    std::cin >> mAB;
    int mA = mAB;
    mAB += 1;//Добавляем под вектор столбец

    //Вектор В
    float* matB = new float[n];

    //Вектор У
    float* matY = new float[n];

    //Матрица АB
    float** matAB = new float* [n];
    for (i = 0; i < n; i++)
        matAB[i] = new float[mAB];

    //Матрица А
    float** matA = new float* [n];
    for (i = 0; i < n; i++)
        matA[i] = new float[mA];

    //Матрица А^2
    float** newmatA = new float* [n];
    for (i = 0; i < n; i++)
        newmatA[i] = new float[mA];

    //Матрица А^3
    float** newmatA3 = new float* [n];
    for (i = 0; i < n; i++)
        newmatA3[i] = new float[mA];

    //инициализируем
    std::cout << std::endl << "Введите  А: " << std::endl;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < mA; j++)
        {
            std::cin >> matA[i][j];
        }
    }
    std::cout << std::endl;
    
    // Bектор В
    std::cout << std::endl << "Введите  В: " << std::endl;
    InputVek(n, matB);

    // Bектор Y
    std::cout << std::endl << "Введите  Y: " << std::endl;
    InputVek(n, matY);

    //Создаем АВ
    MatAB(n, mA, matB, mAB, matA, matAB);

    //выводим массив АХ=В
    std::cout << "Матрица АХ=В: " << std::endl;
    OutputMat(n, mAB, matAB);
 
    MatrixMul(n, mA, matA, matA, newmatA);
    MatrixMul(n, mA, matA, newmatA, newmatA3);

    std::cout << "Гаус АХ=В: " << std::endl;
    Metod_Gays(mAB, n, matAB);

    //Создаем А3В
    MatAB(n, mA, matB, mAB, newmatA3, matAB);

    std::cout << "Матрица А3=: " << std::endl;
    OutputMat(n, mA, newmatA3);
    std::cout << "Матрица А^3Х=В: " << std::endl;
    OutputMat(n, mAB, matAB);

    std::cout << "Гаус А^3Х=В: " << std::endl;
    Metod_Gays(mAB, n, matAB);

    Resul(n, matY, newmatA3);

    delete[] matAB, matA, newmatA, newmatA3, matB, matY;

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

void OutputMat(int n, int m, float** matrix)
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

void MatrixMul(int n, int m, float** matA, float** matA2, float** newmatA)
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            newmatA[i][j] = 0;
            for (int k = 0; k < n; k++)
                newmatA[i][j] += matA[i][k] * matA2[k][j];
        }
}

void MatAB(int n, int mA, float* matB, int mAB, float** matA, float** matAB)
{
    
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < mA; j++)
        {
            matAB[i][j] = matA[i][j];
        }
    }
    for (int i = 0; i < n; i++)
    {
        matAB[i][mAB-1] = matB[i];
    }
}

void InputVek(int n, float* vek)
{
    for (int i = 0; i < n; i++)
    {
        std::cin >> vek[i];
    }
}

void Resul(int n, float* vekY, float** newmatA3)
{
    float* vek = new float[n];

    float result = 0;

    for (int i = 0; i < n; i++)
    {
        vek[i] =0;
    }
 
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            vek[i] = vek[i] + (newmatA3[j][i] * vekY[j]);
        }
    }

    for (int i = 0; i < n; i++)
    {
        std::cout << std::endl << vek[i] << std::endl;
    }

    for (int i = 0; i < n; i++)
    {
        result = result + (vek[i] * vekY[i]);
    }

    std::cout << std::endl << result << std::endl;

}