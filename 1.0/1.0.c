#include <stdio.h>
//#include <stdlib.h>
#define NELEMS(x)  (sizeof(x) / sizeof((x)[0]))
//数组长度 N
#define N 5
void print(const int a[],const int m){
    for (int i = 0; i < m ; ++i) {
        printf("%d ",a[i]);
    }
    printf("\n");
}
void make_apart(const int a[],int output1[],int output2[]){
    for (int i = 0; i < N/2; ++i) {
        output1[i]=a[i];
    }
    for (int j = N/2; j < N; ++j) {
        output2[j-N/2]=a[j];
    }
}
void change(int *a,int *b){
    int c= *a;
    *a = *b;
    *b = c;
}
void fix_arrange(int a[],const int m){
    for (int i = 0; i < m-1; ++i) {
        for (int j = i+1; j < m; ++j) {
            if(a[j]<a[i]) {change( &(a[i]) , &(a[j]) );}
        }
    }
}
void two_in_one(const int a[],const int b[],int c[]){
    int len_a=N/2;
    int len_b=N-N/2;
    int a_index=0;
    int c_index=0;
    for (int i = 0; i < len_b; ++i) {
        while ( (a_index!=len_a) && (a[a_index]<b[i]) ){
            c[c_index++]=a[a_index++];
        }
        c[c_index++]=b[i];
    }
    for (int j = a_index; j < len_a; ++j) {
        c[c_index++]=a[a_index++];
    }
}
int main()
{
    int a[N] = {11,8,2,6,3};
    int output1[N/2];
    int output2[N-N/2];
    int output[N];
    make_apart(a,output1,output2);
    fix_arrange(output1,N/2);
    fix_arrange(output2,N-N/2);
    two_in_one(output1,output2,output);
    print(output,N);
    //system("pause");
    return 0;
}