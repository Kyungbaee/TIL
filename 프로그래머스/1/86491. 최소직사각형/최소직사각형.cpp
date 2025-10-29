#include <string>
#include <vector>

using namespace std;

int maxWidth, maxHeight;

int solution(vector<vector<int>> sizes) {
    for(vector<int> size : sizes){
        maxWidth = max(maxWidth, max(size[0], size[1]));
        maxHeight = max(maxHeight, min(size[0], size[1]));
    }
    return maxWidth * maxHeight;
}