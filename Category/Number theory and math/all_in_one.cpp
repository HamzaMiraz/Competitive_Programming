#include<bits/stdc++.h>
using namespace std;

const int N = 1e6 + 9;
int spf[N]; // smallest prime factors
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  for (int i = 2; i < N; i++) {
    spf[i] = i;
  }
  for (int i = 2; i < N; i++) {
    if (spf[i] == i) {
      for (int j = i; j < N; j += i) {
        spf[j] = min(spf[j], i);
      }
    }
  }
    int x; cin >> x;
    cout << spf[x] << ' ';

    int gpf = 0;
    int distinct_prime_factors = 0;
    int total_prime_factors = 0;
    int number_of_divisors = 1;
    long long sum_of_divisors = 1;
    while (x > 1) {
      int p = spf[x]; // smallest prime factor of x
      gpf = max(gpf, p);
      distinct_prime_factors++;
      int power_of_k = 0;
      int prime_power = 1;

      while (x % p == 0) {
        ++power_of_k;
        total_prime_factors++;
        prime_power *= p;
        x /= p;
      }

      number_of_divisors *= (power_of_k + 1);
      sum_of_divisors *= (1LL * prime_power * p - 1) / (p - 1);
    }

    cout << gpf << ' ';

    cout << distinct_prime_factors << ' ';

    cout << total_prime_factors << ' ';

    cout << number_of_divisors << ' ';

    cout << sum_of_divisors << '\n';

  return 0;
}