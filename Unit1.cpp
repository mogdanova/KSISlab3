#include <vcl.h>
#pragma hdrstop
#pragma argsused
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
class Package{
    public:
        int Procent;
        int maxLen;
        int curLen;
        int *Name;
};

class Queue{
    public:
        int Name;
};

int main(int argc, char* argv[])
{
    unsigned int start = clock();

    Package *p = new Package[5];

    p->Procent=1;
    p->maxLen=2;
    p->curLen=0;
    p->Name = new int[2];

    (p+1)->Procent=1;
    (p+1)->maxLen=4;
    (p+1)->curLen=0;
    (p+1)->Name = new int[4];

    (p+2)->Procent=2;
    (p+2)->maxLen=3;
    (p+2)->curLen=0;
    (p+2)->Name = new int[3];

    (p+3)->Procent=3;
    (p+3)->maxLen=2;
    (p+3)->curLen=0;
    (p+3)->Name = new int[2];

    (p+4)->Procent=3;
    (p+4)->maxLen=1;
    (p+4)->curLen=0;
    (p+4)->Name = new int[1];

    Queue *q = new Queue[20];

    for (int i = 0; i < 20; i++){
        (q+i)->Name=i;
        printf("Paket %d\n", (q+i)->Name);
    }

    int s=1, i, j=0;
    
    for(i=0; i<p->maxLen && j<20; i++, j++){
        p->Name[i]=(q+j)->Name;
        p->curLen++;
    }
    for(i=0; i<(p+1)->maxLen && j<20; i++, j++){
        (p+1)->Name[i]=(q+j)->Name;
        (p+1)->curLen++;
    }
    for(i=0; i<(p+2)->maxLen && j<20; i++, j++){
        (p+2)->Name[i]=(q+j)->Name;
        (p+2)->curLen++;
    }
    for(i=0; i<(p+3)->maxLen && j<20; i++, j++){
        (p+3)->Name[i]=(q+j)->Name;
        (p+3)->curLen++;
    }
    for(i=0; i<(p+4)->maxLen && j<20; i++, j++){
        (p+4)->Name[i]=(q+j)->Name;
        (p+4)->curLen++;
    }
    
    while(s){
        printf("\nbufer 1:");
        for(int w=0; w<p->curLen; w++){
            printf(" Paket %d", (q+p->Name[w])->Name);
        }
        printf("\nbufer 2:");
        for(int w=0; w<(p+1)->curLen; w++){
            printf(" Paket %d", (q+(p+1)->Name[w])->Name);
        }
        printf("\nbufer 3:");
        for(int w=0; w<(p+2)->curLen; w++){
            printf(" Paket %d", (q+(p+2)->Name[w])->Name);
        }
        printf("\nbufer 4:");
        for(int w=0; w<(p+3)->curLen; w++){
            printf(" Paket %d", (q+(p+3)->Name[w])->Name);
        }
        printf("\nbufer 5:");
        for(int w=0; w<(p+4)->curLen; w++){
            printf(" Paket %d", (q+(p+4)->Name[w])->Name);
        }

        for(int w=0; w<p->Procent && p->curLen>0; w++){
            printf("\nPaket %d svoboden", (q+p->Name[0])->Name);
            for(int x=0; x<p->curLen-1; x++){
                p->Name[x]=p->Name[x+1];
            }
            p->curLen--;
            if(j<20){
                p->Name[p->curLen]=(q+j)->Name;
                p->curLen++;
                j++;
            }
        }
                
        for(int w=0; w<(p+1)->Procent && (p+1)->curLen>0; w++){
            printf("\nPaket %d svoboden", (q+(p+1)->Name[0])->Name);
            for(int x=0; x<(p+1)->curLen-1; x++){
                (p+1)->Name[x]=(p+1)->Name[x+1];
            }
            (p+1)->curLen--;
            if(j<20){
                (p+1)->Name[(p+1)->curLen]=(q+j)->Name;
                (p+1)->curLen++;
                j++;
            }
        }
                
        for(int w=0; w<(p+2)->Procent && (p+2)->curLen>0; w++){
            printf("\nPaket %d svoboden", (q+(p+2)->Name[0])->Name);
            for(int x=0; x<(p+2)->curLen-1; x++){
                (p+2)->Name[x]=(p+2)->Name[x+1];
            }
                (p+2)->curLen--;
                if(j<20){
                    (p+2)->Name[(p+2)->curLen]=(q+j)->Name;
                    (p+2)->curLen++;  
                    j++;
                }
        }
           
        for(int w=0; w<(p+3)->Procent && (p+3)->curLen>0; w++){
            printf("\nPaket %d svoboden", (q+(p+3)->Name[0])->Name);
            for(int x=0; x<(p+3)->curLen-1; x++){
                (p+3)->Name[x]=(p+3)->Name[x+1];
            }
            (p+3)->curLen--;
            if(j<20){
                (p+3)->Name[(p+3)->curLen]=(q+j)->Name;
                (p+3)->curLen++;
                j++;
            }
        }
                
        for(int w=0; w<(p+4)->Procent && (p+4)->curLen>0; w++){
            printf("\nPaket %d svoboden", (q+(p+4)->Name[0])->Name);
            for(int x=0; x<(p+4)->curLen-1; x++){
                (p+4)->Name[x]=(p+4)->Name[x+1];
            }
            (p+4)->curLen--;
            if(j<20){
                (p+4)->Name[(p+4)->curLen]=(q+j)->Name;
                (p+4)->curLen++;
                j++;
            }
        }
        printf("\n");
        for(i=0; i<10; i++){
            printf("-");
        }      

        if(j==20 && p->curLen==0 && (p+1)->curLen==0 && (p+2)->curLen==0 && (p+3)->curLen==0 && (p+4)->curLen==0){
            s=0;
        }
    }
    printf("\nVremya vupolneniya %d sec", clock());
    getch();
    return 0;
}

