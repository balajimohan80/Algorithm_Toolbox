#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;
#if 0
void Binary_Search(const vector<int>& Augumented_Array, vector<int>& starts, vector<int>& ends, int Compare, int& cnt) {
	int Left = 0;
	int Right = Augumented_Array.size() - 1;
	while (Left <= Right) {
		int Mid = Left + ((Right - Left) / 2);
		if (Compare >= starts[Augumented_Array[Mid]] && Compare <= ends[Augumented_Array[Mid]] ) {
			int Index = Mid;
			while (Index < starts.size() && (Compare >= starts[Augumented_Array[Index]] && 
				Compare <= ends[Augumented_Array[Index]])) {
				++cnt;
				++Index;
			}
			Index = Mid - 1;
			while (Index > -1 && (Compare >= starts[Augumented_Array[Index]] &&
				Compare <= ends[Augumented_Array[Index]])) {
				++cnt;
				--Index;
			}
			break;
		}
		if (Compare <= ends[Augumented_Array[Mid]]) Right = Mid - 1;
		else Left = Mid + 1;
	}
}

vector<int> fast_count_segments(vector<int>& starts, vector<int>& ends, vector<int> points) {
	vector<int> cnt(points.size(),0);
	vector<int> Augumented_Array(starts.size()+);
	for (int i = 0; i < starts.size(); i++) {
		Augumented_Array[i] = i;
	}
	
	std::sort(Augumented_Array.begin(), Augumented_Array.end(), [starts, ends](const int a, const int b) {
		if (ends[a] < ends[b]) {
			return true;
		}
		else if (ends[a] == ends[b]) {
			if (starts[a] > starts[b]) {
				return true;
			}
			return false;
		}
		return false;
		//return (ends[a] < ends[b]) ? true : (ends[a] == ends[b]) ? (starts[a] > starts[b]) ? true : false : false;
	});
  
	for (int i = 0; i < points.size(); i++) {
	#if 0
			for (int j = 0; j < starts.size(); j++) {
				if (starts[Augumented_Array[j]] > points[i]) break;
				cnt[i] += starts[Augumented_Array[j]] <= points[i] && 
					points[i] <= ends[Augumented_Array[j]];
			}
#else	
			Binary_Search(Augumented_Array, starts, ends, points[i], cnt[i]);
#endif
	}
	return cnt;
}
#endif

vector<int> fast_count_segments(vector<int>& starts, vector<int>& ends, vector<int> points) {
	std::sort(starts.begin(), starts.end());
	std::sort(ends.begin(), ends.end());
	vector<int> Ret(points.size());

	for (int i = 0; i < points.size(); i++) {
		std::vector<int>::iterator Start_It = std::lower_bound(starts.begin(), starts.end(), points[i]);
		int Start_Count; 
		if (Start_It == starts.end()) Start_Count = starts.size();
		else {
			Start_Count = std::distance(starts.begin(), Start_It);
			while (Start_It != starts.end() && *Start_It == points[i]) {
			       	++Start_Count;
				++Start_It;
			}
		}

		std::vector<int>::iterator End_It = std::lower_bound(ends.begin(), ends.end(), points[i]);
		int End_Count;
		if (End_It == ends.end()) End_Count = ends.size();
		else {
			End_Count = std::distance(ends.begin(), End_It);
			//if (*End_It == points[i]) --End_Count;
		}
		Ret[i] = Start_Count - End_Count;
 	}

	return Ret;
}




vector<int> naive_count_segments(vector<int> starts, vector<int> ends, vector<int> points) {
  vector<int> cnt(points.size());
  for (size_t i = 0; i < points.size(); i++) {
    for (size_t j = 0; j < starts.size(); j++) {
      cnt[i] += starts[j] <= points[i] && points[i] <= ends[j];
    }
  }
  return cnt;
}

int main() {
  int n, m;
  std::cin >> n >> m;
  vector<int> starts(n), ends(n);
  for (size_t i = 0; i < starts.size(); i++) {
    std::cin >> starts[i] >> ends[i];
  }
  vector<int> points(m);
  for (size_t i = 0; i < points.size(); i++) {
    std::cin >> points[i];
  }
  
  //use fast_count_segments
  vector<int> cnt = fast_count_segments(starts, ends, points);
  for (size_t i = 0; i < cnt.size(); i++) {
    std::cout << cnt[i] << ' ';
  }
  return 0;
}
