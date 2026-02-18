
class Solution {
public:
    const long long MOD = 1000000007;

    int nthMagicalNumber(int n, int a, int b) {
        
        long long lcmVal = lcm(a, b);

        long long low = 1;
        long long high = 1e18;

        while (low <= high) {
            
            long long mid = low + (high - low) / 2;

            long long count = mid / a + mid / b - mid / lcmVal;

            if (count < n)
                low = mid + 1;
            else
                high = mid - 1;
        }

        return low % MOD;
    }

private:
    long long gcd(long long a, long long b) {
        while (b != 0) {
            long long temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }

    long long lcm(long long a, long long b) {
        return (a / gcd(a, b)) * b;  
    }
};
