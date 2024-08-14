#include <bits/stdc++.h>
using namespace std;

/*
Sample Input 1:
3
Sample Output 1:
* * *
* * *
* * *

*/
void nForest(int n)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {

            cout << "*";
        }
        cout << endl;
    }
}

/*
Sample Input 1:
5
Sample Output 1:
 *
 * *
 * * *
 * * * *
 * * * * *

*/
void nForest1(int n)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {

            cout << "*";
        }
        cout << endl;
    }
}

// nForest2 question --->
/*
Sample Input 3 :
4
Sample Output 3 :
* * * *
* * *
* *
*

*/
void seeding(int n)
{
    for (int i = n; i >= 1; i--)
    {
        for (int j = 1; j <= i; j++)
        {

            cout << "*";
        }
        cout << endl;
    }
}

/*
Sample Input 1:
5
Sample Output 1:
        *
      * *
    * * *
  * * * *
* * * * *

*/
void nForest3(int n)
{
    for (int i = 1; i <= n; i++)
    {
        // space
        for (int space = 1; space <= n - i; space++)
        {
            cout << " ";
        }
        // star
        for (int star = 1; star <= i; star++)
        {
            cout << "*";
        }
        cout << endl;
    }
}

/*
Sample Input 1:
5
Sample Output 1:
* * * * *
  * * * *
    * * *
      * *
        *

*/
void nForest4(int n)
{
    for (int i = n; i >= 1; i--)
    {
        // space
        for (int space = 1; space <= n - i; space++)
        {
            cout << " ";
        }
        // star
        for (int star = 1; star <= i; star++)
        {
            cout << "*";
        }
        cout << endl;
    }
}

/*
Sample Input 1:
3
Sample Output 1:
1
1 2
1 2 3

 */
void nTriangle(int n)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {

            cout << j;
        }
        cout << endl;
    }
}

/*
Sample Input 1:
3
Sample Output 1:
1
2 2
3 3 3

*/
void triangle(int n)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {

            cout << i;
        }
        cout << endl;
    }
}

/*
Sample Input 3 :
7
Sample Output 3 :
1 2 3 4 5 6 7
1 2 3 4 5 6
1 2 3 4 5
1 2 3 4
1 2 3
1 2
1

*/
void nNumberTriangle(int n)
{
    for (int i = n; i >= 1; i--)
    {
        for (int j = 1; j <= i; j++)
        {

            cout << j;
        }
        cout << endl;
    }
}

/*
Sample Input 1:
3
Sample Output 1:
  *
 ***
*****

*/
void nStarTriangle(int n)
{
    for (int i = 1; i <= n; i++)
    {

        // space
        for (int space = 1; space <= n - i; space++)
        {
            cout << " ";
        }
        // star
        for (int star = 1; star <= 2 * i - 1; star++)
        {
            cout << "*";
        }
        // space
        for (int space = 1; space <= n - i; space++)
        {
            cout << " ";
        }
        cout << endl;
    }
}

/*
Sample Input 1:
3
Sample Output 1:
*****
 ***
  *

*/
void nStarTriangle2(int n)
{
    for (int i = n; i >= 1; i--)
    {

        // space
        for (int space = 1; space <= n - i; space++)
        {
            cout << " ";
        }
        // star
        for (int star = 1; star <= 2 * i - 1; star++)
        {
            cout << "*";
        }
        // space
        for (int space = 1; space <= n - i; space++)
        {
            cout << " ";
        }
        cout << endl;
    }
}

/*
Sample Input 1:
3
Sample Output 1:
  *
 ***
*****
*****
 ***
  *

*/
void nStarDiamond(int n)
{
    // first half section ---->
    for (int i = 1; i <= n; i++)
    {

        // space
        for (int space = 1; space <= n - i; space++)
        {
            cout << " ";
        }
        // star
        for (int star = 1; star <= 2 * i - 1; star++)
        {
            cout << "*";
        }
        // space
        for (int space = 1; space <= n - i; space++)
        {
            cout << " ";
        }
        cout << endl;
    }

    // second half section --->
    for (int i = n; i >= 1; i--)
    {

        // space
        for (int space = 1; space <= n - i; space++)
        {
            cout << " ";
        }
        // star
        for (int star = 1; star <= 2 * i - 1; star++)
        {
            cout << "*";
        }
        // space
        for (int space = 1; space <= n - i; space++)
        {
            cout << " ";
        }
        cout << endl;
    }
}

/*
Sample Input 1:
5
Sample Output 1:
*
**
***
****
*****    // ye only ek baar hi aaya hai so second half ke time i ->  n-1 se start krna rhega
****
***
**
*

*/

