#include<iostream>
#include<math.h>
//����� ������
void Metod_Gays(int m, int n, float** matrix);
//����� ������
void InputMat(int n, int m, float** matrix); 
//��������� ������
void MatrixMul(int n, int m, float** matA, float** matA2, float** newmatA);
//�������� AX=B � A^3X=B
void MatAB(int n, int mA, float* matB, int mAB, float** matA, float** matAB);

int main()
{
	setlocale(LC_ALL, "rus");
    int i, j, n, mAB;
    //������� ������
    std::cout << "���������� ���������: ";
    std::cin >> n;
    std::cout << "���������� ����������: ";
    std::cin >> mAB;
    int mA = mAB;
    mAB += 1;//��������� ��� ������ �������

    //������ �
    float* matB = new float[n];

    //������� �B
    float** matAB = new float* [n];
    for (i = 0; i < n; i++)
        matAB[i] = new float[mAB];

    //������� �^3B
    float** matA3B = new float* [n];
    for (i = 0; i < n; i++)
        matA3B[i] = new float[mAB];

    //������� �
    float** matA = new float* [n];
    for (i = 0; i < n; i++)
        matA[i] = new float[mA];

    //������� �^2
    float** newmatA = new float* [n];
    for (i = 0; i < n; i++)
        newmatA[i] = new float[mA];

    //������� �^3
    float** newmatA3 = new float* [n];
    for (i = 0; i < n; i++)
        newmatA3[i] = new float[mA];

    //��������������
    std::cout << std::endl << "�������  �: " << std::endl;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < mA; j++)
        {
            std::cin >> matA[i][j];
        }
    }
    std::cout << std::endl;
    
    // B����� �
    std::cout << std::endl << "�������  �: " << std::endl;
    for (i = 0; i < n; i++)
    {
        std::cin >> matB[i];
    }

    //������� ��
    MatAB(n, mA, matB, mAB, matA, matAB);

    //������� ������ ��=�
    std::cout << "������� ��=�: " << std::endl;
    InputMat(n, mAB, matAB);
 
    MatrixMul(n, mA, matA, matA, newmatA);
    MatrixMul(n, mA, matA, newmatA, newmatA3);

    //������� �3�
    MatAB(n, mA, matB, mAB, newmatA3, matA3B);

    std::cout << "���� ��=�: " << std::endl;
    Metod_Gays(mAB, n, matAB);

    std::cout << "������� �2=: " << std::endl;
    InputMat(n, mA, newmatA);
    std::cout << "������� �3=: " << std::endl;
    InputMat(n, mA, newmatA3);
    std::cout << "������� �3�=�: " << std::endl;
    InputMat(n, mAB, matA3B);

    std::cout << "���� �3�=�: " << std::endl;
    Metod_Gays(mAB, n, matA3B);

    delete[] matAB;
    delete[] matA;
    delete[]newmatA;
    delete[]newmatA3;

    system("pause");

	return 0;
}

void Metod_Gays(int m, int n, float** matrix)
{
    //����� ������
    //������ ���, ���������� � ������������������ ����
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
    /*�������� ���*/
    xx[n - 1] = matrix[n - 1][n];
    for (i = n - 2; i >= 0; i--)
    {
        xx[i] = matrix[i][n];
        for (j = i + 1; j < n; j++) xx[i] -= matrix[i][j] * xx[j];
    }

    //������� �������
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

//A+B
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