#include "stdafx.h"
#include <stdlib.h>
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

#define y true
#define n false

void main()
{
    if(n)
    {
        int*a = new int[10];
        cout << "enter a number" << endl;
        cin >> a[0];

        _asm
        {
            mov ebx, a
            mov eax, [ebx]
            mov ecx, 10
            xor esi, esi
            mov edi, ebx
            cld
            rep stosd
        }
        for (int i = 0; i < 10; i++)
            cout << a[i] << " ";
        cout << endl;
        cout << endl;
        delete[] a;
    }
    if(n)
    {
        int a, b;
        cout << "enter number of elements" << endl;
        cin >> a;
        cout << "enter multiplier" << endl;
        cin >> b;
        int*arr1 = new int[a];
        int*arr2 = new int[a*b];

        for (int i = 0; i < a; i++)
        {
            arr1[i] = rand() % 200 - 100;
            cout << arr1[i] << " ";
        }
        cout << endl;

        _asm
        {
            xor edx, edx
            mov edi, [arr2]

            mov ecx, b
            l1:
            push ecx
            mov ecx, a
            mov esi, [arr1]
            cld
            rep movsd
            pop ecx
            loop l1
        }

        for (int i = 0; i < a*b; i++)
            cout << arr2[i] << " ";
        cout << endl;
        delete[] arr1;
        delete[] arr2;
    }
    if(n)
    {
        int a, b;
        cout << "enter number of elements" << endl;
        cin >> a;
        int*arr1 = new int[a];
        int*arr2 = new int[a];
        for (int i = 0; i < a; i++)
        {
            arr1[i] = rand() % 100;
            cout << arr1[i] << " ";
        }
        cout << endl;
        cout << "enter a number to find" << endl;
        cin >> b;
        _asm
        {
            mov eax, b
            mov ecx, a
            xor esi, esi
            mov edi, [arr2]
            cld
            rep stosd

            mov edi, [arr2]
            mov esi, [arr1]
            mov ecx, a
            inc ecx
            cld 
            repne cmpsd

            mov eax, a
            sub eax, ecx
            mov b, eax
        }
        cout << b << endl;
        cout << endl;
        delete[] arr1;
        delete[] arr2;
    }
    if(n)
    {
        int a, b;
        cout << "enter number of elements" << endl;
        cin >> a;
        int*arr1 = new int[a];
        int*arr2 = new int[a];
        cout << "enter sequence 1" << endl;
        for (int i = 0; i < a; i++)
            cin >> arr1[i];
        cout << endl;

        cout << "enter sequence 2" << endl;
        for (int i = 0; i < a; i++)
            cin >> arr2[i];
        cout << endl;

        _asm
        {
            mov edi, [arr2]
            mov esi, [arr1]
            mov ecx, a
            inc ecx
            cld
            repe cmpsd

            mov eax, a
            sub eax, ecx
            mov b, eax
        }

        cout << b << endl;
        cout << endl;
        delete[] arr1;
        delete[] arr2;
    }
    if(y)
    {

    }

    system("pause");
}