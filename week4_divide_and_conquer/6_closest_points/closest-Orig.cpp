#include<iostream>
#include<algorithm>
#include<vector>
#include <iomanip>
#include <cmath>
#include <limits>

using namespace std;

struct Point {
	int x;
	int y;
};

double dist(Point p1, Point p2)
{
	return sqrt((p1.x - p2.x) * (p1.x - p2.x) +
		(p1.y - p2.y) * (p1.y - p2.y)
	);
}

double Brute_Force(vector<Point>& P, int Left, int Right) {
#if 1
	double min = std::numeric_limits<double>::max();
	for (int i = Left; i <= Right; ++i) {
		for (int j = i + 1; j <= Right; ++j) {
			double Temp = dist(P[i], P[j]);
			if (Temp < min)
				min = Temp;
		}
	}
	return min;
#else	
	std::pair<int, int> XY(abs(P[Left].x - P[Left+1].x), abs(P[Left].y - P[Left+1].y));
    for (int i = Left ; i <= Right; i++) {
        for (int j = i + 1; j <= Right; j++) {
            std::pair<int, int> Temp_XY(abs(P[i].x - P[j].x), abs(P[i].y - P[j].y));
	    XY = (Temp_XY.first + Temp_XY.second < XY.first + XY.second) ? Temp_XY : XY;
	}
    }
    double Ret = static_cast<double>(XY.first * XY.first);
    Ret += static_cast<double>(XY.second * XY.second);
    return sqrt(Ret);
#endif
}

double Closest_Channel(vector<Point>& Prune, double D) {
	double Min = D;
	std::sort(Prune.begin(), Prune.end(), [](const Point& A, const Point& B) {
			return (A.y < B.y);
	});
	for (int i = 0; i < Prune.size(); i++) {
		for (int j = i+1; j < Prune.size() && abs(Prune[i].y - Prune[j].y) < Min; j++) {
			double Temp_Dist = dist(Prune[i], Prune[j]);
			Min = (Temp_Dist < Min) ? Temp_Dist : Min;
		}
	}
	return Min;
}

double Minimal_Distance(vector<Point>& P, int Left, int Right) {
	if (Right - Left < 3) {
		return Brute_Force(P, Left, Right);
	}

	int Mid = ((Right - Left) / 2) + Left;
	double D1 = Minimal_Distance(P, Left, Mid-1);
	double D2 = Minimal_Distance(P, Mid, Right);
	double D = min(D1, D2);

	vector<Point> Prune_XY;
	for (int i = Left; i <= Right; i++) {
		if (abs(P[i].x - P[Mid].x) < D) {
			Prune_XY.push_back(P[i]);
		}
	}
	double Temp_Dist = Closest_Channel(Prune_XY, D);
	return min(D,Temp_Dist);
}

double Closest(vector<Point>& P) {
	sort(P.begin(), P.end(), [](const Point& A, const Point& B) {
		return (A.x < B.x);
		});
	return Minimal_Distance(P, 0, P.size() - 1);
}

int main() {
#if 1
	size_t n;
	std::cin >> n;
	vector<Point> P(n);
	for (size_t i = 0; i < n; i++) {
		std::cin >> P[i].x >> P[i].y;
	}
	std::cout << std::fixed;
	std::cout << std::setprecision(9) << Closest(P) << "\n";
#else
	vector<Point> P = { {4, 4}, {-2, -2}, {-3, -4}, {-1, 3}, {2, 3} , {-4, 0}, {1, 1}, {-1, -1}, {3, -1}, {-4, 2}, {-2, 4} };
	std::cout << Closest(P) << "\n"; 
#endif	
	return 0;
}
