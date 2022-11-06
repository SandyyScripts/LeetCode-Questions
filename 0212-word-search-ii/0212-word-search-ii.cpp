class Solution {
private:    
    vector<string> ans;
    int m;
    int n;
public:
    struct Trie {
        Trie() {
            is_word = false;
            freq = 0;
        }
        unordered_map<char, Trie*> subs;
        bool is_word;
        int freq;
    };
    
    void insert(Trie* root, string& word) {
        for (char& c : word) {
            if (!root->subs[c]) {
                root->subs[c] = new Trie();
            }
            root = root->subs[c];
            root->freq++;
        }
        root->is_word = true;
    }
        
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        ans.clear();
        m = board.size();
        n = board[0].size();
        Trie* root = new Trie();
        for (string& s : words) {
            insert(root, s);
        }
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (root->subs[board[i][j]] && root->subs[board[i][j]]->freq > 0) {
                    string path = "";
                    path.push_back(board[i][j]);
                    int found = 0;
                    search(board, i, j, root->subs[board[i][j]], path, found);
                }
            }
        }
        return ans;
    }
    
    void search(vector<vector<char>>& board, int row, int col, Trie* node, string& path, int& found) {
        if (node->is_word) {
            ans.push_back(path);
            node->is_word = false;
            found++;
        }
        board[row][col] = '#';
        int found_right = 0;
        int found_down = 0;
        int found_left = 0;
        int found_up = 0;
        //cout << row << " " << col << endl;
        //cout << path << endl;
        if (col < n - 1 && node->subs[board[row][col+1]] && node->subs[board[row][col+1]]->freq > 0) { // move right
            path.push_back(board[row][col+1]);
            search(board, row, col+1, node->subs[board[row][col+1]], path, found_right);
        }
        if (row < m - 1 && node->subs[board[row+1][col]] && node->subs[board[row+1][col]]->freq > 0) { // move down
            path.push_back(board[row+1][col]);
            search(board, row+1, col, node->subs[board[row+1][col]], path, found_down);
        }
        if (col > 0 && node->subs[board[row][col-1]] && node->subs[board[row][col-1]]->freq > 0) { // move left
            path.push_back(board[row][col-1]);
            search(board, row, col-1, node->subs[board[row][col-1]], path, found_left);
        }
        if (row > 0 && node->subs[board[row-1][col]] && node->subs[board[row-1][col]]->freq > 0) { // move up
            path.push_back(board[row-1][col]);
            search(board, row-1, col, node->subs[board[row-1][col]], path, found_up);
        }
        found += found_right + found_left + found_up + found_down;
        node->freq -= found;
        board[row][col] = path.back();
        path.pop_back();
    }
};