void nStarTriangle3(int n)
{
    // for first half --->
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {

            cout << "*";
        }
        cout << endl;
    }
    // for second half --->
    for (int i = n - 1; i >= 1; i--)
    {
        for (int j = 1; j <= i; j++)
        {

            cout << "*";
        }
        cout << endl;
    }
}

/*
Sample Input 3 :
6
Sample Output 3 :
1
0 1
1 0 1
0 1 0 1
1 0 1 0 1
0 1 0 1 0 1

*/

void nBinaryTriangle(int n)
{
    for (int i = 1; i <= n; i++)
    {

        for (int j = 1; j <= i; j++)
        {
            if ((i + j) % 2 == 0) // Even
                cout << "1";

            else // odd
                cout << "0";
        }
        cout << endl;
    }
}

/*
Sample Input 3 :
7
Sample Output 3 :
1                         1
1 2                     2 1
1 2 3                 3 2 1
1 2 3 4             4 3 2 1
1 2 3 4 5         5 4 3 2 1
1 2 3 4 5 6     6 5 4 3 2 1
1 2 3 4 5 6 7 7 6 5 4 3 2 1

*/

void numberCrown(int n)
{

    for (int i = 1; i <= n; i++)
    {

        // number
        for (int num = 1; num <= i; num++)
        {
            cout << num;
        }
        // space
        for (int space = 1; space <= 2 * (n - i); space++)
        {
            cout << " ";
        }
        // number
        for (int num = i; num >= 1; num--)
        {
            cout << num;
        }
        cout << endl;
    }
}

/*
Sample Input 3 :
7
Sample Output 3 :
1
2 3
4 5 6
7 8 9 10
11 12 13 14 15
16 17 18 19 20 21
22 23 24 25 26 27 28

*/
void nNumberTriangle2(int n)
{

    int num = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cout << num++ << " ";
        }
        cout << endl;
    }
}
/*
Sample Input 3 :
7
Sample Output 3 :
A
A B
A B C
A B C D
A B C D E
A B C D E F
A B C D E F G

*/
void nLetterTriangle(int n)
{

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            char ch = 'A' + j - 1;
            cout << ch;
        }
        cout << endl;
    }
}
/*
Sample Input 3 :
7
Sample Output 3 :
A B C D E F G
A B C D E F
A B C D E
A B C D
A B C
A B
A

*/
void nLetterTriangle2(int n)
{
    for (int i = n; i >= 1; i--)
    {
        for (int j = 1; j <= i; j++)
        {
            char ch = 'A' + j - 1;
            cout << ch;
        }
        cout << endl;
    }
}

/*
Sample Input 3 :
4
Sample Output 3 :
A
B B
C C C
D D D D

*/
void alphaRamp(int n)
{
    for (int i = 1; i <= n; i++)
    {
        char ch = 'A' + i - 1;
        for (int j = 1; j <= i; j++)
        {

            cout << ch;
        }
        cout << endl;
    }
}
/*
Sample Input 1:
3
Sample Output 1:
    A
  A B A
A B C B A

*/

void alphaHill(int n)
{

    for (int i = 1; i <= n; i++)
    {

        // space
        for (int space = 1; space <= n - i; space++)
        {
            cout << " ";
        }
        // Alphabets
        char ch = 'A' - 1; // in down side, increase and decrease operation first then print

        for (int letter = 1; letter <= 2 * i - 1; letter++)
        {

            // Increase
            if (letter <= i)
            {
                ch = ch + 1;
            }
            // Decrease
            else
            {
                ch = ch - 1;
            }
            cout << ch;
        }

        cout << endl;
    }
}

/*
Sample Input 1:
3
Sample Output 1:
C
C B
C B A

*/
void alphaTriangle(int n)
{

    for (int i = 1; i <= n; i++)
    {
        char ch = 'A' + n;
        for (int j = 1; j <= i; j++)
        {
            ch--;
            cout << ch;
        }
        cout << endl;
    }
}

/*
Input Format: N = 6
Result:
************
*****  *****
****    ****
***      ***
**        **
*          *
*          *
**        **
***      ***
****    ****
*****  *****
************

*/
void symmetry(int n)
{

    // upper side
    for (int i = 1; i <= n; i++)
    {

        // star
        for (int star = 1; star <= n + 1 - i; star++)
        {
            cout << "*";
        }

        // space
        for (int space = 1; space <= 2 * (i - 1); space++)
        {
            cout << " ";
        }

        // star
        for (int star = 1; star <= n + 1 - i; star++)
        {
            cout << "*";
        }
        cout << endl;
    }

    // down side
    for (int i = n; i >= 1; i--)
    {

        // star
        for (int star = 1; star <= n + 1 - i; star++)
        {
            cout << "*";
        }

        // space
        for (int space = 1; space <= 2 * (i - 1); space++)
        {
            cout << " ";
        }

        // star
        for (int star = 1; star <= n + 1 - i; star++)
        {
            cout << "*";
        }
        cout << endl;
    }
}

