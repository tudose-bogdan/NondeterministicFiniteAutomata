#include <iostream>
#include <string.h>
#include <fstream>
#include <vector>
using namespace std;

typedef struct
{
    int a;
    char x;
    vector<int> b;

}tranzitii;


int main()
{

  ifstream f("date.in");
  ofstream fout("date.out");

    int nrstari;
    f>>nrstari;
    int q[nrstari];
    for(int i=0;i<nrstari;i++)
            f>>q[i];

        int nrlit;

        f>>nrlit;
        char sigma[nrlit];

        for(int i=0;i<nrlit;i++)
        f>>sigma[i];

        int stareinitiala;
        f>>stareinitiala;

        int nrstarifinale;
        f>>nrstarifinale;
        int starifinale[nrstarifinale];

        for(int i=0;i<nrstarifinale;i++)
        f>>starifinale[i];


 int nrtranzitii;
 f>>nrtranzitii;
 tranzitii v[nrtranzitii];

 for(int i=0;i<nrtranzitii;i++)
 {
     int g;
     f>>v[i].a>>v[i].x>>g;
     v[i].b.push_back(g);
 }



 int nrcuvintedeparsat;
 f>>nrcuvintedeparsat;
 char s[10000];
 int caut;
    for(int i=0;i<nrcuvintedeparsat;i++)
 {
     f>>s;
     char litera;
     vector <int>stareactuala;
     stareactuala.push_back(stareinitiala);
     for(int j=0;j<strlen(s);j++)
     {
         litera=s[j];
         vector<int> starinoi;

         caut=1;
         for(int i=0;i<nrlit;i++)
            if(litera==sigma[i])
            caut=0;
         if(caut==1)
         {
            cout<<"cuvant incorect"<<endl;
             break;
         }

       for(int f=0;f<stareactuala.size();f++)
         for(int g=0;g<nrtranzitii;g++)
            if(v[g].x==litera && v[g].a==stareactuala[f])
         {
            for(int y=0;y<v[g].b.size();y++)
            {
                int c=1;
                for(int i=0;i<starinoi.size();i++)
                    if(v[g].b[y]==starinoi[i])
                    c=0;
                if(c==1)starinoi.push_back(v[g].b[y]);
            }

         }
         stareactuala.clear();
         for(int i=0;i<starinoi.size();i++)
            stareactuala.push_back(starinoi[i]);

         starinoi.clear();
     }

      int ok=0;
      for(int i=0;i<nrstarifinale && ok==0;i++)
        for(int j=0;j<stareactuala.size();j++)
        if(starifinale[i]==stareactuala[j])
        ok=1;

      if(ok==0)
        fout<<"NU"<<endl;
      else fout<<"DA"<<endl;
 }

    return 0;
}
