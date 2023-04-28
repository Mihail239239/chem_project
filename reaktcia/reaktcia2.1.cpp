#include <bits/stdc++.h>

using namespace std;


#define int long long
#define isupper bolshie_bukvy
#define islower malenkie_bukvy
#define isdigit tcifra

struct ION
{
 string name;
 int zarad;
 int koordinat=0;
};


string int_v_stroku(int a)
{
    string vosvrat;
    if(a<0)
    {
        vosvrat="-";
        a=-a;
    }
    if(a==0)
    {
        vosvrat="0";
    }
    while(a>0)
    {
        vosvrat.push_back('0'+a%10);
        a=a/10;
    }
    reverse(vosvrat.begin(), vosvrat.end());
    return vosvrat;
}

template <typename T>
pair<vector <T>, vector<T>> rasdelenie_na_dva(vector<T> A, int dlina1)
{
    vector <T> A1, A2;
    for(int i=0;i<dlina1; ++i)
    {
        A1.push_back(A[i]);
    }
    for(int i=dlina1; i<A.size(); ++i)
    {
        A2.push_back(A[i]);
    }
    pair<vector <T>, vector<T>> rasdelenie;
    rasdelenie.first=A1;
    rasdelenie.second=A2;
    return rasdelenie;
}

template <typename T>
string vStroku(T val)
{
    ostringstream oss;
    oss<< val;
    return oss.str();
}

template<typename T>
T fromString(const string& s)
{
  istringstream iss(s);
  T res;
  iss >> res;
  return res;
}


template<typename T>
vector <T> operator - (vector <T> a, vector <T> b)
{
    vector <T> c;
    for(int t=0; t<max(a.size(), b.size()); ++t)
    {
        if(t<a.size())
        {
            if(t<b.size())
            {
                c.push_back(a[t]-b[t]);
            }
            else
            {
                c.push_back(a[t]);
            }
        }
        else
        {
            c.push_back(-b[t]);
        }
    }
    return c;
}

template<typename T>
vector <T> operator + (vector <T> a, vector <T> b)
{
    vector <T> c;
    for(int t=0; t<max(a.size(), b.size()); ++t)
    {
        if(t<a.size())
        {
            if(t<b.size())
            {
                c.push_back(a[t]+b[t]);
            }
            else
            {
                c.push_back(a[t]);
            }
        }
        else
        {
            c.push_back(b[t]);
        }
    }
    return c;
}

template<typename T>
vector <T> operator * (T a, vector <T> b)
{
    vector <T> c;
    for(int t=0; t<b.size(); ++t)
    {
        c.push_back(b[t]*a);
    }
    return c;
}

template<typename T>
vector <T> operator * (vector <T> b, T a)
{
    vector <T> c;
    for(int t=0; t<b.size(); ++t)
    {
        c.push_back(b[t]*a);
    }
    return c;
}


signed NOD(int a, int b)
{
    if(a<0) a=-a;
    if(b<0) b=-b;
    int c;
    if(a<b)
    {
        c=a;
        a=b;
        b=c;
    }
    if(b==0) return a;
    return NOD(b, a%b);
}




signed NOK(int a, int b)
{
    return abs(a*b)/NOD(a,b);
}



class RACIONAL
{
private:
    int znamenatel;
    int chislitel;
public:
    int chisl()
    {
        return chislitel;
    }
    int znam()
    {
        return znamenatel;
    }
    RACIONAL(int p, int q)
    {
        if(p!=0)
        {
        int nod=NOD(p,q);
        chislitel=p/nod;
        znamenatel=q/nod;
        if(znamenatel<0)
        {
            chislitel=-chislitel;
            znamenatel=-znamenatel;
        }
        }
        else
        {
            chislitel=0;
            znamenatel=1;
        }
    }
    RACIONAL(pair <int,int> drob)
    {
        int p=drob.first, q=drob.second;
        if(p!=0)
        {
        int nod=NOD(p,q);
        chislitel=p/nod;
        znamenatel=q/nod;
        if(znamenatel<0)
        {
            chislitel=-chislitel;
            znamenatel=-znamenatel;
        }
        }
        else
        {
            chislitel=0;
            znamenatel=1;
        }
    }
    pair <int,int> racvpair()
    {
        pair<int, int> drob={chislitel, znamenatel};
        return drob;
    }
    int racvint()
    {
        return chislitel/znamenatel;
    }
    double racvdouble()
    {
        return chislitel*1.0/znamenatel;
    }
    RACIONAL(int p)
    {
        chislitel=p;
        znamenatel=1;
    }
};

//typedef RACIONAL rac;


namespace std {

decltype(cout)& operator << (decltype(cout)& where, RACIONAL what) {
    where << what.chisl() << '/' <<what.znam();
    return where;
}

};
bool operator != (RACIONAL a, RACIONAL b)
{
    if(a.chisl()*b.znam()!=b.chisl()*a.znam())
    {
        return true;
    }
    return false;
}

bool operator == (RACIONAL a, RACIONAL b)
{
    if(a.chisl()*b.znam()!=b.chisl()*a.znam())
    {
        return false;
    }
    return true;
}

RACIONAL operator + (RACIONAL a, RACIONAL b)
{
    RACIONAL c(a.chisl()*b.znam()+b.chisl()*a.znam(), a.znam()*b.znam());
    return c;
}

RACIONAL operator - (RACIONAL a, RACIONAL b)
{
    RACIONAL c(a.chisl()*b.znam()-b.chisl()*a.znam(), a.znam()*b.znam());
    return c;
}

RACIONAL operator - (RACIONAL a)
{
    RACIONAL c(-a.chisl(), a.znam());
    return c;
}

RACIONAL operator * (RACIONAL a, RACIONAL b)
{
    RACIONAL c(a.chisl()*b.chisl(), a.znam()*b.znam());
    return c;
}

RACIONAL operator * (RACIONAL a, int b)
{
    RACIONAL c(a.chisl()*b, a.znam());
    return c;
}

RACIONAL operator * (int b, RACIONAL a)
{
    RACIONAL c(a.chisl()*b, a.znam());
    return c;
}

vector<RACIONAL> operator * (RACIONAL b, vector<RACIONAL> a)
{
    for(int t=0; t<a.size(); ++t)
    {
        a[t]=a[t]*b;
    }
    return a;
}

vector<RACIONAL> operator * (vector<RACIONAL> a, RACIONAL b)
{
    for(int t=0; t<a.size(); ++t)
    {
        a[t]=a[t]*b;
    }
    return a;
}

vector <int> vectorracvint(vector<RACIONAL> A)
{
    vector <int> B;
    for(int i=0;i<A.size();++i)
    {
        B.push_back(A[i].racvint());
    }
    return B;
}

RACIONAL operator / (RACIONAL a, RACIONAL b)
{
    RACIONAL c(a.chisl()*b.znam(), a.znam()*b.chisl());
    return c;
}

RACIONAL operator / (RACIONAL a, int b)
{
    RACIONAL c(a.chisl(), a.znam()*b);
    return c;
}

RACIONAL operator / (int b, RACIONAL a)
{
    RACIONAL c(a.chisl(), a.znam()*b);
    return c;
}

template<typename T>
class MATRITCA_CLASS
{
private:
    vector <vector<T>> matritca;
public:
    MATRITCA_CLASS(vector <vector<T>> a)
    {
        matritca=a;
    }
    void dobavlenie_stroki(vector<T> a)
    {
        matritca.push_back(a);
    }
    void dobavlenie_stolbtca(vector<T> a)
    {
        for(int i=0; i<matritca.size(); ++i)
        {
            matritca[i].push_back(a[i]);
        }
    }
    void vyvod()
    {
        for(int i=0; i<matritca.size(); ++i)
        {
            for(int j=0; j<matritca[i].size(); ++j)
            {
                cout << matritca[i][j] << " ";
            }
            cout << '\n';
        }
    }
    vector <vector<T>> telo()
    {
        return matritca;
    }
    void pomenyt_stroki(int m, int n)
    {
        int s=m+n;
        m=min(m,n);
        n=s-m;
        matritca.insert(matritca.begin()+n,matritca[m]);
        matritca.insert(matritca.begin()+m,matritca[n]);
        matritca.erase(matritca.begin()+m+1,matritca.begin()+m+1);
        matritca.erase(matritca.begin()+n+1,matritca.begin()+n+1);
    }
    void privedenie_k_trapetcevidnoi_forme()
    {
        int N_stroki_s_ne_nul_elem;
        for(int j=0; j<matritca[0].size(); ++j)
        {
            N_stroki_s_ne_nul_elem=-1;
            if(j<matritca.size())
            {
            for(int i=j; i<matritca.size(); ++i)
            {
                if(matritca[i][j]!=RACIONAL(0) && N_stroki_s_ne_nul_elem==-1)
                {
                    N_stroki_s_ne_nul_elem=i;
                }
                if(i!=N_stroki_s_ne_nul_elem && N_stroki_s_ne_nul_elem!=-1)
                {
                    matritca[i]=matritca[i]-(matritca[i][j]/matritca[N_stroki_s_ne_nul_elem][j])*matritca[N_stroki_s_ne_nul_elem];
                }
            }
            if(N_stroki_s_ne_nul_elem!=-1)
            {
                int n=N_stroki_s_ne_nul_elem;
                int m=j;
                int s=m+n;
                m=min(m,n);
                n=s-m;
                matritca.insert(matritca.begin()+n,matritca[m]);
                matritca.insert(matritca.begin()+m,matritca[n+1]);
                matritca.erase(matritca.begin()+m+1,matritca.begin()+m+2);
                matritca.erase(matritca.begin()+n+1,matritca.begin()+n+2);
            }
            }
        }
    }
};


//vector<RACIONAL>

template<typename T>
MATRITCA_CLASS <T> operator + (MATRITCA_CLASS <T> A, MATRITCA_CLASS <T> B)
{
    vector <vector<T>> telo_c;
    vector<T> pustaia_stroka;
    for(int i=0; i<A.telo().size();++i)
    {
        telo_c.push_back(pustaia_stroka);
        for(int j=0; j<A.telo()[0].size(); ++j)
        {
            telo_c[i].push_back(A.telo()[i][j]+B.telo()[i][j]);
        }
    }
    MATRITCA_CLASS <T> C(telo_c);
    return C;
}

template <typename T>
MATRITCA_CLASS <T> operator - (MATRITCA_CLASS <T> A, MATRITCA_CLASS <T> B)
{
    vector <vector<T>> telo_c;
    vector<T> pustaia_stroka;
    for(int i=0; i<A.telo().size();++i)
    {
        telo_c.push_back(pustaia_stroka);
        for(int j=0; j<A.telo()[0].size(); ++j)
        {
            telo_c[i].push_back(A.telo()[i][j]-B.telo()[i][j]);
        }
    }
    MATRITCA_CLASS <T> C(telo_c);
    return C;
}

