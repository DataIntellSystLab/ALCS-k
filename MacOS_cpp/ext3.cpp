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
string tabappstr[1000000];
string tabapppos[1000000];

int main()
{
    ofstream staf("finalresult.txt");
    string mx,nomeoutext1,nomeoutext2,nomeinput1,nomeinput2;
    fstream fparm("parameter.txt");
    if (!fparm)
        {
         staf<<"***************** pgm ext3 **"<<endl;
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
           if (iparm==6)
               nomeinput1=xparm;
           if (iparm==7)
               nomeinput2=xparm;
           if (iparm==8)
               nomeoutext1=xparm;
           if (iparm==9)
               nomeoutext2=xparm;

        }
       }
    tapparm=iparm;
    fparm.close();

    int m;
    string xfil, xrec1,xrec2,xrec1prec, xrec2prec;
    m=stoi(mx);
    string nx1,nx2,strallun,numstart,recall,ultcar;
    long long int n1, n2;
    int maxstrextendedT1=0;
    int maxstrextendedT2=0;
    int  limitestringamax=10000;
    strallun="";
    int scritti1=0;
    int iapp=0;
    int tap;

    ifstream finp1(nomeinput1);
    fstream fout1(nomeoutext1,fstream::out);
    if (!finp1)
        {
         staf<<"*********************** pgm ext3 **"<<endl;
         staf<<"** INPUT "<<nomeinput1<<" NOT FOUND "<<endl;
         staf<<"***********************************"<<endl;
         staf.close();
         return 99;
        }
    int i1=0;
    string zero5="00000";
    string zona5,zona5a;
    string zero15="000000000000000";
    string zona15;
    string appoggio;
    int swallungatat1=0;
    int numstrallT1=0;
    if (finp1)
    {
       while(getline(finp1,xrec1))
       {
           i1++;
           if (i1==1)
           {
               xrec1prec=xrec1;
               continue;
           }
           nx1=xrec1prec.substr(0,15);
           n1 =stoi(nx1);
           nx2=xrec1.substr(0,15);
           n2 =stoi(nx2);
           if ((n2-n1)==1)
              {
                swallungatat1=1;swallungatat1=1;
                numstart=nx1;
                strallun=xrec1prec.substr(16,m);
                ultcar=xrec1.substr(16+m-1,1);
                strallun= strallun + ultcar;
                recall=numstart + " " + strallun;
                fout1<<recall<<endl;
                scritti1++;
                if (strallun.length()>maxstrextendedT1)
                    maxstrextendedT1=strallun.length();
                if (maxstrextendedT1>limitestringamax)
                    {
                      staf<<"****************************** pgm ext3 **"<<endl;
                      staf<<"***********************************************"<<endl;
                      staf<<"***     LENGTH ELOGATED STRING > LIMIT      ***"<<endl;
                      staf<<"***********************************************"<<endl;
                      staf<<"***    file T1 length string  "<<maxstrextendedT1<<endl;
                      staf<<"***    limit supported        "<<limitestringamax<<endl;
                      staf<<"***********************************************"<<endl;
                      staf<<"***********************************************"<<endl;
                      staf.close();
                      return 99;
                    }

                tabappstr[iapp]=strallun;
                tabapppos[iapp]=numstart;
                tap=iapp;
                iapp++;

                for(int y=0;y<tap;y++)
                   {
                     strallun=tabappstr[y] + ultcar;
                     numstart=tabapppos[y];
                     recall=numstart + " " + strallun;
                     fout1<<recall<<endl;
                     scritti1++;
                     if (strallun.length()>maxstrextendedT1)
                         maxstrextendedT1=strallun.length();
                     if (maxstrextendedT1>limitestringamax)
                        {
                          staf<<"****************************** pgm ext3 **"<<endl;
                          staf<<"***********************************************"<<endl;
                          staf<<"***     LENGTH ELOGATED STRING > LIMIT      ***"<<endl;
                          staf<<"***********************************************"<<endl;
                          staf<<"***    file T1 length string  "<<maxstrextendedT1<<endl;
                          staf<<"***    limit supported        "<<limitestringamax<<endl;
                          staf<<"***********************************************"<<endl;
                          staf<<"***********************************************"<<endl;
                          staf.close();
                          return 99;
                        }
                     tabappstr[y]=strallun;
                     tabapppos[y]=numstart;
                   }
               }
              else
               {
                 if (swallungatat1==1)
                    {
                      numstrallT1++;
                      swallungatat1=0;
                    }
                 iapp=0;
               }
               xrec1prec=xrec1;
        }
    }

    if (swallungatat1==1)
       numstrallT1++;
    finp1.close();
    fout1.close();

    ifstream finp2(nomeinput2);
    fstream fout2(nomeoutext2,fstream::out);
    strallun="";
    int scritti2=0;
    iapp=0;
    int swallungatat2=0;
    int numstrallT2=0;
    if (!finp2)
        {
         staf<<"*********************** pgm ext3 **"<<endl;
         staf<<"** INPUT "<<nomeinput2<<" NOT FOUND"<<endl;
         staf<<"***********************************"<<endl;
         staf.close();
         return 99;
        }
    int i2=0;
    if (finp2)
    {
       while(getline(finp2,xrec2))
       {
           i2++;
           if (i2==1)
           {
               xrec2prec=xrec2;
               continue;
           }
           nx1=xrec2prec.substr(0,15);
           n1 =stoi(nx1);
           nx2=xrec2.substr(0,15);
           n2 =stoi(nx2);
           if ((n2-n1)==1)
              {
                swallungatat2=1;
                numstart=nx1;
                strallun=xrec2prec.substr(16,m);
                ultcar=xrec2.substr(16+m-1,1);
                strallun= strallun + ultcar;
                recall=numstart + " " + strallun;
                fout2<<recall<<endl;
                scritti2++;
                if (strallun.length()>maxstrextendedT2)
                    maxstrextendedT2=strallun.length();
                if (maxstrextendedT2>limitestringamax)
                   {
                    staf<<"****************************** pgm ext3 **"<<endl;
                    staf<<"***********************************************"<<endl;
                    staf<<"***     LENGTH ELOGATED STRING > LIMIT      ***"<<endl;
                    staf<<"***********************************************"<<endl;
                    staf<<"***    file T2 length string  "<<maxstrextendedT1<<endl;
                    staf<<"***    limit supported        "<<limitestringamax<<endl;
                    staf<<"***********************************************"<<endl;
                    staf<<"***********************************************"<<endl;
                    staf.close();
                    return 99;
                   }
                tabappstr[iapp]=strallun;
                tabapppos[iapp]=numstart;
                tap=iapp;
                iapp++;
                for(int y=0;y<tap;y++)
                   {
                     strallun=tabappstr[y] + ultcar;
                     numstart=tabapppos[y];
                     recall=numstart + " " + strallun;
                     fout2<<recall<<endl;
                     scritti2++;
                     if (strallun.length()>maxstrextendedT2)
                         maxstrextendedT2=strallun.length();
                     if (maxstrextendedT2>limitestringamax)
                        {
                         staf<<"****************************** pgm ext3 **"<<endl;
                         staf<<"***********************************************"<<endl;
                         staf<<"***     LENGTH ELOGATED STRING > LIMIT      ***"<<endl;
                         staf<<"***********************************************"<<endl;
                         staf<<"***    file T2 length string  "<<maxstrextendedT1<<endl;
                         staf<<"***    limit supported        "<<limitestringamax<<endl;
                         staf<<"***********************************************"<<endl;
                         staf<<"***********************************************"<<endl;
                         staf.close();
                         return 99;
                        }
                     tabappstr[y]=strallun;
                     tabapppos[y]=numstart;
                   }
               }
              else
               {
                 if (swallungatat2==1)
                    {
                      numstrallT2++;
                      swallungatat2=0;
                    }
                 iapp=0;
               }
               xrec2prec=xrec2;
        }
    }

    if (swallungatat2==1)
       numstrallT2++;
    finp2.close();
    fout2.close();



   if ((i1==0) || (i2==0))
  {
      staf<<"****************************** pgm ext3 **"<<endl;
      staf<<"***********************************************"<<endl;
      staf<<"***     EXTENDED STRINGS NOT FOUND          ***"<<endl;
      staf<<"***********************************************"<<endl;
      staf<<"***    MINIMUM LENGTH REQUIRED "<<setfill('0')<<setw(5)<<m<<"        ***"<<endl;
      staf<<"***********************************************"<<endl;
      staf<<"***********************************************"<<endl;
      staf.close();
      return 99;
  }


    cout<<"pgm EXT3"<<endl;
    cout<<"T1 read ...... "<<i1<<endl;
    cout<<"T2 read ...... "<<i2<<endl;
    cout<<"T1 write..... "<<scritti1<<endl;
    cout<<"T2 write..... "<<scritti2<<endl;
    cout<<"T1 elong..... "<<numstrallT1<<endl;
    cout<<"T2 elong..... "<<numstrallT2<<endl;
    ofstream outparm("parameter.txt");
    tbparm[13]="T1MAX" + to_string(maxstrextendedT1);
    tbparm[14]="T2MAX" + to_string(maxstrextendedT2);
    tbparm[18]="T1ext" + to_string(scritti1);
    tbparm[19]="T2ext" + to_string(scritti2);
    tbparm[31]="T1exn" + to_string(numstrallT1);
    tbparm[32]="T2exn" + to_string(numstrallT2);
    for (int j=0;j<tapparm;j++)
   {
      outparm<<tbparm[j]<<endl;
   }
    outparm.close();

staf.close();
cout<<"program end"<<endl;
return 0;
}
