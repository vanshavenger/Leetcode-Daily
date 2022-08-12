class Solution {
public:
    int poorPigs(int buckets, int ie, int est) {
        int a = ceil(log(buckets)/log(1 + (est/ie)));
        return a;
    }
};
