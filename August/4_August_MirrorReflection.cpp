class Solution {
public:
    int solve(int p,int q,int dist,int br,int tr,int tl,int bl){
        if(p == dist) return tr;
        if(dist == 0) return br;
        if((q + dist) <= p){
            return solve(p,q,dist + q,bl,tl,tr,br);
        }else{
            return solve(p,q,dist - p + q,tl,bl,br,tr);
        }
    }
    int mirrorReflection(int p, int q) {
        return solve(p,q,q,0,1,2,3);
    }
};
