#include <bits/stdc++.h>

using namespace std;

int getArea(pair<int, int> LL, pair<int, int> UR) {
    return (UR.first - LL.first) * (UR.second - LL.second);
}

int getAreaofIntersection(pair<int, int> BLL,
                          pair<int, int> BUR,
                          pair<int, int> TLL,
                          pair<int, int> TUR) {
    
    pair <int, int> LL =
        make_pair(
                  max(BLL.first, TLL.first),
                  max(BLL.second, TLL.second));
    pair <int, int> UR =
        make_pair(
                  min(BUR.first, TUR.first),
                  min(BUR.second, TUR.second));
    
    // no intersection
    if (LL.first > UR.first || LL.second > UR.second)
        return 0;
    
    return getArea(LL, UR);
}

int main() {
    pair<int, int> points[6] = {}; // B1LL, B1UR, B2LL, B2UR, TLL, TUR
    int x, y;
    for (int i = 0; i < 6; i++) {
        cin >> x >> y;
        points[i] = make_pair(x, y);
    }
    
    int B1 = getArea(points[0], points[1]);
    int B2 = getArea(points[2], points[3]);
    
    int R1 = getAreaofIntersection(points[0], points[1], points[4], points[5]);
    int R2 = getAreaofIntersection(points[4], points[5], points[2], points[3]);

    cout << (B1 - R1) + (B2 - R2);
    
    return 0;

}
