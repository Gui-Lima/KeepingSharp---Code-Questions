function abs(nb){
    if (nb < 0)
        nb = -nb
    return nb
}

function smallest(arr){
    smalest = 1000000;
    saveRank = 0;
    for(keys in arr){
        if(arr[keys] < smalest){
            smalest = arr[keys];
            saveRank = keys;
        }
    }
    return saveRank;
}

function nexus(users) {
  var arr = []
  for (keys in users){
    arr[keys] = abs(keys - users[keys])
  }
    return parseInt(smallest(arr));
}