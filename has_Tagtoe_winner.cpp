/* 8 means empty */
bool has_Tagtoe_winner(vector< vector<int> > &board, int n)
{
    bool has_incline_winner= true,   has_diagonal_winner = true;
    for(int row=0; row<n; ++row) {
        bool has_winner = true;
        for(int col=0; col<n-1; ++col) {
            if(row == 0 &&
                    (a[col][col]==8 || a[col][col] != a[col+1][col+1])) {
                has_incline_winner = false
            }
            if(row == 0 &&
                    ( a[col][2-col]==8 || a[col][2-col] == a[[col+1][2-col-1]) ) {
                has_diagonal_winner = false;
            }
            if(a[row][col]==8 || a[row][col] != a[row][col+1]) {
                flag = false;
            }
        }
        if(flag || has_incline_winner || has_dagonal_winner)
            return true;
    }

    for(int col=0; col<n; ++col) {
        has_winner = true;
        for(int row=0; row<n-1; ++row) {
            if(a[row][col]==8 || a[row][col]!=a[row+1][col]) {
                has_winner= false;
                break;
            }
        }
        if(has_winner)
            return true;
    }

    return  false;
}
