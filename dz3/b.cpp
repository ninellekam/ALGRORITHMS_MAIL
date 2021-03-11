#include <iostream> 
#include <vector>
using namespace std; 

vector<vector<int> > matrix;

void    sorting(vector<pair<int, int> > &vec, int N) {
    for(int i = 1; i < N; i++)     
	    for(int j = i; j > 0 && vec[j-1] > vec[j]; j--) 
			swap(vec[j-1], vec[j]);        
}

void    load_matrix(int N, int M) {
	for(int i = 0; i < N; ++i)
		{
			matrix.push_back(vector<int> (M));
			for(int j = 0; j < M; ++j)
				cin >> matrix[i][j];
        }
}

void    sort_matrix(int N, int M) {
    int min = (1u << 31) - 1;
    int min_i = 0, min_j = 0;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) 
            if (matrix[i][j] < min) {
                min = matrix[i][j];
                min_i = i;
                min_j = j;
            }
    }
    vector<pair<int, int> > m_i(N);
    vector<pair<int, int> > m_j(M);

    for(int i = 0; i < N; ++i)
		m_i[i] = {matrix[i][min_j], i};

	for(int j = 0; j < M; ++j)
		m_j[j] = {matrix[min_i][j], j};

		sorting(m_j, M);
		sorting(m_i, N);

	for(int i = 0; i < N; ++i) {
		for(int j = 0; j < M; ++j)
			cout << matrix[m_i[i].second][m_j[j].second] << ' ';
		cout << '\n';
	}
}

int main() { 
    int N, M;
    cin >> N >> M;
    load_matrix(N, M);
    sort_matrix(N, M);
    return 0; 
} 

