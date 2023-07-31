#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int bigger(int a, int b) {
	if (a > b) {
		return a;
	}

	return b;
}

int main(void) {
	int arr[1001] = { 0, };
	int dp[1001];
	int N;

	scanf("%d", &N);

	for (int i = 0; i < N; dp[i++] = 1) {
		scanf("%d", &arr[i]);
	}

	for (int i = N - 1; i >= 0; i--) {
		for (int j = i + 1; j < N; j++) {
			if ((arr[j] < arr[i]) && (dp[i] < dp[j] + 1)) {
				dp[i] = dp[j] + 1;
			}
		}
	}
	
	int result = 0;
	for (int i = 0; i < N; i++) {
		result = bigger(result, dp[i]);
	}

	printf("%d", result);

	return 0;
}