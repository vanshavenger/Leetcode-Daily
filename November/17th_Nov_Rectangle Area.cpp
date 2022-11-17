class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        int areaOfSqrA = (C-A) * (D-B);
        int areaOfSqrB = (G-E) * (H-F);
        int left = max(A, E);
        int right = min(G, C);
        int bottom = max(F, B);
        int top = min(D, H);
        int overlap = 0;
        if(right > left && top > bottom) overlap = (right - left) * (top - bottom);
        return areaOfSqrA + areaOfSqrB - overlap;
    
}
};
