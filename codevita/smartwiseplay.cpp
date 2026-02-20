#include <bits/stdc++.h>
using namespace std;
const double EPSILON = 1e-6;

struct Point {
    double x, y;
    bool operator==(const Point& o) const {
        return fabs(x - o.x) < EPSILON && fabs(y - o.y) < EPSILON;
    }
    bool operator<(const Point& o) const {
        if (fabs(x - o.x) > EPSILON) return x < o.x;
        return y < o.y;
    }
};

struct HashPoint {
    size_t operator()(const Point& p) const noexcept {
        long long rx = llround(p.x / EPSILON);
        long long ry = llround(p.y / EPSILON);
        return std::hash<long long>()((rx << 32) ^ ry);
    }
};

struct Line {
    Point p1, p2;
};

double dist(const Point& a, const Point& b) {
    return hypot(a.x - b.x, a.y - b.y);
}

bool find_intersection(const Line& l1, const Line& l2, Point& inter) {
    double x1 = l1.p1.x, y1 = l1.p1.y, x2 = l1.p2.x, y2 = l1.p2.y;
    double x3 = l2.p1.x, y3 = l2.p1.y, x4 = l2.p2.x, y4 = l2.p2.y;
    double den = (y4 - y3) * (x2 - x1) - (x4 - x3) * (y2 - y1);
    if (fabs(den) < EPSILON) return false;
    double ua = ((x4 - x3) * (y1 - y3) - (y4 - y3) * (x1 - x3)) / den;
    double ub = ((x2 - x1) * (y1 - y3) - (y2 - y1) * (x1 - x3)) / den;
    if (ua >= -EPSILON && ua <= 1 + EPSILON && ub >= -EPSILON && ub <= 1 + EPSILON) {
        inter = {x1 + ua * (x2 - x1), y1 + ua * (y2 - y1)};
        return true;
    }
    return false;
}

double area(const vector<Point>& poly) {
    double s = 0;
    for (size_t i = 0; i + 1 < poly.size(); i++)
        s += poly[i].x * poly[i + 1].y - poly[i + 1].x * poly[i].y;
    return fabs(s) / 2;
}

bool dfs(Point u, Point p, vector<Point>& path, unordered_map<Point, vector<Point>, HashPoint>& adj,
         unordered_set<Point, HashPoint>& vis, unordered_set<Point, HashPoint>& stack, vector<Point>& cyc) {
    vis.insert(u);
    stack.insert(u);
    path.push_back(u);
    for (auto& v : adj[u]) {
        if (v == p) continue;
        if (stack.count(v)) {
            auto it = find(path.begin(), path.end(), v);
            if (it != path.end()) {
                cyc.insert(cyc.end(), it, path.end());
                cyc.push_back(v);
                return true;
            }
        }
        if (!vis.count(v)) {
            if (dfs(v, u, path, adj, vis, stack, cyc)) return true;
        }
    }
    path.pop_back();
    stack.erase(u);
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<Line> sticks(n);
    for (int i = 0; i < n; i++) {
        double x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        sticks[i] = {{x1, y1}, {x2, y2}};
    }

    unordered_map<int, set<Point>> pts;
    for (int i = 0; i < n; i++) pts[i] = {sticks[i].p1, sticks[i].p2};
    unordered_set<Point, HashPoint> ints;

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            Point inter;
            if (find_intersection(sticks[i], sticks[j], inter)) {
                ints.insert(inter);
                pts[i].insert(inter);
                pts[j].insert(inter);
            }
        }
    }

    if (ints.empty()) {
        cout << "Abandoned";
        return 0;
    }

    unordered_map<Point, vector<Point>, HashPoint> adj;
    vector<Line> segs;
    for (auto& kv : pts) {
        vector<Point> p(kv.second.begin(), kv.second.end());
        sort(p.begin(), p.end());
        for (size_t i = 0; i + 1 < p.size(); i++) {
            adj[p[i]].push_back(p[i + 1]);
            adj[p[i + 1]].push_back(p[i]);
            segs.push_back({p[i], p[i + 1]});
        }
    }

    unordered_set<Point, HashPoint> vis;
    vector<Point> cycle;
    for (auto& st : ints) {
        if (!vis.count(st)) {
            vector<Point> path, cyc;
            unordered_set<Point, HashPoint> stack;
            if (dfs(st, {NAN, NAN}, path, adj, vis, stack, cyc)) {
                cycle = cyc;
                break;
            }
        }
    }

    if (cycle.empty() || cycle.size() < 4 || !(cycle.front() == cycle.back())) {
        cout << "Abandoned";
        return 0;
    }

    double a = area(cycle);
    if (a < EPSILON) {
        cout << "Abandoned";
        return 0;
    }

    double tl = 0, cl = 0;
    for (auto& s : segs) tl += dist(s.p1, s.p2);
    for (size_t i = 0; i + 1 < cycle.size(); i++) cl += dist(cycle[i], cycle[i + 1]);
    double rem = max(0.0, tl - cl);
    double comp = (rem * rem) / (4 * M_PI);

    if (fabs(a - comp) < EPSILON) cout << "Computer";
    else if (a > comp) cout << "Kalyan";
    else cout << "Computer";

    return 0;
}