template <typename T>
MATRITCA_CLASS <T> operator * (MATRITCA_CLASS <T> A, MATRITCA_CLASS <T> B)
{
    vector <vector<T>> telo_c;
    vector<T> pustaia_stroka;
    T d;
    for(int i=0; i<A.telo().size();++i)
    {
        telo_c.push_back(pustaia_stroka);
        for(int j=0; j<B.telo()[0].size(); ++j)
        {
            d=0;
            for(int t=0; t<B.telo().size();++t)
            {
                d+=A.telo()[i][t]*B.telo()[t][j];
            }
            telo_c[i].push_back(d);
        }
    }
    MATRITCA_CLASS <T> C(telo_c);
    return C;
}

string sozdatel_po_naboru(pair<string,int> kation, pair<string, int> anion)
{
    string vesh="";
    int a=0;
    int d1=NOK(kation.second, abs(anion.second))/kation.second;
    int d2=NOK(kation.second, abs(anion.second))/abs(anion.second);
    int eleme1=0;//количество элементов
    for(int t=0; t<kation.first.size(); ++t)
    {
        if(kation.first[t]>='A' && kation.first[t]<='Z')
        {
            eleme1++;
        }
    }
    int eleme2=0;//количество элементов
    for(int t=0; t<anion.first.size(); ++t)
    {
        if(anion.first[t]>='A' && anion.first[t]<='Z')
        {
            eleme2++;
        }
    }
    if(d1!=1 && eleme1>1)
    {
        a=1;
        vesh.insert(0,"(");
    }
    vesh.insert(a,kation.first);
    if(d1!=1 && eleme1>1)
    {
        vesh.insert(kation.first.size()+a,")");
        ++a;
    }
    if(d1!=1)
    {
        vesh.insert(kation.first.size()+a, to_string(d1));
        ++a;
    }

    if(d2!=1 && eleme2!=1)
    {
        vesh.insert(kation.first.size()+a,"(");
        ++a;
    }
    vesh.insert(kation.first.size()+a, anion.first);
    if(d2!=1 && eleme2!=1)
    {
        vesh.insert(kation.first.size()+a+anion.first.size(), ")");
        ++a;
    }
    if(d2!=1)
    {
        vesh.insert(kation.first.size()+a+anion.first.size(), to_string(d2));
        ++a;
    }
    if(vesh=="HOH")
    {
        vesh="H2O";
    }
    return(vesh);
}

string sozdatel(int i, int l)
{
    int n_1=37;
    ION ion[n_1];
    ion[0].name="H";
    ion[0].zarad=1;

    ion[1].name="Li";
    ion[1].zarad=1;

    ion[2].name="K";
    ion[2].zarad=1;

    ion[3].name="Na";
    ion[3].zarad=1;

    ion[4].name="NH4";
    ion[4].zarad=1;

    ion[5].name="Ba";
    ion[5].zarad=2;

    ion[6].name="Ca";
    ion[6].zarad=2;

    ion[7].name="Mg";
    ion[7].zarad=2;

    ion[8].name="Sr";
    ion[8].zarad=2;

    ion[9].name="Al";
    ion[9].zarad=3;

    ion[10].name="Cr";
    ion[10].zarad=3;

    ion[11].name="Fe";
    ion[11].zarad=2;

    ion[12].name="Fe";
    ion[12].zarad=3;

    ion[13].name="Ni";
    ion[13].zarad=2;

    ion[14].name="Co";
    ion[14].zarad=2;

    ion[15].name="Mn";
    ion[15].zarad=2;

    ion[16].name="Zn";
    ion[16].zarad=2;

    ion[17].name="Ag";
    ion[17].zarad=1;

    ion[18].name="Hg";
    ion[18].zarad=2;

    ion[19].name="Pb";
    ion[19].zarad=2;

    ion[20].name="Sn";
    ion[20].zarad=2;

    ion[21].name="Cu";
    ion[21].zarad=2;

    ion[22].name="Cu";
    ion[22].zarad=1;

    ion[23].name="OH";
    ion[23].zarad=-1;

    ion[24].name="F";
    ion[24].zarad=-1;

    ion[25].name="Cl";
    ion[25].zarad=-1;

    ion[26].name="Br";
    ion[26].zarad=-1;

    ion[27].name="I";
    ion[27].zarad=-1;

    ion[28].name="S";
    ion[28].zarad=-2;

    ion[29].name="SO3";
    ion[29].zarad=-2;

    ion[30].name="SO4";
    ion[30].zarad=-2;

    ion[31].name="NO3";
    ion[31].zarad=-1;

    ion[32].name="NO2";
    ion[32].zarad=-1;

    ion[33].name="PO4";
    ion[33].zarad=-3;

    ion[34].name="CO3";
    ion[34].zarad=-2;

    ion[35].name="MnO4";
    ion[35].zarad=-1;

    ion[36].name="MnO4";
    ion[36].zarad=-2;

   /* ion[35].name="MnO4";
    ion[35].zarad=-2;

    ion[36].name="ClO";
    ion[36].zarad=-1;

    ion[37].name="ClO2";
    ion[37].zarad=-1;

    ion[38].name="ClO3";
    ion[38].zarad=-1;

    ion[39].name="ClO4";
    ion[39].zarad=-1;

    ion[40].name="SeO4";
    ion[40].zarad=-2;*/

    if(ion[i].zarad<0) //катион ставит на первое место (в i), если он не на первом месте
    {
        int chislo_bufer=l;
        l=i;
        i=chislo_bufer;
    }
    string vesh="";
    int a=0;
    int d1=NOK(ion[i].zarad, abs(ion[l].zarad))/ion[i].zarad;
    int d2=NOK(ion[i].zarad, abs(ion[l].zarad))/abs(ion[l].zarad);
    int eleme1=0;//количество элементов
    for(int t=0; t<ion[i].name.size(); ++t)
    {
        if(ion[i].name[t]>='A' && ion[i].name[t]<='Z')
        {
            eleme1++;
        }
    }
    int eleme2=0;//количество элементов
    for(int t=0; t<ion[l].name.size(); ++t)
    {
        if(ion[l].name[t]>='A' && ion[l].name[t]<='Z')
        {
            eleme2++;
        }
    }
    if(d1!=1 && eleme1>1)
    {
        a=1;
        vesh.insert(0,"(");
    }
    vesh.insert(a,ion[i].name);
    if(d1!=1 && eleme1>1)
    {
        vesh.insert(ion[i].name.size()+a,")");
        ++a;
    }
    if(d1!=1)
    {
        vesh.insert(ion[i].name.size()+a, to_string(d1));
        ++a;
    }

    if(d2!=1 && eleme2!=1)
    {
        vesh.insert(ion[i].name.size()+a,"(");
        ++a;
    }
    vesh.insert(ion[i].name.size()+a, ion[l].name);
    if(d2!=1 && eleme2!=1)
    {
        vesh.insert(ion[i].name.size()+a+ion[l].name.size(), ")");
        ++a;
    }
    if(d2!=1)
    {
        vesh.insert(ion[i].name.size()+a+ion[l].name.size(), to_string(d2));
        ++a;
    }
    if(vesh=="HOH")
    {
        vesh="H2O";
    }
    return(vesh);
}



string proverka(string x) //Отвечает за то, что введен набор элементов и правильно расставлены скобки
{
    int k=0;
    char h[166]="H HeLiBeB C N O F NeNaMgAlSiP S ClArK CaScTiV CrMnFeCoNiCuZnGaGeAsSeBrKrRbSrY ZrNbMoTcRuRhPdAgCdInSnSbTeI XeCsBaLaCePrNdPmSmEuGdTbDyHoErTmYbLuHfTaW ReOsIrPtAuHg\0\0";
    char y[3]="\0 ";
    int f;
    string pravilnost="верно";
    int n=x.size();
    int kolvo_skobok_1=0;
    int kolvo_skobok_2=0;
    for(int t=0; t<n; ++t)
    {
        f=0;
        if(x[t]=='(')
        {
            ++kolvo_skobok_1;
        }
        else{
        if(x[t]==')')
        {
            --kolvo_skobok_1;
            if(kolvo_skobok_1<0 || kolvo_skobok_2<0)
            {
                pravilnost="Скобки расставлены неверно.";
                break;
            }
        }
        else{
        if(x[t]=='[')
        {
            ++kolvo_skobok_2;
        }
        else{
        if(x[t]==']')
        {
            --kolvo_skobok_2;
            if(kolvo_skobok_1<0 || kolvo_skobok_2<0)
            {
                pravilnost="Скобки расставлены неверно.";
                break;
            }
        }
        else{
        if((x[t]<'0' || x[t]>'9') && (x[t]!='*' && x[t]!=',') && (x[t]<'A' || x[t]>'Z') && (x[t]<'a' || x[t]>'z'))
        {
            pravilnost="Присутствуют непонятные символы.";
            //pravilnost.push_back(x[t]);
            break;
        }
        else
        {
            if(x[t]<'0' || x[t]>'9')
            {
            if(x[t]>'Z' && x[t]!='*' && x[t]!=',')
            {
                pravilnost="Соединение введено некорректно.";
                break;
            }
            else
            {
                if(t==(n-1))
                {
                    k=0;
                    while(k<166)
                    {
                        if(x[t]==h[k] && h[k+1]==y[1])
                        {
                            f=1;
                            break;
                        }
                        k+=2;
                    }
                }
                else
                {
                    if(x[t]!='*' && x[t]!=',')
                    {
                    if(x[t+1]<'a' || x[t+1]>'z')
                    {
                        k=0;
                        while(k<166)
                        {
                            if(x[t]==h[k] && h[k+1]==y[1])
                            {
                                f=1;
                                break;
                            }
                            k+=2;
                        }
                    }
                    else
                    {
                        if(x[t+1]>='a' && x[t+1]<='z')
                        {
                            k=0;
                            while(k<166)
                            {
                                if(x[t]==h[k] && h[k+1]==x[t+1])
                                {
                                    f=1;
                                    ++t;
                                    break;
                                }
                                k+=2;
                            }
                        }
                    }
                    }
                    else
                    {
                        f=1;
                    }
                }
                if(f==0)
                {
                    pravilnost="Соединение введено некорректно.";
                    break;
                }
            }
            }
        }
        }
        }
        }
        }
    }
    if(kolvo_skobok_1!=0 || kolvo_skobok_2!=0)
        {
            pravilnost="Скобки расставлены неверно.";
        }
    return pravilnost;
}




