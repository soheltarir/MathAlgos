/**
 * @file Factorial.cpp
 * @brief
 *
 * factorial(n)
 *  1) Create an array ‘res[]’ of MAX size where MAX is number of maximum digits in output.
 *  2) Initialize value stored in ‘res[]’ as 1 and initialize ‘res_size’ (size of ‘res[]’) as 1.
 *  3) Do following for all numbers from x = 2 to n.
 *  ……a) Multiply x with res[] and update res[] and res_size to store the multiplication result.
 *
 * How to multiply a number ‘x’ with the number stored in res[]?
 * The idea is to use simple school mathematics. We one by one multiply x with every digit of res[]. The important point to note here is digits are multiplied from rightmost digit to leftmost digit. If we store digits in same ord1) Initialize carry as 0.
 * 2) Do following for i = 0 to res_size – 1
 *  ….a) Find value of res[i] * x + carry. Let this value be prod.
 *  ….b) Update res[i] by storing last digit of prod in it.
 *  ….c) Update carry by storing remaining digits in carry.
 * 3) Put all digits of carry in res[] and increase res_size by number of digits in carry.
 *
 * @author Sohel Tarir
 * @version 1.0
 * @date 2015-03-09
 */

#include <iostream>
#include <time.h>
using namespace std;

#define MAX 1000

int multiply(int x, int res[], int res_size);

void factorial(int n){
    int res[MAX];
    res[0] = 1;
    int res_size = 1;
    for (int x = 2; x <= n; x++){
        res_size = multiply(x, res, res_size);
    }
    cout << "Factorial of given number is \n";
    for (int i = res_size - 1; i >= 0; i--)
        cout << res[i];
    cout << "\n";
}

int multiply(int x, int res[], int res_size){
    int carry = 0;
    for (int i = 0; i < res_size; i++){
        int prod = res[i]*x + carry;
        res[i] = prod % 10;
        carry = prod/10;
    }

    while (carry){
        res[res_size] = carry%10;
        carry = carry/10;
        res_size++;
    }

    return res_size;
}

int main(int argc, char** argv){
    clock_t tStart = clock();
    factorial(atoi(argv[1]));
    cout << "Time Taken: " << (double)(clock() - tStart)/(CLOCKS_PER_SEC*1000) << endl;
    return 0;
}
