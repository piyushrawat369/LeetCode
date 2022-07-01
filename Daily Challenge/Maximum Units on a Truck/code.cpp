int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {

    sort(boxTypes.begin(), boxTypes.end(), [](auto& a, auto& b) { return a[1] > b[1];});
    
    int ans = 0;
    for(auto& b: boxTypes){
        int count = min(b[0], truckSize);
        ans += count*b[1];
        truckSize -= count;
        if(!truckSize)
        return ans;
    }
    return ans;
}
