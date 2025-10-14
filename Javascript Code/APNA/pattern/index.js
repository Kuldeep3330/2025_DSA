
// squarePatt(5);
function squarePatt(n){
    for(let i=1; i<=n; i++){
        let row=" "
        for( let j=1; j<=n; j++){
            row=row+j+" ";
        }
        console.log(row);        
    }
}
squarePatt(5);

function squareForStar(n){
    for( let i=1; i<=n; i++){
        let row=" ";
        for(let j=1; j<=n; j++){
            row= row+"* ";
        }
        console.log(row);       
    }
}
squareForStar(5);

// trianglePatt(5);
 function trianglePatt(n){
    for(let i=1; i<=n; i++){
        let row=" ";
        for( let j=1; j<=i; j++){
            row= row+"* ";
        }
        console.log(row);
    }
 }
 trianglePatt(5);

// inverted trianglePatt(5);
function invertedTrianglePatt(n){
    for(let i=n; i>=1; i--){
        let row=" ";
        for(let j=1; j<=i; j++){
            row= row+"* ";
        }
        console.log(row);
    }
}
invertedTrianglePatt(5);

// inverted trianglePatt 
function invertTriangle(n){
    for(let i=1; i<=n; i++){
        let row=" ";
        //for spaces
        for(let j=1;j<i;j++){
            row=row+"  ";
        }
        //for stars
        for(let j=1; j<=n-i+1; j++){
            row= row+i+" ";
        }
        console.log(row);
    }
}
invertTriangle(5);

// Pyramid pattern
function pyramidPatt(n){
    for(let i=1; i<=n; i++){
        let row=" ";
        //for spaces
        for(let j=1; j<=n-i; j++){
            row=row+"  ";
        }
        //for numbers
        for( let j=1; j<=i; j++){
            row= row+j+" ";
        }
        //for numbers in reverse order
        for(let j=i-1; j>=1; j--){
            row=row+j+" ";
        }
        console.log(row);
    }
}
console.log("pyramid pattern", pyramidPatt(5));







