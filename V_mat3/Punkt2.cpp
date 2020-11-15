#include<iostream>
#include<math.h>

void InputVek(int n, float* vek);
void InputMat(int m, float** mat);

int main()
{
    int n = 4;
    int m = 3;
	setlocale(LC_ALL, "rus");

	//Вектор A
    float* vekA = new float[n];

    //Матрица С
    float** matC = new float* [n];
    for (int i = 0; i < n; i++)
        matC[i] = new float[m];

    float do1 = 0, do2 = 0, res1 = 0;
    float do3 = 0, res2 = 0;
    std::cout << "Введите вектор А " <<  std::endl;
    InputVek(n, vekA);
    std::cout << "Введите матрицу С " << std::endl;
    InputMat(m, matC);

    for (int i = 0; i < n; i++)
    {
        do1= do1+ vekA[i];
    }
 
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < m; j++)
        {
            do2= do2+ matC[i][j];
        }
    }

    for (int i = 0; i < n; i++)
    {
        do3 = do3 + (vekA[i]* vekA[i]);
    }

    res1 = (do2 * do2) + do1 * 2;
    res2 = res1 / ((do1+1) * (do3+1));

    std::cout <<"Ответ S = "<< res2 << std::endl;

	return 0;
}

void InputVek(int n, float* vek)
{
    for (int i = 0; i < n; i++)
    {
        std::cin >> vek[i];
    }
}

void InputMat(int m, float** mat)
{
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < m; j++)
        {
            std::cin >> mat[i][j];
        }
    }
}

