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

string tbstrmax[5000];
string tbpost1max[5000] [500];
string tbpost2max[5000] [500];
int tbstrmaxlimit=5000;
int tbposmaxlimit=500;


int main()
{
    ofstream staf("finalresult.txt");
    long long int liminf, limsup;
    liminf=0;
    limsup=0;

    string mx,inpext1t2,xmaxlength;
    ifstream fparm("parameter.txt");
    if (!fparm)
        {
         staf<<"******************* pgm ext5 **"<<endl;
         staf<<"**** INPUT PARAMETER NOT FOUND "<<endl;
         staf<<"*******************************"<<endl;
         staf.close();
         return 99;
        }

    int iparm=0;
    string tbparm[35];
    int tapparm;
    string xparm,testoT1,testoT2;
    if (fparm)
       {
        while(getline(fparm,xparm))
        {
           tbparm[iparm]=xparm;
           iparm++;
           if (iparm==1)
               mx=xparm;
           if (iparm==13)
               inpext1t2=xparm;
           if (iparm==16)
               xmaxlength=xparm;
           if (iparm==17)
               testoT1=xparm;
           if (iparm==18)
               testoT2=xparm;
        }
       }
    tapparm=iparm;
    fparm.close();

    int m;
    int maxlun;
    m=stoi(mx);
    maxlun=stoi(xmaxlength);
    for (int y1=0;y1<tbstrmaxlimit;y1++)
    {
      tbstrmax[y1]="";

      for (int y2=0;y2<tbposmaxlimit;y2++)
          {
              tbpost1max[y1] [y2] ="";
              tbpost2max[y1] [y2] ="";
          }
    }

    ifstream fext1t2(inpext1t2);
    string xrecfext1t2,lunghezza;
    int indmax,indt1max,indt2max;
    int swmaxtrovato=0;


    if (!fext1t2)
        {
         staf<<"****************** pgm ext5 **"<<endl;
         staf<<"** INPUT "<<inpext1t2<<" NOT FOUND"<<endl;
         staf<<"*******************************"<<endl;
         staf.close();
         return 99;
        }

 staf<<"      FINAL RESULT"<<endl;
 staf<<"T1 file: "<<testoT1<<endl;
 staf<<"T2 file: "<<testoT2<<endl;
 staf<<endl;

string nprec="";
string xfile, xlung, xposiz, xstrin, xn, nx,xnprec,xcompllung;
string xposizprec,xcompllungprec,xposizscr,xcompllungscr,xposizscartato;
xposizprec="0";
xcompllungprec="0";
xposizscr="0";
xcompllungscr="0";
xposizscartato="0";
int ilung;
indmax=0;
indt1max=0;
indt2max=0;
int letti=0;
int contt1[2000];
int contt2[2000];
    for (int i=0;i<2000;i++)
        {
            contt1[i]=0;
            contt2[i]=0;
        }
 if (fext1t2)
    {
       while(getline(fext1t2,xrecfext1t2))
       {
        letti++;

        xn=xrecfext1t2;

        xfile=xn.substr(0, xn.find(";", 0));
        xn.erase(0, xn.find(";",0)+1);
        xposiz=xn.substr(0, xn.find(";", 0));
        xn.erase(0, xn.find(";",0)+1);
        xcompllung=xn.substr(0, xn.find(";", 0));
        xn.erase(0, xn.find(";",0)+1);
        xlung=xn.substr(0, xn.find(";", 0));
        xn.erase(0, xn.find(";",0)+1);
        xstrin=xn.substr(0, xn.find(";", 0));
        xn.erase(0, xn.find(";",0)+1);
        if ( (stoi(xposiz) >= liminf) && ( (stoi(xposiz) + stoi(xlung)) <=limsup) )
           {
             continue;
           }
         liminf=stoi(xposiz);
         limsup=stoi(xposiz) + stoi(xlung);
         ilung=stoi(xlung);
         staf<<xfile<<" "<<setfill('0')<<setw(5)<<xlung<<"  pos: "<<setfill('0')<<setw(15)<<xposiz<<"  "<<xstrin<<endl;
         if (xfile=="T1")
            contt1[ilung-m-1]++;
         if (xfile=="T2")
            contt2[ilung-m-1]++;
         if (ilung==maxlun)
            {
              swmaxtrovato=0;
              for(int y=0;y<indmax;y++)
                 {
                   if (indmax>tbstrmaxlimit)
                      {
                       staf<<"*********************** pgm ext5 **"<<endl;
                       staf<<"** max extend string > "<<tbstrmaxlimit<<endl;
                       staf<<"************************************"<<endl;
                       staf.close();
                       return 99;
                      }
                    if (tbstrmax[y]==xstrin)
                       {
                        if (xfile=="T1")
                           {
                               if (indt1max>tbposmaxlimit)
                                  {
                                    staf<<"*********************** pgm ext5 **"<<endl;
                                    staf<<"** positioning for max extend string > "<<tbposmaxlimit<<endl;
                                    staf<<"************************************"<<endl;
                                    staf.close();
                                    return 99;
                                  }
                               tbpost1max [y] [indt1max] = xposiz;
                               indt1max++;
                           }
                        else
                           {
                             if (indt2max>tbposmaxlimit)
                                {
                                  staf<<"*********************** pgm ext5 **"<<endl;
                                  staf<<"** positioning for max extend string > "<<tbposmaxlimit<<endl;
                                  staf<<"***********************************"<<endl;
                                  staf.close();
                                  return 99;
                                 }
                             tbpost2max [y] [indt2max] = xposiz;
                             indt2max++;
                           }
                        swmaxtrovato=1;
                       }
                 }
              if (swmaxtrovato==0)
                 {
                    if (indmax>tbstrmaxlimit)
                      {
                       staf<<"*********************** pgm ext5 **"<<endl;
                       staf<<"** max extend string > <"<<tbstrmaxlimit<<endl;
                       staf<<"***********************************"<<endl;
                       staf.close();
                       return 99;
                      }
                    tbstrmax[indmax]=xstrin;
                    if (xfile=="T1")
                       {
                         if (indt1max>tbposmaxlimit)
                            {
                             staf<<"*********************** pgm ext5 **"<<endl;
                             staf<<"** positioning for max extend string > "<<tbposmaxlimit<<endl;
                             staf<<"***********************************"<<endl;
                             staf.close();
                             return 99;
                            }
                         tbpost1max [indmax] [indt1max] = xposiz;
                         indt1max++;
                       }
                     else
                       {
                         if (indt2max>tbposmaxlimit)
                            {
                             staf<<"*********************** pgm ext5 **"<<endl;
                             staf<<"** positioning for max extend string > "<<tbposmaxlimit<<endl;
                             staf<<"************************************"<<endl;
                             staf.close();
                             return 99;
                            }
                         tbpost2max [indmax] [indt2max] = xposiz;
                         indt2max++;
                       }
                    indmax++;
                  }
             }
        xnprec=xrecfext1t2;
    }
  }
staf<<endl;
staf<<"*** FINAL STATISTICS ***"<<endl;
staf<<endl;
staf<<"T1 strings"<<endl;
float sumT1,sumT2,numT1,numT2;
long long int wriT1, wriT2;
wriT1=0;
wriT2=0;
sumT1=0;
sumT2=0;
numT1=0;
numT2=0;
for (int i=0;i<2000;i++)
{
    if (contt1[i] >0)
    {
        staf<<"length strings "<<i+m+1<<"  : "<<contt1[i]<<endl;
        sumT1=sumT1+((i+m+1)*contt1[i]);
        numT1=numT1+contt1[i];
        wriT1=wriT1+contt1[i];
    }

}
staf<<endl;
staf<<"T2 strings"<<endl;

for (int i=0;i<2000;i++)
{
    if (contt2[i] >0)
    {
        staf<<"length strings "<<i+m+1<<"  : "<<contt2[i]<<endl;
        sumT2=sumT2+((i+m+1)*contt2[i]);
        numT2=numT2+contt2[i];
        wriT2=wriT2+contt2[i];
    }

}
float media;
staf<<endl;
staf<<" number of strings elongated in T1    ... "<< wriT1 << endl;
media=(sumT1 / numT1);
staf<<" medium length strings elongated in T1... "<<media<< endl;
staf<<" number of strings elongated in T2    ... "<< wriT2 << endl;
media=(sumT2 / numT2);
staf<<" medium length strings elongated in T2... "<< media << endl;

staf<<endl;
staf<<" ************************************ "<<endl;
staf<<" **  STRING OF MAXIMUM LENGTH      ** "<<endl;
staf<<" **   CONTAINED IN T1 and T2       ** "<<endl;
staf<<" ************************************ "<<endl;
staf<<" MAXIMUM LENGTH : "<<setfill('0')<<setw(5)<<maxlun<<endl;
staf<<endl;
for (int y1=0;y1<indmax;y1++)
{
   staf<<" STRING : "<<tbstrmax[y1]<<endl;
   for (int y2=0;y2<indt1max;y2++)
        if (tbpost1max[y1] [y2]!="")
            staf<<"    pos : "<<tbpost1max[y1] [y2]<<" in the text T1"<<endl;
   for (int y2=0;y2<indt2max;y2++)
        if (tbpost2max[y1] [y2]!="")
            staf<<"    pos : "<<tbpost2max[y1] [y2]<<" in the text T2"<<endl;
   staf<<endl;
}
staf<<" ************************************ "<<endl;
staf<<" ************************************ "<<endl;
staf<<" ************************************ "<<endl;
staf.close();
cout<<"**** PGM EXT5 ****"<<endl;
cout<<"Read    : "<<letti<<endl;

ofstream outparm("parameter.txt");
tbparm[28]="T1wri" + to_string(wriT1);
tbparm[29]="T2wri" + to_string(wriT2);
long long int wriT1T2;
wriT1T2=wriT1+wriT2;
tbparm[30]="T1T2wri" + to_string(wriT1T2);
for (int j=0;j<tapparm;j++)
    {
     outparm<<tbparm[j]<<endl;
    }
outparm.close();

return 0;
}

