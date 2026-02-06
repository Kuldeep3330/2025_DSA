// // //search
// // function search(arr, target){
// //     for(let i=0; i<arr.length; i++){
// //         if(arr[i]===target) return i;
// //     }
// //     return -1;
// // }
// // console.log(search([1,2,3,4,5], 3));

// // //search using includes
// // function searchIncludes(arr, target){
// //     return arr.includes(target);
// // }
// // console.log(searchIncludes([1,2,3,4,5], 6));

// // // arr push
// // let arr=[1,2,3];
// // arr.push(4);
// // console.log(arr);//[1,2,3,4]

// // //arr pop
// // arr.pop();
// // console.log(arr);//[1,2,3]

// // //arr unshift
// // arr.unshift(0);
// // console.log(arr);//[0,1,2,3]

// // //arr shift
// // arr.shift();
// // console.log(arr);//[2,3]

// // let arr2=[4,5,6];
// // //arr splice
// // arr2.splice(1,2);
// // console.log(arr2);//[4]

// // //arr slice
// // let arr3=[1,2,3,4,5];
// // let newArr=arr3.slice(1,4);
// // console.log(newArr);//[2,3,4]

// // arr3.includes(10);//false

// // arr3.indexOf(1);//0

// // arr3.find((x)=>x>3);//4 Returns first element satisfying a condition

// // arr3.findIndex((x)=>x>3);//3 Returns index of first element satisfying a condition

// // arr3.map((x)=>x*2);//[2,4,6,8,10] Creates a new array by applying a function to each element

// // arr3.filter(x=>x>2);//[3,4,5]

// // arr3.reduce((a, b)=>a+b, 0); //15 //prefux sum

// // [1,[2,3], 4, [5,[10]]].flat(1);//[1,2,3,4,5,[10]]

// // let arr4=[20, 13, 51, 6, 89];
// // arr4.sort((a,b)=>a-b); //[6,13, 20, 51, 89]

// // //sort in descending order
// // arr4.sort((a,b)=>b-a); //[89, 51, 20, 13, 6]

// // //reverse an array
// // arr4.reverse(); //[6, 13, 20, 51, 89]
// // console.log(arr4);

// // function reverseArray(arr){
// //     let low=0, high=arr.length-1;
// //     while(low<high){
// //         let temp=arr[low];
// //         arr[low]= arr[high];
// //         arr[high]=temp;
// //         low++;
// //         high--;
// //     }
// // }

// // //merge two arrays
// // let arr5=[1,2,3];
// // let arr6=[4,5,6];
// // let mergedArr=arr5.concat(arr6);//[1,2,3,4,5,6]
// // console.log(mergedArr);

// // //merge using spread operator
// // let mergedArr2=[...arr5, ...arr6];//[1,2,3,4,5,6]
// // console.log(mergedArr2);

// // //for loop
// // //1. for of loop
// // for (const element of arr4) {
// //     console.log(element);//prints elements of arr4    
// // }

// // //2. for in loop
// // for (const key in arr5) {    
// //     console.log(arr4[key]);//prints elements of arr4   
// // }

// // //insert at specific position
// // arr4.splice(1, 0, 15);
// // console.log(arr4);//[6, 15, 13, 20, 51, 89]

// // //// start DSA
// // // insert at given position
// // function insertEle(arr, n, x, cap, pos){
// //     if(n==cap) return n;
// //     const idx=pos-1;

// //     for( let i =n-1; i>=idx ; i--){
// //         arr[i+1]=arr[i];
// //     }
// //     arr[idx]=x;
// //     return n+1;
// // }
// // console.log(insertEle([1,2,3,4,5], 5, 10, 10, 3));//6

// // //largetst element in an array
// // function largestSmallestEle(arr){
// //     let max=Math.max(...arr);
// //     let min=Math.min(...arr);
// //     return [max, min];
// // }

// // console.log(largestSmallestEle([1,2,3,4,5]));//[5,1]

// // function largestEle(arr){
// //     let max=-Infinity;
// //     for (const element of arr) {
// //         if(element>max){
// //             max=element;
// //         }       
// //     }
// //     return max;
// // }
// // console.log(largestEle([1,2,3,4,5]));//5

// // //second largest element in an array
// // function secondLargestEle(arr){
// //     let first=-Infinity, second=-Infinity;
// //     for(let i=0;i<arr.length;i++){
// //         if(arr[i]>first){
// //             second=first;
// //             first=arr[i];
// //         }else if(arr[i]>second && arr[i]!=first){
// //             second=arr[i];
// //         }
// //     }
// //     return second===-Infinity?-1:second;
// // }

// // //to check if array is sorted or not
// // function isSorted(arr){
// //     for( let i=0; i<arr.length-1; i++){
// //         if( arr[i]>arr[i+1]){
// //             return false;
// //         }
// //     }
// //     return true;
// // }
// // console.log(isSorted([1,2,3,4,5]));//true

