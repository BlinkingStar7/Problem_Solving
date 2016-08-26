#include <vector>
#include <string>
using namespace std;

class Elections {
	public:
		int visit(vector<string> l) {
			int ans = 0, numerator=2, denominator=1;

			for (int i=0; i<l.size(); ++i) {
				string &cur = l[i];
				int num = 0;
				for (int j=0; j<cur.size(); ++j)
					if (cur[j] == '1') ++num;
				if (num * denominator < numerator * cur.size()) {
					ans = i;
					denominator = cur.size();
					numerator = num;
				}
			}
			return ans;
		}
}



