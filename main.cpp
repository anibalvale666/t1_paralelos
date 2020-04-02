#include <iostream>
#include <chrono>
using namespace std;

int *generateArray(int t)
{
    srand(time(0));
    int *b;
    b= new int[t];
    for(int i=0;i<t;i++)
    {
        *(b+i) = rand() % 100;
    }
    return b;
}

int **generateMatrix(int f,int c)
{
    srand(time(0));
    int **b;
    b= new int*[f];
    for(int i=0;i<f;i++)
        b[i] = new int[c];


    for(int i=0;i<f;i++)
        for(int j=0;j<c;j++)
        {
            b[i][j] = rand() % 100;
        }
    return b;

}

void intercambio(int *a,int *b)
{
    int j;
    j = *a;
    *a = *b;
    *b = j;
}

void imprimir(int *a,int t)
{
    for(int i=0;i<t;i++)
    {
        cout << *(a+i) << " ";
    }
    cout << endl;
}


int main()
{
    int MAX = 20000;
    int **A, *x,*y;
    A = generateMatrix(MAX,MAX);
    x = generateArray(MAX);
    y = generateArray(MAX);

    for( int i=0;i<MAX;i++)
        y[i] = 0;

    cout << "probando con " << MAX << " elementos\n\n";
    /*first pairs of loop*/
    auto start = std::chrono::system_clock::now();
    for(int i=0;i<MAX;i++)
        for(int j=0;j<MAX;j++)
            y[i] += A[i][j]* x[j];

    auto end = std::chrono::system_clock::now();
    /*addign y = 0*/
    for( int i=0;i<MAX;i++)
        y[i] = 0;


    auto start2 = std::chrono::system_clock::now();
    /*second pairs of loop*/
    for(int j=0;j<MAX;j++)
        for(int i=0;i<MAX;i++)
            y[i] += A[i][j]* x[j];

    auto end2 = std::chrono::system_clock::now();


    std::chrono::duration<float,std::milli> duration = end - start;

    cout << " \nfirst loop " << duration.count() << "s\n" << endl;

    std::chrono::duration<float,std::milli> duration2 = end2 - start2;

    cout << " \nsecond loop " << duration2.count() << "s\n" << endl;


    return 0;
}
