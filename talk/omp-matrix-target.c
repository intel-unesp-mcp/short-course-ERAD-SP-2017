#include <stdio.h>
#include <malloc.h>

int main(){
    int r, c, i, j, *a , *b , *sum;
    char hn[600];

    #pragma omp parallel
    {
      gethostname(hn,600);
      printf("hostname %s\n",hn);
    }

    r=20000;
    c=20000;

    b = (int*)malloc(r*c*sizeof(double));
    a = (int*)malloc(r*c*sizeof(double));
    sum = (int*)malloc(r*c*sizeof(double));

    #pragma omp parallel for
    for(i=0; i<r; ++i)
        for(j=0; j<c; ++j) {
          a[i*r + j]=i+j;
          b[i*r + j]=i-j;
        }

    #pragma omp target map(to:a[0:r*c]) map(to:b[0:r*c]) map(from:sum[0:r*c])
    {
    #pragma omp parallel for
    for(i=0;i<r;++i)
        for(j=0;j<c;++j)
            sum[i*r+j] = a[i*r+j] + b[i*r+j];

    }
    free(sum);
    free(b);
    free(a);

    return 0;
}