vector <RACIONAL> reshenie_sistemy_nul(MATRITCA_CLASS<RACIONAL> A)
{
    int nomer_ne_nul=-1;
    RACIONAL otvet=RACIONAL(0);
    A.privedenie_k_trapetcevidnoi_forme();
    vector <vector <RACIONAL> > a=A.telo();
    vector <RACIONAL> reshenie_naoborot;
    for(int i=a.size()-1; i>-1; i=i-1)
    {
        if(a[i][a[0].size()-1]!=0 || nomer_ne_nul!=-1)
        {
            if(nomer_ne_nul==-1)
            {
                nomer_ne_nul=i;
                reshenie_naoborot.push_back(RACIONAL(1));
                if(a[i][a[0].size()-3]!=0) // Может вылезать, но редко (когда 2 вещества)
                {
                   cout << a[i][a[0].size()-3] << a[i][a[0].size()-2] << a[i][a[0].size()-1] ;//C7H14+KMnO4+H2SO4=CH3COCH3+CH3CH2COCH3+MnSO4+H2O+K2SO4
                    return {RACIONAL(-2)};
                }
            }
            otvet=RACIONAL(0);
            int z=a[0].size();
            for(int t=z-1; t>z-2-nomer_ne_nul+i; --t)
            {
                otvet=otvet-a[i][t]*reshenie_naoborot[z-1-t];
            }
            if(a[i][z-2-nomer_ne_nul+i]!=0)
            {
                reshenie_naoborot.push_back(otvet/a[i][z-2-nomer_ne_nul+i]);
            }
            else
            {
                if(otvet==0)
                {
                    return {RACIONAL(-1)};
                }
                else
                {
                    return{RACIONAL(0)};
                }
            }
        }
    }
    vector <RACIONAL> reshenie;
    reverse(reshenie_naoborot.begin(),reshenie_naoborot.end());
    reshenie=reshenie_naoborot;
    for(int t=0; t<reshenie.size();++t)
    {
        if(reshenie[t].znam()>1)
        {
            reshenie=reshenie*reshenie[t].znam();
        }
    }
    return reshenie;
}

signed kolvo_elementa_funktcia(string veshestvo, int nomer_element)
{
    int kolvo=1;
    string kolvo_elementa_string="";
    for(int i=nomer_element; (i<veshestvo.size() && (veshestvo[i]>='0' && veshestvo[i]<='9')); ++i)
    {
        kolvo_elementa_string.push_back(veshestvo[i]);
        nomer_element++;
    }
    if(kolvo_elementa_string!="")
    {
        kolvo*=stoi(kolvo_elementa_string);
        kolvo_elementa_string="";
    }
    int kolvo_skobok=0;
    for(int i=nomer_element; i<veshestvo.size(); ++i)
    {
        if(veshestvo[i]=='(' || veshestvo[i]=='[')
        {
            ++kolvo_skobok;
        }
        if(veshestvo[i]==')' || veshestvo[i]==']')
        {
            if(kolvo_skobok>0)
            {
                --kolvo_skobok;
            }
            else
            {
                if(veshestvo[i+1]>='0' && veshestvo[i+1]<='9')
                {
                    ++i;
                    for(i; i<veshestvo.size() && (veshestvo[i]>='0' && veshestvo[i]<='9'); ++i)
                    {
                        kolvo_elementa_string.push_back(veshestvo[i]);
                    }
                    if(kolvo_elementa_string!="")
                    {
                        kolvo*=stoi(kolvo_elementa_string);
                        kolvo_elementa_string="";
                    }
                    --i;
                }

            }
        }
    }
    //([Al[Cu(CuOH)2]3]4)5=Cu+Al+Cu[OH]5
    return kolvo;
}

//template<typename T>
MATRITCA_CLASS <RACIONAL> reaktcia_v_uravnenie  (string reaktcia)
{
    vector <string> veshestva;
    string element;
    string bufer;
    string veshestvo;
    int kolvo_veshestv=count(reaktcia.begin(),reaktcia.end(),'+')+2;
    int kolvo_elementa_int;
    string kolvo_elementa_string;
    map <string, int> nomer_stroki_elementa;
    vector<vector<RACIONAL>> sistema_uravneniy;
    vector <RACIONAL> nul_stroka;
    for(int i=0; i<kolvo_veshestv;++i)
    {
        nul_stroka.push_back(RACIONAL(0));
    }
    /*sistema_uravneniy.push_back(nul_stroka);
    for(int i=0; i<nul_stroka.size();++i)
    {
        for(int t=0;t<reaktcia.size(); ++t)
        {
            if(reaktcia[t]=='^')
            {
                ++t;
                while((reaktcia[t]>='0' && reaktcia[t]<='9') || reaktcia[t]=='-')
                {
                    kolvo_elementa_string.push_back(reaktcia[t]);
                    ++t;
                }
            }
        }
    }*/
    for(int t=0; t<reaktcia.size(); ++t)
    {
        if(reaktcia[t]>='A' && reaktcia[t]<='Z')
        {
            element.clear();
            element.push_back(reaktcia[t]);
            if(reaktcia[t+1]>='a' && reaktcia[t+1]<='z' )
            {
                element.push_back(reaktcia[t+1]);
            }
            if(nomer_stroki_elementa.find(element)==nomer_stroki_elementa.end())
            {
                nomer_stroki_elementa[element]=nomer_stroki_elementa.size();
            }
        }
    }
    for(int i=0; i<nomer_stroki_elementa.size();++i)
    {
        sistema_uravneniy.push_back(nul_stroka);
    }
    int t=0;
    int nomer_nachala=0;
    for(int i=0; i<reaktcia.size(); ++i)
    {
        if(reaktcia[i]=='+' || reaktcia[i]=='=')
        {
            ++t;
            nomer_nachala=i+1;
        }
        if(reaktcia[i]>='A' && reaktcia[i]<='Z')
        {
            element.erase(element.begin(),element.end());
            element.push_back(reaktcia[i]);
            if(reaktcia[i+1]>='a' && reaktcia[i+1]<='z' )
            {
                ++i;
                element.push_back(reaktcia[i]);
            }
            int k=i+1;
            for(; (k<reaktcia.size() && reaktcia[k]!='+') && reaktcia[k]!='='; ++k){}
            veshestvo=reaktcia.substr(nomer_nachala,k-nomer_nachala);
            kolvo_elementa_int=kolvo_elementa_funktcia(veshestvo,i+1-nomer_nachala);
            if(i>reaktcia.find("="))
            {
                sistema_uravneniy[nomer_stroki_elementa[element]][t]=sistema_uravneniy[nomer_stroki_elementa[element]][t]-RACIONAL(kolvo_elementa_int);
            }
            else
            {
                sistema_uravneniy[nomer_stroki_elementa[element]][t]=sistema_uravneniy[nomer_stroki_elementa[element]][t]+RACIONAL(kolvo_elementa_int);
            }
        }
    }
    return MATRITCA_CLASS <RACIONAL> (sistema_uravneniy);

}

vector<string> reagenty_veshestva(string reakcia)
{
    reakcia.erase(reakcia.find("="),reakcia.size()-reakcia.find("="));
    reakcia=reakcia+"+";
    vector <string> reagenty;
    while(reakcia!="")
    {
        reagenty.push_back(reakcia.substr(0,reakcia.find("+")));
        reakcia.erase(0,reakcia.find("+")+1);
    }
    return reagenty;
}

vector<string> produkty_veshestva(string reakcia)
{
    reakcia.erase(0,reakcia.find("=")+1);
    reakcia=reakcia+"+";
    vector <string> produkty;
    while(reakcia!="")
    {
        produkty.push_back(reakcia.substr(0,reakcia.find("+")));
        reakcia.erase(0,reakcia.find("+")+1);
    }
    return produkty;
}


double KOLVO_IONA(string x, int t) //Рассчитывает количество иона
{
    double kolvo=1;
    int kolvo_skobok=0;
    string bufer="";
    for(int i=0; i<t; ++i)
    {
        if(x[i]=='(')
        {
            kolvo_skobok++;
        }
        if(x[i]==')')
        {
            kolvo_skobok--;
        }
    }
    for(int i=1; x[t+i]>='0' && x[t+i]<='9'; ++i)
    {
        bufer.push_back(x[t+i]);
    }
    if(bufer!="")
    {
        kolvo*=stod(bufer);
        bufer="";
    }
    for(t; t<x.size(); ++t)
    {
        if(kolvo_skobok==0)
        {
            break;
        }
        if(x[t]=='(')
        {
            ++kolvo_skobok;
        }
        if(x[t]==')')
        {
            if(kolvo_skobok>0)
            {
                ++t;
                for(; x[t]>='0' && x[t]<='9'; ++t)
                {
                    bufer.push_back(x[t]);
                }
                if(bufer!="")
                {
                    kolvo*=stod(bufer);
                    bufer="";
                }
            }
            kolvo_skobok--;
        }
    }
    return kolvo;
}








signed rastvorimost(int nomer_ion1, int nomer_ion2)
{
    int n=37;
    int tablichka[37][37]=
    {
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,0,0,0,0,5,5,0,0,0,0,5,0,4},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,2,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,2,2,0,0,2,2,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,0,0,0,0,2,1,0,0,2,2,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,2,0,0,0,0,1,0,0,0,2,1,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,2,0,0,0,0,0,1,0,0,2,2,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,1,0,0,0,3,3,0,0,0,2,3,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,2,0,0,2,3,3,0,0,3,2,3,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4,0,2,2,0,0,0,2,2,0,0,0,2,2,4,4},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,2,0,0,4,3,3,0,0,3,2,3,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,0,0,0,0,2,2,0,0,0,2,6,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,0,0,0,0,2,2,0,0,1,2,6,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,0,0,0,0,2,4,0,0,0,2,2,4,4},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,0,0,0,0,2,1,0,0,0,2,6,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,7,0,2,2,2,2,2,1,0,1,2,2,1,1},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,7,3,0,1,2,2,2,3,3,3,2,6,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,2,1,1,2,2,2,2,0,3,2,2,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,0,0,0,1,2,4,0,0,3,2,3,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,2,0,0,0,4,2,4,0,0,3,2,6,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,2,2,2,2,2,2,2,0,3,2,2,4,4},
    {2,0,0,0,0,0,0,2,1,2,2,2,2,2,2,2,2,7,7,2,2,2,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,1,0,0,0,1,2,2,2,1,2,2,2,0,0,0,0,0,3,2,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,0,1,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,1,1,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,4,4},
    {0,0,0,0,0,0,0,0,0,0,2,0,4,0,0,0,0,2,2,2,1,4,2,0,0,0,0,0,0,0,0,0,0,0,0,4,4},
    {5,0,0,0,0,0,0,0,0,3,3,2,3,2,2,2,2,2,2,2,2,2,2,0,0,0,0,0,0,0,0,0,0,0,0,4,4},
    {5,0,0,0,0,2,2,1,0,3,3,2,3,2,2,4,1,2,2,2,4,4,2,0,0,0,0,0,0,0,0,0,0,0,0,4,4},
    {0,0,0,0,0,2,1,0,1,0,0,0,0,0,0,0,0,1,3,2,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,3,0,3,0,1,0,0,1,3,3,3,3,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,2,0,0,3,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {5,0,0,0,0,2,2,1,2,3,3,2,3,6,6,2,6,2,6,2,3,6,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,4,0,0,0,4,0,1,0,0,0,0,4,0,0,0,4,4,4,4,0,0,0,0,0,0,0},
    {4,0,0,0,0,0,0,0,0,0,0,4,0,0,0,4,0,1,0,0,0,0,4,0,0,0,4,4,4,4,0,0,0,0,0,0,0},
    };
    if(nomer_ion1>=0 && nomer_ion1<n && nomer_ion2>=0 && nomer_ion2<n)
    {
        return tablichka[nomer_ion1][nomer_ion2];
    }
    else
    {
        return -1;
    }
}







