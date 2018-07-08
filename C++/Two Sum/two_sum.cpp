long getMax(const std::vector<int>& numbers, int target){
    long max = -10000;
    for(int i =0;i<numbers.size();i++){
        if(numbers[i] > max){
            max = numbers[i];
        }
    }
    if(max < target){
        max = target;
    }
    return max;
}


std::pair<std::size_t, std::size_t> two_sum(const std::vector<int>& numbers, int target) {
    long highestNumber = getMax(numbers, target);
    long a[highestNumber];

    for(int i =1;i<=numbers.size();i++){
      int k = numbers[i-1];
      a[k] = i;
    }

    for(int i =0;i<numbers.size();i++){
        int numberNeededToEqualTarget = target - numbers[i];
        long exists = a[numberNeededToEqualTarget];
        if(exists && i != exists - 1){
            return {i, --exists};
        }
    }

    return {0, 0};
}