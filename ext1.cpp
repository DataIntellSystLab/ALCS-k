#include <iostream>
#include<fstream>
#include<string>
#include <sstream>
#include<iomanip>
#include<stdlib.h>
#include<stdio.h>
#include<cmath>
#include <stdexcept>
#include <stdc++.h>
using namespace std;

int main(int argc, char *argv[])
{
    ofstream staf("finalresult.txt");
    string codelab;
    long long int m,posint;
    string tabtipo[9];
    tabtipo[0]="T10T20";
    tabtipo[1]="T11T20";
    tabtipo[2]="T10T21";
    tabtipo[3]="T11T20";
    tabtipo[4]="T11T21";
    tabtipo[5]="T10";
    tabtipo[6]="T11";
    tabtipo[7]="T20";
    tabtipo[8]="T21";

   //PARAMETER CONTROL
    if (argv[1]==0 || argv[2]==0 || argv[3]==0 || argv[4]==0 )
      {
         staf<<"****************** pgm ext1 **"<<endl;
         staf<<"**** PARAMETER NOT CORRECT    ****"<<endl;
         staf<<"**********************************"<<endl;
         staf.close();
         return 99;
      }
      string nomefileT1=argv[2];
      string nomefileT2=argv[3];
      codelab=argv[4];
      int swtipo=0;
      for(int i=0;i<9;i++)
         {
            if (codelab==tabtipo[i])
            {
                i=9;
                swtipo=1;
            }
         }
      if (swtipo==0)
       {
         staf<<"***************** pgm ext1 **"<<endl;
         staf<<"**** PARM ELAB NOT CORRECT "<<endl;
         staf<<"*****************************"<<endl;
         staf.close();
         return 99;
       }


    try
    {
        m=stoi(argv[1]);
    }
     catch (invalid_argument&)
    {
         staf<<"***************** pgm ext1 **"<<endl;
         staf<<"**  STRING LENGTH NOT NUMERIC"<<endl;
         staf<<"*****************************"<<endl;
         staf.close();
        return 99;
    }
    if (m<=11)
      {
         staf<<"***************** pgm ext1 **"<<endl;
         staf<<"****** STRING LENGTH > 11 "<<endl;
         staf<<"*****************************"<<endl;
         staf.close();
         return 99;
      }
     string tipof1,tipof2,saltaprimorecf1,saltaprimorecf2;
     tipof1=" ";
     tipof2=" ";
     saltaprimorecf1=" ";
     saltaprimorecf2=" ";
     if (codelab.length()==3)
        {
         tipof1=codelab.substr(0,2);
         saltaprimorecf1=codelab.substr(2,1);
         if (tipof1=="T2")
            {tipof2=tipof1;saltaprimorecf2=saltaprimorecf1;tipof1="";saltaprimorecf1="";}
        }
     if (codelab.length()==6)
        {
         tipof1=codelab.substr(0,2);
         saltaprimorecf1=codelab.substr(2,1);
         tipof2=codelab.substr(3,2);
         saltaprimorecf2=codelab.substr(5,1);
        }



  // PARAMETER CONTROL END
    string sortstrT1="sortstrT1.txt";
    string sortstrT2="sortstrT2.txt";
    string strcomT1="strcomT1.txt";
    string strcomT2="strcomT2.txt";
    string sortstrcomT1="sortstrcomT1.txt";
    string sortstrcomT2="sortstrcomT2.txt";
    string strextT1="strextT1.txt";
    string strextT2="strextT2.txt";
    string sortstrextT1="sortstrextT1.txt";
    string sortstrextT2="sortstrextT2.txt";
    string strextT1T2="strextT1T2.txt";
    string sortstrextT1T2="sortstrextT1T2.txt";
    int maxlun=0;
    long long int letti;
    long long int scritti,wriT1=0,wriT2=0;
    long long int ctrscarti;
    int lungrec;
    int yy;
    string xrec;
    string x1,stringa;
    cout<<"**** PGM EXT1 ****"<<endl;


 if (tipof1=="T1")
 {
    ifstream finT1(nomefileT1);
    if (!finT1)
       {
        staf<<"**************** pgm ext1 **"<<endl;
        staf<<"**** INPUT "<<nomefileT1<<" NOT FOUND"<<endl;
        staf<<"*****************************"<<endl;
        staf.close();
        return 99;
       }
    ofstream fouT1("outT1.txt");
 //**************************************
 // Text T1 Processing
 //**************************************
    letti=0;
    scritti=0;
    ctrscarti=0;
    if (finT1)
    {
     string xrec="";
     stringa="";
     posint=1;
     yy=0;

     while(getline(finT1,xrec))
        {
          letti++;
          if ( (letti==1) && saltaprimorecf1=="1" )
             continue;
          lungrec=xrec.length();
          for(int kk=0;kk<lungrec;kk++)
          {
            x1=xrec.substr(kk,1);
            yy++;
            if ( (x1=="A") ||  (x1=="C") || (x1=="G") || (x1=="T") )
               {
               stringa=stringa+x1;
               if (stringa.length()==m)
                  {
                    fouT1<<stringa<<" "<<setfill('0')<<setw(15)<<posint<<" "<<setfill('0')<<endl;
                    stringa=stringa.substr(1,(m-1));
                    scritti++;
                    posint++;
                   }
                else
                  continue;
                 }
             else
                {
                  ctrscarti=ctrscarti + stringa.length() + 1;
                  stringa="";
                  posint=yy+1;
                }
              }
           }
        }

    if (ctrscarti==0)
        ctrscarti=m-1;
    cout<<"T1 text"<<endl;
    cout<<"records read      : "<<letti<<endl;
    cout<<"records written   : "<<scritti<<endl;
    cout<<"records discarded : "<<ctrscarti<<endl;
    cout<<"n                 : "<<yy<<endl;
    wriT1=scritti;
    fouT1.close();
    finT1.close();
 }
 //**************************************
 // END Text T1 Processing
 //**************************************


 if (tipof2=="T2")
 {

   ifstream finT2(nomefileT2);
   if (!finT2)
      {
       staf<<"**************** pgm ext1 **"<<endl;
       staf<<"**** INPUT "<<nomefileT2<<" NOT FOUND"<<endl;
       staf<<"****************************"<<endl;
       staf.close();
       return 99;
      }
    ofstream fouT2("outT2.txt");
  //**************************************
  // Text T2 Processing
  //**************************************
    letti=0;
    scritti=0;
    ctrscarti=0;
    if (finT2)
    {
     string xrec="";
     stringa="";
     posint=1;
     yy=0;

     while(getline(finT2,xrec))
        {
          letti++;
          if ( (letti==1) && saltaprimorecf2=="1" )
             continue;
          lungrec=xrec.length();
          for(int kk=0;kk<lungrec;kk++)
          {
            x1=xrec.substr(kk,1);
            yy++;
            if ( (x1=="A") ||  (x1=="C") || (x1=="G") || (x1=="T") )
               {
               stringa=stringa+x1;
               if (stringa.length()==m)
                  {
                    fouT2<<stringa<<" "<<setfill('0')<<setw(15)<<posint<<" "<<setfill('0')<<endl;
                    stringa=stringa.substr(1,(m-1));
                    scritti++;
                    posint++;
                   }
                else
                  continue;
                 }
             else
                {
                  ctrscarti=ctrscarti + stringa.length() + 1;
                  stringa="";
                  posint=yy+1;
                }
              }
           }
        }

    if (ctrscarti==0)
        ctrscarti=m-1;
    cout<<"T2 text"<<endl;
    cout<<"records read      : "<<letti<<endl;
    cout<<"records written   : "<<scritti<<endl;
    cout<<"records discarded : "<<ctrscarti<<endl;
    cout<<"n                 : "<<yy<<endl;
    wriT2=scritti;
    fouT2.close();
    finT2.close();
 }
 //**************************************
 // END Text T1 Processing
 //**************************************

    ofstream fparm("parameter.txt");
    fparm<<m<<endl;
    fparm<<sortstrT1<<endl;
    fparm<<sortstrT2<<endl;
    fparm<<strcomT1<<endl;
    fparm<<strcomT2<<endl;
    fparm<<sortstrcomT1<<endl;
    fparm<<sortstrcomT2<<endl;
    fparm<<strextT1<<endl;
    fparm<<strextT2<<endl;
    fparm<<sortstrextT1<<endl;
    fparm<<sortstrextT2<<endl;
    fparm<<strextT1T2<<endl;
    fparm<<sortstrextT1T2<<endl;
    fparm<<"T1MAX0"<<endl;
    fparm<<"T2MAX0"<<endl;
    fparm<<maxlun<<endl;
    fparm<<nomefileT1<<endl;
    fparm<<nomefileT2<<endl;
    fparm<<"T1ext0"<<endl;
    fparm<<"T2ext0"<<endl;
    fparm<<"free  "<<endl;
    fparm<<"T1T2ext0"<<endl;
    fparm<<"T1str"<<wriT1<<endl;
    fparm<<"T2str"<<wriT2<<endl;
    fparm<<"T1dup0"<<endl;
    fparm<<"T2dup0"<<endl;
    fparm<<"T1mat0"<<endl;
    fparm<<"T2mat0"<<endl;
    fparm<<"T1wri0"<<endl;
    fparm<<"T2wri0"<<endl;
    fparm<<"T1T2wri0"<<endl;
    fparm<<"free"<<endl;
    fparm<<"free"<<endl;
    fparm<<"free"<<endl;
    fparm<<"free"<<endl;
    fparm.close();

    return 0;
}
