#include <inttypes.h>
#include <stdint.h>
#include <stdio.h>

int main() {
	int test_cases;
	scanf("%d", &test_cases);
	
	for (int t = 0; t < test_cases; ++t) {
		uint64_t third, third_last, sum;
		scanf("%" SCNu64 " %" SCNu64 " %" SCNu64, &third, &third_last, &sum);
		
		if (third == third_last) {
			// r == 1
			
			uint64_t n = sum / third;
			
			printf("%" PRIu64 "\n", n);
			for (uint64_t i = 0; i < n - 1; ++i) {
				printf("%" PRIu64 " ", third);
			}
			printf("%" PRIu64 "\n", third);
			
		} else {
			uint64_t r = 2;
			while (third % (r * r) != 0 || (third_last * (r * r * r)) + sum != (third / (r * r)) + (sum * r)) {
				++r;
			}
			
			uint64_t first = third / (r * r);
			uint64_t last = third_last * (r * r);
			
			uint64_t n = 1;
			for (uint64_t i_th = last; i_th != first; i_th /= r) {
				++n;
			}
			
			printf("%" PRIu64 "\n", n);
			for (uint64_t i_th = first; i_th != last; i_th *= r) {
				printf("%" PRIu64 " ", i_th);
			}
			printf("%" PRIu64 "\n", last);
		}
		
	}
	
	return 0;
}