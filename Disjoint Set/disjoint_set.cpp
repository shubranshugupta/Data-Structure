class DisjointSet{
    int *parent, *rank, n;
    
    void makeSet(){
        for(int i=0; i<n; i++){
            parent[i]=i;
        }
    }
public:
    DisjointSet(int n){
        this->n=n;
        parent = new int[n];
        rank = new int[n];
        makeSet();
    }
    
    int find(int val){
        if(parent[val]!=val){
            parent[val] = find(parent[val]);
        }
        return parent[val];
    }
    
    void unions(int x, int y){
        int xset = find(x);
        int yset = find(y);
        
        if(xset==yset){
            return;
        }
        
        if(rank[xset] < rank[yset]){
            parent[xset]=yset;
        }else if(rank[xset] > rank[yset]){
            parent[yset]=xset;
        }else{
            parent[yset]=xset;
            rank[xset] = rank[xset] + 1;
        }
    }
};