signed opredelenie_iona(string nazvanie_iona, int zarad_iona)
{
    int i1=-1;

    int n_1=37;
    ION ion[n_1];
    ion[0].name="H";
    ion[0].zarad=1;

    ion[1].name="Li";
    ion[1].zarad=1;

    ion[2].name="K";
    ion[2].zarad=1;

    ion[3].name="Na";
    ion[3].zarad=1;

    ion[4].name="NH4";
    ion[4].zarad=1;

    ion[5].name="Ba";
    ion[5].zarad=2;

    ion[6].name="Ca";
    ion[6].zarad=2;

    ion[7].name="Mg";
    ion[7].zarad=2;

    ion[8].name="Sr";
    ion[8].zarad=2;

    ion[9].name="Al";
    ion[9].zarad=3;

    ion[10].name="Cr";
    ion[10].zarad=3;

    ion[11].name="Fe";
    ion[11].zarad=2;

    ion[12].name="Fe";
    ion[12].zarad=3;

    ion[13].name="Ni";
    ion[13].zarad=2;

    ion[14].name="Co";
    ion[14].zarad=2;

    ion[15].name="Mn";
    ion[15].zarad=2;

    ion[16].name="Zn";
    ion[16].zarad=2;

    ion[17].name="Ag";
    ion[17].zarad=1;

    ion[18].name="Hg";
    ion[18].zarad=2;

    ion[19].name="Pb";
    ion[19].zarad=2;

    ion[20].name="Sn";
    ion[20].zarad=2;

    ion[21].name="Cu";
    ion[21].zarad=2;

    ion[22].name="Cu";
    ion[22].zarad=1;

    ion[23].name="OH";
    ion[23].zarad=-1;

    ion[24].name="F";
    ion[24].zarad=-1;

    ion[25].name="Cl";
    ion[25].zarad=-1;

    ion[26].name="Br";
    ion[26].zarad=-1;

    ion[27].name="I";
    ion[27].zarad=-1;

    ion[28].name="S";
    ion[28].zarad=-2;

    ion[29].name="SO3";
    ion[29].zarad=-2;

    ion[30].name="SO4";
    ion[30].zarad=-2;

    ion[31].name="NO3";
    ion[31].zarad=-1;

    ion[32].name="NO2";
    ion[32].zarad=-1;

    ion[33].name="PO4";
    ion[33].zarad=-3;

    ion[34].name="CO3";
    ion[34].zarad=-2;

    ion[35].name="MnO4";
    ion[35].zarad=-1;

    ion[36].name="MnO4";
    ion[36].zarad=-2;
    for(int i=0; i<n_1; ++i)
    {
        if(ion[i].name==nazvanie_iona && ion[i].zarad==zarad_iona)
        {
            i1=i;
        }
    }

    return i1; //Если ион так и не найден, то вернётся -1

}







pair <int, int> pro_osadok(string osadok) //возвращает номера ионов, из которых состоит осадок
{
    int n_1=37, n_11=23;
    ION ion[n_1];
    ion[0].name="H";
    ion[0].zarad=1;

    ion[1].name="Li";
    ion[1].zarad=1;

    ion[2].name="K";
    ion[2].zarad=1;

    ion[3].name="Na";
    ion[3].zarad=1;

    ion[4].name="NH4";
    ion[4].zarad=1;

    ion[5].name="Ba";
    ion[5].zarad=2;

    ion[6].name="Ca";
    ion[6].zarad=2;

    ion[7].name="Mg";
    ion[7].zarad=2;

    ion[8].name="Sr";
    ion[8].zarad=2;

    ion[9].name="Al";
    ion[9].zarad=3;

    ion[10].name="Cr";
    ion[10].zarad=3;

    ion[11].name="Fe";
    ion[11].zarad=2;

    ion[12].name="Fe";
    ion[12].zarad=3;

    ion[13].name="Ni";
    ion[13].zarad=2;

    ion[14].name="Co";
    ion[14].zarad=2;

    ion[15].name="Mn";
    ion[15].zarad=2;

    ion[16].name="Zn";
    ion[16].zarad=2;

    ion[17].name="Ag";
    ion[17].zarad=1;

    ion[18].name="Hg";
    ion[18].zarad=2;

    ion[19].name="Pb";
    ion[19].zarad=2;

    ion[20].name="Sn";
    ion[20].zarad=2;

    ion[21].name="Cu";
    ion[21].zarad=2;

    ion[22].name="Cu";
    ion[22].zarad=1;

    ion[23].name="OH";
    ion[23].zarad=-1;

    ion[24].name="F";
    ion[24].zarad=-1;

    ion[25].name="Cl";
    ion[25].zarad=-1;

    ion[26].name="Br";
    ion[26].zarad=-1;

    ion[27].name="I";
    ion[27].zarad=-1;

    ion[28].name="S";
    ion[28].zarad=-2;

    ion[29].name="SO3";
    ion[29].zarad=-2;

    ion[30].name="SO4";
    ion[30].zarad=-2;

    ion[31].name="NO3";
    ion[31].zarad=-1;

    ion[32].name="NO2";
    ion[32].zarad=-1;

    ion[33].name="PO4";
    ion[33].zarad=-3;

    ion[34].name="CO3";
    ion[34].zarad=-2;

    ion[35].name="MnO4";
    ion[35].zarad=-1;

    ion[36].name="MnO4";
    ion[36].zarad=-2;
    for(int i=0; i<n_11; i++)//пробегаемся по катионам
    {
        for(int j=n_11; j<n_1; ++j) // по анионам
        {
            if(sozdatel(i,j)==osadok)
            {
                return make_pair(i,j);
            }
        }
    }

}








