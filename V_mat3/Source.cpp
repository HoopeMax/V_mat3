//#include<iostream>
//#include<math.h>
////����� ������
//void Metod_Gays(int m, int n, float** matrix);
////����� ������
//void OutputMat(int n, int m, float** matrix); 
////��������� ������
//void MatrixMul(int n, int m, float** matA, float** matA2, float** newmatA);
////�������� AX=B � A^3X=B
//void MatAB(int n, int mA, float* matB, int mAB, float** matA, float** matAB);
////���� ������� � � �
//void InputVek(int n, float* vek);
//// �(�)*�^3*Y
//void Resul(int n, float* vekY, float** newmatA3);
//
//int main()
//{
//	setlocale(LC_ALL, "rus");
//    int i, j, n, mAB;
//    //������� ������
//    std::cout << "���������� ���������: ";
//    std::cin >> n;
//    std::cout << "���������� ����������: ";
//    std::cin >> mAB;
//    int mA = mAB;
//    mAB += 1;//��������� ��� ������ �������
//
//    //������ �
//    float* matB = new float[n];
//
//    //������ �
//    float* matY = new float[n];
//
//    //������� �B
//    float** matAB = new float* [n];
//    for (i = 0; i < n; i++)
//        matAB[i] = new float[mAB];
//
//    //������� �
//    float** matA = new float* [n];
//    for (i = 0; i < n; i++)
//        matA[i] = new float[mA];
//
//    //������� �^2
//    float** newmatA = new float* [n];
//    for (i = 0; i < n; i++)
//        newmatA[i] = new float[mA];
//
//    //������� �^3
//    float** newmatA3 = new float* [n];
//    for (i = 0; i < n; i++)
//        newmatA3[i] = new float[mA];
//
//    //��������������
//    std::cout << std::endl << "�������  �: " << std::endl;
//    for (i = 0; i < n; i++)
//    {
//        for (j = 0; j < mA; j++)
//        {
//            std::cin >> matA[i][j];
//        }
//    }
//    std::cout << std::endl;
//    
//    // B����� �
//    std::cout << std::endl << "�������  �: " << std::endl;
//    InputVek(n, matB);
//
//    // B����� Y
//    std::cout << std::endl << "�������  Y: " << std::endl;
//    InputVek(n, matY);
//
//    //������� ��
//    MatAB(n, mA, matB, mAB, matA, matAB);
//
//    //������� ������ ��=�
//    std::cout << "������� ��=�: " << std::endl;
//    OutputMat(n, mAB, matAB);
// 
//    MatrixMul(n, mA, matA, matA, newmatA);
//    MatrixMul(n, mA, matA, newmatA, newmatA3);
//
//    std::cout << "���� ��=�: " << std::endl;
//    Metod_Gays(mAB, n, matAB);
//
//    //������� �3�
//    MatAB(n, mA, matB, mAB, newmatA3, matAB);
//
//    std::cout << "������� �^3=: " << std::endl;
//    OutputMat(n, mA, newmatA3);
//    std::cout << "������� �^3*�=�: " << std::endl;
//    OutputMat(n, mAB, matAB);
//
//    std::cout << std::endl << "���� �^3*�=�: " << std::endl;
//    Metod_Gays(mAB, n, matAB);
//
//    std::cout << std::endl << "�(�)*�^3*Y: " << std::endl;
//    Resul(n, matY, newmatA3);
//
//    delete[] matAB, matA, newmatA, newmatA3, matB, matY;
//
//    system("pause");
//
//	return 0;
//}
//
//void Metod_Gays(int m, int n, float** mat)
//{
//    //����� ������
//    //������ ���, ���������� � ������������������ ����
//    float  p_val;
//    int k, i, j;
//    float* vekx = new float[m];
//
//    for (i = 0; i < n; i++)
//    {
//        p_val = mat[i][i];
//        for (j = n; j >= i; j--)
//            mat[i][j] /= p_val;
//        for (j = i + 1; j < n; j++)
//        {
//            p_val = mat[j][i];
//            for (k = n; k >= i; k--)
//                mat[j][k] -= p_val * mat[i][k];
//        }
//    }
//    //�������� ���
//    vekx[n - 1] = mat[n - 1][n];
//    for (i = n - 2; i >= 0; i--)
//    {
//        vekx[i] = mat[i][n];
//        for (j = i + 1; j < n; j++) vekx[i] -= mat[i][j] * vekx[j];
//    }
//
//    //������� �������
//    for (i = 0; i < n; i++)
//        std::cout << vekx[i] << " ";
//    std::cout << std::endl;
//}
//
//void OutputMat(int n, int m, float** matrix)
//{
//    std::cout << std::endl;
//    for (int i = 0; i < n; i++)
//    {
//        for (int j = 0; j < m; j++)
//            std::cout << matrix[i][j] << " ";
//        std::cout << std::endl;
//    }
//    std::cout << std::endl;
//}
//
//void MatrixMul(int n, int m, float** matA, float** matA2, float** newmatA)
//{
//    for (int i = 0; i < n; i++)
//        for (int j = 0; j < m; j++)
//        {
//            newmatA[i][j] = 0;
//            for (int k = 0; k < n; k++)
//                newmatA[i][j] += matA[i][k] * matA2[k][j];
//        }
//}
//
//void MatAB(int n, int mA, float* matB, int mAB, float** matA, float** matAB)
//{
//    
//    for (int i = 0; i < n; i++)
//    {
//        for (int j = 0; j < mA; j++)
//        {
//            matAB[i][j] = matA[i][j];
//        }
//    }
//    for (int i = 0; i < n; i++)
//    {
//        matAB[i][mAB-1] = matB[i];
//    }
//}
//
//void InputVek(int n, float* vek)
//{
//    for (int i = 0; i < n; i++)
//    {
//        std::cin >> vek[i];
//    }
//}
//
//void Resul(int n, float* vekY, float** newmatA3)
//{
//    float* vek = new float[n];
//
//    float result = 0;
//
//    for (int i = 0; i < n; i++)
//    {
//        vek[i] =0;
//    }
// 
//    for (int i = 0; i < n; i++)
//    {
//        for (int j = 0; j < n; j++)
//        {
//            vek[i] = vek[i] + (newmatA3[j][i] * vekY[j]);
//        }
//    }
//
//    for (int i = 0; i < n; i++)
//    {
//        result = result + (vek[i] * vekY[i]);
//    }
//
//    std::cout << std::endl <<"z = "<< result << std::endl;
//    delete[]  vek;
//}