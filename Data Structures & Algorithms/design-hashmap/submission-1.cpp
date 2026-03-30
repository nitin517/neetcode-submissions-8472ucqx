class MyHashMap {
public:
    int n;
    vector<int> v;
    vector<bool> vis;

    MyHashMap() {
        n = 1000001; // safe for keys up to 10^6
        v.resize(n, 0);
        vis.resize(n, false);
    }
    
    void put(int key, int value) {
        v[key] = value;   // fixed typo
        vis[key] = true;
    }
    
    int get(int key) {
        if (!vis[key]) return -1;
        return v[key];
    }
    
    void remove(int key) {
        vis[key] = false;
    }
};