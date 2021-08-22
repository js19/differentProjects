let fs = require("fs");

function convertArrayToInts(a){
    let b = a.toString().split('\n').map(function(item){
        return parseInt(item, 10);
    });
    return b;
}

function merge(array, temp, left, mid, right){
    var left_end;
    var size;
    var temp_pos;
    
    left_end = mid - 1;
    temp_pos = left;
    size = right - left + 1;
    while((left <= left_end) && (mid <= right)){
        if(array[left] <= array[mid]){
            temp[temp_pos] = array[left];
            temp_pos++;
            left++;
        }else{
            temp[temp_pos] = array[mid];
            temp_pos++;
            mid++;
        }
    }

    while(left <= left_end){
        temp[temp_pos] = array[left];
        left++;
        temp_pos++;
    }
    while(mid <= right){
        temp[temp_pos] = array[mid];
        temp_pos++;
        mid++;
    }
    
    for(var i = 0; i < size; i++){
        array[right] = temp[right];
        right--;
    }
}


function mergeSort(array, temp, left, right){
    var mid;
    if(right > left){
        mid = Math.floor((right + left) / 2);
        mergeSort(array, temp, left, mid);
        mergeSort(array, temp, mid + 1, right);
        merge(array, temp, left, mid + 1, right);
    }
}


var array = fs.readFileSync('E:/youtube video/10randomNums.txt');
var temp = [0, 0, 0, 0, 0, 0, 0, 0, 0, 0];
array = convertArrayToInts(array);
console.log(array);
mergeSort(array, temp, 0, 9);
console.log(array);



