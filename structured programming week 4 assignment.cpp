#include<stdio.h>
int main(){
    FILE *ifp,*ofp;
    int howmany,i,j,sum=0;
    double avg=0;
    ifp=fopen("input.txt","r");
    ofp=fopen("output.txt","w+");
    rewind(ifp);
    fscanf(ifp,"%d",&howmany);
    int arr[howmany];
    for(i=0;i<howmany;i++){
        fscanf(ifp,"%d",&arr[i]);
}
printf("The values in array are :\n");
    for(i=0;i<howmany;i++){
        printf("%d\t",arr[i]);
        fprintf(ofp,"%d\t",arr[i]);
    }
    for(j=0;j<howmany;j++){
        sum+=arr[j];
    }
    avg=(double)sum/howmany;
    printf("\nThe average value is :%lf",avg);
    fprintf(ofp,"The average value is :%lf",avg);
    for(i=1;i<howmany;i++){
        if(arr[0]<arr[i]){
            arr[0]=arr[i];
        }
    }
        printf("\nMax value is :%d\n\n",arr[0]);
        fprintf(ofp,"\nMax value is :%d\n\n",arr[0]);
        fclose(ifp);
        fclose(ofp);
        return 0;
    }



