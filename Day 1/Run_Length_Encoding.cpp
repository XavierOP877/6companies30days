string encode(string src)
{     
  //Your code here 
  string result = "";
    int count = 1;
    for (int i = 1; i < src.length(); i++) {
        if (src[i] == src[i - 1]) {
            count++;
        } else {
            result += src[i - 1] + to_string(count);
            count = 1;
        }
    }
    result += src.back() + to_string(count);
    return result;
}     
 