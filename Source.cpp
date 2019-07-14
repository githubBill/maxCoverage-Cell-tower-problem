#include <iostream>
#include <utility>
#include <vector>
#include <array>
#include <stdio.h>

using namespace std;

pair <int, vector<int> > solve(vector<int> inArr) {

	int n = inArr.size();
	vector<int> dp(n+1, 0);    // initialize with all zeros (n+1) elements
	dp[0] = 0;
	dp[1] = inArr[0];		  // population of first town

	for (int i = 2; i <= n; i++) {
		dp[i] = std::max(dp[i - 1], dp[i - 2] + inArr[i - 1]);  // inArr[i-1] because inArr zero indexed with n total elements
	}

	// maximum number of people that we can cover  is dp[n]
	// now construct the town vector : towns in which we place towers

	vector<int> OPT;    // optimal solution
	// using backtracking to construct OPT  since we now know all the values of dp[]
	

	for (int w = n ; w >= 1; w--) {
		if (w == 1)
			OPT.push_back(w);
		else if (dp[w] == (dp[w - 2] + inArr[w-1]) ) {    // if inArr was 1-indexed we would have inArr[w] instead 
			OPT.push_back(w);							  // town (w) has a cell tower
			w = w - 1;		// dont consider adjacent town as indicated by the rules (adjacent cities cant have both towers)
		}
		else if (dp[w] == dp[w - 1]) {
			// pass
			// means that the town we represent with number (w) does not have a cell tower
		}

	}

	return make_pair(dp[n], OPT);
}

int main(int argc, char* argv) {

	// dynamic programming implementation |  T(n)= theta(n) (linear time )
	// you are given a list of town populations ( 1 population number for each town)
	// you can build cell towers in any town as long as dont build towers in adjacent towns
	// max number of people you can cover ? how you cover them (in which towns do you build towers [..])

	/*Let Vk be the value of the kth cell tower,
		1 - indexed.
		Let OPT(k) be the maximum number of people
		we can cover using the first k cell towers.
		If C is a set of cell towers, let C(k) denote the
		number of people covered by the towers in C
		numbered at most k. Then it holds that OPT(0)=0,OPT(1)=V1 , OPT(k) = max(OPT(k-1),OPT(k-2)+Vk) .
	*/
	
	
	// data input  (example n=7 towns)
	vector<int> popV{ 14, 42, 13, 33, 30, 8, 24 }; // 1st town pop = 14 , 2nd town pop = 22 ....
	

	pair<int, vector<int> > res = solve(popV);

	cout << "maximum number of people that we can cover is: " << res.first << endl;
	cout << " we place towers in these towns" << endl;

	for (int i = 0; i < res.second.size(); i++) {

		cout << res.second[i] << " ";
	}

	return 0;

}











