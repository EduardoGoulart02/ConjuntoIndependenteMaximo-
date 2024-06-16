#include <iostream>
#include <vector>
using namespace std;

void leituraGrafo(vector<vector<int>> &, int);
vector<int> maiorconjunto(vector<vector<int>> &);

int main()
{
    int n, m;
    cout << "Digite o número de vértices: ";
    cin >> n;
    cout << "Digite o número de arestas: ";
    cin >> m;
    vector<vector<int>> Grafo;
    Grafo.assign(n, vector<int>());
    leituraGrafo(Grafo, m);

    vector<int> melhorSolucao = maiorconjunto(Grafo);
    cout << "Conjunto Independente Máximo: ";
    for (int v : melhorSolucao) {
        cout << v << " ";
    }
    cout << endl;
    cout << "Tamanho do Conjunto Independente Máximo: " << melhorSolucao.size() << endl;

    cout << "Total de Vértices: " << n << endl;
    cout << "Total de Arestas: " << m << endl;
    return 0;
}

void leituraGrafo(vector<vector<int>> &G, int m)
{
    int a, b;
    cout << "Digite as arestas (vertice1 vertice2):" << endl;
    while (m--)
    {
        cin >> a >> b;
        G[a].push_back(b); 
    }
}

bool verificaoVertice(int v, vector<int> &solucao, vector<vector<int>> &G) {
    for (int i : solucao) {
        for (int vizinho : G[i]) { 
            if (vizinho == v) {
                return false;
            }
        }
        for (int vizinho : G[v]) { 
            if (vizinho == i) {
                return false;
            }
        }
    }
    return true;
}

void maiorconjunto(int v, vector<int> &solucao, vector<int> &melhorSolucao, vector<vector<int>> &G) {
    if (v == G.size()) {
        if (solucao.size() > melhorSolucao.size()) {
            melhorSolucao = solucao;
        }
        return;
    }

    if (verificaoVertice(v, solucao, G)) {
        solucao.push_back(v);
        maiorconjunto(v + 1, solucao, melhorSolucao, G);
        solucao.pop_back();
    }

    maiorconjunto(v + 1, solucao, melhorSolucao, G);
}

vector<int> maiorconjunto(vector<vector<int>> &G) {
    vector<int> solucao, melhorSolucao;
    maiorconjunto(0, solucao, melhorSolucao, G);

    return melhorSolucao;
}
