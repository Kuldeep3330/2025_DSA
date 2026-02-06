// function maxEle(arr){
//     let maxim= -Infinity
//     for (const i in arr) {
//         if(arr[i]>maxim){
//             maxim=arr[i]
//         }        
//     }
//     return maxim;
// }

// console.log(maxEle([1,2,26,4,5]));


function print(...arr, a, b){
    console.log(b);
}

print(10, 20, 30, 40)

function print_2(a, b, ...arr){
    console.log(b);
}

print_2(10, 20, 30, 50);