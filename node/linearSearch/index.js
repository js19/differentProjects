let fs = require("fs");

function linearSearch(array, target){
    for(i in array){
        if(array[i] == target){
            return i;
        }
    }

    return -1;
}

function print(index, num){
    index > -1 ? console.log(num + " Found at index " + index) : console.log(num + " was NOT found");
}

var array = fs.readFileSync('/Users/Jeff/Desktop/youtube video/10000numbers.txt').toString().split("\n");

let index = linearSearch(array, 3630);
print(index, 3630);

index = linearSearch(array, 11000);
print(index, 11000);





