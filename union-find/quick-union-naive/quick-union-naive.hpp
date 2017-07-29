class QuickUnionNaive {
private:
    int *_data;
    int _totalSize;

    int Root(int el);

public:
    QuickUnionNaive(int totalSize);
    ~QuickUnionNaive();

    void Union(int elA, int elB);
    bool Connected(int elA, int elB);
    void Print();
};