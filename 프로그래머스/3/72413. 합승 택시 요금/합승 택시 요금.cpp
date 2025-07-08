#include <string>
#include <vector>
#include <unordered_map>
#include <climits>

using namespace std;

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    int answer = INT_MAX;

    // 무한대 초기화
    vector<vector<int>> path(n + 1, vector<int>(n + 1, INT_MAX));
    for (int i = 1; i <= n; ++i)
    {
        path[i][i] = 0;
    }
    // 요금 반영
    for (auto ele : fares)
    {
        path[ele[0]][ele[1]] = ele[2];
        path[ele[1]][ele[0]] = ele[2];
    }

    // 플로이드 워셜, 경유했을 때 더 짧은 경로가 있는지 검사
    for (int k = 1; k <= n; ++k)
    {
        for (int i = 1; i <= n; ++i)
        {
            for (int j = 1; j <= n; ++j)
            {
                if (INT_MAX != path[i][k] && INT_MAX != path[k][j])
                {
                    path[i][j] = min(path[i][j], path[i][k] + path[k][j]);
                }
            }
        }
    }

    for (int i = 1; i <= n; ++i)
    {
        if (INT_MAX != path[s][i] && INT_MAX != path[i][a] && INT_MAX != path[i][b])
        {
            // s->i, i->a, i->b 최소값 비용 계산
            answer = min(answer, path[s][i] + path[i][a] + path[i][b]);
        }
    }

    return answer;
}