/*
Input Format: N = 6
Result:
*          *
**        **
***      ***
****    ****
*****  *****
************
*****  *****
****    ****
***      ***
**        **
*          *

*/
void symmetry3(int n)
{
    // upper half
    for (int i = 1; i <= n; i++)
    {
        // star
        for (int j = 1; j <= i; j++)
        {
            cout << "*";
        }

        // space
        for (int j = 1; j <= 2 * (n - i); j++)
        {
            cout << " ";
        }

        // star
        for (int j = i; j >= 1; j--)
        {
            cout << "*";
        }

        cout << endl;
    }

    // down half

    for (int i = n - 1; i >= 1; i--)
    {
        // star
        for (int j = 1; j <= i; j++)
        {
            cout << "*";
        }

        // space
        for (int j = 1; j <= 2 * (n - i); j++)
        {
            cout << " ";
        }

        // star
        for (int j = i; j >= 1; j--)
        {
            cout << "*";
        }
        cout << endl;
    }
}

void symmetry2(int n)
{

    // upper side

    for (int i = n; i >= 1; i--)
    {

        // star
        for (int star = 1; star <= n + 1 - i; star++)
        {
            cout << "*";
        }

        // space
        for (int space = 1; space <= 2 * (i - 1); space++)
        {
            cout << " ";
        }

        // star
        for (int star = 1; star <= n + 1 - i; star++)
        {
            cout << "*";
        }
        cout << endl;
    }
    // down side
    // start with 2 because hrizontal axis ke respect me symmetry nahi hai balki vertical axis ke respect me hai
    for (int i = 2; i <= n; i++)
    {

        // star
        for (int star = 1; star <= n + 1 - i; star++)
        {
            cout << "*";
        }

        // space
        for (int space = 1; space <= 2 * (i - 1); space++)
        {
            cout << " ";
        }

        // star
        for (int star = 1; star <= n + 1 - i; star++)
        {
            cout << "*";
        }
        cout << endl;
    }
}

/*
Sample Input 3 :
8
Sample Output 3 :
********
*      *
*      *
*      *
*      *
*      *
*      *
********

*/

void getStarPattern(int n)
{

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {

            if (i == 1 || i == n || j == 1 || j == n)
            {
                cout << "* ";
            }
            else
            {
                cout << "  ";
            }
        }
        cout << endl;
    }
}

/*
Sample Input 2 :
5
Sample Output 2 :
555555555
544444445
543333345
543222325
543212345
543222325
543333345
544444445
555555555

*/

/*
Convert original matrix to second matrix --

555555555                        000000000
544444445                        011111110
543333345                        012222210
543222325                        012333210
543212345         ------->       012343210
543222325                        012333210
543333345                        012222210
544444445                        011111110
555555555                        000000000

*/

void getNumberPattern(int n)
{
    int total = 2 * n - 1;

    for (int row = 1; row <= total; row++)
    {

        for (int col = 1; col <= total; col++)
        {

            // find all four direction distance
            int up = row - 1;
            int left = col - 1;
            int down = total - row;
            int right = total - col;

            // find min value

            int val = min(up, min(left, min(down, right)));

            int actulval = n - val;

            cout << actulval;
        }
        cout << endl;
    }
}

int main()
{

    int n;
    cout << "n : ";
    cin >> n;

    // nForest1(n);
    // seeding(n);  // nForest2
    // nForest3(n);
    // nForest4(n);

    // nTriangle(n);
    // triangle(n);
    // nNumberTriangle(n);

    // nStarTriangle(n);
    // nStarTriangle2(n);
    // nStarDiamond(n);
    // nStarTriangle3(n);

    // nBinaryTriangle(n);

    // numberCrown(n);

    // nNumberTriangle2(7);

    // nLetterTriangle(n);
    // nLetterTriangle2(n);

    // alphaRamp(n);
    // alphaHill(n);
    // alphaTriangle(n);

    // symmetry(n);
    // symmetry2(n);
    // symmetry3(n);

    // getStarPattern(n);
    // getNumberPattern(n);
}