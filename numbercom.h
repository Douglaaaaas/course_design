static int k;
class numbercom {
	int max;
	char number[7][5];
	int score;
	int x;
	int y;
	int combinednums;
public:
	int getcombinednums();
	char getnum(int line, int queue);
	numbercom() {
		max = 1;
		for (int i = 0; i < 5; i++) {
			for (int j = 0; j < 5; j++) {
				number[i][j] = ' ';
			}
		}
		combinednums = 0;
	}
	
	void cleanall();
};
int numbercom::getcombinednums() {
	return combinednums;
}
void numbercom::changenum(int queue) {
int j = 6;
while (j > 0 && number[j][queue] != ' ') {
	j--;
}
number[j][queue] = '0' + x;
bool Combine = false;
int k, m, n;
bool combine = false;
while (1) {
	while (1) {
		for (k = 6; k >= 0; k--) {
			if (number[k][0] ==number[k][1] && number[k][1] == number[k][2] && number[k][2] == number[k][3] && number[k][3] == number[k][4] && number[k][0] != ' ') {
				combinednums++;
				combine = true;
				Combine = true;
				number[k][4] = number[k][4] + 4;
				score = score + (number[k][4] - '0');
				for (m = k - 1; m > 0; m--) {
					for (n = 3; n >= 0; n--) {
						number[m + 1][n] = number[m][n];
						number[0][n] = ' ';
					}
				}
			}
		}
		if (combine == false) break;
		combine = false;
	}
	while (1) {
		for (k = 4; k >= 0; k--) {
			for (int m = 0; m <= 3; m++) {
				if (number[m][k] == number[m + 1][k] && number[m + 1][k] == number[m + 2][k] && number[m + 2][k] == number[m + 3][k] && number[m + 3][k] == number[m + 4][k] && number[m + 4][k] != ' ') {
					combinednums++;
					combine = true;
					Combine = true;
					number[m + 4][k] = number[m + 4][k] + 4;
					score = score + (number[m + 4][k] - '0');
					for (n = m + 3; n >= m; n--) {
						number[n][k] = ' ';
					}
				}
			}
		}
		if (combine == false) break;
		combine = false;
	}
	int p;
	while (1) {
		for (k = 6; k >= 0; k--) {
			for (p = 0; p <= 1; p++) {
				if (number[k][p] == number[k][p + 1] && number[k][p + 1] == number[k][p + 2] && number[k][p + 2] == number[k][p + 3] && number[k][p] != ' ') {
					combinednums++;
					combine = true;
					Combine = true;
					number[k][p + 3] = number[k][p + 3] + 3;
					score = score + (number[k][p + 3] - '0');
					for (m = k - 1; m > 0; m--) {
						for (n = p + 2; n >= p; n--) {
							number[m + 1][n] = number[m][n];
							number[0][n] = ' ';
						}
					}
				}
			}
		}
		if (combine == false) break;
		combine = false;
	}
	while (1) {
		for (k = 4; k >= 0; k--) {
			for (p = 0; p <= 4; p++) {
				if (number[p][k] == number[p + 1][k] && number[p + 1][k] == number[p + 2][k] && number[p + 2][k] == number[p + 3][k] && number[p + 3][k] != ' ') {
					combinednums++;
					combine = true;
					Combine = true;
					number[p + 3][k] = number[p + 3][k] + 3;
					score = score + (number[p + 3][k] - '0');
					for (n = p + 2; n >= p; n--) {
						number[n][k] = ' ';
					}
				}
			}
		}
		if (combine == false) break;
		combine = false;
	}
	while (1) {
		for (k = 6; k >= 0; k--) {
			for (p = 0; p <= 2; p++) {
				if (number[k][p] == number[k][p + 1] && number[k][p + 1] == number[k][p + 2] && number[k][p] != ' ') {
					combinednums++;
					combine = true;
					Combine = true;
					number[k][p + 2] = number[k][p + 2] + 2;
					score = score + (number[k][p + 2] - '0');
					for (m = k - 1; m > 0; m--) {
						for (n = p + 1; n >= p; n--) {
							number[m + 1][n] = number[m][n];
							number[0][n] = ' ';
						}
					}
				}
			}
		}
		if (combine == false) break;
		combine = false;
	}
	while (1) {
		for (k = 4; k >= 0; k--) {
			for (p = 0; p <= 5; p++) {
				if (number[p][k] == number[p + 1][k] && number[p + 1][k] == number[p + 2][k] && number[p + 2][k] != ' ') {
					combinednums++;
					combine = true;
					Combine = true;
					number[p + 2][k] = number[p + 2][k] + 2;
					score = score + (number[p + 2][k] - '0');
					for (n = p + 1; n >= p; n--) {
						number[n][k] = ' ';
					}
				}
			}
		}
		if (combine == false) break;
		combine = false;
	}
	while (1) {
		for (k = 6; k >= 0; k--) {
			for (p = 0; p <= 3; p++) {
				if (number[k][p] == number[k][p + 1] && number[k][p] != ' ') {
					combinednums++;
					combine = true;
					Combine = true;
					number[k][p + 1] = number[k][p + 1] + 1;
					score = score + (number[k][p + 1] - '0');
					for (m = k - 1; m > 0; m--) {
						for (n = p; n >= p; n--) {
							number[m + 1][n] = number[m][n];
							number[0][n] = ' ';
						}
					}
				}
			}
		}
		if (combine == false) break;
		combine = false;
	}
	while (1) {
		for (k = 4; k >= 0; k--) {
			for (p = 0; p <= 6; p++) {
				if (number[p][k] == number[p + 1][k] && number[p + 1][k] != ' ') {
					combinednums++;
					combine = true;
					Combine = true;
					number[p + 1][k] = number[p + 1][k] + 1;
					score = score + (number[p + 1][k] - '0');
					for (n = p; n >= p; n--) {
						number[n][k] = ' ';
					}
				}
			}
		}
		if (combine == false) break;
		combine = false;
	}
	if (Combine == false) break;
	Combine = false;
}
int h,i,j;
for (j = 0; j < 7; j++) {
	for (i = 0; i < 5; i++) {
		if (number[j][i] == '9') {
			for (h = j; h > 0; h--) {
				number[h][i] = number[h - 1][i];
			}
			number[0][i] = ' ';
		}
	}
}
char temp = number[0][0];
for (i = 0; i < 7; i++) {
	for (j = 0; j < 5; j++) {
		if (number[i][j] > temp) temp = number[i][j];
	}
}
if (temp == ' ') max = 1;
else max = temp - '0';
}