

#define SIZE 100
#define MAX 450
#include<iostream>
#include<cstdio>
#include<cmath>
#include<string>
using namespace std;
char c[SIZE / 2 + 1][SIZE / 2 * MAX + 1];
int n, weight[SIZE + 1];

int main(void)
{
int i, j, k, min, sum, test_case;

scanf(" %d", &test_case);

while(test_case--)
{
scanf(" %d", &n);

for(i = 0, sum = 0; i < n; i++)
{
scanf(" %d", &weight[i]);
sum += weight[i];
}

memset(c, 0, sizeof(c));
c[0][0] = 1;

for(i = 0; i < n / 2; i++)
{
for(j = 0; j <= i                                                                                                                                                                                                                                                                                                                                                                    