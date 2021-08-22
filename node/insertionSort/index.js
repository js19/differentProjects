let fs = require("fs");

function insertionSort(a){
    let j;
    let min;
    for(let i = 1; i < a.length; i++){
        j = i - 1;
        min = a[i];
        while(j >= 0 && a[j] > min){
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = min;
    }
}

function convertArrayToInts(a){
    let b = a.toString().split(',').map(function(item){
        return parseInt(item, 10);
    });

    return b;

}


var array = fs.readFileSync('E:/youtube video/10randomNums.txt').toString().split("\n");
array = convertArrayToInts(array);
console.log(array);
console.log("Insertion Sorting....")
insertionSort(array);
console.log(array);