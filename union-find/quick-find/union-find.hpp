class UnionFind {
private:
    int *_data;
    int _totalSize;

public:
    UnionFind(int totalSize);
    ~UnionFind();

    void Union(int elA, int elB);
    bool Connected(int elA, int elB);
    void Print();
};