#include <iostream>
#include <vector>
#include <stdlib.h>

using std::cin;
using std::cout;
using std::vector;
//using std::max;

int compute_min_refills(int dist, int tank, vector<int>& stops) {
	int Min_No_Refills = 0;
	int Curr_G_Station = 0;
	int Last_G_Station = 0;
	int Index = 0;
	//if (tank < stops[0]) return -1;
	while (Index < stops.size() && stops[Index] <= dist) {
		Last_G_Station = Curr_G_Station;
		while (Index < stops.size() && abs(stops[Index] - Last_G_Station) <= tank) {
			Curr_G_Station = stops[Index];
			Index++;
		}
		
		if (Last_G_Station == Curr_G_Station) {
			return -1;
		}

		if (Index < stops.size()) {
			++Min_No_Refills;
			//std::cout << Min_No_Refills << ": " << Curr_G_Station << std::endl;
		}
	
	}

	if (abs(Last_G_Station - dist) > tank) {
		//std::cout << Min_No_Refills << ": " << Curr_G_Station << std::endl;
		return abs(Curr_G_Station - dist) <= tank ? ++Min_No_Refills : -1;
	}
		
	return Min_No_Refills;
}


int main() {
    int d = 0;
    cin >> d;
    int m = 0;
    cin >> m;
    int n = 0;
    cin >> n;

    vector<int> stops(n);
    for (size_t i = 0; i < n; ++i)
        cin >> stops.at(i);

    cout << compute_min_refills(d, m, stops) << "\n";

    return 0;
}
