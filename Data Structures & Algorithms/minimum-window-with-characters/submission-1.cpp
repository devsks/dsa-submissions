class Solution {
   public:
    string doExists(string s, vector<int> fq, int window) {
        int cur_size = 0, i = 0;
        while (i < window && i < s.length()) {
            fq[s[i]]--;
            ++i;
        }
        do {
            bool allMatch = true;
            for (int j = 0; j < 256; ++j) {
                if (fq[j] > 0) {
                    allMatch = false;
                    break;
                }
            }
            if (allMatch) {
                return s.substr(i-window,window);
            }

            fq[s[i - window]]++;

            if (i < s.length()) {
                fq[s[i]]--;
            }

            ++i;
        } while (i <= s.length());
        return "";
    }
    string minWindow(string s, string t) {
        int low = t.length(), high = s.length();
        string answer;
        vector<int> fq_of_t(256);
        for (char c : t) {
            fq_of_t[c]++;
        }
        while (low <= high) {
            int mid = (low + high) >> 1;
            string res = doExists(s, fq_of_t, mid);
          //  cout<<mid<<" ";
            if (res.length()==mid) {
                answer = res;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return answer;
    }
};
