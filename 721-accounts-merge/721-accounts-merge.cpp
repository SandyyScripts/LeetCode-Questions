class UnionFind {
public:
    //Constructor    
    UnionFind(int size) : leader(size), rank(size)
    {
        for (int i = 0; i < size; i++)
        {
            leader[i] = i; //all start off as their own leader
            rank[i] = 1; //all start off as 1
        }
    }
    
    //Find function
    int find(int node)
    {
        if (node == leader[node]) {
            return node; //if it's its own leader
        }
        return leader[node] = find(leader[node]);
    }
    
    //union function
    void unionMerge(int node1, int node2)
    {
        int leader1 = find(node1);
        int leader2 = find(node2);
        if (leader1 == leader2) {
            return;
        }
        else if (rank[leader1] > rank[leader2]) {
            leader[leader2] = leader1; //append smaller one to larger
        }
        else if (rank[leader1] < rank[leader2]) {
            leader[leader1] = leader2;
        }
        else {
            //must be same size; this is the only scenario where the size
            //of a chain gets updated too
            leader[leader2] = leader1;
            rank[leader1]++;
        }
    }
    
    //isSame component function
    bool isConnected(int node1, int node2)
    {
        return find(node1) == find(node2);
    }
    
private:
    vector<int> leader;
    vector<int> rank;
};


class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n=accounts.size();
        UnionFind UF(n);
        unordered_map<string,int> hTable;
        for(int i=0;i<n;i++){
            for(int j=1;j<accounts[i].size();j++){
                if(hTable.find(accounts[i][j])==hTable.end()){
                    hTable[accounts[i][j]]=i;
                }
                else{
                    UF.unionMerge(i, hTable[accounts[i][j]]);
                }
            }
        }
        vector<vector<string>> output;
        vector<vector<string>> acc(n);
        unordered_set<string> emailSet;
         for (int i = 0; i < n; i++)
        {
            for (int j = 1; j < accounts[i].size();j++)
            {
                if (emailSet.find(accounts[i][j]) == emailSet.end()) {
                    int index = UF.find(hTable[accounts[i][j]]);
                    if(acc[index].empty()) {
                        acc[index].push_back(accounts[i][0]);
                    }
                    acc[index].push_back(accounts[i][j]);
                    emailSet.insert(accounts[i][j]);
                }
            }
        }
        
        //now traverse through the map
        for (int i = 0; i < n; i++)
        {
            if (!acc[i].empty()) {
                sort(acc[i].begin()+1, acc[i].end());
                output.push_back(acc[i]);
            }
        }
        return output;
    }
};