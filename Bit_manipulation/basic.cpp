#include <bits/stdc++.h>
using namespace std;

void findEvenOdd(int N)
{
    if ((N & 1) == 0)
    {
        cout << "EVEN" << endl;
    }
    else
    {
        cout << "ODD" << endl;
    }
}
void checkBitsSetOrReset(int N, int BitsNo)
{
    int mask = 1 << BitsNo;

    if ((N & mask) == 0)
    {
        cout << "CLEAR BITS" << endl;
    }
    else
    {
        cout << "SET BITS" << endl;
    }
}
void resetBits(int N, int BitsNo)
{

    int mask = 1 << BitsNo;
    mask = ~(mask);

    cout << (N & mask) << endl;
}
void setBits(int N, int BitsNo)
{
    // shift 1 , how many times (BitsNo) that take position for operation
    int mask = 1 << BitsNo;

    cout << (N | mask) << endl;
}
void removeLastBits(int N)
{
    cout << (N & (N - 1)) << endl;
}
void powerOf2(int N)
{
    // take and with N-1 and if it get 0 then true of power of 2

    int mask = (N - 1);
    // cout << N - 1 << endl;
    // cout << (N & mask) << endl;
    // N & mask ko always bracket me rakhe
    ((N & mask) == 0) ? cout << "TRUE" << endl : cout << "FALSE" << endl;
}
void countNoOfSetBits2(int N)
{
    int count = 0;
    // last bits reset concept
    while (N != 0)
    {
        N = N & (N - 1);
        count++;
    }
    cout << "SET BITS: " << count << endl;
}
void countNoOfSetBits1(int N)
{
    int count = 0;

    while (N != 0)
    {

        if (N & 1 == 1)
        {
            count++;
        }
        // right shift of N and Updation on N;
        N = N >> 1;
        cout << "hello" << endl;
        cout << N << endl;
    }
    cout << "SET BITS: " << count << endl;
}
int main()
{
    int N = 12;

    findEvenOdd(129);
    // checkBitsSetOrReset(13, 1);
    // setBits(10, 2);
    // resetBits(13, 2);

    // removeLastBits(N);
    // powerOf2(N);
    // countNoOfSetBits2(N);

    return 0;
}