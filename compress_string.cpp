/* 压缩字符串, 5555444444 -> 4564 (格式就是连续的个数+数字本身) */
stirng compress_string(stirng numbers) {
    int len = number.length();
    if(numbers==null || n==0)
        return null;
    int cnt = 1;
    string compressed_string = “”;
    for(int i=0; i<n-1; ++i) {
        if(numbers[i] == numbers[i+1]) {
            ++cnt;
        }else {
            compressed_string += to_string(cnt) + to_string(numbers[i]);
            cnt = 1;
        }
    }
    compressed_string += to_string(cnt) + to_string(numbers[n-1]);
    return compressed_string;
}
