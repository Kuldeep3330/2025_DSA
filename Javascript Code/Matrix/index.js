const matrix=[[1,2,3],[4,5,6],[7,8,9]];
for(let i=0; i<matrix.length; i++){
    for( let j=0; j<matrix[0].length; j++){
        console.log(matrix[i][j]);
    }
}

const matrix2=Array.from({length:3}, ()=> Array(4).fill(0));
console.log(matrix2);

//Matrix in snake pattern
function printSnakePattern(mat){
    let rows=mat.length;
    let cols=mat[0].length;
    for(let i=0; i<rows; i++){
        if(i==0 || i%2==0){
            for(let j=0; j<cols; j++){
                console.log(mat[i][j]+" ");                
            }
        }
        else{
            for( let j=cols-1; j>=0; j--){
                console.log(mat[i][j]+" ");
            }
        }
    }
}

printSnakePattern([[1,2,3],[4,5,6],[7,8,9]]);

//Matrix Boundary traversal
function printBoundary(mat) {
  const r = mat.length;
  const c = mat[0].length;
  let result = [];

  let left = 0, right = c - 1, top = 0, bottom = r - 1;

  // Top row
  for (let i = left; i <= right; i++) result.push(mat[top][i]);
  top++;

  // Right column
  for (let i = top; i <= bottom; i++) result.push(mat[i][right]);
  right--;

  // Bottom row
  for (let i = right; i >= left; i--) result.push(mat[bottom][i]);
  bottom--;

  // Left column
  for (let i = bottom; i >= top; i--) result.push(mat[i][left]);
  left++;

  console.log(result.join(" "));
}

// Example:
printBoundary([
  [1, 2, 3, 4],
  [5, 6, 7, 8],
  [9, 10, 11, 12],
  [13, 14, 15, 16]
]);
// Output: 1 2 3 4 8 12 16 15 14 13 9 5

//Matrix in spiral form

// transpose of a matrix
function transpose(mat){
    let rows=mat.length;
    let cols=mat[0].length;
    for(let i=0; i<rows; i++){
        for(let j=i+1; j<cols; j++){
            [mat[i][j], mat[j][i]]=[mat[j][i], mat[i][j]];
        }
    }
}
let mat3=[[1,2,3],[4,5,6],[7,8,9]];
transpose(mat3);
console.log(mat3);
//rotate matrix by 90 degree
function rotateBy90(mat){
    transpose(mat);
    let rows=mat.length;
    let cols=mat[0].length;
    for(let i=0; i<rows; i++){
        let left=0, right=cols-1;
        while(left<right){
            [mat[i][left], mat[i][right]]=[mat[i][right], mat[i][left]];
            left++;
            right--;
        }
    }

}

let mat4=[[1,2,3],[4,5,6],[7,8,9]];
rotateBy90(mat4);
console.log(mat4);
