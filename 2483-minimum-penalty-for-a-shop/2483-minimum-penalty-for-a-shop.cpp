class Solution {
public:
    int bestClosingTime(string customers) {
        // int n = customers.size();
        // vector<int> prefix(n+1,0),postfix(n+1,0);
        // for(int i=1;i<=n;i++){
        //     prefix[i]=prefix[i-1];
        //     if(customers[i-1]=='N')
        //         prefix[i]++;
        // }
        // for(int i=n-1;i>=0;i--){
        //     postfix[i]=postfix[i+1];
        //     if(customers[i+1]=='Y')
        //         postfix[i]++;
        // }
        // for(auto x:prefix){
        //     cout<<x<<" ";
        // }
        // cout<<endl;
        // for(auto x:postfix){
        //     cout<<x<<" ";
        // }
        // cout<<endl;
        // int penalty=1e8,idx=0;
        // for(int i=0;i<=n;i++){
        //     cout<<prefix[i]+postfix[i]<<" ";
        //     if(penalty>prefix[i]+postfix[i]){
        //         penalty=prefix[i]+postfix[i];
        //         idx=i;
        //     }
        // }
        // return idx;
        int n = customers.length();
        int Y = 0;

        for (int i = 0; i < n; i++) {
            Y += (customers[i] == 'Y' ? 1 : 0);
        }

        int min_p = n;
        int hour = n;
        int y_found = 0;
        int n_found = 0;

        for (int h = 0; h <= n; h++) {
            int y_remaining = Y - y_found;
            int pen = y_remaining + n_found;

            if (pen < min_p) {
                hour = h;
                min_p = pen;
            }

            if (h < n && customers[h] == 'N') {
                n_found++;
            }

            if (h < n && customers[h] == 'Y') {
                y_found++;
            }
        }

        return hour;
    }
};