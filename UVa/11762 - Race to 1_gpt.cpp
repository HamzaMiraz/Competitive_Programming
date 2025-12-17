#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
#include <algorithm>
#include <map>

using namespace std;

// N এর সর্বোচ্চ সম্ভাব্য মান
const int MAX_N = 1000000;

// Sieve of Eratosthenes ব্যবহার করে মৌলিক সংখ্যা সংরক্ষণ করার জন্য ভেক্টর
vector<int> primes;

// মেমোয়াইজেশন টেবিল (DP table)
// double মান সংরক্ষণের জন্য map ব্যবহার করা হচ্ছে, কারণ N এর মান 10^6 পর্যন্ত হতে পারে।
map<int, double> memo;

/**
 * @brief Sieve of Eratosthenes ব্যবহার করে MAX_N পর্যন্ত মৌলিক সংখ্যা তৈরি করে।
 */
void sieve() {
    vector<bool> is_prime(MAX_N + 1, true);
    is_prime[0] = is_prime[1] = false;

    for (int p = 2; p * p <= MAX_N; p++) {
        if (is_prime[p]) {
            for (int i = p * p; i <= MAX_N; i += p)
                is_prime[i] = false;
        }
    }

    for (int p = 2; p <= MAX_N; p++) {
        if (is_prime[p]) {
            primes.push_back(p);
        }
    }
}
// 

/**
 * @brief N থেকে 1 এ পৌঁছানোর প্রত্যাশিত ধাপ সংখ্যা E(N) নির্ণয় করে।
 * E(N) = (k/m) + (1/m) * sum( E(N/P) ) যেখানে P হলো N এর মৌলিক উৎপাদক।
 * @param n বর্তমান সংখ্যা।
 * @return প্রত্যাশিত ধাপ সংখ্যা।
 */
double exp(int n) {
    // বেস কেস: 1 এ পৌঁছানো মানে 0 অতিরিক্ত ধাপ
    if (n == 1) {
        return 0.0;
    }
    
    // মেমোয়াইজেশন চেক
    if (memo.count(n)) {
        return memo[n];
    }

    // 1. N এর চেয়ে ছোট বা সমান সকল মৌলিক সংখ্যা P গণনা (k)
    // primes ভেক্টরটি ইতোমধ্যে সাজানো আছে, তাই upper_bound ব্যবহার করা যেতে পারে
    // যা n এর চেয়ে বড় প্রথম মৌলিক সংখ্যার দিকে নির্দেশ করে।
    auto it = upper_bound(primes.begin(), primes.end(), n);
    
    // k = N এর চেয়ে ছোট বা সমান মৌলিক সংখ্যার মোট সংখ্যা।
    int k = distance(primes.begin(), it); 

    // 2. N এর স্বতন্ত্র মৌলিক উৎপাদকগুলি খুঁজে বের করা (m)
    // এবং E(N/P) এর যোগফল (sum_E_N_over_P) গণনা
    
    double sum_E_N_over_P = 0.0;
    vector<int> prime_factors; // N এর মৌলিক উৎপাদকগুলি সংরক্ষণের জন্য

    // N এর উৎপাদকগুলি primes ভেক্টরের মধ্যে খুঁজতে হবে।
    for (int p : primes) {
        if (p > n) break; // n এর চেয়ে বড় মৌলিক সংখ্যা দেখার প্রয়োজন নেই

        if (n % p == 0) {
            prime_factors.push_back(p);
            // p হলো N এর একটি মৌলিক উৎপাদক, তাই E(N/p) গণনা করতে হবে।
            sum_E_N_over_P += exp(n / p); 
        }
    }

    // m = N এর স্বতন্ত্র মৌলিক উৎপাদকের সংখ্যা
    int m = prime_factors.size(); 

    // যদি N এর কোনো মৌলিক উৎপাদক না থাকে (যা N>1 এর জন্য শুধুমাত্র মৌলিক সংখ্যা N এর ক্ষেত্রেই সম্ভব),
    // তখন m=1 (কারণ N নিজেই একটি মৌলিক সংখ্যা P)।
    if (m == 0 && n > 1) { 
        // এই ক্ষেত্রে, n নিজেই একটি মৌলিক সংখ্যা p। 
        // এই ক্ষেত্রে n < sqrt(MAX_N) এর চেয়ে বড় হবে।
        m = 1; 
        sum_E_N_over_P = exp(n / n); // E(1) = 0
    }


    // 3. প্রত্যাশিত ধাপ সংখ্যার চূড়ান্ত সমীকরণ প্রয়োগ:
    // E(N) = (k/m) + (1/m) * sum( E(N/P) )
    double result = (double)k / m + sum_E_N_over_P / m;

    // মেমোয়াইজেশন: ফলাফল সংরক্ষণ করা
    return memo[n] = result;
}


int main() {
    // দ্রুত I/O এর জন্য
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    sieve(); // প্রাইম সংখ্যা তৈরি করা

    int T;
    cin >> T;
    
    // E(1) এর মান সেট করা (যদিও exp ফাংশন এটি পরিচালনা করে)
    memo[1] = 0.0;

    for (int t = 1; t <= T; ++t) {
        int N;
        cin >> N;

        // exp ফাংশন কল করা
        double expected_steps = exp(N);

        // আউটপুট প্রিন্ট করা
        cout << "Case " << t << ": " << fixed << setprecision(10) << expected_steps << "\n";
    }

    return 0;
}