// test currency class with friend

#include <iostream>
#include "currencyFriend.h"

using namespace std;

int main()
{
   currency g, h(plus, 3, 50), i, j;

   // try out both forms of setValue
   g.setValue(minus, 2, 25);
   i.setValue(-6.45);

   // do an add and output
   j = h + g;
   cout << h << " + " << g << " = " << j << endl;

   // do an increment and output
   cout << i << " incremented by " << h
        << " is " << (i += h) << endl;

   // do two adds in a sequence
   j                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                 