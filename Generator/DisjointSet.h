using namespace std;
#include <map>

template <class T>
class DisjointSet {
private:
    map<T, int> _rank;
    map<T, T> _parent;
    int _n;
  
public:
    DisjointSet(int n)
    {
        _n = n;
        makeSet(); 
    } 
  
    void makeSet()
    { 
        for (int i = 0; i < _n; i++) {
            for (int j = 0; j < _n; j++) {
                _parent[make_pair(i, j)] = make_pair(i, j);
                _rank[make_pair(i, j)] = 1;
            }
        } 
    } 
    T find(T x)
    {
        if (_parent[x] != x) {
            _parent[x] = find(_parent[x]);
        }
        return _parent[x];
    } 
  
    void join(T x, T y)
    {
        T xset = find(x);
        T yset = find(y);
        if (xset == yset)
            return; 

        if (_rank[xset] < _rank[yset]) {
            _parent[xset] = yset;
        } else if (_rank[xset] > _rank[yset]) {
            _parent[yset] = xset;
        } else {
            _parent[yset] = xset;
            _rank[xset] = _rank[xset] + 1;
        } 
    } 
}; 