// USACO 2019 December Contest, Gold -- Problem 1: Painting the Barn
//
// The barn is a 200x200 grid of unit cells; cell (i, j) is the square
// [i-1, i] x [j-1, j], so cells are indexed 1..SZ.
//
// A 2D difference array gives cnt[i][j], the number of coats on each cell.
// base = number of cells already at exactly k coats.
//
// The two new rectangles are disjoint, so every cell is covered by at most one
// of them, i.e. each cell gains at most one coat. A cell inside a new rectangle
// therefore contributes:
//     +1  if it had k-1 coats (it becomes k)
//     -1  if it had k   coats (it becomes k+1)
//      0  otherwise
// Call that value val[i][j]. The gain of a rectangle is its sum over val, so
// the task reduces to picking two disjoint rectangles of maximum total sum.
//
// Two disjoint axis-parallel rectangles can always be separated by a vertical
// or a horizontal line: if their x-ranges overlap AND their y-ranges overlap
// they would intersect. So it is enough to compute, for every split position c,
//     bestL[c] = max subrectangle sum lying entirely in slices 1..c
//     bestR[c] = max subrectangle sum lying entirely in slices c..SZ
// once with slices = columns and once with slices = rows, and maximize
// bestL[c] + bestR[c+1]. Painting fewer than two rectangles is covered by
// clamping the gain at 0 (zero rectangles) and by bestL[SZ] (one rectangle).
//
// Max subrectangle sums come from the usual O(SZ^3) sweep: fix a slice range
// [a, b], keep running sums perpendicular to it, and run Kadane over them.
//
// Complexity: O(SZ^3) = 8e6 per axis, plus O(n) to read the input.

#include <bits/stdc++.h>
using namespace std;

const int SZ = 200;              // barn coordinates run 0..200, so cells are 1..200
const int NEG = INT_MIN / 4;     // small enough to lose every max, large enough not to overflow

int cnt[SZ + 2][SZ + 2];         // coats per cell
int val[SZ + 2][SZ + 2];         // +1 at k-1 coats, -1 at k coats, 0 otherwise

int endAt[SZ + 2];               // best subrectangle whose last slice is exactly this one
int startAt[SZ + 2];             // best subrectangle whose first slice is exactly this one
int bestL[SZ + 2], bestR[SZ + 2];
int runSum[SZ + 2];

// Fills bestL / bestR. Slices are columns of val when transposed is false and
// rows of val when it is true.
void solveAxis(bool transposed) {
    for (int i = 0; i <= SZ + 1; i++) endAt[i] = startAt[i] = NEG;

    for (int a = 1; a <= SZ; a++) {
        for (int i = 0; i <= SZ + 1; i++) runSum[i] = 0;

        for (int b = a; b <= SZ; b++) {
            // runSum[i] becomes the sum of val over slices a..b at offset i,
            // then Kadane finds the best contiguous range of offsets.
            int cur = NEG, best = NEG;
            for (int i = 1; i <= SZ; i++) {
                runSum[i] += transposed ? val[b][i] : val[i][b];
                cur = max(runSum[i], cur + runSum[i]);
                best = max(best, cur);
            }
            endAt[b] = max(endAt[b], best);
            startAt[a] = max(startAt[a], best);
        }
    }

    bestL[0] = NEG;
    for (int c = 1; c <= SZ; c++) bestL[c] = max(bestL[c - 1], endAt[c]);

    bestR[SZ + 1] = NEG;
    for (int c = SZ; c >= 1; c--) bestR[c] = max(bestR[c + 1], startAt[c]);
}

int main() {
    ifstream fin("paintbarn.in");

    int n, k;
    fin >> n >> k;

    for (int i = 0; i < n; i++) {
        int x1, y1, x2, y2;
        fin >> x1 >> y1 >> x2 >> y2;
        // Shift by one so the rectangle covers cells [x1, x2-1] x [y1, y2-1].
        x1++; y1++; x2++; y2++;
        cnt[x1][y1]++;
        cnt[x2][y1]--;
        cnt[x1][y2]--;
        cnt[x2][y2]++;
    }

    int base = 0;
    for (int i = 1; i <= SZ; i++) {
        for (int j = 1; j <= SZ; j++) {
            cnt[i][j] += cnt[i - 1][j] + cnt[i][j - 1] - cnt[i - 1][j - 1];
            base += (cnt[i][j] == k);
            val[i][j] = (cnt[i][j] == k - 1) - (cnt[i][j] == k);
        }
    }

    int gain = 0;                                   // painting nothing is always allowed

    solveAxis(false);                               // split by a vertical line
    gain = max(gain, bestL[SZ]);                    // best single rectangle
    for (int c = 1; c < SZ; c++) gain = max(gain, bestL[c] + bestR[c + 1]);

    solveAxis(true);                                // split by a horizontal line
    for (int c = 1; c < SZ; c++) gain = max(gain, bestL[c] + bestR[c + 1]);

    ofstream("paintbarn.out") << base + gain << endl;

    return 0;
}
