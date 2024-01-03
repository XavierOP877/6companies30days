class DataStream {
public:
    int count = 0;
    int last = 0;
    int tempk, tempval;

    DataStream(int value, int k) {
        tempval = value;
        tempk = k;    
    }
    
    bool consec(int num) {
        count++;
        if(num == tempval){
            last++;
        }
        else{
            last = 0;
        }
        if(count < tempk){
            return false;
        }
        else if(last >= tempk){
            return true;
        }
        return false;
    }
};

/**
 * Your DataStream object will be instantiated and called as such:
 * DataStream* obj = new DataStream(value, k);
 * bool param_1 = obj->consec(num);
 */