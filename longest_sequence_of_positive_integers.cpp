/* Given an array of integers, print out the longest sequence of positive integers. */
/* For example, given {-1, 2, 3, -4, 6, 12, 8, 9, -3, -5}, print out {6, 12, 8, 9} */
void print_longest_sequence_of_positive_integers(vector &vec) {
    int end_position = 0, res = 0, longest_len = 0;
    for(int  i=0; i<vec.size(); ++i) {
        if(vec[i] >= 0) {
            ++res;
        }else {
            if(res > longest_len) {
                longest_len = res;
                end_position = i + 1;
            }
            res  = 0;
        }
    }
    if(res > longest_len) {
        longest_len = res;
        end_position = vec.size();
    }
    for(int i=end_position-longest_len; i<longest_len; ++i) {
        cout<<vec[i]<<" "<<endl;
    }
}
