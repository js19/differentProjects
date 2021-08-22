let fs = require("fs");

function selectionSort(a){
    let min;
    for(let i = 0; i < a.length - 1; i++){
        min = i;
        for(let j = i + 1; j < a.length; j++){
            if(a[j] < a[min]){
                min = j;
            }
        }

        let temp = a[min];
        a[min] = a[i];
        a[i] = temp;

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
console.log("Selection Sorting....")
selectionSort(array);
console.log(array);