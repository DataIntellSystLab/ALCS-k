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
    string mx, nomeinput1, nomeinput2, nomeout;
    ofstream staf("finalresult.txt");

    fstream fparm("parameter.txt");
    if (!fparm)
        {
         staf<<"***************** pgm ext4 **"<<endl;
         staf<<"**** INPUT PARAMETER NOT FOUND  **"<<endl;
         staf<<"**********************************"<<endl;
         staf.close();
         return 99;
        }

    int iparm=0;
    string tbparm[35];
    int tapparm;
    string xparm;
    if (fparm)
       {
        while(getline(fparm,xparm))
        {
           tbparm[iparm]=xparm;
           iparm++;
           if (iparm==1)
               mx=xparm;
           if (iparm==10)
               nomeinput1=xparm;
           if (iparm==11)
               nomeinput2=xparm;
           if (iparm==12)
               nomeout=xparm;
         }
       }
    tapparm=iparm;
    fparm.close();

    ofstream fout1(nomeout);
    ifstream t1(nomeinput1);
    if (!t1)
        {
         staf<<"***************** pgm ext4 **"<<endl;
         staf<<"**** T1 "<<nomeinput1<<" NOT FOUND"<<endl;
         staf<<"*****************************"<<endl;
         staf.close();
         return 99;
        }



    ifstream t2(nomeinput2);
    if (!t2)
        {
         staf<<"***************** pgm ext4 **"<<endl;
         staf<<"**** T2 "<<nomeinput2<<" NOT FOUND"<<endl;
         staf<<"*****************************"<<endl;
         t1.close();
         staf.close();
         return 99;
        }

    int m=stoi(mx);
    string x1, x2, key1, key2, keyc;
    string num1, num2;
    long long int letti1=0, letti2=0, scritti1=0;
    int swsalta2=0;
    int swfinet1=0;
    int swfinet2=0;
    int lungrec1, lungrec2,maxxlun;
    maxxlun=0;
    string zero5="00000";
    string zona5,zona5a,appoggio;
    int xlun,complxlun;



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
          lungrec1=x1.length();
          num1=x1.substr(0,15);
          key1=x1.substr(16,lungrec1-15);
          xlun=key1.length();
          if (key1==keyc)
             {
               zona5=zero5;
               complxlun=99999-xlun;
               zona5.replace(5 - to_string(complxlun).length(),to_string(complxlun).length(),to_string(complxlun));
               zona5a=zero5;
               zona5a.replace(5 - to_string(xlun).length(),to_string(xlun).length(),to_string(xlun));
               appoggio="T1;" + num1 + ";" + zona5 + ";" + zona5a + ";" + key1 + ";";
               fout1<<appoggio<<endl;
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

          lungrec2=x2.length();
          num2=x2.substr(0,15);
          key2=x2.substr(16,lungrec2-15);
          xlun=key2.length();
          if (key2==keyc)
             {
               zona5=zero5;
               complxlun=99999-xlun;
               zona5.replace(5 - to_string(complxlun).length(),to_string(complxlun).length(),to_string(complxlun));
               zona5a=zero5;
               zona5a.replace(5 - to_string(xlun).length(),to_string(xlun).length(),to_string(xlun));
               appoggio="T2;" + num2 + ";" + zona5 + ";" + zona5a + ";" + key2 + ";";
               fout1<<appoggio<<endl;
               scritti1++;
               goto LETTURA2;
             }
       }

    CONFRONTO:
        if (swfinet1==1 || swfinet2==1)
            goto FINE;
        if (key1==key2)
            {
             xlun=key1.length();
             if (xlun>maxxlun)
                   maxxlun=xlun;
             zona5=zero5;
             complxlun=99999-xlun;
             zona5.replace(5 - to_string(complxlun).length(),to_string(complxlun).length(),to_string(complxlun));
             zona5a=zero5;
             zona5a.replace(5 - to_string(xlun).length(),to_string(xlun).length(),to_string(xlun));
             appoggio="T1;" + num1 + ";" + zona5 + ";" + zona5a + ";" + key1 + ";";
             fout1<<appoggio<<endl;
             scritti1++;
             xlun=key2.length();
             zona5=zero5;
             complxlun=99999-xlun;
             zona5.replace(5 - to_string(complxlun).length(),to_string(complxlun).length(),to_string(complxlun));
             zona5a=zero5;
             zona5a.replace(5 - to_string(xlun).length(),to_string(xlun).length(),to_string(xlun));
             appoggio="T2;" + num2 + ";" + zona5 + ";" + zona5a + ";" + key2 + ";";
             fout1<<appoggio<<endl;
             scritti1++;
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
       ofstream outparm("parameter.txt");
       tbparm[15]=to_string(maxxlun);
       tbparm[21]="T1T2ext" + to_string(scritti1);
       for (int j=0;j<tapparm;j++)
          {
           outparm<<tbparm[j]<<endl;
          }
       outparm.close();
       cout<<"**** PGM EXT4 ****"<<endl;
       cout<<"End of processing"<<endl;
       cout<<"read  T1  : "<<letti1<<endl;
       cout<<"read  T2  : "<<letti2<<endl;
       cout<<"write T1T2: "<<scritti1<<endl;
       cout<<endl;
       fout1.close();
       t1.close();
       t2.close();
       staf.close();
  }

