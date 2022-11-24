#include <bits/stdc++.h>
#define int short
using namespace std;
long long timee,now_time,cnt=0,wq;
template<typename T> void vyvesti_vector(vector<T> a){
    for(int i = 0; i < a.size(); ++i){
        cout << a[i] << " ";
        //fout << a[i] << " ";
    }
    cout<< '\n';
    //fout << "\n";
}
template<typename T> void wyvesti_vector(vector<T> a){
    for(int i = 0; i < a.size(); ++i){
        vyvesti_vector(a[i]);
    }
}
 inline  vector<vector<int>> case_1d (vector<int>& a,vector<int>& b){
    if(a.size()!=b.size()) return {{-3}};
    int summa1 = 0, summa2 = 0;
    for(int i = 0; i < a.size(); ++i){
        summa1+=a[i]; summa2+=b[i];
    }
    if(summa1!=summa2) return {{-2}};
    vector<int> indexa(a.size());
    for(int i = 0; i < a.size(); ++i){
        indexa[i] = i;
    }
    sort(indexa.begin(),indexa.end(),[&](int x, int y){return(a[x]<a[y]);});
    vector<int> indexb(a.size());
    for(int i = 0; i < a.size(); ++i){
        indexb[i] = i;
    }
    sort(indexb.begin(),indexb.end(),[&](int x, int y){return(b[x]<b[y]);});

    for(int i = 0; i < a.size(); ++i){
        if(a[indexa[i]]!=b[indexb[i]]) {
            return {{-1}};
        }
    }

    int koren_proizvodnoi = 0;
    vector<vector<int>> otvet(a.size());
    otvet[indexa[0]].push_back(indexb[0]);
    for(int i = 1; i < a.size(); ++i){
        if(a[indexa[i]] > a[indexa[koren_proizvodnoi]]){
            koren_proizvodnoi = i;
            otvet[indexa[i]].push_back(indexb[i]);
        }
        else {
            for(auto tmp : otvet[indexa[koren_proizvodnoi]]) otvet[indexa[i]].push_back(tmp);
            otvet[indexa[i]].push_back(indexb[i]);
            for(int j = koren_proizvodnoi; j < i; ++j){
                otvet[indexa[j]].push_back(indexb[i]);
            }
        }
    }
    return otvet;
}
const int ogranichenie_na_stepen = 4;
  inline vector<vector<int>> genocid_nulej (vector<vector<int>>& a){
    vector<vector<int>> otvet(a.size());
    for(int i = 0; i < a.size(); ++i){
        for(int j = 0; j < a[0].size(); ++j){
            if(a[i][j]!=0){ otvet[i].push_back(a[i][j]); }
        }
    }
    for(int i = 0; i < a.size(); ++i){
        for(int j = otvet[i].size(); j < ogranichenie_na_stepen; ++j){
            otvet[i].push_back(0);
        }
    }
    return otvet;
}
 inline  vector<int> peresechenie (vector<int>& a, vector<int>& b){
    vector<int> otvet;
    set<int> elementib;
    for(int i = 0; i < b.size();++i){
        elementib.insert(b[i]);
    }
    for(int i = 0; i < a.size();++i){
        if(elementib.find(a[i]) != elementib.end()) otvet.push_back(a[i]);
    }
    return otvet;
}
inline   vector<vector<int>> otseivanie_teoremoj_vieta (vector<vector<int>>& u, vector<vector<int>>& v){
    vector<vector<int>> otvet (u.size(), vector<int>(1,0));
    vector<vector<int>> a = genocid_nulej(u);
    vector<vector<int>> b = genocid_nulej(v);
    if(a.size()!=b.size()) return {{-6}};
    vector<int> suma(a.size(),0);
    vector<int> sumb(b.size(),0);
    for(int i = 0; i < a.size(); ++i){
        for(int j = 0; j < a[0].size();++j){
            suma[i] += a[i][j];
        }
    }
    for(int i = 0; i < a.size(); ++i){
        for(int j = 0; j < a[0].size();++j){
            sumb[i] += b[i][j];
        }
    }
    vector<vector<int>> sravnenie_summ = case_1d(suma,sumb);
    if(sravnenie_summ[0][0] < 0) return {{-5}};
    for(int i = 0; i < otvet.size(); ++i){
        otvet[i] = sravnenie_summ[i];
    }

    return otvet;
}
  inline vector<vector<int>> rebra_v_tablicu (int kol_vo_ver, vector<vector<int>>& rebra){
    vector<vector<int>> otvet (kol_vo_ver, vector<int> (kol_vo_ver,0));
    for(int i = 0; i < rebra.size(); ++i){
        otvet[rebra[i][0]][rebra[i][1]]+=rebra[i][2];
        otvet[rebra[i][1]][rebra[i][0]]+=rebra[i][2];
    }
    return otvet;
}
 bool podstavit (vector<int> parosochetanie, vector<vector<int>>& a, vector<vector<int>>& b){
    //parosochetanie[i] = j <=> i ver iz a sopostavlena j ver iz b
    for(int i = 0; i < b.size(); ++i){
        for(int t=0; t<b.size(); ++t)
        {
            if(a[i][t]!=b[parosochetanie[i]][parosochetanie[t]])
            {
                return false;
            }
        }
    }
    return true;
}
const int ogranichenie_na_kolvo_vershin = 50;
vector<int> match(ogranichenie_na_kolvo_vershin,-1);
vector<bool>used(ogranichenie_na_kolvo_vershin);
  inline bool dfs(vector<vector<int>>& g, int v){
    if(used[v]){return false;}
    used[v] = true;
    for(int u:g[v]){
        if(match[u]==-1 || dfs(g,match[u])){
            match[u] = v;
            return true;
        }
    }
    return false;
}
    vector<int> max_parosochetanie (vector<vector<int>>& g, int n){
    for(int v = 0;  v < n; ++v){
        fill(used.begin(),used.end(),false);
        bool t = dfs(g,v);
    }
    vector<int> ans;
    for(int i = 0; i < n; ++i){
        if(match[i]==-1) return {-1};
        ans.push_back(match[i]);
    }
    return ans;
}
vector<vector<int>> vse_parosoch;
  inline void all_parosoch (vector<vector<int>>& rebra, vector<int>& ans, vector<int>& usedb, int k){
    int n = usedb.size();
    if(k==n) {vse_parosoch.push_back(ans); return;}
    int i = k;
            for(int j: rebra[i]){
                if(usedb[j] == 0){
                    usedb[j] = 1;
                    ans[i] = j;
                    k++;
                    all_parosoch(rebra,ans,usedb,k);
                    k--;

                    usedb[j] = 0;
                    ans[i] = -1;
                }
            }
            return;

}
void out_n(int n){
if(n<10) cout << 0; cout << n;
}
void out_time (long long time){
    cout << "Time - ";
    out_n((time-timee)/3600);
    cout << ":";
    out_n(((time-timee)/60)%60);
    cout << ":";
    out_n((time-timee)%60);
    cout << " Graphs - " << cnt << " out of " << wq << " (" << cnt*100/wq << "%)";
}
 inline bool iseq (vector<vector<int>>& a, vector<vector<int>>& b){
     if(time(0) >= now_time+1){
        cout << '\r';
        out_time(now_time);
        now_time = time(0);
     }
    int n = a.size();
    vector<vector<int>> c = otseivanie_teoremoj_vieta(a,b);
    switch(c[0][0]){
    case -6:
        ////cout<< "Code -6: sizes are not equal";
        return 0;
    case -5:
        //cout<< "Code -5: sums are not equal" << '\n';
        return 0;
    case -4:
        ////cout<< "Code -4: sigma2s are not equal";
        return 0;
    case -3:
        ////cout<< "Code -3: sigma3s are not equal";
        return 0;
    case -2:
        ////cout<< "Code -2: multiples are not equal";
        return 0;
    default:
        vector<int> tmp = max_parosochetanie(c,n);
        if(tmp[0] == -1){
            //cout<< "Code -7: max_parosochetanie does not include all ver" << endl;

            return false;
        }
        if(podstavit(tmp,a,b)){
            //vyvesti_vector(tmp);
            return true;
        }
        vector<int> ans(n,-1);
        vector<int> usedb (n,0);
        all_parosoch(c,ans,usedb,0);
        for(int i = 0; i < vse_parosoch.size(); ++i){
           //cout << "!" << vse_parosoch.size() << '\n';
            if(podstavit(vse_parosoch[i],a,b)){
                //vyvesti_vector(vse_parosoch[i]);
                vse_parosoch.erase(vse_parosoch.begin(),vse_parosoch.end());
                return true;
            }
        }
        //cout<< "Code -1: these two vectors are not equal without any obvious reason" << '\n';
    vse_parosoch.erase(vse_parosoch.begin(),vse_parosoch.end());
        return false;
    }
    return 0;
}
vector<vector<vector<int>>> vse_graphy;



