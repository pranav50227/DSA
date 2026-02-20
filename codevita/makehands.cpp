#include <bits/stdc++.h>
using namespace std;

struct PlayingCard {
    int rank;
    int symbol;
};

int getValue(const string &t) {
    if (t == "A") return 1;
    if (t == "J") return 11;
    if (t == "Q") return 12;
    if (t == "K") return 13;
    return stoi(t);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int rounds;
    if (!(cin >> rounds)) return 0;

    vector<PlayingCard> deckA, deckB;
    for (int i = 0; i < rounds; ++i) {
        string t1, t2;
        int s1, s2;
        cin >> t1 >> s1 >> t2 >> s2;
        deckA.push_back({getValue(t1), s1});
        deckB.push_back({getValue(t2), s2});
    }

    vector<int> hierarchy(4);
    for (int i = 0; i < 4; ++i) cin >> hierarchy[i];

    vector<int> priority(5);
    for (int i = 0; i < 4; ++i) priority[hierarchy[i]] = i;

    auto compare = [&](const PlayingCard &a, const PlayingCard &b) {
        if (a.rank != b.rank) return a.rank < b.rank;
        return priority[a.symbol] > priority[b.symbol];
    };

    sort(deckA.begin(), deckA.end(), compare);
    sort(deckB.begin(), deckB.end(), compare);

    deque<PlayingCard> playerA(deckA.begin(), deckA.end());
    deque<PlayingCard> playerB(deckB.begin(), deckB.end());

    vector<PlayingCard> table;
    int turn = 0;

    while (true) {
        if (turn == 0) {
            if (playerA.empty()) {
                if (playerB.empty()) cout << "TIE";
                else cout << "LOSER";
                break;
            }
        } else {
            if (playerB.empty()) {
                if (playerA.empty()) cout << "TIE";
                else cout << "WINNER";
                break;
            }
        }

        PlayingCard draw;
        if (turn == 0) {
            draw = playerA.front();
            playerA.pop_front();
        } else {
            draw = playerB.front();
            playerB.pop_front();
        }

        table.push_back(draw);

        if (table.size() >= 2) {
            PlayingCard prev = table[table.size() - 2];
            PlayingCard curr = table.back();
            if (curr.rank == prev.rank && priority[curr.symbol] < priority[prev.symbol]) {
                sort(table.begin(), table.end(), compare);
                if (turn == 0) {
                    for (auto &c : table) playerA.push_back(c);
                } else {
                    for (auto &c : table) playerB.push_back(c);
                }
                table.clear();
                continue;
            }
        }

        turn ^= 1;
    }

    return 0;
}
