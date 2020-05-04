#include <algorithm>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <vector>
#include <string>
#include <cmath>
#include <cstdlib>
#include <limits>

using std::vector;
using std::string;
using std::pair;
using std::min;

struct Point  
{  
    public: 
    int x, y;  
}; 

int compareX(const void* a, const void* b)  
{  
    Point *p1 = (Point *)a, *p2 = (Point *)b;  
    return (p1->x - p2->x);  
}  
  
int compareY(const void* a, const void* b)  
{  
    Point *p1 = (Point *)a, *p2 = (Point *)b;  
    return (p1->y - p2->y);  
}

double dist(Point p1, Point p2)  
{  
    return sqrt( (p1.x - p2.x)*(p1.x - p2.x) +  
                (p1.y - p2.y)*(p1.y - p2.y)  
            );  
}  
  
double bruteForce(Point P[], int n)  
{  
#if 1	
    double min = std::numeric_limits<double>::max(); 
    for (int i = 0; i < n; ++i)  
        for (int j = i+1; j < n; ++j)  
            if (dist(P[i], P[j]) < min)  
                min = dist(P[i], P[j]);  
    return min;
#else
    std::pair<int, int> XY(abs(P[1].x - P[0].x), abs(P[1].y - P[0].y));
    for (int i = 0 ; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            std::pair<int, int> Temp_XY(abs(P[i].x - P[j].x), abs(P[i].y - P[j].y));
	    XY = (Temp_XY.first + Temp_XY.second 
			< XY.first + XY.second) ? Temp_XY : XY;
	}
    }
    double Ret = static_cast<double>(XY.first * XY.first);
    Ret += static_cast<double>(XY.second * XY.second);
    return sqrt(Ret);
#endif    
}  
  
double min(double x, double y)  
{  
    return (x < y)? x : y;  
}  

#if 0
double stripClosest(Point strip[], int size, double d)  
{
    double min = d; // Initialize the minimum distance as d  
  
    qsort(strip, size, sizeof(Point), compareY);  
    for (int i = 0; i < size; ++i)  
        for (int j = i+1; j < size && (strip[j].y - strip[i].y) < min; ++j)  
            if (dist(strip[i],strip[j]) < min)  
                min = dist(strip[i], strip[j]);  
  
    return min;
}  
#else
double stripClosest(vector<Point> &Strip,  double d) {
	double Min = d;
#if 1	
	std::sort(Strip.begin(), Strip.end(), [](const Point& A, const Point& B) {
			return (A.y < B.y);
	});
#endif
	for (int i = 0; i < Strip.size(); i++) {
		for (int j = i + 1; j < Strip.size() && abs(Strip[i].y - Strip[j].y) < Min; ++j) {
			double Temp_Dist = dist(Strip[i], Strip[j]);
			Min = (Temp_Dist < Min) ? Temp_Dist : Min;
		}
	}
	return Min;
}
#endif
  
double closestUtil(Point P[], int n)  
{  
    // If there are 2 or 3 points, then use brute force  
    if (n <= 3)  
        return bruteForce(P, n);  
  
    // Find the middle point  
    int mid = n/2;  
    Point midPoint = P[mid];  
  
    double dl = closestUtil(P, mid);  
    double dr = closestUtil(P + mid, n - mid);  
  
    double d = min(dl, dr);  
#if 0    
    Point strip[11];  
    int j = 0;  
    for (int i = 0; i < n; i++)  
        if (abs(P[i].x - midPoint.x) < d)  
            strip[j] = P[i], j++;  
   return min(d, stripClosest(strip, j, d) );  
#else
	vector<Point> Strip;
	for (int i = 0; i < n; i++) {
		if (abs(P[i].x - midPoint.x) < d)
			Strip.push_back(P[i]);
	}
	double Temp_Dist = stripClosest(Strip, d);
	return min(d, Temp_Dist);
#endif
}  

double minimal_distance(Point P[], int n)  
{  
#if 0
    qsort(P, n, sizeof(Point), compareX);  
#else
	vector<Point> Temp_P(n);
	std::copy(P, P + n, Temp_P.begin());

	sort(Temp_P.begin(), Temp_P.end(), [](const Point& A, const Point& B) {
		return (A.x < B.x);
	});
	for (int i = 0; i < n; i++) {
		P[i] = Temp_P[i];
	}
#endif
    return closestUtil(P, n);  
} 



int main() {
#if 0
	size_t n;
	std::cin >> n;
	Point P[n]; { 6, 3 } { 14, 0 } { 8, 12 }
	for (size_t i = 0; i < n; i++) {
		std::cin >> P[i].x >> P[i].y;
	}
	std::cout << std::fixed;
	std::cout << std::setprecision(9) << minimal_distance(P, n) << "\n";
#else
	//Point P[] = { {4, 4}, {-2, -2}, {-3, -4}, {-1, 3}, {2, 3} , {-4, 0}, {1, 1}, {-1, -1}, {3, -1}, {-4, 2}, {-2, 4} };
	//Point P[] = {{ 6 ,3 }, { 14, 0 } ,{ 8, 12 }};
	Point P[] = { { 12 ,2 } , { 10 ,14 } , { 0 ,13 } , { 9 ,0 } };
	int n = sizeof(P)/sizeof(P[0]);
	std::cout << std::fixed;
	std::cout << std::setprecision(9) << minimal_distance(P, n) << "\n";
#
#endif
}
