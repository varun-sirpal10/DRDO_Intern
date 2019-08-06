#include<iostream>
#include<fstream>
#include<cmath>

using namespace std;

void hexadecimal(unsigned long *v0){
    long int i = 0;
    while(v0[i]){
         switch (v0[i]) {
        case '0':
            v0[i] = 0000;
            break;
        case '1':
            v0[i] = 0001;
            break;
        case '2':
            v0[i] = 0010;
            break;
        case '3':
            v0[i] = 0011;
            break;
        case '4':
            v0[i] = 0100;
            break;
        case '5':
            v0[i] = 0101;
            break;
        case '6':
            v0[i] = 0110;
            break;
        case '7':
            v0[i] = 0111;
            break;
        case '8':
            v0[i] = 1000;
            break;
        case '9':
            v0[i] = 1001;
            break;
        case 'A':
        case 'a':
            v0[i] = 1010;
            break;
        case 'B':
        case 'b':
            v0[i] = 1011;
            break;
        case 'C':
        case 'c':
            v0[i] = 1100;
            break;
        case 'D':
        case 'd':
            v0[i] = 1101;
            break;
        case 'E':
        case 'e':
            v0[i] = 1110;
            break;
        case 'F':
        case 'f':
            v0[i] = 1111;
            break;
        }
        i++;
      }
}

int countSetBits(unsigned long n)
{
    int count = 0;
    while (n)
    {
        count += n & 1;
        n = n >> 1;
    }
    return count;
}

void main(){

    clrscr();

    fstream traces,pt;
    traces.open("traces.txt",ios::in);
    pt.open("pt.txt",ios::in);

    for(int kguess=0;kguess<256;kguess++){
        int i=0,j=0;
        char pt[1000];
        while(!pt.eof()){
            for(i=0;i<1000;i++){
                pt[i] = pt.read();
            }
        }
        while(j<1000){
            unsigned long v0=pt[j],v1=pt[j+1];
            int k[8] = [kguess,0,0,0,0,0,0,0];
            int k0[4] = [k[0],k[1],k[2],k[3]];
            int k1[4] = [k[4],k[5],k[6],k[7]];
            sum += delta;
            v0 += ((v1<<4)+k0) ^ (v1+sum) ^ ((v1>>5)+k1);
            v0 = hexadecimal(v0);
            num[kguess] = countSetBits(v0); //Hamming Weight values array

            j++;
        }
    }
    while(!traces.eof()){
        int M,N;
        M = 5;
        N = 1000
        for(int x=0;x<M;x++){
            for(int y=0;y<N;y++){
                    char trace[N][M];
                    trace[x] = traces.read();
                    float product[1000],avg1,avg2,avg3;
                    long int sum1,sum2,sum3;
                    sum1=sum2=sum3=0;
                    product[j] = trace[j]*num[j];
                    sum1 += product[j];
                    sum2 += trace[j];
                    sum3 += num[j];
            }

        }
            avg1 = sum1/M;
            avg2 = sum2/M;
            avg3 = sum3/M;

            double max=0;
            for( n = 0; n < M; n++ ){
                float var1,var2;
                var1=var2=0;
                 var1 += pow((trace[n] - avg2),2);
              var2 += pow((num[n] - avg3),2);

            var1 /= M;
            var2 /= M;
            float sd1,sd2;
            sd1 = sqrt(var1);
            sd2 = sqrt(var2);

            float numerator = avg1 - avg2*avg3;
            float denominator = sd1*sd2;
            float pearson[1000];
            pearson[n] = numerator/denominator;
            if(pearson[n] > max){
                max = pearson[n]
            }
        }

        cout<<"Best Key Guess: "<<max;
     }
  }