// // //remove duplicates from sorted array
// // function removeDups(arr){
// //     let arr2=[];
// //     arr.push(arr[0]);
// //     for( let i=1; i<arr.length; i++){
// //         if(arr[i]!= arr2[arr2.length - 1]){
// //             arr2.push(arr[i]);
// //         }
// //     }
// //     return arr2;
// // }
// // console.log(removeDups([1,1,2,2,3,4,5]));//[1,2,3,4,5]

// // //method 2 to remove duplicates from sorted array

// // const removeDups_1= arr=>[...new Set(arr)]
// // console.log(removeDups_1([1,1,2,2,3,4,5]));//[1,2,3,4,5]

// // // const removeDups_2=(arr)=>{
// // //     return [...new Set(arr)]
// // // }

// // //move zeros to end of array
// // function moveZeros(arr){
// //     let count=0;
// //     for( let i=0; i<arr.length; i++){
// //         if(arr[i]!=0){
// //             arr[count++]=arr[i];
// //         }
// //     }
// //     while(count<arr.length){
// //         arr[count++]=0;
// //     }
// //     return arr;
// // }

// // console.log(moveZeros([0,1,0,3,12]));//[1,3,12,0,0]

// // //left rotate an array by d elements
// // function leftRotate(arr, d){
// //     d=d%arr.length;
// //     let rotatedArr=arr.slice(d).concat(arr.slice(0,d));
// //     return rotatedArr;
// // }
// // console.log(leftRotate([1,2,3,4,5], 2));//[3,4,5,1,2]

// // //method 2
// // function reverse(arr, start, end) {
// //   while (start < end) {
// //     [arr[start], arr[end]] = [arr[end], arr[start]]; // swap
// //     start++;
// //     end--;
// //   }
// // }

// // function leftRotateInPlace(arr, d) {
// //   const n = arr.length;
// //   d = d % n;

// //   reverse(arr, 0, d - 1);   // Reverse first d elements
// //   reverse(arr, d, n - 1);   // Reverse remaining n-d elements
// //   reverse(arr, 0, n - 1);   // Reverse whole array
// // }

// // // Example:
// // let arr7 = [1, 2, 3, 4, 5];
// // leftRotateInPlace(arr7, 2);
// // console.log(arr7); // [3, 4, 5, 1, 2]

// // //leaders in an array
// // function leadersInArray(arr){
// //     let leaders=[];
// //     leaders.push(arr[arr.length-1]);
// //     for( let i=arr.length-2; i>=0; i--){
// //         if(arr[i]>leaders[leaders.length-1]){
// //             leaders.push(arr[i])
// //         }
// //     }
// //     return leaders.reverse();
// // }
// // console.log(leadersInArray([16,17,4,3,5,2]));//[17,5,2]

// // //Maximum difference between two elements such that larger element appears after the smaller element
// // // arr[j]-arr[i], j>i
// // function maxDiff(arr){
// //     let res=arr[1]-arr[0];
// //     let minVal=arr[0];
// //     for(let j=1; j<arr.length; j++){
// //         res=Math.max(res, arr[j]-minVal);
// //         minVal=Math.min(minVal, arr[j]);
// //     }
// //     return res;
// // }

// // console.log(maxDiff([2,3,10,6,4,8,1]));//8

// // //frequencies of array elements
// // function frequencies(arr){

// //     let freqMap=new Map();
// //     for(const num of arr){
// //         if(freqMap.has(num)){
// //             freqMap.set(num, freqMap.get(num)+1);
// //         }
// //         else{
// //             freqMap.set(num, 1);
// //         }
// //     }
// //     return freqMap;
// // }
// // console.log(frequencies([10,20,20,10,10,30,50,10,20]));//Map(4) { 10 => 4, 20 => 3, 30 => 1, 50 => 1 }

// // //stock buy and sell to maximize profit

// // function stockBuySell(prices){
// //     let n=prices.length;
// //     let profit=0;
// //     for(let i=1; i<n; i++){
// //         if(prices[i]>prices[i-1]){
// //             profit+=prices[i]-prices[i-1];
// //         }
// //     }
// //     return profit;
// // }
// // console.log(stockBuySell([7,1,5,3,6,4]));//7

// // //trapping rain water
// // function trapRainWater(heights){
// //     let n = heights.length;
// //     let leftMax = new Array(n).fill(0);
// //     let rightMax = new Array(n).fill(0);
// //     leftMax[0]=heights[0];
// //     for(let i=1; i<n; i++){
// //         leftMax[i]= Math.max(leftMax[i-1], heights[i]);
// //     }

// //     rightMax[n-1]=heights[n-1];
// //     for( let i=n-2; i>=0; i--){
// //         rightMax[i]= Math.max(rightMax[i+1], heights[i]);
// //     }

// //     let waterTrapped=0;

// //     for( let i=1; i<=n-1; i++){
// //         waterTrapped+=Math.min(leftMax[i], rightMax[i])-heights[i];
// //     }
// //     return waterTrapped;
// // }

// // console.log(trapRainWater([0,1,0,2,1,0,1,3,2,1,2,1]));//6

