#include <bits/stdc++.h>

using namespace std;

#define int long long
# define isupper bolshie_bukvy
# define islower malenkie_bukvy
#define isdigit tcifra

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


int NOD(int a, int b)
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




string proverka(string x)
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

int kolvo_elementa_funktcia(string veshestvo, int nomer_element)
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
                }
                --i;
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
/*template<typename T>
template<typename T>
class matrix {
public:
    matrix() : body() {}
    const vector< vector<T> >& get_ref() const {
        return body;
    }
    void multiply_into_myself(T what) {
        for(auto& row : body) {
            for(auto& elem : row) {
                elem*=what;
            }
        }
    }
private:
    vector< vector<T> > body;
};*/

/*bool test() {
    vector<RACIONAL> f(2, 3), g(3, 4);
    if(f-f != RACIONAL(0)) {
        return false;
    }
    if(f+g != RACIONAL(17, 12)) {
        return false;
    }
    if(f != f) {
        return false;
    }
    //...
    return true;
}*/

signed main()
{
    setlocale(LC_ALL, "rus");
    cout << fixed << setprecision(5);
    vector<RACIONAL> pustaia_stroka;
    string reaktcia;
    string veshestvo;
    cin >> reaktcia;
    if(reaktcia.find("=")==string::npos)
    {
        cout << "Нет =!";
        return 0;
    }
    pair<vector<int>,vector<string>> reagenty;
    pair<vector<int>,vector<string>> produkty;
    reagenty.second=reagenty_veshestva(reaktcia);
    produkty.second=produkty_veshestva(reaktcia);
    for(int i=0; i<reagenty.second.size(); ++i)
    {
        if(proverka(reagenty.second[i])!="верно")
        {
            cout <<reagenty.second[i] << " " << proverka(reagenty.second[i]);
            return 0;
        }
    }
    for(int i=0; i<produkty.second.size(); ++i)
    {
        if(proverka(produkty.second[i])!="верно")
        {
            cout <<produkty.second[i] << proverka(reagenty.second[i]);
            return 0;
        }
    }
    MATRITCA_CLASS<RACIONAL> A=reaktcia_v_uravnenie(reaktcia);
    vector<int> koeffecienty=vectorracvint(reshenie_sistemy_nul(A));
    if(koeffecienty.size()!=1)
    {cout << '\n';
    pair <vector <int>, vector <int>> koeffecienty_reakcii=rasdelenie_na_dva(koeffecienty,reagenty.second.size());
    reagenty.first=koeffecienty_reakcii.first;
    produkty.first=koeffecienty_reakcii.second;
    for(int i=0; i<reagenty.first.size(); ++i)
    {
        cout<< reagenty.first[i] << reagenty.second[i];
        if(i!=reagenty.first.size()-1)
        {
            cout << "+";
        }
    }
    cout << "=";
    for(int i=0; i<produkty.first.size(); ++i)
    {
        cout << produkty.first[i] << produkty.second[i];
        if(i!=produkty.first.size()-1)
        {
            cout << "+";
        }
    }
    }
    else
    {
        cout << "Реакция уравнивается не единственным образом!";
    }
    //cout << RACIONAL(0)*RACIONAL(0);
    return 0;
}
//Cu(Zn)4(OH)20=Zn+Cu5Zn(OH)15+OH

//C10H20+KMnO4+H2SO4+H2O=CH3COOH+C7H15COOH+MnSO4