vector <pair<string, int>>  rasloshenie(string x) // возвращает разложение вещества x, учитывая то, что останется что-то в осадке (но не количественно)
{
    int sum_zarad;
    int kolvo_skobok_1=0;
    int kolvo_skobok_2=0;
    int flag2;
    int n_1=37;
    int kolvo_variantov;
    int dlinadis;
    int kolvo_elementa_dis;
    double k_a;
    char rastvorim1;
    char rastvorim2;
    char rastvorim3;
    char rastvorim4;
    string z2;
    string y="";
    string rastvorim_str;
    string ion1;
    string anion1;
    string proverka="";
    string itog="";
    string bufer="";
    vector <string> veshestvo(0);
    vector <vector <pair <pair<string, int>, double> > > dis(1); // В паре хранится ион (пара: имя и заряд) и его количество
    vector <int> variant(n_1);
    for(int i=0; i<n_1; ++i)
    {
        variant[i]=i;
    }
    char z;
    int dlinakation1;
    int dlinaanion1;
    int zaradkation1;
    int zaradanion1;
    int d1, d2, d3, d4, d5, d6, c5, c6, an_1, an_2;
    int a=0;
    int kat_1, kat_2, dlina_1, b1,b2,b3,b4;

    ION ion[n_1];
    ion[0].name="H";
    ion[0].zarad=1;

    ion[1].name="Li";
    ion[1].zarad=1;

    ion[2].name="K";
    ion[2].zarad=1;

    ion[3].name="Na";
    ion[3].zarad=1;

    ion[4].name="NH4";
    ion[4].zarad=1;

    ion[5].name="Ba";
    ion[5].zarad=2;

    ion[6].name="Ca";
    ion[6].zarad=2;

    ion[7].name="Mg";
    ion[7].zarad=2;

    ion[8].name="Sr";
    ion[8].zarad=2;

    ion[9].name="Al";
    ion[9].zarad=3;

    ion[10].name="Cr";
    ion[10].zarad=3;

    ion[11].name="Fe";
    ion[11].zarad=2;

    ion[12].name="Fe";
    ion[12].zarad=3;

    ion[13].name="Ni";
    ion[13].zarad=2;

    ion[14].name="Co";
    ion[14].zarad=2;

    ion[15].name="Mn";
    ion[15].zarad=2;

    ion[16].name="Zn";
    ion[16].zarad=2;

    ion[17].name="Ag";
    ion[17].zarad=1;

    ion[18].name="Hg";
    ion[18].zarad=2;

    ion[19].name="Pb";
    ion[19].zarad=2;

    ion[20].name="Sn";
    ion[20].zarad=2;

    ion[21].name="Cu";
    ion[21].zarad=2;

    ion[22].name="Cu";
    ion[22].zarad=1;

    ion[23].name="OH";
    ion[23].zarad=-1;

    ion[24].name="F";
    ion[24].zarad=-1;

    ion[25].name="Cl";
    ion[25].zarad=-1;

    ion[26].name="Br";
    ion[26].zarad=-1;

    ion[27].name="I";
    ion[27].zarad=-1;

    ion[28].name="S";
    ion[28].zarad=-2;

    ion[29].name="SO3";
    ion[29].zarad=-2;

    ion[30].name="SO4";
    ion[30].zarad=-2;

    ion[31].name="NO3";
    ion[31].zarad=-1;

    ion[32].name="NO2";
    ion[32].zarad=-1;

    ion[33].name="PO4";
    ion[33].zarad=-3;

    ion[34].name="CO3";
    ion[34].zarad=-2;

    ion[35].name="MnO4";
    ion[35].zarad=-1;

    ion[36].name="MnO4";
    ion[36].zarad=-2;

    x.push_back('!'); // Добавление в конец символа, символизирующего в конец (упрощает код)
    for(int t=0; t<x.size(); ++t) // Отвечает за разложение
    {
        if(x[t]=='(' && y=="")
        {
            ++kolvo_skobok_1;
        }
        else
        {
            if(x[t]==')' && y=="")
            {
                --kolvo_skobok_1;
            }
            else
            {
                if((y!="" || x[t]<'0') || x[t]>'9')
                {
                y.push_back(x[t]);
                if(t<x.size()-1 && (x[t+1]>='a' && x[t+1]<='z')) // Отвечает за то, чтобы элемент добавлялся целиком
                {
                    ++t;
                    y.push_back(x[t]);
                }
                kolvo_variantov=variant.size();
                for(int i=0; i<kolvo_variantov; ++i) // Ищет подходящие ионы
                {
                    while(y.size()>ion[variant[i]].name.size())
                    {
                        ++i;
                        if(i>=kolvo_variantov)
                        {
                            break;
                        }
                    }
                    if(i<kolvo_variantov) //Проверяет не вылез ли алгоритм за пределы вектора
                    {
                        ion1=ion[variant[i]].name;
                        ion1.resize(y.size()); // Сохранение части проверяемого ионы
                        if(y==ion1) // Проверка, кодходит ли этот ион
                        {
                            variant.push_back(variant[i]); //Если подходит добавляем информацию про него
                        }
                    }
                    else //Если вылезли,
                    {
                        break; // Выход из цикла
                    }
                }
                kolvo_variantov=variant.size()-kolvo_variantov; //Посчитали количесство добавившихся вариантов
                if(kolvo_variantov!=0) //Если варианты ещё есть
                {
                    kolvo_variantov=variant.size()-kolvo_variantov;
                    variant.erase(variant.begin(), variant.begin() + kolvo_variantov); // Удаление устаревшей информации
                }
                else
                {
                    if(variant.size()==0)
                    {
                        cout << "ERROR!";
                    }

                    if(variant.size()==1) //Если ион определён однозначно
                    {
                        //cout << y << t << '\n';
                        if(y[y.size()-1]>='a' && y[y.size()]<='z') // Возможно, мы добавили 2 символа сразу
                        {
                            --t;
                            y.pop_back();
                        }
                        --t; // Возвращение на 1 элемент назад, тк перескочили
                        y.pop_back();
                        if(y!=ion[variant[0]].name)
                        {
                            cout << "ERROR";
                        }
                        for(int i=0; i<dis.size();++i)
                        {
                            dis[i].push_back(make_pair(make_pair(ion[variant[0]].name, ion[variant[0]].zarad),KOLVO_IONA(x, t))); //Добавь в вектор данные про него
                        }
                        y=""; //Обнуления для поиска нового элемента.
                        variant.erase(variant.begin(), variant.end());
                        for(int i=0; i<n_1; ++i)
                        {
                            variant.push_back(i);
                        }
                    }
                    if(variant.size()==2)
                    {
                        if(y[y.size()-1]>='a' && y[y.size()]<='z') // Возможно, мы добавили 2 символа сразу
                        {
                            --t;
                            y.pop_back();
                        }
                        --t; // Возвращение на 1 элемент назад, тк перескочили
                        y.pop_back();
                        if(ion[variant[0]].name==y)
                        {
                            if(ion[variant[1]].name==y)
                            {
                                //cout << "!" << variant[0] << variant[1] << " ";
                                dlinadis=dis.size();
                                dis[0].push_back(make_pair(make_pair(ion[variant[0]].name, ion[variant[0]].zarad),KOLVO_IONA(x, t))); //Добавь в вектор данные про него
                                kolvo_elementa_dis=dis[0][dis[0].size()-1].second;
                                dis.push_back(dis[0]);
                                dis[dlinadis][dis[dlinadis].size()-1].first.second=ion[variant[1]].zarad;
                                for(int j=1; j<dlinadis; ++j)
                                {
                                    dis[j].push_back(make_pair(make_pair(ion[variant[0]].name, ion[variant[0]].zarad),kolvo_elementa_dis));
                                    dis.push_back(dis[j]);
                                    dis[dlinadis+j][dis[dlinadis].size()-1].first.second=ion[variant[1]].zarad;
                                }
                                y=""; //Обнуления для поиска нового элемента.
                                variant.erase(variant.begin(), variant.end());
                                for(int i=0; i<n_1; ++i)
                                {
                                    variant.push_back(i);
                                }
                            }
                            else
                            {
                                dis[0].push_back(make_pair(make_pair(ion[variant[0]].name, ion[variant[0]].zarad),KOLVO_IONA(x, t))); //Добавь в вектор данные про него
                                for(int j=1; j<dis.size(); ++j)
                                {
                                    dis[j].push_back(dis[0][dis[0].size()-1]);
                                }
                                y=""; //Обнуления для поиска нового элемента.
                                variant.erase(variant.begin(), variant.end());
                                for(int i=0; i<n_1; ++i)
                                {
                                    variant.push_back(i);
                                }
                            }
                        }
                        else
                        {
                            if(ion[variant[1]].name==y)
                            {
                                variant[0]=variant[1];
                                dis[0].push_back(make_pair(make_pair(ion[variant[1]].name, ion[variant[1]].zarad),KOLVO_IONA(x,t))); //Добавь в вектор данные про него
                                for(int j=1; j<dis.size(); ++j)
                                {
                                    dis[j].push_back(dis[0][dis[0].size()-1]);
                                }
                                y=""; //Обнуления для поиска нового элемента.
                                variant.erase(variant.begin(), variant.end());
                                for(int i=0; i<n_1; ++i)
                                {
                                    variant.push_back(i);
                                }
                            }
                            else
                            {
                                cout << "ERROR";
                            }
                        }
                    }
                    if(variant.size()>=3 && y!="" && y!="!")
                    {
                        if(y[y.size()-1]>='a' && y[y.size()]<='z') // Возможно, мы добавили 2 символа сразу
                        {
                            --t;
                            y.pop_back();
                        }
                        --t; // Возвращение на 1 элемент назад, тк перескочили
                        y.pop_back();
                        for(int j1=0; j1<variant.size(); ++j1)
                        {
                            if(ion[variant[j1]].name==y)
                            {
                                dis[0].push_back(make_pair(make_pair(ion[variant[j1]].name, ion[variant[j1]].zarad),KOLVO_IONA(x,t))); //Добавь в вектор данные про него
                                for(int j=1; j<dis.size(); ++j)
                                {
                                    dis[j].push_back(dis[0][dis[0].size()-1]);
                                }
                                y=""; //Обнуления для поиска нового элемента.
                                variant.erase(variant.begin(), variant.end());
                                for(int i=0; i<n_1; ++i)
                                {
                                    variant.push_back(i);
                                }
                                break;
                            }
                        }
                    }
                }
                }
            }
        }
    }
    sum_zarad=1;
    while(sum_zarad!=0)//уничтожает варианты в которых сумма зарядов не ноль
    {
        sum_zarad=0;
        for(int i=0; i<dis[0].size(); ++i)
        {
            sum_zarad+=dis[0][i].second*dis[0][i].first.second;
        }
        if(sum_zarad!=0)
        {
            dis.erase(dis.begin());
        }
        if(dis.size()==0)
        {
            vector <pair<string, int> > pustota;
            return pustota;
        }
    }
    int i2, i3;
    for(int i=0; i<dis[0].size();++i) // контролирует выпадение осадков
    {
        for(int t=i+1; t<dis[0].size(); ++t) // начинаем не с 0, ибо со всеми предыдущими уже связывались
        {
            i2=opredelenie_iona(dis[0][i].first.first, dis[0][i].first.second);
            i3=opredelenie_iona(dis[0][t].first.first, dis[0][t].first.second);
            if((rastvorimost(i2,i3)==2 && dis[0][i].second>0) && dis[0][t].second>0)
            {
                //cout << "@";
                bufer=sozdatel(i2,i3); // в буфере сохраняется вещество
                //cout << dis[0][i].first.first << " " << dis[0][i].first.second << " " << dis[0][i].second << " " << dis[0][t].first.first << " " << dis[0][t].second;
                if(dis[0][i].second/abs(dis[0][t].first.second)>=dis[0][t].second/abs(dis[0][i].first.second)) // Если в избытке катион
                {
                    dis[0][i].second-=dis[0][t].second/abs(dis[0][i].first.second)*abs(dis[0][t].first.second); //уменьшаем количество катиона
                    dis[0][t].first.first=bufer; //кладём вещество на место аниона
                    dis[0][t].first.second=0; //заряд вещества 0
                    dis[0][t].second=dis[0][t].second/abs(dis[0][i].first.second)*NOD(dis[0][i].first.second,dis[0][t].first.second); //такого количество вещества
                   //cout << dis[0][i].first.first << " " << dis[0][i].first.second << " " << dis[0][i].second << '\n';
                }
                else
                {
                    dis[0][t].second-=dis[0][i].second/abs(dis[0][t].first.second)*abs(dis[0][i].first.second); //уменьшаем количество аниона
                    dis[0][i].first.first=bufer; //кладём вещество на место катиона
                    dis[0][i].first.second=0; //заряд вещества 0
                    dis[0][i].second=dis[0][i].second/abs(dis[0][t].first.second)*NOD(dis[0][i].first.second,dis[0][t].first.second); //такого количество вещества
                }
                if(dis[0][i].second==0)// Если i-ый ион закончился,
                {
                    break; //то дальнейшая проверка бессмыслена
                }
            }
        }
    }
    vector <pair<string, int>> vosvrat; //то, что в итоге возвращаем (нужно, чтобы очиститься от ставших пустыми ячеек)
    for(int i=0; i<dis[0].size(); ++i)
    {
        if(dis[0][i].second!=0) //Если не нулевое количество,
        {
            vosvrat.push_back(dis[0][i].first); // то кладём
            //cout << dis[0][i].first.first << " ";
        }
    }
    //cout << '\n';
    return vosvrat;
}






