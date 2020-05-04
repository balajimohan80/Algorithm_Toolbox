#include <algorithm>
#include <iostream>
#include <climits>
#include <vector>

using std::vector;

struct Segment {
  int start, end;
};

vector<int> optimal_points(vector<Segment> &segments) {
	vector<int> points;
	std::sort(segments.begin(), segments.end(), [](const Segment& A, const Segment& B) {return A.end < B.end; });
	points.push_back(segments[0].end);

	for (int i = 1; i < segments.size(); i++) {
		if (points.back() < segments[i].start) {
			points.push_back(segments[i].end);
		}
	}

#if 0
	for (size_t i = 0; i < segments.size(); ++i) {
		points.push_back(segments[i].start);
		points.push_back(segments[i].end);
	}
#endif
	return points;;
}

int main() {
  int n;
  std::cin >> n;
  vector<Segment> segments(n);
  for (size_t i = 0; i < segments.size(); ++i) {
    std::cin >> segments[i].start >> segments[i].end;
  }
  vector<int> points = optimal_points(segments);
  std::cout << points.size() << "\n";
  for (size_t i = 0; i < points.size(); ++i) {
    std::cout << points[i] << " ";
  }
}
