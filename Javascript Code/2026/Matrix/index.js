
//creating 2D Matrix in JAvascript
// let n=3
// let arr= Array.from({length:n}, ()=>Array(n).fill(0))

// for(let i=0; i<n; i++){
//     let row=""
//     for(let j=0; j<n; j++){
//         row+=arr[i][j]+" ";
//     }
//     console.log(row);    
// }

//snake pattern
// let mat= Array.from({length:r},()=>Array(c).fill(0));
//method 1
// function snakePattern(mat){
//     let r=mat.length;
//     let c=mat[0].length;

//     for(let i=0; i<r; i++){
//         let row=""
//         if(i%2===0){
//             for(let j=0; j<c; j++){
//                 row+=mat[i][j]+" "
//             }
//         }else{
//             for(let j=c-1; j>=0; j--){
//                 row+=mat[i][j]+" ";
//             }
//         }
//         console.log(row);        
//     }
// }

//Method2
// function snakePatt(mat){
//     for(let i=0; i<mat.length; i++){
//         let row= i%2===0 ? mat[i].join(" "):mat[i].slice().reverse().join(" ")
//         console.log(row);        
//     }
// }

// //4. Boundary Traversal
// function printBoundary(mat) {
//   let r = mat.length;
//   let c = mat[0].length;

//   let top = 0, bottom = r - 1, left = 0, right = c - 1;

//   for (let i = left; i <= right; i++) console.log(mat[top][i]);
//   for (let i = top + 1; i <= bottom; i++) console.log(mat[i][right]);
//   if (top !== bottom) {
//     for (let i = right - 1; i >= left; i--) console.log(mat[bottom][i]);
//   }
//   if (left !== right) {
//     for (let i = bottom - 1; i > top; i--) console.log(mat[i][left]);
//   }
// }

// //5. Spiral Traversal
// function spiralTraversal(mat) {
//   let top = 0, left = 0;
//   let bottom = mat.length - 1;
//   let right = mat[0].length - 1;

//   while (top <= bottom && left <= right) {
//     for (let i = left; i <= right; i++) console.log(mat[top][i]);
//     top++;

//     for (let i = top; i <= bottom; i++) console.log(mat[i][right]);
//     right--;

//     if (top <= bottom) {
//       for (let i = right; i >= left; i--) console.log(mat[bottom][i]);
//       bottom--;
//     }

//     if (left <= right) {
//       for (let i = bottom; i >= top; i--) console.log(mat[i][left]);
//       left++;
//     }
//   }
// }

// // transpose of a matrix
// function transpose(mat){
//     let n = mat.length

//     for( let i=0; i<n; i++){
//         for( let j=i+1; j<n; j++){
//             [mat[i][j], mat[j][i]]=[mat[j][i], mat[i][j]]
//         }
//     }
// }

// //Rotate Matrix by 90° Anti-clockwise
// //step1 first tranpose
// //step2 reverse column

// function rotateBy90(mat) {
//   let n = mat.length;

//   // Transpose
//   for (let i = 0; i < n; i++) {
//     for (let j = i + 1; j < n; j++) {
//       [mat[i][j], mat[j][i]] = [mat[j][i], mat[i][j]];
//     }
//   }

//   // Reverse columns
//   for (let col = 0; col < n; col++) {
//     let top = 0, bottom = n - 1;
//     while (top < bottom) {
//       [mat[top][col], mat[bottom][col]] =
//         [mat[bottom][col], mat[top][col]];
//       top++;
//       bottom--;
//     }
//   }
// }


//8. Search in Row-wise & Column-wise Sorted Matrix
function searchMatrix(mat, x) {
  let r = mat.length;
  let c = mat[0].length;

  let i = 0, j = c - 1;

  while (i < r && j >= 0) {
    if (mat[i][j] === x) {
      console.log(`Found at ${i}, ${j}`);
      return;
    } else if (mat[i][j] > x) {
      j--;
    } else {
      i++;
    }
  }
  console.log("Not Found");
}

//9. Median of Row-wise Sorted Matrix
function medianOfSortedMatrix(mat) {
  let r = mat.length;
  let c = mat[0].length;

  let min = mat[0][0];
  let max = mat[0][c - 1];

  for (let i = 1; i < r; i++) {
    min = Math.min(min, mat[i][0]);
    max = Math.max(max, mat[i][c - 1]);
  }

  let desired = Math.floor((r * c + 1) / 2);

  while (min < max) {
    let mid = Math.floor((min + max) / 2);
    let count = 0;

    for (let i = 0; i < r; i++) {
      count += mat[i].filter(x => x <= mid).length;
    }

    if (count < desired) min = mid + 1;
    else max = mid;
  }
  return min;
}


let mat = [
    [1, 2, 3],
    [4, 5, 6],
    [7, 8, 9]
];

// rotateBy90(mat)

// snakePattern(mat);
// transpose(mat)

console.log(mat);