// // //maximum consecutive ones
// // function maxConsecutiveOnes(arr){
// //     let maxCount=0, count=0;
// //     for( let i=0; i<arr.length; i++){
// //         if(arr[i]===0){
// //             maxCount=Math.max(maxCount, count);
// //             count=0;
// //         }else{
// //             count++;
// //         }
// //     }
// //     return Math.max(maxCount, count);
// // }

// // console.log(maxConsecutiveOnes([1,1,0,1,1,1]));//3

// // //Kadane algorithm to find maximum subarray sum
// // function maximumSubarraySum(arr) {
// //   const n = arr.length;
// //   let temp = new Array(n);
// //   temp[0] = arr[0];

// //   for (let i = 1; i < n; i++) {
// //     temp[i] = Math.max(temp[i - 1] + arr[i], arr[i]);
// //   }

// //   let res = -Infinity;
// //   for (let i = 0; i < n; i++) {
// //     res = Math.max(res, temp[i]);
// //   }

// //   return res;
// // }

// // // Example:
// // console.log(maximumSubarraySum([-2, 1, -3, 4, -1, 2, 1, -5, 4])); 
// // // Output: 6 (subarray [4, -1, 2, 1])

// // // circular array maximum subarray sum
// // function circularMaximumSubarraySum(arr) {
// //     let max_normal=maximumSubarraySum(arr);
// //     if(max_normal<0) return max_normal;

// //     let arr_sum=0;
// //     for(let i=0; i<arr.length; i++){
// //         arr_sum+=arr[i];
// //         arr[i]=-arr[i];
// //     }
// //     let max_circular=arr_sum+maximumSubarraySum(arr);
// //     return Math.max(max_normal, max_circular);
// // }

// // console.log(circularMaximumSubarraySum([8, -4, 3, -5, 4]));//12

// // //majority element in an array
// // //using map
// // function majorityElement(arr){
// //     let freqMap=new Map();
// //     for(const num of arr){
// //         if(freqMap.has(num)){
// //             freqMap.set(num, freqMap.get(num)+1);
// //         }else{
// //             freqMap.set(num, 1);
// //         }
// //     }
// //     let majorityCount=Math.floor(arr.length/2);
// //     for(const [key, value] of freqMap){
// //         if(value>majorityCount){
// //             return key;

// //         }
// //     }
// //     return -1;
// // }
// // console.log(majorityElement([3,2,3]));//3

// // //method 2 using sorting
// // function majorityElement_2(arr){
// //     let res=0, count=1;
// //     for(let i=1; i<arr.length; i++){
// //         if(arr[i]==arr[res]){
// //             count++;
// //         }else{
// //             count--;
// //         }
// //         if(count==0){
// //             res=i;
// //             count=1;
// //         }
// //     }
// //     let count2=0;
// //     for(let i=0; i<arr.length; i++){
// //         if(arr[i]==arr[res]){
// //             count2++;
// //         }
// //     }
// //     return count2>Math.floor(arr.length/2)?arr[res]:-1;
// // }

// // console.log(majorityElement_2([3,2,3]));//3

// //left shift by k positions
// let arr=[1,2,3,4,5];
// let temp= new Array(arr.length);
// let k=2;
// for( let i=0; i<arr.length; i++){
//     temp[i]=arr[(i+k)%arr.length];
// }
// console.log(temp);//[3,4,5,1,2]




// const obj={
//     a:1,
//     b:2,
//     c:{
//         d:3
//     }
// }
// //to convert shallow copy
// const obj2=obj;
// obj2.c.d=10;
// console.log(obj.c.d);//10
// //to convert deep copy
// const obj3={...obj};
// obj3.c.d=20;
// console.log(obj.c.d);//10
// // console.log(obj3.a);//20


// var a = 1
// function foo(){
//  var a = 2
//  console.log(a)
// }
// foo()
// console.log(a);

// "use strict"
// function foo(){
//     a = 2
//   }
//   foo()
//   console.log(a);

// var answer = 0;

// const baseValue = value => multipleValue => value * multipleValue;

// const multiple = baseValue(2);
// answer = multiple(5);
// console.log(answer);// 10

// function outerFunc(outerParam) {
//   function innerFunc(innerParam) {
//      outerParam["b"] = innerParam;
//   }
//   return innerFunc;
// }

// const obj = {a:1}
// const example = outerFunc(obj);
// const answer = example(2)
// console.log(obj);

// let arr =[1,2]
// function test(array){
//   array.push(3)
// }
// test(arr)
// console.log(arr)

// let arr =[1,2]
// function test(array){
//   array.push(3)
// }
// test([...arr])
// console.log(arr) //[1,2] because we passed a copy of arr using spread operator that is why original arr is not modified

// let arr =[1,2]
// function test(array){
//   array = [1,2,3]
// }
// test(arr)
// console.log(arr)

// const carDetails = {
//     name: "Tomer",
//     getName(){
//        return this.name;
//     },
//   };
//   var name = "Joe";
//   var getCarName = carDetails.getName;
//   console.log(getCarName());// undefined because this refers to global object where name is not defined

// console.log(a)
// console.log(b)
// var a = 2
// let b = 2

a()
function a(){
    console.log("a")
}
b();
var b =function(){
    console.log("b")
}