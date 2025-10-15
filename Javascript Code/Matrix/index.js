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
        let row=" ";
        if(i==0 || i%2==0){
            for(let j=0; j<cols; j++){
                // console.log(mat[i][j]+" ");  
                row=row+mat[i][j]+" ";              
            }
        }
        else{
            for( let j=cols-1; j>=0; j--){
                // console.log(mat[i][j]+" ");
                row=row+mat[i][j]+" ";
            }
        }
        console.log(row);
    }
}

printSnakePattern([[1,2,3,4],[5,6,7,8],[9,10,11,12], [13,14,15,16]]);


// Matrix Boundary traversal
function boundaryTraversal(mat){
    let rows=mat.length, cols=mat[0].length;
    let top=0, left=0, bottom=rows-1, right=cols-1;
    let row="";
    for( let i=left; i<=right; i++){
        row=row+mat[top][i]+" ";
    }
    top++;
    for(let i=top; i<=bottom; i++){
        row=row+mat[i][right]+" ";
    }
    right--;
    for(let i =right; i>=left; i--){
        row=row+mat[bottom][i]+" ";
    }
    bottom--;
    for( let i=bottom; i>=top;i--){
        row=row+mat[i][left]+" ";
    }
    left++;
    return row;
}

console.log(boundaryTraversal([[1,2,3,4],[5,6,7,8],[9,10,11,12],[13,14,15,16]]));

//transpose of matrix
function transpose(mat){
    let rows=mat.length;
    let cols=mat[0].length;
    for( let i=0; i<rows; i++){
        for(let j=i+1; j<cols; j++){
            [mat[i][j], mat[j][i]]=[mat[j][i], mat[i][j]]
        }
    }
}
let mat3=[[1,2,3,4],[5,6,7,8],[9,10,11,12],[13,14,15,16]];
transpose(mat3);
console.log(mat3);

// rotate by 90 degree
function rotateBy90(mat){
    // first transpose the matrix
    let rows=mat.length, cols=mat[0].length;
    for(let i=0; i<rows; i++){
        for(let j=i+1; j<cols; j++){
            [mat[i][j], mat[j][i]]=[mat[j][i], mat[i][j]]
        }
    }

    
    for(let i=0; i<cols; i++){
        let low=0, high=rows-1;
        while(low<high){
            [mat[low][i], mat[high][i]]=[mat[high][i], mat[low][i]];
            low++;
            high--;
        }
    }
}

let mat4=[[1,2,3],[4,5,6],[7,8,9]];
rotateBy90(mat4);
console.log(mat4);