signed main(){
    for(int i = 20; i <= 20; ++i){

    timee = time(0);
    now_time = timee;

    ifstream fin ("file.txt");
    int n1,n2;
    if(i!=1) fin >> n2 >> n1;
    wq = n1*n2;
    auto timee = clock();
    if(i!=1) {for(int qq = 0; qq < n1; ++qq){
        vector<vector<int>> tmp(n2,vector<int>(n2));
        for(int i = 0;i < n2; ++i){
            for(int j= 0; j < n2; ++j){
                fin >> tmp[i][j];
            }
        }
        for(int i = 0; i < n2; ++i){
            for(int j = 0; j < n2; ++j){
                if(i==j){
                    tmp[j].push_back(1);
                }
                else {
                    tmp[j].push_back(0);
                }
            }
            vector<int> tmp2 (n2+1,0);
            tmp2[i] = 1;
            tmp.push_back(tmp2);
            bool f = true;
            bool f1 = true;
            cnt++;
            for(int i = 0; i < tmp.size();++i){
                int sum = 0;
                for(int j = 0; j < tmp[i].size(); ++j){
                    sum+=tmp[i][j];
                }
                if(sum>4){
                    f1=false;
                    break;

                }
            }
            if(f1){for(int i = 0; i < vse_graphy.size();++i){
            if(iseq(tmp,vse_graphy[i])) {f=false; break;}
        }
        if(f) {vse_graphy.push_back(tmp);
        cout << '\r' << vse_graphy.size() << " - "; out_time(now_time); cout << '\n';
        }}
        tmp.pop_back();
        for(int j = 0; j < n2; ++j){
            tmp[j].pop_back();
        }
        }
    }
    fopen("file.txt","w");
    ofstream fout ("file.txt");
    fout << '\n';
    fout << vse_graphy[0].size() << ' ' << vse_graphy.size() << '\n';
    for(int i = 0; i < vse_graphy.size();++i){
        for(int k = 0; k < vse_graphy[i].size(); ++k){
            for(int l = 0; l < vse_graphy[i][0].size(); ++l){
                fout << vse_graphy[i][k][l] << ' ';
            }
            fout << '\n';
        }
        fout << '\n';
    }
    cout << '\n' << "Execution time: " << clock()-timee << " ms n = " << vse_graphy[0].size();
    vse_graphy.clear();
    }
    if(i==1){
        fopen("file.txt","w");
    ofstream fout ("file.txt");
    fout << '\n';
    fout << 1 << ' ' << 1 << '\n' << 1 << '\n';
    }
    }
}
