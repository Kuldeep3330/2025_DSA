// binary search in js
function binarySearch(arr, x){
    let low=0, high=arr.length-1;
    while(low<=high){
        let mid=Math.floor((low+high)/2)
        if(arr[mid]===x){
            return mid
        }else if( arr[mid]>x){
            high=mid-1;
        }else{
            low=mid+1;
        }
    }
    return -1;
}
console.log(binarySearch([1,2,3,4,5], 4));//3

//first occurence of an element in a sorted array
function firstOccurence(arr, x){
    let low=0, high=arr.length-1;
    let res=-1;
    while(low<=high){
        let mid=Math.floor((low+high)/2);
        if(arr[mid]===x){
            res=mid;
            high=mid-1;
        }else if(arr[mid]>x){
            high=mid-1;
        }else{
            low=mid+1;
        }
    }
    return res;
}
console.log(firstOccurence([1,2,2,2,3,4,5], 2));//1

//last occurence of an element in a sorted array
function lastOccurence(arr, x){
    let low =0, high=arr.length-1
    let res=-1;
    while(low<=high){
        let mid=Math.floor((low+high)/2);
        if(arr[mid]===x){
            res=mid;
            low=mid+1;
        }else if(arr[mid]>x){
            high=mid-1;
        }else{
            low=mid+1;
        }
    }
    return res;
}
console.log(lastOccurence([1,2,2,2,3,4,5], 2));//3

//count ones in a sorted binary array
function countOnes(arr){
    let low=0, high=arr.length-1;
    let res=-1;
    while(low<=high){
        let mid=Math.floor((low+high)/2)
        if(arr[mid]===0){
            low=mid+1;
        }else{
            if(mid===0 || arr[mid-1]===0){
                return n-mid;
            }else{
                high=mid-1;
            }
        }
    }
    return 0;
}

console.log(countOnes([0,0,0,1,1,1,1]));//4
