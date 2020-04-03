#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAXLINE 1000
#define INIT_TAB_SIZE 20

struct YearTemp{
    int year;
    float tempAvgSummer;
    float tempAvgWinter;
    float tempDifference;
};

int float_compare_summer(const void* q1, const void* q2){
    if(((struct YearTemp*)q1)->tempAvgSummer < ((struct YearTemp*)q2)->tempAvgSummer) return 1;
    if(((struct YearTemp*)q1)->tempAvgSummer >= ((struct YearTemp*)q2)->tempAvgSummer) return -1;
}

int float_compare_winter(const void* q1, const void* q2){
    if(((struct YearTemp*)q1)->tempAvgWinter < ((struct YearTemp*)q2)->tempAvgWinter) return -1;
    if(((struct YearTemp*)q1)->tempAvgWinter >= ((struct YearTemp*)q2)->tempAvgWinter) return 1;
}

int float_compare_diff(const void* q1, const void* q2){
    if(((struct YearTemp*)q1)->tempDifference < ((struct YearTemp*)q2)->tempDifference) return 1;
    if(((struct YearTemp*)q1)->tempDifference >= ((struct YearTemp*)q2)->tempDifference) return -1;
}

int main(){
    FILE * fp;
    //float *TAB[INIT_TAB_SIZE];
    float ** TAB = (float**) malloc(INIT_TAB_SIZE * sizeof(*TAB));
    float **pTAB;
    float TMP[14];
    double average=0;
    int counter = 1;
    int i=0, j=0, k=0;
    size_t buffer_size = 20;
    char *buffer = (char*) malloc(buffer_size * sizeof(char));
    int line_size = 0;
    fp = fopen("dane.txt", "r+");
    if(fp==0){
        printf("Error opening a file: dane.txt \n");
        return 1;
    }
    i=0;
    line_size = getline(&buffer, &buffer_size, fp);
    while (line_size >= 0){
        //printf("%d : %d\n", i, line_size);
        line_size = getline(&buffer, &buffer_size, fp);
        if(i == counter * INIT_TAB_SIZE){
            pTAB=TAB;
            pTAB = (float**) realloc(pTAB, (INIT_TAB_SIZE + counter * 20)*sizeof(*TAB));
            if(pTAB){
                TAB = pTAB;
                printf("Allocated sucessfully!\n");
            }
            else{
                printf("Error allocating memory!\n");
                return 1;
            }
            counter++;
        }
        //printf("%d : %s", i, buffer);
        j=0;
        int offset=0, readCharCount;
        while(sscanf(buffer+offset, "%f%n", &TMP[j], &readCharCount)==1){
            // printf("%d : Data from float: %f \n", j ,TMP[j]);  // <- debug
            offset+=readCharCount;
            j++;
        }
        TAB[i] = (float*) malloc(14 * sizeof(float));
        for(j=0; j<14; j++){
            TAB[i][j] = TMP[j];
            //printf("Data #%d: %f \n", j, TAB[i][j]);
        }
        //printf("%d pointer to year: %p \n", i, TAB[i]);
        i++;
    }
    fclose(fp);
    for(j=0; j<i; j++){
        //printf("%d pointer to year: %p \n", j, TAB[j]);
        printf("Year: %d, average temperature: %f\n", (int)TAB[j][0], TAB[j][13]);
    }
    float *averageSummer = (float*) malloc(i*sizeof(float));
    float *averageWinter = (float*) malloc(i*sizeof(float));
    for(j=0; j<i-1; j++){
        averageSummer[j] = (TAB[j][7] + TAB[j][8])/2;
        //printf("Year: %d, average summer temperature: %f\n", (int)TAB[j][0], averageSummer[j]);
    }
    for(j=0; j<i-1; j++){
        averageWinter[j] = (TAB[j][1] + TAB[j][2])/2;
        //printf("Year: %d, average winter temperature: %f\n", (int)TAB[j][0], averageWinter[j]);
    }
    struct YearTemp * helpfulStructure = (struct YearTemp*) malloc((i-1) * sizeof(struct YearTemp));
    for(j=0; j<i-1; j++){
        helpfulStructure[j].year = TAB[j][0];
        helpfulStructure[j].tempAvgSummer = averageSummer[j];
        helpfulStructure[j].tempAvgWinter = averageWinter[j];
        helpfulStructure[j].tempDifference = averageSummer[j]-averageWinter[j];
        printf("Year: %d, avg. summer temperature: %f, avg. winter temperature: %f\n", helpfulStructure[j].year, helpfulStructure[j].tempAvgSummer, helpfulStructure[j].tempAvgWinter);
    }
    qsort(helpfulStructure, i-1, sizeof(struct YearTemp), float_compare_summer);
    for(j=0; j<i-1; j++){
        printf("Hot summer no. #%d, year: %d, avg. temperature: %f\n", j+1, helpfulStructure[j].year, helpfulStructure[j].tempAvgSummer);
    }
    qsort(helpfulStructure, i-1, sizeof(struct YearTemp), float_compare_winter);
    for(j=0; j<i-1; j++){
        printf("Cold winter no. #%d, year: %d, avg. temperature: %f\n", j+1, helpfulStructure[j].year, helpfulStructure[j].tempAvgWinter);
    }
    qsort(helpfulStructure, i-1, sizeof(struct YearTemp), float_compare_diff);
    for(j=0; j<i-1; j++){
        printf("Biggest difference no. #%d, year: %d, avg. temperature difference: %f\n", j+1, helpfulStructure[j].year, helpfulStructure[j].tempDifference);
    }
    printf("Freeing memory...\n");
    for(j=0; j<i; j++){
        float * temp = TAB[j];
        free(temp);
    }
    free(TAB);
    free(buffer);
    free(helpfulStructure);
    return 0;
}
