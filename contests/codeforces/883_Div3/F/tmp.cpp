#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main() {
	int test_cases;
	cin >> test_cases;
	for (int test_case = 0; test_case < test_cases; test_case++) {
		int n;
		cin >> n;
		vector<int> v(n);
		map<int, int> m;
		for (int i = 0; i < n; i++) {
			cin >> v[i];
			m[v[i]]++;
		}
		vector<int> elements_to_erase;
		int ans;
		for (int i = 0; i < 5; i++) {
			if (v.size() - elements_to_erase.size() == 1) {
				cout << "! " << ans << endl;
				break;
			}
			cout << "- " << elements_to_erase.size() << " ";
			for (int j = 0; j < elements_to_erase.size(); j++) {
				cout << elements_to_erase[j] << " ";
			}
			cout << endl;
			vector<int> new_v;
			map<int, int> new_m;
			for (int j = 0; j < v.size() - elements_to_erase.size(); j++) {
				int x;
				cin >> x;
				new_v.push_back(x);
				new_m[x]++;
			}
			elements_to_erase.clear();
			int tm = -1;
			for (auto& k : new_m) {
				if (k.second > m[k.first]) {
					tm = k.first;
				}
			}
			if (tm != -1) {
				for (int j = 0; j < new_v.size(); j++) {
					if (new_v[j] != tm)
						elements_to_erase.push_back(j + 1);
					else
						ans = j + 1;
				}
				m.clear();
				m[tm] = new_m[tm];
			}
			v = new_v;
		}
	}
	return 0;
}
