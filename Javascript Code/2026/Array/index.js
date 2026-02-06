// //Array operations
// //Linear Search
// function searchEle(arr, ele){
//     for(let i=0; i<arr.length; i++){
//         if(arr[i]===ele){
//             return true;
//         }
//     }
//     return false;
// }

// console.log(searchEle([1,2,3,4,5], 3)); // true

// //search usong built in library
// const arr=[1,2,3,4,5];
// console.log(arr.includes(6)); // false
// console.log(arr.indexOf(4)); // 3
// console.log(arr.lastIndexOf(2)); // 1
// const index= arr.indexOf(3);
// console.log(index!==-1?index:"not found");// 2


// //Binary search
// function bSearch(arr, x){
//     let low=0, high=arr.length-1;
//     while(low<=high){
//         let mid=Math.floor((low+high)/2);
//         if(arr[mid]===x){
//             return mid;
//         }else if(arr[mid]<x){
//             low=mid+1;
//         }else{
//             high=mid-1;
//         }
//     }
//     return -1;
// }

// console.log(bSearch([1,2,3,4,5], 4)); // 3

//insert element at a given position
// function insertAt(arr, pos, val){
//     if(pos<0 || pos>arr.length){
//         console.log("Invalid position");
//         return;
//     }
//     arr.splice(pos, 0, val);// array.splice(startIndex, deleteCount, item1, item2, ...)
//     return arr;
// }

// console.log(insertAt([1,2,3,4], 2, 10)); // [1, 2, 10, 3, 4]

// differece between splice and slice
// array.slice(startIndex, endIndex)
// array.splice(startIndex, deleteCount, item1, item2, ...)

// // remove by index
// const arr=[1,2,3,4,5];
// arr.splice(2, 1)// removes 1 element at index 2
// console.log(arr); // [1, 2, 4, 5]


// // remove by value
// function removeByValue(arr, val){
//     const index= arr.indexOf(val);  
//     if(index!==-1){
//         arr.splice(index, 1);
//     }
//     return arr;
// }

// console.log(removeByValue([1,2,3,4,5], 3)); // [1, 2, 4, 5]


//remove all occurrences of a value
// function removeAllByValue(arr, val){
//     const newArr=arr.filter(item=>item!==val);
//     return newArr;
// }

// console.log(removeAllByValue([1,2,3,4,5,3], 3)); // [1, 2, 4, 5]

//Largest & second largest
// function largest(arr){
//     return Math.max(...arr);
// }

// function secondLargest(arr){
//     let first= -Infinity, second=-Infinity;
//     for(let x of arr){
//         if(x>first){
//             second=first;
//             first=x;
//         }else if(x>second && x!=first){
//             second=x;
//         }
//     }
//     return second;
// }

// console.log(largest([1,2,3,4,5])); // 5
// console.log(secondLargest([1,2,3,4,5])); // 4


// //check sorted
// function isSorted(arr){
//     for( let i=1; i<arr.length; i++){
//         if(arr[i]<arr[i-1]){
//             return false;
//         }
//     }
//     return true
// }
// console.log(isSorted([1,2,35,4,5]));//

// //Remove duplicates(sorted array)
// function removeDups(arr){
//     let j=0;
//     for(let i=1; i<arr.length; i++){
//         if(arr[i]!==arr[j]){
//             j++
//             arr[j]=arr[i]
//         }
//     }
//     return arr.slice(0, j+1);
// }

// console.log(removeDups([1,2,2,3,4,4,5])); // [1, 2, 3, 4, 5]


// //move zeroes to end
// function moveZeroes(arr){
//     let j=0
//     for( let i=0; i<arr.length; i++){
//         if(arr[i]!==0){
//             [arr[j], arr[i]]=[arr[i], arr[j]];
//             j++;
//         }
//     }
// }

// const arr=[0,1,0,3,12];
// moveZeroes(arr);
// console.log(arr); // [1, 3, 12, 0, 0]

// array.slice(startIndex, endIndex)

//left rotate an array by d positions

// function leftRotate(arr, d){
//     d=d%arr.length; // in case d>arr.length
//     return arr.slice(d).concat(arr.slice(0, d));
// }

// console.log(leftRotate([1,2,3,4,5], 2)); // [3, 4, 5, 1, 2]


// // leaders in an array
// // [16, 17, 4, 3, 5, 2]-> [17, 5, 2]
// function leaders(arr){
//     let leaders=[];
//     let max=-Infinity
//     for( let i=arr.length-1; i>=0; i--){
//         if(arr[i]>max){
//             max=arr[i];
//             leaders.push(max);
//         }
//     }
//     return leaders.reverse();   
// }
// console.log(leaders([16, 17, 4, 3, 5, 2])); // [17, 5, 2]

// //frequencies in sorted array
// function frequencies(arr){
//     let n = arr.length;
//     let freq=1;
//     for( let i=1; i<n; i++){
//         if(arr[i]===arr[i-1]){
//             freq++;
//         }else{
//             console.log(arr[i-1] + " occurs " + freq + " times");
//             freq=1;
//         }
//     }
//     console.log(arr[n-1] + " occurs " + freq + " times");
// }
// frequencies([10,10,20,20,20,30]);

// //method 2 using map
// function frequenciesMap(arr){
//     let freqMap=new Map();  
//     for( let x of arr){
//         freqMap.set(x, (freqMap.get(x) || 0) + 1);
//     }
//     for( let [key, value] of freqMap){
//         console.log(key + " occurs " + value + " times");
//     }
// }
// frequenciesMap([10,10,20,20,20,30]);


//Trapping Rain water
function trappingWater(arr){
    let n=arr.length;
    let left=Array(n), right=Array(n)
    left[0]=arr[0]
    for( let i=1; i<n; i++){
        left[i]=Math.max(left[i-1], arr[i]);
    }

    right[n-1]=arr[n-1]
    for( let i=n-2; i>=0; i--){
        right[i]=Math.max(right[i+1], arr[i]);
    }
    let res=0;
    for(let i=1; i<n-1; i++){
        res+=Math.min(left[i], right[i])-arr[i]
    }   
    return res;
}

console.log(trappingWater([2,1,3,4,9]));// output 

//Kadane's ALgorithm

function maxSubarray(arr){
    let curr=arr[0] , res=arr[0];
    for(let i=1; i<arr.length; i++){
        curr=Math.max(arr[i], curr+arr[i]);
        res=Math.max(res, curr)
    }
    return res;
}

