#include <stdio.h>
#include <stdlib.h>

//функция возводит перестановку a длиной n в степень pw, возвращает новую перестановку 
int* pen_pow(int* a, int n, int pw) {
    int* ans = malloc(sizeof(int)*n); 
    for (int i = 0; i < n; ++i) {
        //перебираем каждый i-ый элемент
        ans[i] = i+1; //изначально ans[i] будет хранить свой порядковый номер (i+1)
        for (int j = 0; j < pw; ++j) {
            //перемножаем перестановку саму на себя поэлементно pw раз
            ans[i] = a[ans[i]-1];
        }
    }
    return ans; //возвращаем результат
}

int main()
{
    //вводим данные
    int n;
    scanf("%d", &n);
    int* a = malloc(sizeof(int)*n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", a+i);
    }
    
    //возводим перестановку в третью степень
    int* p = pen_pow(a, n, 3);
    
    //выводим новую перестановку
    for (int i = 0; i < n; ++i) {
        printf("%d ", p[i]);
    }

    return 0;
}
