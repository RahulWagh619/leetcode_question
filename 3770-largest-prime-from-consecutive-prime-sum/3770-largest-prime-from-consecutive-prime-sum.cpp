class Solution {
public:
    // Generate all primes up to n using Sieve of Eratosthenes
    vector<int> sieveOfEratosthenes(int n) {
        if (n < 2) return {};
        
        vector<bool> isPrime(n + 1, true);
        isPrime[0] = isPrime[1] = false;
        
        for (int i = 2; i * i <= n; i++) {
            if (isPrime[i]) {
                for (int j = i * i; j <= n; j += i) {
                    isPrime[j] = false;
                }
            }
        }
        
        vector<int> primes;
        for (int i = 2; i <= n; i++) {
            if (isPrime[i]) {
                primes.push_back(i);
            }
        }
        return primes;
    }

    // Check if a number is prime (for sums that might exceed n)
    bool checkPrime(int num) {
        if (num < 2) return false;
        if (num == 2 || num == 3) return true; 
        if (num % 2 == 0 || num % 3 == 0) return false;
        
        for (int i = 5; i * i <= num; i += 2) {
            if (num % i == 0) {
                return false; 
            }
        }
        return true; 
    }

    int largestPrime(int n) {
        if (n == 1) {
            return 0;
        }
        
        // Generate primes up to n using sieve
        vector<int> val = sieveOfEratosthenes(n);
        
        long long sum = 0;
        int i = 0;
        long long ans = 0;
        
        // Iterate through primes and track largest prime sum
        while (sum <= n && i < val.size()) {
            sum += val[i];
            
            if (sum > n) {
                sum -= val[i];
                break;
            }
            
            if (checkPrime(sum)) {
                ans = sum;
            }
            
            i++;
        }
        
        return ans;
    }
};
