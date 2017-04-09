#include <stdio.h>
int main(){
    int r, c, i, j, *a , *b , *sum;
    char hn[600];

    #pragma omp parallel
    {
      gethostname(hn,600);
      printf("hostname %s\n",hn);
    }

    r=40000;
    c=40000;

    a = (int*)malloc(r*c*sizeof(int));
    b = (int*)malloc(r*c*sizeof(int));
    sum = (int*)malloc(r*c*sizeof(int));

    #pragma omp parallel for
    for(i=0; i<r; ++i)
        for(j=0; j<c; ++j) {
	  a[i*r + j]=i+j;
          b[i*r + j]=i-j;
        } 

    #pragma omp parallel for
    for(i=0;i<r;++i)
        for(j=0;j<c;++j)
            sum[i*r+j] = a[i*r+j] + b[i*r+j];

    free(a);
    free(b);
    free(sum);	

    return 0;
}
