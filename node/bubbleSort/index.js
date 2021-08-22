let fs = require("fs");

function bubbleSort(a){
    for(let i = 0; i < a.length; i++){
        for(let j = i + 1; j < a.length; j++){
            if(a[i] > a[j]){
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
}

function convertArrayToInts(a){
    let b = a.toString().split(',').map(function(item){
        return parseInt(item, 10);
    });

    return b;

}


var array = fs.readFileSync('/Users/Jeff/Desktop/youtube video/10randomNums.txt').toString().split("\n");
array = convertArrayToInts(array);
console.log(array);
console.log("Bubble Sorting....")
bubbleSort(array);
console.log(array);






