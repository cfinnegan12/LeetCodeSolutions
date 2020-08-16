class ArrangingCoins
{
public:
	int arrangeCoins(int n) {
		int rows = 0;

		while (n - rows > 0) {
			rows++;
			n -= rows;
		}

		return rows;
	}
};