vector <pair<string, int>> OVR(int nomer_ion1, int nomer_ion2, int kislotnost)  //реакция для написания ОВР
{
    vector <pair<string, int>> vosvrat;
    //cout << nomer_ion1 << " " << nomer_ion2 << '\n';
    int nomer_okislitela, nomer_vosstanovitela, flag=1;
    if(nomer_ion1==21 || nomer_ion1==35 || nomer_ion1==36 || nomer_ion1==12) //Если первый ион -- окислитель
    {
        nomer_okislitela=nomer_ion1;
        nomer_vosstanovitela=nomer_ion2;
    }
    else
    {
        nomer_okislitela=nomer_ion2;
        nomer_vosstanovitela=nomer_ion1;
    }
    switch(nomer_okislitela)
    {
    case 12: // Fe 3+
    {
        vosvrat.push_back(make_pair("Fe",2));
        //cout << vosvrat[1].first;
        if(nomer_vosstanovitela==27)
        {
            vosvrat.push_back(make_pair("I2",0));
        }
    }
    break;
    case 21: // Cu 2+
    {
        vosvrat.push_back(make_pair("Cu",1));
        if(nomer_vosstanovitela==27)
        {
            vosvrat.push_back(make_pair("I2",0));
        }
        else
        {
            vosvrat.push_back(make_pair("Fe",3));
        }
    }
    break;
    case 35:
    {
        switch(nomer_vosstanovitela)
        {
        case 11: //с Fe 2+
            {
                vosvrat.push_back(make_pair("Fe",3));
            }
            break;
        case 22: //с Cu +
            {
                vosvrat.push_back(make_pair("Cu",2));
            }
            break;
        case 15: // с Mn 2+
            {
                if(kislotnost==0)
                {
                    vosvrat.push_back(make_pair("MnO2",0));
                }
                else
                {
                    if(kislotnost>0)
                    {
                        vosvrat.push_back(make_pair("MnO4",-2));
                    }
                    flag=0;
                }
            }
            break;
        case 26:
            {
                vosvrat.push_back(make_pair("Br2",0));
            }
            break;
        case 27:
            {
                vosvrat.push_back(make_pair("I2",0));
            }
            break;
        case 28: //с S 2-
            {
                if(kislotnost<0) // среда кислая
                {
                    vosvrat.push_back(make_pair("SO4",-2));
                }
                else
                {
                    if(kislotnost==0) //среда нейтральная
                    {
                        vosvrat.push_back(make_pair("SO4",-2));
                    }
                    else //среда щелочная
                    {
                        vosvrat.push_back(make_pair("SO4",-2));
                    }
                }
            }
            break;
        case 29: //с SO3 2-
            {
                if(kislotnost<0 || kislotnost==0) // среда кислая или нейтральная
                {
                    vosvrat.push_back(make_pair("SO4",-2));
                }
                else
                {
                    flag=0;
                }
            }
            break;
        default:
            {
                flag=0;
            }
            break;
        }
        if(nomer_vosstanovitela!=15 && flag!=0)
        {
            if(kislotnost>0)//если среда щелочная
            {
                vosvrat.push_back(make_pair("MnO4", -2));
                vosvrat.push_back(make_pair("H2O", 0));
            }
            else
            {
                if(kislotnost==0)
                {
                    vosvrat.push_back(make_pair("MnO2",0));
                    vosvrat.push_back(make_pair("OH",-1));
                }
                else
                {
                    vosvrat.push_back(make_pair("Mn",2));
                    vosvrat.push_back(make_pair("H2O", 0));
                }
            }
        }
    }
    break;
    case 36: //с MnO4 2-
        {
            if(kislotnost>0) //если среда щелочная
            {
                flag=0;
            }
            else
            {
                switch(nomer_vosstanovitela)
                {
                case 11: //с Fe 2+
                    {
                        vosvrat.push_back(make_pair("Fe",3));
                    }
                    break;
                case 22: //с Cu +
                    {
                        vosvrat.push_back(make_pair("Cu",2));
                    }
                    break;
                case 15: // с Mn 2+
                    {
                        if(kislotnost==0)
                        {
                            vosvrat.push_back(make_pair("MnO2",0));
                        }
                        else
                        {
                            if(kislotnost>0)
                            {
                                vosvrat.push_back(make_pair("MnO4",-2));
                            }
                            flag=0;
                        }
                    }
                    break;
                case 26:
                    {
                        vosvrat.push_back(make_pair("Br2",0));
                    }
                    break;
                case 27:
                    {
                        vosvrat.push_back(make_pair("I2",0));
                    }
                    break;
                case 28: //с S 2-
                    {
                        if(kislotnost<0) // среда кислая
                        {
                            vosvrat.push_back(make_pair("SO4",-2));
                        }
                        else
                        {
                            if(kislotnost==0) //среда нейтральная
                            {
                                vosvrat.push_back(make_pair("SO4",-2));
                            }
                            else //среда щелочная
                            {
                                vosvrat.push_back(make_pair("S",0));
                            }
                        }
                    }
                    break;
                case 29: //с SO3 2-
                    {
                        if(kislotnost<0 || kislotnost==0) // среда кислая или нейтральная
                        {
                            vosvrat.push_back(make_pair("SO4",-2));
                        }
                        else
                        {
                            flag=0;
                        }
                    }
                    break;
                default:
                    {
                        flag=0;
                    }
                    break;
                }
                if(nomer_vosstanovitela!=15 && flag!=0)
                {
                    if(kislotnost==0)
                    {
                        vosvrat.push_back(make_pair("MnO2",0));
                    }
                    else
                    {
                        vosvrat.push_back(make_pair("Mn",2));
                    }
                }
            }
        }
    break;
    }
    return vosvrat;
}


string sozdatel_oxida(string element, int zarad)
{
    string oxid=element;
    string chislo1=vStroku(zarad/NOD(zarad,2));
    string chislo2=vStroku(2/NOD(zarad,2));
    if(chislo1=="1") chislo1="";
    if(chislo2=="1") chislo2="";
    oxid=oxid+chislo2+"O"+chislo1;
    return oxid;
}



