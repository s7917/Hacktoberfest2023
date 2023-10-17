class Solution {
public:
    int twoEggDrop(int n) {
        int i=1;
        while((i*(i+1))/2<n)i++;return i;
    }
};
