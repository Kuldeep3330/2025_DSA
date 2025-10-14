function IsPAl(n){
    let dup=n;
    let rev=0;
    while(n>0){
        let d=n%10;
        rev=rev*10+d;
        n=Math.floor(n/10);
    }
    return rev==dup;
}

console.log(IsPAl(121));

//Armstrong number
function IsArmstrong(n){
    let dup=n;
    let sum=0;
    while(n>0){
       let last=n%10;
        sum+=last*last*last;
        n=Math.floor(n/10); 
    }
    return sum==dup;
}

console.log(IsArmstrong(153));

//print all divisors of a number
function printDivisors(n){
    let divs=[];
    for(let i=1;i<=Math.floor(n/2);i++){
        if(n%i==0){
            divs.push(i);
        }
    }
    divs.push(n);
    return divs;    
}

console.log(printDivisors(28));

//printvdivisorsusing sqrt(n)
function printDivisorsSqrt(n){
    let divs=[];
    for(let i=1;i<=Math.floor(Math.sqrt(n));i++){
        if(n%i==0){
            divs.push(i);
            if(i!=n/i){
                divs.push(n/i);
            }
        }
    }
    return divs;
}
console.log(printDivisorsSqrt(28));

//prime number check

function isPrime(n){
    if(n<=1) return false
    for(let i=2;i<=Math.floor(Math.sqrt(n));i++){
        if(n%i==0) return false;

    }
    return true;
}
console.log(isPrime(2));
//2 is a prime number

//GCD of two numbers
function gcd(a,b){
    if(b==0) return a;
    return gcd(b,a%b);    
}

console.log("gcd of two numbers", gcd(56,98));

//Power exponentiation
function power(a,b){
    if(b==0) return 1;
    if(b%2==0){
        let half=power(a,b/2);
        return half*half;
    }
    else{
        return a*power(a,b-1);
    }    
}

console.log("power", power(2,10));

//Sieve of Eratosthenes
function sieve(n){
    let primes=new Array(n+1).fill(true);
    primes[0]=primes[1]=false;
    for(let i=2;i*i<=n;i++){
        if(primes[i]){
            for(let j=i*i;j<=n;j+=i){
                primes[j]=false;
            }
        }
    }
    let result=[];
    for(let i=2;i<=n;i++){
        if(primes[i]) result.push(i);
    }
    return result;
}