signed main() //пишет реакцию
{
    int n_1=37;
    ION ion[n_1];
    ion[0].name="H";
    ion[0].zarad=1;

    ion[1].name="Li";
    ion[1].zarad=1;

    ion[2].name="K";
    ion[2].zarad=1;

    ion[3].name="Na";
    ion[3].zarad=1;

    ion[4].name="NH4";
    ion[4].zarad=1;

    ion[5].name="Ba";
    ion[5].zarad=2;

    ion[6].name="Ca";
    ion[6].zarad=2;

    ion[7].name="Mg";
    ion[7].zarad=2;

    ion[8].name="Sr";
    ion[8].zarad=2;

    ion[9].name="Al";
    ion[9].zarad=3;
    ion[9].koordinat=4;

    ion[10].name="Cr";
    ion[10].zarad=3;

    ion[11].name="Fe";
    ion[11].zarad=2;

    ion[12].name="Fe";
    ion[12].zarad=3;

    ion[13].name="Ni";
    ion[13].zarad=2;

    ion[14].name="Co";
    ion[14].zarad=2;

    ion[15].name="Mn";
    ion[15].zarad=2;

    ion[16].name="Zn";
    ion[16].zarad=2;
    ion[16].koordinat=4;

    ion[17].name="Ag";
    ion[17].zarad=1;

    ion[18].name="Hg";
    ion[18].zarad=2;

    ion[19].name="Pb";
    ion[19].zarad=2;

    ion[20].name="Sn";
    ion[20].zarad=2;

    ion[21].name="Cu";
    ion[21].zarad=2;

    ion[22].name="Cu";
    ion[22].zarad=1;

    ion[23].name="OH";
    ion[23].zarad=-1;

    ion[24].name="F";
    ion[24].zarad=-1;

    ion[25].name="Cl";
    ion[25].zarad=-1;

    ion[26].name="Br";
    ion[26].zarad=-1;

    ion[27].name="I";
    ion[27].zarad=-1;

    ion[28].name="S";
    ion[28].zarad=-2;

    ion[29].name="SO3";
    ion[29].zarad=-2;

    ion[30].name="SO4";
    ion[30].zarad=-2;

    ion[31].name="NO3";
    ion[31].zarad=-1;

    ion[32].name="NO2";
    ion[32].zarad=-1;

    ion[33].name="PO4";
    ion[33].zarad=-3;

    ion[34].name="CO3";
    ion[34].zarad=-2;

    ion[35].name="MnO4";
    ion[35].zarad=-1;


    ion[36].name="MnO4";
    ion[36].zarad=-2;

    string x="",y;
    cin >> x;
    if(x[x.size()-1]!='=')//Если равно не написано в конце,
    {
        x=x+"="; //то мы его дописываем для удобства
    }
    y=x;
    vector <string> reagenty=reagenty_veshestva(x);//Осознаём реагенты
    vector <pair<string,int>> reagenty_ionnoe_rasloshenie;
    vector <pair<string,int>> produkty_ionnoe_rasloshenie;
    vector <pair<string,int>> bufernoe_rasloshenie;
    vector <RACIONAL> zaradnoe_uravnenie;
    vector <RACIONAL> koefficienty;
    vector <int> koefficienty_int;
    string bufer;
    string reaktcia="";
    string koordinat_string;//координационное число в виде строки
    int kislotnost=0; //<0 -- кислая, =0 -- нейтральная, >0 -- щелочная
    int flag1, flag2, flag_ovr=0;
    for(int i=0; i<reagenty.size(); ++i) //Цель: объединить ионные разложения реагентов, получив качественное разложение (учитывающее УЖЕ выпавшие осадки)
    {
        bufernoe_rasloshenie=rasloshenie(reagenty[i]); //Записываем в буфер разложение очередного реагента
        for(int t1=0; t1<bufernoe_rasloshenie.size(); ++t1) //пробегаемся по его ионам и осадкам
        {
            flag1=1;
            for(int t2=0; t2<reagenty_ionnoe_rasloshenie.size(); ++t2) //пробегаемся по уже имеющимся в разложении
            {
                if(bufernoe_rasloshenie[t1]==reagenty_ionnoe_rasloshenie[t2]) //если совпало, то не будем добавлять
                {
                    flag1=0;
                    break;
                }
            }
            if(flag1==1) //если не совпала частица с уже имеющимися, то
            {
                reagenty_ionnoe_rasloshenie.push_back(bufernoe_rasloshenie[t1]); //добавляем
            }
        }
    }
    int flag_uchastia[reagenty_ionnoe_rasloshenie.size()];
    for(int i=0; i<reagenty_ionnoe_rasloshenie.size(); ++i)
    {
        flag_uchastia[i]=0;
    }
    for(int i=0; i<reagenty_ionnoe_rasloshenie.size(); ++i)//определяем ориентировочную кислотность реакционной смеси
    {
        if(reagenty_ionnoe_rasloshenie[i].first=="H")
        {
            --kislotnost;
        }
        if(reagenty_ionnoe_rasloshenie[i].first=="OH")
        {
            ++kislotnost;
        }
    }


/*
    cout << kislotnost;
    for(int i=0; i<reagenty_ionnoe_rasloshenie.size(); ++i)
    {
        cout << reagenty_ionnoe_rasloshenie[i].first << " ";
    }
    cout << '\n';
*/


    for(int i=0; i<reagenty_ionnoe_rasloshenie.size()-1; ++i) //теперь можно и продукты определить
    {
        for(int t=i+1; t<reagenty_ionnoe_rasloshenie.size(); ++t)
        {
            if(reagenty_ionnoe_rasloshenie[i].second==0 || reagenty_ionnoe_rasloshenie[t].second==0)//если это уже осадок
            {
                if(reagenty_ionnoe_rasloshenie[i].second==0) //если осадок на i-ом месте
                {
                    pair <int, int> zapis_osadka=pro_osadok(reagenty_ionnoe_rasloshenie[i].first);
                    int nomer_kationa=zapis_osadka.first;
                    int nomer_aniona=zapis_osadka.second;
                    if(ion[nomer_aniona].name=="OH" && nomer_kationa!=0 && reagenty_ionnoe_rasloshenie[t].first=="H") //взаимодействие гидроксида и кислоты
                    {
                        flag1=0;
                        flag2=0;
                        for(int i1=0; i1<produkty_ionnoe_rasloshenie.size(); ++i1) //Встречались ли раньше?
                        {
                            if(produkty_ionnoe_rasloshenie[i1].first=="H2O")
                            {
                                flag1=1; //Встречался ранее
                            }
                            if(produkty_ionnoe_rasloshenie[i1].first==ion[nomer_kationa].name && produkty_ionnoe_rasloshenie[i1].second==ion[nomer_kationa].zarad)
                            {
                                flag2=1; //Встречался ранее
                            }
                        }
                        if(flag1==0) produkty_ionnoe_rasloshenie.push_back(make_pair("H2O",0)); //Если не получалась раньше добавь
                        if(flag2==0) produkty_ionnoe_rasloshenie.push_back(make_pair(ion[nomer_kationa].name, ion[nomer_kationa].zarad)); //Если не встречался раньше, добавь
                        flag_uchastia[t]=1;
                        flag_uchastia[i]=1;
                    }
                    if(ion[nomer_aniona].name=="OH" && reagenty_ionnoe_rasloshenie[t].first=="OH" && ion[nomer_kationa].koordinat!=0 && kislotnost>0)
                    {
                        bufer="["+ion[nomer_kationa].name+"(OH)";
                        koordinat_string=int_v_stroku(ion[nomer_kationa].koordinat);
                        bufer=bufer+koordinat_string+"]";
                        produkty_ionnoe_rasloshenie.push_back(make_pair(bufer,ion[nomer_kationa].zarad-ion[nomer_kationa].koordinat));
                        flag_uchastia[t]=1;
                        flag_uchastia[i]=1;
                    }
                }
                else //если осадок на t-ом месте
                {
                    pair <int, int> zapis_osadka=pro_osadok(reagenty_ionnoe_rasloshenie[t].first);
                    int nomer_kationa=zapis_osadka.first;
                    int nomer_aniona=zapis_osadka.second;
                    if(ion[nomer_aniona].name=="OH" && nomer_kationa!=0 && reagenty_ionnoe_rasloshenie[i].first=="H") //взаимодействие гидроксида и кислоты
                    {
                        flag1=0;
                        flag2=0;
                        for(int i1=0; i1<produkty_ionnoe_rasloshenie.size(); ++i1) //Встречались ли раньше?
                        {
                            if(produkty_ionnoe_rasloshenie[i1].first=="H2O")
                            {
                                flag1=1; //Встречался ранее
                            }
                            if(produkty_ionnoe_rasloshenie[i1].first==ion[nomer_kationa].name && produkty_ionnoe_rasloshenie[i1].second==ion[nomer_kationa].zarad)
                            {
                                flag2=1; //Встречался ранее
                            }
                        }
                        if(flag1==0) produkty_ionnoe_rasloshenie.push_back(make_pair("H2O",0)); //Если не получалась раньше добавь
                        if(flag2==0) produkty_ionnoe_rasloshenie.push_back(make_pair(ion[nomer_kationa].name, ion[nomer_kationa].zarad)); //Если не встречался раньше, добавь
                        flag_uchastia[t]=1;
                        flag_uchastia[i]=1;
                    }
                    if(ion[nomer_aniona].name=="OH" && reagenty_ionnoe_rasloshenie[t].first=="OH" && ion[nomer_kationa].koordinat!=0 && kislotnost>0)
                    {
                        bufer="["+ion[nomer_kationa].name+"(OH)";
                        koordinat_string=int_v_stroku(ion[nomer_kationa].koordinat);
                        bufer=bufer+koordinat_string+"]";
                        produkty_ionnoe_rasloshenie.push_back(make_pair(bufer,ion[nomer_kationa].zarad-ion[nomer_kationa].koordinat));
                        flag_uchastia[t]=1;
                        flag_uchastia[i]=1;
                    }
                }
            }
            else //если взаимодействие между ионами
            {
                int nomer_ioni=opredelenie_iona(reagenty_ionnoe_rasloshenie[i].first,reagenty_ionnoe_rasloshenie[i].second);
                int nomer_iont=opredelenie_iona(reagenty_ionnoe_rasloshenie[t].first,reagenty_ionnoe_rasloshenie[t].second);
                int nomer_kationa;
                int nomer_aniona;
                if(reagenty_ionnoe_rasloshenie[i].second*reagenty_ionnoe_rasloshenie[t].second!=0)
                {
                    if(ion[nomer_ioni].zarad>0)
                    {
                        nomer_kationa=nomer_ioni;
                        nomer_aniona=nomer_iont;
                    }
                    else
                    {
                        nomer_kationa=nomer_iont;
                        nomer_aniona=nomer_ioni;
                    }
                    int napravitel=rastvorimost(nomer_ioni,nomer_iont);//показывает тип реакции
                    if(napravitel!=4)
                    {
                        for(int i1=0; i1<reagenty_ionnoe_rasloshenie.size(); ++i1)
                        {
                            int nomer_ioni1=opredelenie_iona(reagenty_ionnoe_rasloshenie[i1].first,reagenty_ionnoe_rasloshenie[i1].second);
                            if(rastvorimost(nomer_ioni, nomer_ioni1)==4 || rastvorimost(nomer_iont, nomer_ioni1)==4)
                            {
                                napravitel=0;
                            }
                        }
                    }
                    if(napravitel!=0)
                    {
                        flag_uchastia[i]=1;
                        flag_uchastia[t]=1;
                        //cout << i << t << '\n';
                    }
                    if(napravitel==1)
                    {
                        napravitel=2;
                    }
                    switch(napravitel)
                    {
                    case 2: //выпадение осадка
                        {
                            bufer=sozdatel(nomer_ioni, nomer_iont);
                            flag1=0;
                            for(int i1=0; i1<reagenty_ionnoe_rasloshenie.size();++i1)
                            {
                                if(reagenty_ionnoe_rasloshenie[i1].first==bufer)
                                {
                                    flag1=1; // вещество встречалось ранее
                                }
                            }
                            for(int i1=0; i1<produkty_ionnoe_rasloshenie.size();++i1)
                            {
                                if(reagenty_ionnoe_rasloshenie[i1].first==bufer)
                                {
                                    flag1=1; // вещество встречалась ранее
                                }
                            }
                            if(flag1==0) produkty_ionnoe_rasloshenie.push_back(make_pair(bufer,0));//записываем его
                        }
                        break;
                    case 3: //гидролиз
                        {
                            bufer=sozdatel(nomer_kationa, opredelenie_iona("OH",-1));
                            flag1=0;
                            for(int i1=0; i1<reagenty_ionnoe_rasloshenie.size();++i1)
                            {
                                if(reagenty_ionnoe_rasloshenie[i1].first==bufer)
                                {
                                    flag1=1; // вещество встречалось ранее
                                }
                            }
                            for(int i1=0; i1<produkty_ionnoe_rasloshenie.size();++i1)
                            {
                                if(reagenty_ionnoe_rasloshenie[i1].first==bufer)
                                {
                                    flag1=1; // вещество встречалась ранее
                                }
                            }
                            if(flag1==0) produkty_ionnoe_rasloshenie.push_back(make_pair(bufer,0)); //записываем его
                            bufer=sozdatel(nomer_aniona,0);
                            if(bufer=="H2SO3")
                            {
                                flag1=0;
                                flag2=0;
                                for(int i1=0; i1<reagenty_ionnoe_rasloshenie.size();++i1)
                                {
                                    if(reagenty_ionnoe_rasloshenie[i1].first=="H2O")
                                    {
                                        flag1=1; // вода встречалась ранее
                                    }
                                    if(reagenty_ionnoe_rasloshenie[i1].first=="SO2")
                                    {
                                        flag2=1; // CO2 встречался ранее
                                    }
                                }
                                for(int i1=0; i1<produkty_ionnoe_rasloshenie.size();++i1)
                                {
                                    if(reagenty_ionnoe_rasloshenie[i1].first=="H2O")
                                    {
                                        flag1=1; // вода встречалась ранее
                                    }
                                    if(reagenty_ionnoe_rasloshenie[i1].first=="SO2")
                                    {
                                        flag2=1; // CO2 встречался ранее
                                    }
                                }
                                if(flag1==0) produkty_ionnoe_rasloshenie.push_back(make_pair("H2O",0)); // то она разлагается на воду
                                if(flag2==0) produkty_ionnoe_rasloshenie.push_back(make_pair("SO2",0)); // и сернистый газ
                            }
                            else
                            {
                                if(bufer=="H2CO3")
                                {
                                    flag1=0;
                                    flag2=0;
                                    for(int i1=0; i1<reagenty_ionnoe_rasloshenie.size();++i1)
                                    {
                                        if(reagenty_ionnoe_rasloshenie[i1].first=="H2O")
                                        {
                                            flag1=1; // вода встречалась ранее
                                        }
                                        if(reagenty_ionnoe_rasloshenie[i1].first=="CO2")
                                        {
                                            flag2=1; // CO2 встречался ранее
                                        }
                                    }
                                    for(int i1=0; i1<produkty_ionnoe_rasloshenie.size();++i1)
                                    {
                                        if(reagenty_ionnoe_rasloshenie[i1].first=="H2O")
                                        {
                                            flag1=1; // вода встречалась ранее
                                        }
                                        if(reagenty_ionnoe_rasloshenie[i1].first=="CO2")
                                        {
                                            flag2=1; // CO2 встречался ранее
                                        }
                                    }
                                    if(flag1==0) produkty_ionnoe_rasloshenie.push_back(make_pair("H2O",0));
                                    if(flag2==0) produkty_ionnoe_rasloshenie.push_back(make_pair("CO2",0));
                                }
                                else
                                {
                                    produkty_ionnoe_rasloshenie.push_back(make_pair(sozdatel(nomer_aniona,0),0));
                                }
                            }
                        }
                        break;
                    case 4:
                        {
                            bufernoe_rasloshenie=OVR(nomer_aniona, nomer_kationa, kislotnost); //получаем продукты овр
                            if(bufernoe_rasloshenie.size()!=0)
                            {
                                flag_uchastia[i]=1;
                                flag_uchastia[t]=1;
                                flag_ovr=1;
                            }
                            for(int i1=0; i1<bufernoe_rasloshenie.size(); ++i1)
                            {
                                bufer=bufernoe_rasloshenie[i1].first;
                                flag1=0;
                                for(int j1=0; j1<reagenty_ionnoe_rasloshenie.size();++j1)
                                {
                                    if(reagenty_ionnoe_rasloshenie[j1].first==bufernoe_rasloshenie[i1].first && reagenty_ionnoe_rasloshenie[j1].second==bufernoe_rasloshenie[i1].second)
                                    {
                                        flag1=1; // вещество встречалось ранее
                                    }
                                   //cout << reagenty_ionnoe_rasloshenie[j1].first << " ";
                                }
                                for(int j1=0; j1<produkty_ionnoe_rasloshenie.size();++j1)
                                {
                                    if(produkty_ionnoe_rasloshenie[j1].first==bufernoe_rasloshenie[i1].first && produkty_ionnoe_rasloshenie[j1].second==bufernoe_rasloshenie[i1].second)
                                    {
                                        flag1=1; // вещество встречалось ранее
                                    }
                                    //cout << produkty_ionnoe_rasloshenie[j1].first << " ";
                                }
                                if(flag1==0) produkty_ionnoe_rasloshenie.push_back(make_pair(bufernoe_rasloshenie[i1].first,bufernoe_rasloshenie[i1].second)); //записываем его
                            }
                        }
                        break;
                    case 5:
                        {
                            bufer=sozdatel(nomer_aniona,nomer_kationa);
                            if(bufer=="H2SO3") //если это сернистая кислота
                            {
                                flag1=0;
                                flag2=0;
                                for(int i1=0; i1<reagenty_ionnoe_rasloshenie.size();++i1)
                                {
                                    if(reagenty_ionnoe_rasloshenie[i1].first=="H2O")
                                    {
                                        flag1=1; // вода встречалась ранее
                                    }
                                    if(reagenty_ionnoe_rasloshenie[i1].first=="SO2")
                                    {
                                        flag2=1; // CO2 встречался ранее
                                    }
                                }
                                for(int i1=0; i1<produkty_ionnoe_rasloshenie.size();++i1)
                                {
                                    if(reagenty_ionnoe_rasloshenie[i1].first=="H2O")
                                    {
                                        flag1=1; // вода встречалась ранее
                                    }
                                    if(reagenty_ionnoe_rasloshenie[i1].first=="SO2")
                                    {
                                        flag2=1; // CO2 встречался ранее
                                    }
                                }
                                if(flag1==0) produkty_ionnoe_rasloshenie.push_back(make_pair("H2O",0)); // то она разлагается на воду
                                if(flag2==0) produkty_ionnoe_rasloshenie.push_back(make_pair("SO2",0)); // и сернистый газ
                            }
                            else
                            {
                                if(bufer=="H2CO3") //аналогично с угольной кислотой
                                {
                                    flag1=0;
                                    flag2=0;
                                    for(int i1=0; i1<reagenty_ionnoe_rasloshenie.size();++i1)
                                    {
                                        if(reagenty_ionnoe_rasloshenie[i1].first=="H2O")
                                        {
                                            flag1=1; // вода встречалась ранее
                                        }
                                        if(reagenty_ionnoe_rasloshenie[i1].first=="CO2")
                                        {
                                            flag2=1; // CO2 встречался ранее
                                        }
                                    }
                                    for(int i1=0; i1<produkty_ionnoe_rasloshenie.size();++i1)
                                    {
                                        if(reagenty_ionnoe_rasloshenie[i1].first=="H2O")
                                        {
                                            flag1=1; // вода встречалась ранее
                                        }
                                        if(reagenty_ionnoe_rasloshenie[i1].first=="CO2")
                                        {
                                            flag2=1; // CO2 встречался ранее
                                        }
                                    }
                                    if(flag1==0) produkty_ionnoe_rasloshenie.push_back(make_pair("H2O",0));
                                    if(flag2==0) produkty_ionnoe_rasloshenie.push_back(make_pair("CO2",0));
                                }
                                else
                                {
                                    produkty_ionnoe_rasloshenie.push_back(make_pair(bufer,0));
                                }
                            }
                        }
                        break;
                    case 6:
                        {
                            bufer=sozdatel_po_naboru(make_pair(ion[nomer_kationa].name+"OH", ion[nomer_kationa].zarad-1), make_pair(ion[nomer_aniona].name, ion[nomer_aniona].zarad));
                            flag1=0;
                            for(int i1=0; i1<reagenty_ionnoe_rasloshenie.size();++i1)
                            {
                                if(reagenty_ionnoe_rasloshenie[i1].first==bufer)
                                {
                                    flag1=1; // вещество встречалось ранее
                                }
                            }
                            for(int i1=0; i1<produkty_ionnoe_rasloshenie.size();++i1)
                            {
                                if(reagenty_ionnoe_rasloshenie[i1].first==bufer)
                                {
                                    flag1=1; // вещество встречалась ранее
                                }
                            }
                            if(flag1!=1) produkty_ionnoe_rasloshenie.push_back(make_pair(bufer,0));
                            produkty_ionnoe_rasloshenie.push_back(make_pair("H",1));
                        }
                        break;
                    case 7: // Если образующееся вещество разлагается с образованием оксида
                        {
                            bufer=sozdatel_oxida(ion[nomer_kationa].name, ion[nomer_kationa].zarad);
                            flag1=0;
                            flag2=0;
                            for(int i1=0; i1<reagenty_ionnoe_rasloshenie.size();++i1)
                            {
                                if(reagenty_ionnoe_rasloshenie[i1].first==bufer)
                                {
                                    flag1=1; // вещество встречалось ранее
                                }
                                if(reagenty_ionnoe_rasloshenie[i1].first=="H2O")
                                {
                                    flag2=1; // вода встречалась ранее
                                }
                            }
                            for(int i1=0; i1<produkty_ionnoe_rasloshenie.size();++i1)
                            {
                                if(reagenty_ionnoe_rasloshenie[i1].first==bufer)
                                {
                                    flag1=1; // вещество встречалась ранее
                                }
                                if(reagenty_ionnoe_rasloshenie[i1].first=="H2O")
                                {
                                    flag2=1; // вода встречалась ранее
                                }
                            }
                            if(flag1!=1) produkty_ionnoe_rasloshenie.push_back(make_pair(bufer,0));
                            if(flag2!=1) produkty_ionnoe_rasloshenie.push_back(make_pair("H2O",0));
                        }
                        break;
                    default:


                            break;
                    }
                }
            }

        }
    }
    for(int i=0; i<reagenty_ionnoe_rasloshenie.size();++i)
    {
        if((reagenty_ionnoe_rasloshenie[i].first=="H" || reagenty_ionnoe_rasloshenie[i].first=="OH") && flag_ovr!=0)
        {
            flag_uchastia[i]=1;
        }
        if(flag_uchastia[i]==0)
        {
            produkty_ionnoe_rasloshenie.push_back(reagenty_ionnoe_rasloshenie[i]);
        }
    }
    reaktcia="";
    for(int i=0;  i<reagenty.size(); ++i)
    {
        zaradnoe_uravnenie.push_back(RACIONAL(0));
    }
    reaktcia=x;
    for(int i=0; i<produkty_ionnoe_rasloshenie.size();++i)
    {
        reaktcia=reaktcia+produkty_ionnoe_rasloshenie[i].first;
        reaktcia=reaktcia+"^(";
        reaktcia=reaktcia+int_v_stroku(produkty_ionnoe_rasloshenie[i].second)+")";
        zaradnoe_uravnenie.push_back(RACIONAL(produkty_ionnoe_rasloshenie[i].second));
        if(i!=produkty_ionnoe_rasloshenie.size()-1) reaktcia=reaktcia+"+";
    }
    MATRITCA_CLASS <RACIONAL> sistema=reaktcia_v_uravnenie(reaktcia);
    sistema.dobavlenie_stroki(zaradnoe_uravnenie);
    koefficienty=reshenie_sistemy_nul(sistema);
    //cout << reaktcia;
    if(koefficienty.size()==1) //если не решилось
    {
        //cout << '\n' << "!"<< '\n';
        reaktcia="H2O+"+reaktcia; //попробуем добавить водички
        reagenty.insert(reagenty.begin(),"H2O");
        //cout << reaktcia;
        MATRITCA_CLASS <RACIONAL> sistema=reaktcia_v_uravnenie(reaktcia);
        zaradnoe_uravnenie.insert(zaradnoe_uravnenie.begin(),0);
        sistema.dobavlenie_stroki(zaradnoe_uravnenie);
        koefficienty=reshenie_sistemy_nul(sistema);
    }
    for(int i=0; i<koefficienty.size();++i)
    {
        koefficienty_int.push_back(koefficienty[i].racvint());
        //cout <<"! " << koefficienty_int[i] << " ";
    }
    //if(koefficienty.size()>1)
    //{
        reaktcia="";
        for(int i=0; i<reagenty.size();++i)
        {
            if(koefficienty_int[i]!=1)
            {
                reaktcia=reaktcia+int_v_stroku(koefficienty_int[i]);
            }
            reaktcia=reaktcia+reagenty[i];
            if(i!=reagenty.size()-1) reaktcia=reaktcia+"+";
        }
        reaktcia=reaktcia+"=";
        for(int i=0; i<produkty_ionnoe_rasloshenie.size();++i)
        {
            if(koefficienty_int[i+reagenty.size()]!=1)
            {
                reaktcia=reaktcia+int_v_stroku(koefficienty_int[i+reagenty.size()]);
            }
            reaktcia=reaktcia+produkty_ionnoe_rasloshenie[i].first;
            if(produkty_ionnoe_rasloshenie[i].second!=0)
            {
                reaktcia=reaktcia+"^(";
                reaktcia=reaktcia+int_v_stroku(produkty_ionnoe_rasloshenie[i].second)+")";
            }
            if(i!=produkty_ionnoe_rasloshenie.size()-1) reaktcia=reaktcia+"+";
        }

        cout << '\n' << reaktcia;
   // }
    //else
   // {
     //   cout << "Mayu";
    //}

    return 0;
}





    // Сохранение на всякий случай
    /*int n_1=41;
    ION ion[n_1];
    ion[0].name="H";
    ion[0].zarad=1;

    ion[1].name="Li";
    ion[1].zarad=1;

    ion[2].name="K";
    ion[2].zarad=1;

    ion[3].name="Na";
    ion[3].zarad=1;

    ion[4].name="NH4";
    ion[4].zarad=1;

    ion[5].name="Ba";
    ion[5].zarad=2;

    ion[6].name="Ca";
    ion[6].zarad=2;

    ion[7].name="Mg";
    ion[7].zarad=2;

    ion[8].name="Sr";
    ion[8].zarad=2;

    ion[9].name="Al";
    ion[9].zarad=3;

    ion[10].name="Cr";
    ion[10].zarad=3;

    ion[11].name="Fe";
    ion[11].zarad=2;

    ion[12].name="Fe";
    ion[12].zarad=3;

    ion[13].name="Ni";
    ion[13].zarad=2;

    ion[14].name="Co";
    ion[14].zarad=2;

    ion[15].name="Mn";
    ion[15].zarad=2;

    ion[16].name="Zn";
    ion[16].zarad=2;

    ion[17].name="Ag";
    ion[17].zarad=1;

    ion[18].name="Hg";
    ion[18].zarad=2;

    ion[19].name="Pb";
    ion[19].zarad=2;

    ion[20].name="Sn";
    ion[20].zarad=2;

    ion[21].name="Cu";
    ion[21].zarad=2;

    ion[22].name="Cu";
    ion[22].zarad=1;

    ion[23].name="OH";
    ion[23].zarad=-1;

    ion[24].name="F";
    ion[24].zarad=-1;

    ion[25].name="Cl";
    ion[25].zarad=-1;

    ion[26].name="Br";
    ion[26].zarad=-1;

    ion[27].name="I";
    ion[27].zarad=-1;

    ion[28].name="S";
    ion[28].zarad=-2;

    ion[29].name="SO3";
    ion[29].zarad=-2;

    ion[30].name="SO4";
    ion[30].zarad=-2;

    ion[31].name="NO3";
    ion[31].zarad=-1;

    ion[32].name="NO2";
    ion[32].zarad=-1;

    ion[33].name="PO4";
    ion[33].zarad=-3;

    ion[34].name="MnO4";
    ion[34].zarad=-1;

    ion[35].name="MnO4";
    ion[35].zarad=-2;

    ion[36].name="ClO";
    ion[36].zarad=-1;

    ion[37].name="ClO2";
    ion[37].zarad=-1;

    ion[38].name="ClO3";
    ion[38].zarad=-1;

    ion[39].name="ClO4";
    ion[39].zarad=-1;

    ion[40].name="SeO4";
    ion[40].zarad=-2;*/






