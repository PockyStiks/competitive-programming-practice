#include <iostream>
#include <limits>
#include <string>
#include <vector>
using namespace std;

float inf = numeric_limits<float>::infinity();

float floydWarshallSum(vector<vector<float>> dist) {
    int V = dist.size(); 
    float total = 0;
 
    for (int k = 0; k < V; k++) {
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                if (dist[i][k] != inf && dist[k][j] != inf)
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }

    for (int i = 0; i < V; i++) {
        for (int j = i + 1; j < V; j++) {
            if (dist[i][j] != inf)
                total += dist[i][j];
        }
    }

    return total;
}

int main() {
    vector<vector<float>> dist(45, vector<float>(45, inf));
    int s = dist.size();

    for (int i = 0; i < s; i++) {
        dist[i][i] = 0;
    }

    for (int i = 0; i < 85; i++) {
        string a, b, c;
        cin >> a >> b >> c;

        a = a.substr(0, a.size() - 1);
        b = b.substr(0, b.size() - 1);
        dist[stoi(a) - 1][stoi(b) - 1] = stof(c);
        dist[stoi(b) - 1][stoi(a) - 1] = stof(c);
    }
    
    float smallest = inf;
    vector<int> ans;
    
    for (int i = 0; i < s; i++) {
        for (int j = i + 1; j < s; j++) {
            float old1 = dist[i][j];
            dist[i][j] = 0;
            dist[j][i] = 0;
            
            for (int k = i; k < s; k++) {
                int start_l = (k == i) ? j + 1 : k + 1;
                for (int l = start_l; l < s; l++) {
                    float old2 = dist[k][l];
                    dist[k][l] = 0;
                    dist[l][k] = 0;
                    float w = floydWarshallSum(dist);

                    if (w < smallest) {
                        smallest = w;
                        ans = {i, j, k, l};
                    }

                    dist[k][l] = old2;
                    dist[l][k] = old2;
                }
            }
            dist[i][j] = old1;
            dist[j][i] = old1;
        }
    }

    for (int i : ans) {
        cout << i + 1 << " ";
    }
}
