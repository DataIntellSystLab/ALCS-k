#include <iostream>
#include<fstream>
#include<string>
#include <sstream>
#include<iomanip>
#include<stdlib.h>
#include<stdio.h>
#include<cmath>
#include <stdc++.h>
using namespace std;

int main()
{
    string mx, nomefile1, nomefile2, nomefileout1, nomefileout2;
    ofstream staf("finalresult.txt");
    ifstream fparm("parameter.txt");
    if (!fparm)
        {
         staf<<"***************** pgm ext2 **"<<endl;
         staf<<"**** INPUT PARAMETER NOT FOUND"<<endl;
         staf<<"*****************************"<<endl;
         staf.close();
         return 99;
        }

    int iparm=0;
    string xparm;
    string tbparm[35];
    int tapparm;
    if (fparm)
       {
        while(getline(fparm,xparm))
        {
           tbparm[iparm]=xparm;
           iparm++;
           if (iparm==1)
               mx=xparm;
           if (iparm==2)
               nomefile1=xparm;
           if (iparm==3)
               nomefile2=xparm;
           if (iparm==4)
               nomefileout1=xparm;
           if (iparm==5)
               nomefileout2=xparm;
        }
       }
    tapparm=iparm;
    fparm.close();

    ofstream fout1(nomefileout1);
    ofstream fout2(nomefileout2);
    ifstream t1(nomefile1);
    if (!t1)
        {
         staf<<"***************** pgm ext2 **"<<endl;
         staf<<"**** T1 STRING SORTED NOT FOUND "<<endl;
         staf<<"*****************************"<<endl;
         staf.close();
         return 99;
        }



    ifstream t2(nomefile2);
    if (!t2)
        {
         staf<<"***************** pgm ext2 **"<<endl;
         staf<<"**** T2 STRING SORTED NOT FOUND **"<<endl;
         staf<<"**********************************"<<endl;
         t1.close();
         staf.close();
         return 99;
        }

    int m=stoi(mx);
    string x1, x2, key1, key2, keyc,key1prec, key2prec;
    key1prec=" ";
    key2prec=" ";
    string num1, num2;
    long long int letti1=0, letti2=0, scritti1=0, scritti2=0, dupT1=0, dupT2=0;
    int swsalta2=0;
    int swfinet1=0;
    int swfinet2=0;

    LETTURA1:
        if (t1)
        {
          getline(t1,x1);
          if (t1.eof())
            { swfinet1=1;
              if (swsalta2==1)
                 goto CONFRONTO;
              goto LETTURA2;
            }
          letti1++;


          key1=x1.substr(0,m);
          if (key1==key1prec)
              dupT1++;
          key1prec=key1;
          num1=x1.substr(m+1,15);
          if (key1==keyc)
             {
               fout1<<num1<<" "<<key1<<endl;
               scritti1++;
               goto LETTURA1;
             }
          if (swsalta2==1)
             goto CONFRONTO;
        }

     LETTURA2:
        if (t2)
        {
         getline(t2,x2);
         if (t2.eof())
              { swfinet2=1;
                goto CONFRONTO;
              }
          letti2++;

          key2=x2.substr(0,m);
          if (key2==key2prec)
              dupT2++;
          key2prec=key2;
          num2=x2.substr(m+1,15);
          if (key2==keyc)
             {
               fout2<<num2<<" "<<key2<<endl;
               scritti2++;
               goto LETTURA2;
             }
       }

    CONFRONTO:
        if (swfinet1==1 || swfinet2==1)
            goto FINE;
        if (key1==key2)
            {
             fout1<<num1<<" "<<key1<<endl;
             scritti1++;
             fout2<<num2<<" "<<key2<<endl;
             scritti2++;
             swsalta2=0;
             keyc=key1;
             goto LETTURA1;
            }
         if (key1<key2)
           {
             swsalta2=1;
             goto LETTURA1;
           }

        if (key1>key2)
           {
             swsalta2=0;
             goto LETTURA2;
           }


   FINE:
       cout<<"**** PGM EXT2 ****"<<endl;
       cout<<"End of processing"<<endl;
       cout<<"read  T1: "<<letti1<<endl;
       cout<<"read  T2: "<<letti2<<endl;
       cout<<"write T1: "<<scritti1<<endl;
       cout<<"write T2: "<<scritti2<<endl;
       cout<<"write   : "<<scritti1+scritti2<<endl;
       cout<<endl;

       ofstream outparm("parameter.txt");
       tbparm[24]="T1dup" + to_string(dupT1);
       tbparm[25]="T2dup" + to_string(dupT2);
       tbparm[26]="T1mat" + to_string(scritti1);
       tbparm[27]="T2mat" + to_string(scritti2);
       for (int j=0;j<tapparm;j++)
           {
            outparm<<tbparm[j]<<endl;
           }
       outparm.close();

       fout1.close();
       fout2.close();
       t1.close();
       t2.close();
       staf.close();
  }
