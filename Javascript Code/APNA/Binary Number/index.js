//binary number system

//decimal to binary
function decToBin(n){
    let bin="";
    while(n>0){
        let rem=n%2;
        bin=rem+bin;
        n=Math.floor(n/2);
    }
    return bin;
}

console.log(decToBin(10));//1010

//binary to decimal
function binToDec(n){
    let dec=0, base=1;
    while(n>0){
        let last=n%10;
        dec+=last*base; 
        base*=2;// 32 16 8 4 2 1
        n=Math.floor(n/10);
    }
    return dec;
}
console.log(binToDec(101010));//42

//binary to gray
function binToGray(n){
    let bin=n;
    let gray=bin^ (bin>>1);
    return gray;
}
console.log(binToGray(10));//15